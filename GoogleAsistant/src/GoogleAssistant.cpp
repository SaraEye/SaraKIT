#include "GoogleAssistant.hpp"

GoogleAssistant::GoogleAssistant() {
  endProcessing = false;
}
GoogleAssistant::~GoogleAssistant() {}

void GoogleAssistant::startAssistant()
{
  endProcessing = false;
  assistTask = std::thread(&GoogleAssistant::assist, this);
}
void GoogleAssistant::stopAssistant()
{
  endProcessing = true;
  if (assistTask.joinable())
    assistTask.join();
}

void GoogleAssistant::assist()
{
  while (endProcessing == false)
  {
    std::shared_ptr<PulseWrapper> pulsw = PulseWrapper::getInstance();

    AssistRequest request;
    auto *assist_config = request.mutable_config();

    // Set the DialogStateIn of the AssistRequest
    assist_config->mutable_dialog_state_in()->set_language_code(kLanguageCode);
    // Set the DeviceConfig of the AssistRequest
    assist_config->mutable_device_config()->set_device_id(kDeviceInstanceId);
    assist_config->mutable_device_config()->set_device_model_id(kDeviceModelId);

    // Set parameters for audio output
    assist_config->mutable_audio_out_config()->set_encoding(AudioOutConfig::LINEAR16);
    assist_config->mutable_audio_out_config()->set_sample_rate_hertz(16000);

    assist_config->mutable_audio_in_config()->set_encoding(
        AudioInConfig::LINEAR16);
    assist_config->mutable_audio_in_config()->set_sample_rate_hertz(16000);




//User auth based method
//************************************************************

    std::shared_ptr<CallCredentials> call_credentials;
    //TODO get this from user by smartphone app
    std::ifstream t("credentials.json");
    std::string credentials((std::istreambuf_iterator<char>(t)),std::istreambuf_iterator<char>());


  ///token cred file auth
  call_credentials = grpc::GoogleRefreshTokenCredentials(credentials);
  ///


    auto channel_credentials = grpc::SslCredentials(grpc::SslCredentialsOptions());
    auto creds = grpc::CompositeChannelCredentials(channel_credentials, call_credentials);
    ::grpc::ChannelArguments channel_args;

    auto channel = grpc::CreateCustomChannel("embeddedassistant.googleapis.com:443", creds, channel_args);
    std::unique_ptr<EmbeddedAssistant::Stub> assistant(
        EmbeddedAssistant::NewStub(channel));

    grpc::ClientContext context;
    context.set_fail_fast(false);
    context.set_credentials(call_credentials);
//************************************************************




    std::shared_ptr<ClientReaderWriter<AssistRequest, AssistResponse>> stream(
        std::move(assistant->Assist(&context)));
    // Write config in first stream.
    if (verbose)
    {
      std::clog << "assistant_sdk wrote first request: "
                << request.ShortDebugString() << std::endl;
    }
    stream->Write(request);
    auto listener = pulsw->AddListener([stream, &request](char *buf, int buffsize)
       {

              request.set_audio_in(buf, buffsize);
              stream->Write(request); 
        });

    if (verbose)
    {
      std::clog << "assistant_sdk waiting for response ... " << std::endl;
    }
    AssistResponse response;
    while (stream->Read(&response))
    { // Returns false when no more to read.
      if (response.has_audio_out() ||
          response.event_type() == AssistResponse_EventType_END_OF_UTTERANCE)
      {

      }
      if (response.has_audio_out())
      {
        
        std::shared_ptr<std::vector<unsigned char>> data(
            new std::vector<unsigned char>);
        data->resize(response.audio_out().audio_data().length());
        memcpy(&((*data)[0]), response.audio_out().audio_data().c_str(),
               response.audio_out().audio_data().length());
        pulsw->playAudioAsync(data, 16000);
      }
      // CUSTOMIZE: render spoken request on screen
      for (int i = 0; i < response.speech_results_size(); i++)
      {
        auto result = response.speech_results(i);
        if (verbose)
        {
          std::clog << "assistant_sdk request: \n"
                    << result.transcript() << " ("
                    << std::to_string(result.stability()) << ")" << std::endl;
        }
      }

      if (response.dialog_state_out().supplemental_display_text().size() > 0)
      {
        // CUSTOMIZE: render spoken response on screen
        std::clog << "assistant_sdk response:" << std::endl;
        std::cout << response.dialog_state_out().supplemental_display_text()
                  << std::endl;
      }
      // }
    }
    pulsw->stopListen(listener);
    grpc::Status status = stream->Finish();
    if (!status.ok())
    {
      // Report the RPC failure.
      std::cerr << "assistant_sdk failed, error: " << status.error_message()
                << std::endl;
    }
  }
}
