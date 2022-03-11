#ifndef ALEXA_CLIENT_SDK_KWD_PORCUPINE_INCLUDE_PORCUPINE_PORCUPINEKEYWORDDETECTOR_H_
#define ALEXA_CLIENT_SDK_KWD_PORCUPINE_INCLUDE_PORCUPINE_PORCUPINEKEYWORDDETECTOR_H_
#include <atomic>
#include <string>
#include <thread>
#include <unordered_set>
#include <dlfcn.h>
#include <signal.h>


#include <AVSCommon/Utils/AudioFormat.h>
#include <AVSCommon/AVS/AudioInputStream.h>
#include <AVSCommon/SDKInterfaces/KeyWordObserverInterface.h>
#include <AVSCommon/SDKInterfaces/KeyWordDetectorStateObserverInterface.h>

#include "KWD/AbstractKeywordDetector.h"
#include "pv_porcupine.h"


namespace alexaClientSDK {
namespace kwd {

using namespace avsCommon;
using namespace avsCommon::avs;
using namespace avsCommon::sdkInterfaces;

class PorcupineKeywordDetector : public AbstractKeywordDetector {
public:
    /**
     * Creates a @c PorcupineKeywordDetector.
     *
     * @param stream The stream of audio data. This should be formatted in LPCM encoded with 16 bits per sample and
     * have a sample rate of 16 kHz. Additionally, the data should be in little endian format.
     * @param audioFormat The format of the audio data located within the stream.
     * @param keyWordObservers The observers to notify of keyword detections.
     * @param keyWordDetectorStateObservers The observers to notify of state changes in the engine.
     * @param modelFilePath The path to the model file.
     * @param msToPushPerIteration The amount of data in milliseconds to push to Pocupine at a time. Smaller sizes will
     * lead to less delay but more CPU usage. Additionally, larger amounts of data fed into the engine per iteration
     * might lead longer delays before receiving keyword detection events. This has been defaulted to 10 milliseconds
     * as it is a good trade off between CPU usage and recognition delay. Additionally, this was the amount used by
     * Pocupine in example code.
     * @return A new @c PorcupineKeywordDetector, or @c nullptr if the operation failed.
     */
    static std::unique_ptr<PorcupineKeywordDetector> create(
        std::shared_ptr<AudioInputStream> stream,
        avsCommon::utils::AudioFormat audioFormat,
        std::unordered_set<std::shared_ptr<KeyWordObserverInterface>> keyWordObservers,
        std::unordered_set<std::shared_ptr<KeyWordDetectorStateObserverInterface>> keyWordDetectorStateObservers,
        const std::string& porcupinePath,
        std::chrono::milliseconds msToPushPerIteration = std::chrono::milliseconds(10));

    /**
     * Destructor.
     */
    ~PorcupineKeywordDetector() override;
private:
    /**
     * Constructor.
     *
     * @param stream The stream of audio data. This should be formatted in LPCM encoded with 16 bits per sample and
     * have a sample rate of 16 kHz. Additionally, the data should be in little endian format.
     * @param audioFormat The format of the audio data located within the stream.
     * @param keyWordObservers The observers to notify of keyword detections.
     * @param keyWordDetectorStateObservers The observers to notify of state changes in the engine.
     * @param msToPushPerIteration The amount of data in milliseconds to push to Pocupine at a time. Smaller sizes will
     * lead to less delay but more CPU usage. Additionally, larger amounts of data fed into the engine per iteration
     * might lead longer delays before receiving keyword detection events. This has been defaulted to 10 milliseconds
     * as it is a good trade off between CPU usage and recognition delay. Additionally, this was the amount used by
     * Pocupine in example code.
     */
    PorcupineKeywordDetector(
        std::shared_ptr<AudioInputStream> stream,
        std::unordered_set<std::shared_ptr<KeyWordObserverInterface>> keyWordObservers,
        std::unordered_set<std::shared_ptr<KeyWordDetectorStateObserverInterface>> keyWordDetectorStateObservers,
        avsCommon::utils::AudioFormat audioFormat,
        const std::string& porcupinePath,
        std::chrono::milliseconds msToPushPerIteration = std::chrono::milliseconds(50));
    /**
     * Initializes the stream reader, sets up the Pocupine engine, and kicks off a thread to begin processing data from
     * the stream. This function should only be called once with each new @c PocupineKeywordDetector.
     *
     * @return @c true if the engine was initialized properly and @c false otherwise.
     */
    bool init();

    /// The main function that reads data and feeds it into the engine.
    void detectionLoop();


    /// Indicates whether the internal main loop should keep running.
    std::atomic<bool> m_isShuttingDown;

    /// The stream of audio data.
    const std::shared_ptr<avsCommon::avs::AudioInputStream> m_stream;

    /// The reader that will be used to read audio data from the stream.
    std::shared_ptr<avsCommon::avs::AudioInputStream::Reader> m_streamReader;

    /**
     * This serves as a reference point used when notifying observers of keyword detection indices since Pocupine has no
     * way of specifying a start index.
     */
    avsCommon::avs::AudioInputStream::Index m_beginIndexOfStreamReader;

    /// Internal thread that reads audio from the buffer and feeds it to the Pocupine engine.
    std::thread m_detectionThread;

    /// The Pocupine handle.
    pv_porcupine_t *m_session=NULL;

    void *m_porcupine_library=NULL;
    //path to porcupine files
    std::string m_porcupinePath;
    /**
     * The max number of samples to push into the underlying engine per iteration. This will be determined based on the
     * sampling rate of the audio data passed in.
     */
    size_t m_maxSamplesPerPush;

    std::vector<int16_t> audioData;
    //int lastIdx;


    // const char *(*pv_status_to_string_func)(pv_status_t);
    // int32_t (*pv_sample_rate_func)();
   //  pv_status_t (*pv_porcupine_init_func)(const char *, int32_t, const char *const *, const float *, pv_porcupine_t **);
    // void (*pv_porcupine_delete_func)(pv_porcupine_t *);
    // pv_status_t (*pv_porcupine_process_func)(pv_porcupine_t *, const int16_t *, int32_t *);
    // int32_t (*pv_porcupine_frame_length_func)(); 





};
}  // namespace kwd
}  // namespace alexaClientSDK



#endif // ALEXA_CLIENT_SDK_KWD_PORCUPINE_INCLUDE_PORCUPINE_PORCUPINEKEYWORDDETECTOR_H_