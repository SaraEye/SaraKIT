

#include <memory>

#include <AVSCommon/Utils/Logger/Logger.h>

#include "Porcupine/PorcupineKeywordDetector.h"

namespace alexaClientSDK {
namespace kwd {

using namespace avsCommon::utils::logger;

/// String to identify log entries originating from this file.
static const std::string TAG("PorcupineKeywordDetector");

/**
 * Create a LogEntry using this file's TAG and the specified event string.
 *
 * @param The event string for this @c LogEntry.
 */
#define LX(event) alexaClientSDK::avsCommon::utils::logger::LogEntry(TAG, event)

/// The number of hertz per kilohertz.
static const size_t HERTZ_PER_KILOHERTZ = 1000;

/// The timeout to use for read calls to the SharedDataStream.
const std::chrono::milliseconds TIMEOUT_FOR_READ_CALLS = std::chrono::milliseconds(1000);

/// The Pocupine compatible AVS sample rate of 16 kHz.
static const unsigned int PORCUPINE_COMPATIBLE_SAMPLE_RATE = 16000;

/// The Pocupine compatible bits per sample of 16.
static const unsigned int PORCUPINE_COMPATIBLE_SAMPLE_SIZE_IN_BITS = 16;

/// The Pocupine compatible number of channels, which is 1.
static const unsigned int PORCUPINE_COMPATIBLE_NUM_CHANNELS = 1;

/// The Pocupine compatible audio encoding of LPCM.
static const avsCommon::utils::AudioFormat::Encoding PORCUPINE_COMPATIBLE_ENCODING =
    avsCommon::utils::AudioFormat::Encoding::LPCM;

/// The Pocupine compatible endianness which is little endian.
static const avsCommon::utils::AudioFormat::Endianness PORCUPINE_COMPATIBLE_ENDIANNESS =
    avsCommon::utils::AudioFormat::Endianness::LITTLE;

/**
 * Checks to see if an @c avsCommon::utils::AudioFormat is compatible with Pocupine.
 *
 * @param audioFormat The audio format to check.
 * @return @c true if the audio format is compatible with Pocupine and @c false otherwise.
 */
static bool isAudioFormatCompatibleWithPorcupine(avsCommon::utils::AudioFormat audioFormat) {
    if (PORCUPINE_COMPATIBLE_ENCODING != audioFormat.encoding) {
        ACSDK_ERROR(LX("isAudioFormatCompatibleWithPorcupine")
                        .d("reason", "incompatibleEncoding")
                        .d("PocupineEncoding", PORCUPINE_COMPATIBLE_ENCODING)
                        .d("encoding", audioFormat.encoding));
        return false;
    }
    if (PORCUPINE_COMPATIBLE_ENDIANNESS != audioFormat.endianness) {
        ACSDK_ERROR(LX("isAudioFormatCompatibleWithPorcupine")
                        .d("reason", "incompatibleEndianess")
                        .d("PocupineEndianness", PORCUPINE_COMPATIBLE_ENDIANNESS)
                        .d("endianness", audioFormat.endianness));
        return false;
    }
    if (PORCUPINE_COMPATIBLE_SAMPLE_RATE != audioFormat.sampleRateHz) {
        ACSDK_ERROR(LX("isAudioFormatCompatibleWithPorcupine")
                        .d("reason", "incompatibleSampleRate")
                        .d("PocupineSampleRate", PORCUPINE_COMPATIBLE_SAMPLE_RATE)
                        .d("sampleRate", audioFormat.sampleRateHz));
        return false;
    }
    if (PORCUPINE_COMPATIBLE_SAMPLE_SIZE_IN_BITS != audioFormat.sampleSizeInBits) {
        ACSDK_ERROR(LX("isAudioFormatCompatibleWithPorcupine")
                        .d("reason", "incompatibleSampleSizeInBits")
                        .d("PocupineSampleSizeInBits", PORCUPINE_COMPATIBLE_SAMPLE_SIZE_IN_BITS)
                        .d("sampleSizeInBits", audioFormat.sampleSizeInBits));
        return false;
    }
    if (PORCUPINE_COMPATIBLE_NUM_CHANNELS != audioFormat.numChannels) {
        ACSDK_ERROR(LX("isAudioFormatCompatibleWithPorcupine")
                        .d("reason", "incompatibleNumChannels")
                        .d("PocupineNumChannels", PORCUPINE_COMPATIBLE_NUM_CHANNELS)
                        .d("numChannels", audioFormat.numChannels));
        return false;
    }
    return true;
}

std::unique_ptr<PorcupineKeywordDetector> PorcupineKeywordDetector::create(
    std::shared_ptr<avsCommon::avs::AudioInputStream> stream,
    avsCommon::utils::AudioFormat audioFormat,
    std::unordered_set<std::shared_ptr<avsCommon::sdkInterfaces::KeyWordObserverInterface>> keyWordObservers,
    std::unordered_set<std::shared_ptr<avsCommon::sdkInterfaces::KeyWordDetectorStateObserverInterface>>
        keyWordDetectorStateObservers,
    const std::string& porcupinePath,
    std::chrono::milliseconds msToPushPerIteration) {
    if (!stream) {
        ACSDK_ERROR(LX("createFailed").d("reason", "nullStream"));
        return nullptr;
    }

    // TODO: ACSDK-249 - Investigate cpu usage of converting bytes between endianness and if it's not too much, do it.
    if (isByteswappingRequired(audioFormat)) {
        ACSDK_ERROR(LX("createFailed").d("reason", "endianMismatch"));
        return nullptr;
    }

    if (!isAudioFormatCompatibleWithPorcupine(audioFormat)) {
        return nullptr;
    }
    std::unique_ptr<PorcupineKeywordDetector> detector(new PorcupineKeywordDetector(
        stream, keyWordObservers, keyWordDetectorStateObservers, audioFormat, porcupinePath, msToPushPerIteration));
    if (!detector->init()) {
        ACSDK_ERROR(LX("createFailed").d("reason", "initDetectorFailed"));
        return nullptr;
    }
    return detector;
}

PorcupineKeywordDetector::~PorcupineKeywordDetector() {
    m_isShuttingDown = true;
    if (m_detectionThread.joinable()) {
        m_detectionThread.join();
    }
    pv_porcupine_delete(m_session);
}

PorcupineKeywordDetector::PorcupineKeywordDetector(
    std::shared_ptr<AudioInputStream> stream,
    std::unordered_set<std::shared_ptr<KeyWordObserverInterface>> keyWordObservers,
    std::unordered_set<std::shared_ptr<KeyWordDetectorStateObserverInterface>> keyWordDetectorStateObservers,
    avsCommon::utils::AudioFormat audioFormat,
    const std::string& porcupinePath,
    std::chrono::milliseconds msToPushPerIteration) :
        AbstractKeywordDetector(keyWordObservers, keyWordDetectorStateObservers),
        m_stream{stream},
        m_session{nullptr},

