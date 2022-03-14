#ifndef _GOOGLESPEECH_HPP_
#define _GOOGLESPEECH_HPP_
#include <google/cloud/speech/v1/cloud_speech.grpc.pb.h>
#include <grpcpp/grpcpp.h>
#include <chrono>
#include <fstream>
#include <iostream>
#include <string>
#include <thread>
#include "Audio.hpp"
#include "CJSONPost.hpp"
#include <iostream>
#include "base64.hpp"
#include "json.hpp"
#include "KeywordActionManager.hpp"


void AskSaraAI(std::string text);

using json = nlohmann::json;

using google::cloud::speech::v1::Speech;
using google::cloud::speech::v1::StreamingRecognizeRequest;
using google::cloud::speech::v1::StreamingRecognizeResponse;

class GoogleTextToSpeech
{
public:
  GoogleTextToSpeech(std::string key);
  ~GoogleTextToSpeech();
  void transcribe(std::string text);
private:
  void jsonTranscriptonParseAndPlay(std::string text);
  int playAudioPulse(std::string streamData, unsigned int sampleRate, float volumeFactor);
  CJSONPost jsonPost;
};

class GoogleSpeechToText
{
public:
  GoogleSpeechToText(std::string key);
  ~GoogleSpeechToText();
  void startSTT();
  void stopSTT();
  void addPulswStopStream(std::function<void()> stopPulswStream);
  std::vector<std::string> getTranscriptions();

  
private:
  void recognize();
  std::thread speechTask;
  bool endProcessing;
  std::function<void()> stopPulswStreamFunc;
  std::vector<std::string> sttTexts;
  KeywordActionManager kam;
  std::string apiKey;
};



#endif
