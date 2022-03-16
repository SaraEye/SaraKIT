
#include "Gtracker.hpp"
#include "unistd.h"
#include <iostream>

int main(){

    tracker_init();
    
    while(1){
       for(uchar speed=0;speed<110;speed+=10){
                std::cout<<(int)speed<<std::endl;
                controlSpeed(1,50,speed);
                sleep(10);
        }
    }
    return 1;
}