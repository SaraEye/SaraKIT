#ifndef _GOOGLEASSISTANT_HPP_
#define _GOOGLEASSISTANT_HPP_

#include <grpc++/grpc++.h>

#include <getopt.h>

#include <chrono>  // NOLINT
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <thread>  // NOLINT
#include "Audio.hpp"

#include "google/assistant/embedded/v1alpha2/embedded_assistant.grpc.pb.h"
#include "google/assistant/embedded/v1alpha2/embedded_assistant.pb.h"

#include "base64.hpp"

namespace assistant = google::assistant::embedded::v1alpha2;

using assistant::AssistRequest;
using assistant::AssistResponse;
using assistant::AssistResponse_EventType_END_OF_UTTERANCE;
using assistant::AudioInConfig;
using assistant::AudioOutConfig;
using assistant::EmbeddedAssistant;
using assistant::ScreenOutConfig;

using grpc::CallCredentials;
using grpc::Channel;
using grpc::ClientReaderWriter;


class GoogleAssistant
{
public:
  GoogleAssistant();
  ~GoogleAssistant();
  void startAssistant();
  void stopAssistant();

private:
  void assist();
  std::thread assistTask;
  // PulseWrapper pulsw;
  bool endProcessing;
  // char kCredentialsTypeUserAccount[] = "USER_ACCOUNT";
  std::string kLanguageCode = "en-US";
  std::string kDeviceModelId = "saraKIT";
  std::string kDeviceInstanceId = "saraKIT";
  std::string conversation_state="";
  bool verbose = true;
};

#endif