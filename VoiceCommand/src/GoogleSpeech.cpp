#include "GoogleSpeech.hpp"

#include <curl/curl.h>
#include "json.hpp"
#include <ifaddrs.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>

GoogleSpeechToText::GoogleSpeechToText(std::string key)
{
    endProcessing = false;
    apiKey=key;
}
GoogleSpeechToText::~GoogleSpeechToText()
{
    stopSTT();
}

void GoogleSpeechToText::startSTT()
{
    endProcessing = false;
    speechTask = std::thread(&GoogleSpeechToText::recognize, this);
}

void GoogleSpeechToText::stopSTT()
{
    endProcessing = true;
    stopPulswStreamFunc();
    if (speechTask.joinable())
        speechTask.join();
}
void GoogleSpeechToText::addPulswStopStream(std::function<void()> stopPulswStream)
{
    stopPulswStreamFunc = stopPulswStream;
}
void GoogleSpeechToText::recognize()
{
    std::shared_ptr<PulseWrapper> pulsw = PulseWrapper::getInstance();
    GoogleTextToSpeech tts(apiKey);
    while (!endProcessing)
    {
        // dev account auth
        //************************************************************
        auto creds = grpc::GoogleDefaultCredentials();
        auto channel = grpc::CreateChannel("speech.googleapis.com", creds);
        //  PortaudioWrapper pw;
        auto speech = Speech::NewStub(channel);
        //************************************************************

        // Parse command line arguments.
        StreamingRecognizeRequest request;
        auto streaming_config = request.mutable_streaming_config();
        streaming_config->mutable_config()->set_model("default");
        streaming_config->mutable_config()->enable_automatic_punctuation();

        streaming_config->mutable_config()->set_language_code("pl-PL");
        streaming_config->mutable_config()->set_sample_rate_hertz(16000); // Default sample rate.
        streaming_config->mutable_config()->set_encoding(google::cloud::speech::v1::RecognitionConfig::LINEAR16);
        grpc::ClientContext context;

        //  auto streamer = speech->StreamingRecognize(&context);
        std::shared_ptr<grpc::ClientReaderWriter<StreamingRecognizeRequest, StreamingRecognizeResponse>> stream(
            std::move(speech->StreamingRecognize(&context)));
        // Write the first request, containing the config only.
        streaming_config->set_interim_results(true);

        stream->Write(request);
        int duration = 0;
        auto &ep =endProcessing;
        auto listener = pulsw->AddListener([stream, &request, &duration, &ep](char *buf, int buffsize)
                                           {
            if(!ep){
                request.set_audio_content(buf, buffsize);
                stream->Write(request);
                duration += buffsize;
                if (duration > 16000 * 240)//listen for 240s
                {
                    stream->WritesDone();
                    duration=0;
                }

            } });
        addPulswStopStream([stream]()
                           { stream->WritesDone(); });
        StreamingRecognizeResponse response;
        while (stream->Read(&response) && !endProcessing)
        { // Returns false when no more to read.
            // Dump the transcript of all the results.
            //for (int r = 0; r < response.results_size(); ++r)
            if(response.results_size()>0)
            {
                const auto &result = response.results(0);
                // std::cout << "Result stability: " << result.stability() << std::endl;
                //for (int a = 0; a < result.alternatives_size(); ++a)
                if(result.alternatives_size()>0)
                {
                    const auto &alternative = result.alternatives(0);

                    std::cout << "SST result: " << alternative.confidence() << "\t"
                              << alternative.transcript() << std::endl;
                  

                    if (alternative.confidence() > 0)
                    {  
                        duration =16000 * 240+100;         
                        KeywordAction kaction=kam.parseText(alternative.transcript());
                        switch (kaction)
                        {
                        case Hello:
                            tts.transcribe("hello");
                            break;
                        case Bye:
                            tts.transcribe("goodbye");
                            break;
                        default:
                            break;
                        }
                       
                        std::cout << "End of speech" << std::endl;
                    }
                    
                }
            }
        }
        pulsw->stopListen(listener);
        grpc::Status status = stream->Finish();
        if (!status.ok())
        {
            // Report the RPC failure. 
            std::cerr << status.error_message() << std::endl;
        }
    }
}

GoogleTextToSpeech::GoogleTextToSpeech(std::string key)
{
    jsonPost = CJSONPost("https://texttospeech.googleapis.com/v1beta1/text:synthesize?key=" + key);
}
GoogleTextToSpeech::~GoogleTextToSpeech() {}

void GoogleTextToSpeech::transcribe(std::string text)
{
    std::cout << "transcribe: " << text << std::endl;
    if (text.length() > 0)
    {
        std::string jsonstr = "{  \"audioConfig\": {    \"audioEncoding\": \"LINEAR16\",    \"pitch\": 0,  \"sampleRateHertz\": 16000,    \"speakingRate\": 1  },  \"input\": {    \"text\": \"" + text + "\"  },  \"voice\": {    \"languageCode\": \"pl-PL\",    \"name\": \"pl-PL-Wavenet-A\" }}";
        jsonTranscriptonParseAndPlay(jsonPost.send(jsonstr));
    }
}
void GoogleTextToSpeech::jsonTranscriptonParseAndPlay(std::string text)
{
    json coutput = json::parse(text);
    std::string audioData = coutput.value("audioContent", "err");
    json jaudioConfig;
    jaudioConfig = coutput.value("audioConfig", jaudioConfig);
    int sr = jaudioConfig.value("sampleRateHertz", 0);
    std::string wavData = base64_decode(audioData);
    std::shared_ptr<PulseWrapper> pulsw = PulseWrapper::getInstance();
    pulsw->playAudioStringAsync(wavData, sr, 1.0);
}

