#include "GoogleSpeech.hpp"


int main(int argc, char *argv[]){
if(argc<2){
    std::cout<<"Key missing"<<std::endl;
    std::cout<<"You must run app with google api key:"<<std::endl;
    std::cout<<"./voiceCommand <your api key>"<<std::endl;
    return -1;
}

GoogleSpeechToText gstt(argv[1]);
gstt.startSTT();
while(1){sleep(1);};

return 1;
}