        m_maxSamplesPerPush((audioFormat.sampleRateHz / HERTZ_PER_KILOHERTZ) * msToPushPerIteration.count()) {
    m_porcupinePath = porcupinePath + "/";

}

bool PorcupineKeywordDetector::init() {
    m_streamReader = m_stream->createReader(AudioInputStream::Reader::Policy::BLOCKING);
    if (!m_streamReader) {
        ACSDK_ERROR(LX("initFailed").d("reason", "createStreamReaderFailed"));
        return false;
    }

    std::string modelPath = m_porcupinePath + "porcupine_params.pv";
    std::string keyWordPath = m_porcupinePath + "alexa_raspberry-pi.ppn";
    const char* keyword_path = keyWordPath.c_str();
    float sensitivity = 0.5;
    pv_status_t status = pv_porcupine_init(modelPath.c_str(), 1, &keyword_path, &sensitivity, &m_session);
    if (status != PV_STATUS_SUCCESS) {
        // fprintf(stderr, "'pv_porcupine_init' failed with '%s'\n", pv_status_to_string_func(status));
        ACSDK_ERROR(LX("initFailed").d("reason", "porcupineInitFailed"));
        return false;
    }

    m_isShuttingDown = false;
    m_detectionThread = std::thread(&PorcupineKeywordDetector::detectionLoop, this);
    return true;
}

void PorcupineKeywordDetector::detectionLoop() {
    int32_t frame_length = pv_porcupine_frame_length();
    notifyKeyWordDetectorStateObservers(KeyWordDetectorStateObserverInterface::KeyWordDetectorState::ACTIVE);

    //    fprintf(stdout, "frame_length '%d' m_maxSamplesPerPush %ud\n",frame_length, m_maxSamplesPerPush);
    m_maxSamplesPerPush = frame_length;
    //   fprintf(stdout, "m_maxSamplesPerPush %ud\n", m_maxSamplesPerPush);
    int16_t audioDataToPush[m_maxSamplesPerPush];

    while (!m_isShuttingDown) {
        bool didErrorOccur;
        auto wordsRead = readFromStream(
            m_streamReader, m_stream, audioDataToPush, m_maxSamplesPerPush, TIMEOUT_FOR_READ_CALLS, &didErrorOccur);
            // for (int j = 0; j < wordsRead; j++) {
            //         printf("%d;", audioDataToPush[j]);
            //  }
             //   printf("\n");

        for (int i = 0; i < wordsRead; i++) {
            audioData.push_back(audioDataToPush[i]);
        }
        if (audioData.size() >= 512) {
            for (int j = 0; j < 512; j++) {
                audioDataToPush[j] = audioData[j];
            //    printf("%d ", audioDataToPush[j]);
            }
          //  printf("\n ");
        } else {
            continue;
        }
       // if (audioData.size() >= 512) {

            if (didErrorOccur) {
                fprintf(stdout, "'pv_porcupine_process' didErrorOccur \n");
                break;

            } else if (wordsRead > 0) {
                // Words were successfully read.
                notifyKeyWordDetectorStateObservers(
                    KeyWordDetectorStateObserverInterface::KeyWordDetectorState::ACTIVE);
                // int detectionResult = m_kittAiEngine->RunDetection(audioDataToPush, wordsRead);
                int32_t keyword_index = -1;
                pv_status_t status = pv_porcupine_process(m_session, audioDataToPush, &keyword_index);
                if (keyword_index != -1) {
                    notifyKeyWordObservers(
                        m_stream,
                        "ALEXA",
                        KeyWordObserverInterface::UNSPECIFIED_INDEX,
                        m_streamReader->tell());
                } else {
                    if (status != PV_STATUS_SUCCESS) {
                        fprintf(stderr, "'pv_porcupine_process' failed with '%s'\n", pv_status_to_string(status));
                        notifyKeyWordDetectorStateObservers(
                            KeyWordDetectorStateObserverInterface::KeyWordDetectorState::ERROR);
                    }
                    // ACSDK_ERROR(LX("detectionLoopFailed").d("reason", "kittAiEngineError"));
                }
                if (didErrorOccur) {
                    break;
                }
            }
            audioData.erase(audioData.begin(), audioData.begin() + 512);
     //   }
    }
    m_streamReader->close();
}

}  // namespace kwd
}  // namespace alexaClientSDK