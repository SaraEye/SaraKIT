add_definitions("-DACSDK_LOG_MODULE=porcupineKeywordDetector")
add_library(PORCUPINE SHARED
    PorcupineKeywordDetector.cpp)

target_include_directories(PORCUPINE PUBLIC
	"${PORCUPINE_KEY_WORD_DETECTOR_INCLUDE_DIR}"
	"${KWD_SOURCE_DIR}/include" 
	"${PORCUPINE_SOURCE_DIR}/include")

target_link_libraries(PORCUPINE KWD AVSCommon "${PORCUPINE_KEY_WORD_DETECTOR_LIB_PATH}")

# install target
asdk_install()