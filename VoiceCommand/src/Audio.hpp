#ifndef _AUDIO_HPP_
#define _AUDIO_HPP_


#include <pulse/simple.h>
#include <pulse/error.h>
#include <pulse/pulseaudio.h>
#include <grpcpp/grpcpp.h>
#include <thread>
#include <condition_variable>
#include <fstream>
#include "base64.hpp"



typedef struct WAV_HEADER
{
  /* RIFF Chunk Descriptor */
  uint8_t RIFF[4] = {'R', 'I', 'F', 'F'}; // RIFF Header Magic header
  uint32_t ChunkSize;                     // RIFF Chunk Size
  uint8_t WAVE[4] = {'W', 'A', 'V', 'E'}; // WAVE Header
  /* "fmt" sub-chunk */
  uint8_t fmt[4] = {'f', 'm', 't', ' '}; // FMT header
  uint32_t Subchunk1Size = 16;           // Size of the fmt chunk
  uint16_t AudioFormat = 1;              // Audio format 1=PCM,6=mulaw,7=alaw,     257=IBM
                                         // Mu-Law, 258=IBM A-Law, 259=ADPCM
  uint16_t NumOfChan = 1;                // Number of channels 1=Mono 2=Sterio
  uint32_t SamplesPerSec = 16000;        // Sampling Frequency in Hz
  uint32_t bytesPerSec = 16000 * 2;      // bytes per second
  uint16_t blockAlign = 2;               // 2=16-bit mono, 4=16-bit stereo
  uint16_t bitsPerSample = 16;           // Number of bits per sample
  /* "data" sub-chunk */
  uint8_t Subchunk2ID[4] = {'d', 'a', 't', 'a'}; // "data"  string
  uint32_t Subchunk2Size;                        // Sampled data length
} wav_hdr;


class PulseWrapper
{

public:
  ~PulseWrapper();
  static std::shared_ptr<PulseWrapper> getInstance();
  void runMic();
  std::vector<std::function<void(char*,int)>>::iterator AddListener(std::function<void(char*,int)> listener);
  void stopListen(std::vector<std::function<void(char*,int)>>::iterator it);
  //asyncPlay
  int playAudioStringAsync(std::string streamData, unsigned int sampleRate, float volumeFactor);
  //asyncPlay
  int playAudioAsync(std::shared_ptr<std::vector<unsigned char>> streamData, unsigned int sampleRate);

