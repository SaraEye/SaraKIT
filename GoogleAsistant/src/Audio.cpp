#include "Audio.hpp"

PulseWrapper::PulseWrapper()
{
    enablePlayer();
    enableMic();
}
PulseWrapper::~PulseWrapper()
{

    disableMic();
    disablePlayer();
    pwInstance = nullptr;
}

std::shared_ptr<PulseWrapper> PulseWrapper::pwInstance{nullptr};
std::mutex PulseWrapper::pwMutex;
std::shared_ptr<PulseWrapper> PulseWrapper::getInstance()
{
    std::lock_guard<std::mutex> lock(pwMutex);
    if (pwInstance == nullptr)
    {
        pwInstance.reset(new PulseWrapper());
    }
    return pwInstance;
}

std::vector<std::function<void(char *, int)>>::iterator PulseWrapper::AddListener(std::function<void(char *, int)> listener)
{
    std::unique_lock<std::mutex> lock(listenerMutex);
    return listeners.insert(listeners.end(), listener);
}

void PulseWrapper::stopListen(std::vector<std::function<void(char *, int)>>::iterator it)
{
    std::unique_lock<std::mutex> lock(listenerMutex);
    listeners.erase(it);
}
void PulseWrapper::runMic()
{
    pa_simple *smic = NULL;
    int buffsize = 512;
    int ret = 1;
    int error;
    /* The sample type to use */
    pa_sample_spec ss = {
        .format = PA_SAMPLE_S16LE,
        .rate = 16000,
        .channels = 1};
    if (!(smic = pa_simple_new(NULL, "sara_tts_mic", PA_STREAM_RECORD, NULL, "mic", &ss, NULL, NULL, &error)))
    {
        fprintf(stderr, __FILE__ ": pa_simple_new() failed: %s\n", pa_strerror(error));
        return;
    }
    while (!endMic)
    {

        char buf[buffsize];

        /* Record some data ... */
        if (pa_simple_read(smic, buf, sizeof(buf), &error) < 0)
        {
            fprintf(stderr, __FILE__ ": pa_simple_read() failed: %s\n", pa_strerror(error));
        }

        //        file.write(buf, buffsize);
        if(!muteMic){
            std::unique_lock<std::mutex> lock(listenerMutex);
            for (auto &listener : listeners)
            {
                listener(buf, buffsize);
            }
            lock.unlock();
        }
    }
    pa_simple_free(smic);
}
void PulseWrapper::enablePlayer()
{
    endPlayer = false;

    playerTask = std::thread(&PulseWrapper::player, this);
}
void PulseWrapper::disablePlayer()
{
    endPlayer = true;
    if (playerTask.joinable())
        playerTask.join();
}
void PulseWrapper::enableMic()
{
    muteMic=false;
    endMic = false;
    micTask = std::thread(&PulseWrapper::runMic, this);
    // micTask.detach();
}
void PulseWrapper::disableMic()
{
    endMic = true;
    if (micTask.joinable())
        micTask.join();
    for (auto &stopListener : stopListeners)
    {
        stopListener();
    }
}

int PulseWrapper::playAudioStringAsync(std::string streamData, unsigned int sampleRate, float volumeFactor = 1.0)
{
    std::shared_ptr<std::vector<unsigned char>> data(new std::vector<unsigned char>);
    for (int i = 0; i < streamData.length() - sizeof(WAV_HEADER); i += 2)
    {
        short sval = ((short)streamData[sizeof(WAV_HEADER) + i + 1] << 8) | (short)streamData[sizeof(WAV_HEADER) + i];
        sval *= volumeFactor;
        data->push_back(sval & 0xff);
        data->push_back((sval >> 8) & 0xff);
    }
    playAudioAsync(data, sampleRate);
    return 1;
}

int PulseWrapper::playAudioAsync(std::shared_ptr<std::vector<unsigned char>> streamData, unsigned int sampleRate)
{
    std::unique_lock<std::mutex> lock(audioDataMutex);
    audioData.push_back(streamData);
    audioDataCv.notify_one();
    return 1;
}

void PulseWrapper::player()
{
    /* The Sample format to use */
    static const pa_sample_spec pss = {
        .format = PA_SAMPLE_S16LE,
        .rate = 16000, // sampleRate,
        .channels = 1};

    pa_simple *ps;
    int error;
    /* Create a new playback stream */
    if (!(ps = pa_simple_new(NULL, "sara_sst_asyncplayer", PA_STREAM_PLAYBACK, NULL, "asyncplayer", &pss, NULL, NULL, &error)))
    {
        printf(": pa_simple_new() failed: %s\n", pa_strerror(error));
        pa_simple_free(ps);
        return;
    }
    while (!endPlayer)
    {
        std::unique_lock<std::mutex> lock(audioDataMutex);

        while (audioData.size() == 0 && !endPlayer)
        {
            muteMic=false;
            audioDataCv.wait_for(lock, std::chrono::milliseconds(100));
        }
        muteMic=true;
        if (endPlayer)
        {
            break;
        }

        std::shared_ptr<std::vector<unsigned char>> data = audioData[0];
        audioData.erase(audioData.begin());
        if (pa_simple_write(ps, (data->data()), data->size(), &error) < 0)
        {
            printf(": pa_simple_write() failed: %s\n", pa_strerror(error));
            pa_simple_free(ps);
            break;
        }
    }
    if (pa_simple_drain(ps, &error) < 0)
    {
        printf(": pa_simple_drain() failed: %s\n", pa_strerror(error));
        pa_simple_free(ps);
    }
    if (ps)
        pa_simple_free(ps);
}