  void setVolume(int vol);


private:
  PulseWrapper();
  void enablePlayer();
  void disablePlayer();
  void enableMic();
  void disableMic();
  void player();
  static std::shared_ptr<PulseWrapper> pwInstance;
  static std::mutex pwMutex;
  std::vector<std::function<void(char*,int)>>  listeners;
  std::vector<std::function<void()>> stopListeners;
  bool endPlayer;
  bool endMic;
  bool muteMic;
  std::thread micTask;
  std::vector<std::shared_ptr<std::vector<unsigned char>>> audioData;
  std::condition_variable audioDataCv;
  std::mutex audioDataMutex;
  std::mutex listenerMutex;
  std::thread playerTask;



//   struct pa_cvolume v;
//   pa_threaded_mainloop *pa_ml;
//   pa_mainloop_api *pa_mlapi;
//   char *device = "spkr";
//   pa_context *context;

//   std::string beep = base64_decode("UklGRsYRAABXQVZFZm10IBAAAAABAAEAgD4AAAB9AAACABAATElTVBoAAABJTkZPSVNGVA4AAABMYXZmNTguNzYuMTAwAGRhdGGAEQAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAP//AAAAAAAAAAAAAAAAAAAAAAAAAAD///////8AAAAAAAAAAAAAAAAAAAAAAAD//////////wAAAAAAAAAAAAAAAAAAAAAAAAAA////////AAAAAAAAAQABAAEAAQABAAEAAQABAAAA///+//7//v//////AAABAAIAAQABAAAAAAAAAP//AAAAAAAAAAAAAP////8AAAAAAQABAAEAAAAAAAAAAAAAAAAA////////////////AAAAAAAAAAABAAEAAQAAAAAA/////////v/+//7//v///wAAAgADAAMAAwACAAEAAAD/////AAAAAAAA/////////v/+//7///8AAAEAAQAAAAEAAAD///7///8AAAIAAAAFAP3/CAAAACoCGwjVD88WOxr+FxIPAADf7AfZcMj/vpe/fsvt4QQAOiESQP9Wg2H5XDFJoCgCAKjVbrCLloeMU5QNrd7SAgCqKylNKmDvYoFWNT7xHkL+XeFZzKHBssFFy7Xbke9LA8gT4R6TIwUiYBtrETAGo/tD8wPuP+y17czxlvc//sMEjguFEwsb9h9DIK4a9g4u/qHqgddUyGDA98HmzTPjIP+RHaM5fk40WIJUR0OjJrwCEt2lu/OjBpq3n3K0CtWL/OwjaENYVrta8VCPO88euf9M48PN3MGewEXJktlP7tADrxY1JM0qFirhIuEWXAjA+Uftn+TE4O3hnOe18Mz7MwfsEdobnCNGJ2IlQx1UDxH9/Ogz1vnHKcGcw7zPX+TZ/kobPDVgSDxR401JPmUk9gPj4YjDzK1QpM6o0rql1+n6uB5NPN9ONVRCTBA5Rx6QALXk8c5FwgvA6Mf51ynt2gNpGMkn8S8YMLgobhuiChX5eOkR3mLY/tiK39vqIvkzCCEW5iEhKhAtpCmkH/IPbvzE5xnVhceQwbvEJNFz5ff+/BlWMg9EGEzFSCk6KiI6BN3k8sjntAus7q8kwE3abfpfGzc3OkkQT2BIyzaRHQUBwOXzz8HCxr/7xrjWIeyYA18ZJSqRM4M0OC0uH9QMJ/kx56DZ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FQAMAAUACQATAB8ALwA6ADoAMAAaAPn/1f+x/5f/jf+S/6z/0//+/ygASABaAF4AVAA9ACEABwDw/+T/4P/k/+z/9P/7//n/8f/l/9j/zv/M/9b/6P///yEAQQBYAGMAXQBMACwABgDh/8X/s/+u/7f/yP/f//f/CwAWABsAGAARAAoABgAFAAwAFwAhACoALAAoABgAAQDm/8n/t/+o/6z/vP/V//b/FQAxAEMARwBBADMAHQALAPv/7f/o/+r/7//3//v/+v/2/+3/5P/d/9v/3f/r//z/EwArAD8ASABJAD8AKAALAPD/2P/I/8L/yP/R/+T/9v8FAA8AFQAVAA8ACAAFAAUACAAOABYAHgAfAB8AFQAFAPP/3f/M/8H/wP/I/9v/8v8MAB8ALwA1ADMAKgAaAAoA/P/0//D/8P/y//j/+//7//n/9P/s/+f/4v/k/+3/+/8KABwALAA2ADgAMAAjAA0A+f/l/9j/0f/T/9v/5v/1/wAACQAPABAADQAGAAUABQAFAAoADwAVABoAGAASAAcA+//r/9z/0v/R/9X/4P/x/wUAFQAgACgAJwAgABcACwAAAPj/8//y//b/+f/7//r/+//3//L/7f/r/+v/7//5/wUAEwAfACgAKgAmABwAEAAAAPD/5f/f/93/4//r//b//v8HAAsACwAKAAYABQABAAQABwALAA8AFAATAA8ABwD9//H/5//g/9v/3f/m//H/AAANABYAHgAfABoAFAALAAEA+//4//X/9v/6//v/AAD9//r/+P/z//H/8P/y//n/AgALABUAHAAgAB4AGAAOAAIA9v/t/+j/5v/p/+//9//+/wMABwALAAgABQAFAAAAAgAFAAcACwANABEADAAHAAAA9//v/+j/5v/n/+v/9P/+/wcAEAAUABUAFAAQAAkAAwD+//v/+//7//v//f8BAAAA/P/6//b/9f/2//X/+f///wYADwAUABgAFwATAAwAAwD5//T/7//r/+//8v/4//3/AgAFAAUABQAFAAMAAAD//wMABQAHAAsACgALAAcAAQD7//X/7//r/+v/7//1//z/BAALAA8ADwAQAAwACQAEAP///P/6//v/+v/9/wAAAQD///v/+//3//X/9v/6//7/AwAIAA4AEAAPAA8ACgAEAPz/+P/0//D/8f/1//n//f8AAAMABgAFAAYAAgAAAAAAAAAFAAUABQAJAAcABQACAP7/+v/z//H/8P/y//b//P8CAAcACwAKAAsACgAIAAMAAAD+/w==");

};

#endif