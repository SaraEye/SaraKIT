
#include "Gtracker.hpp"
#include "unistd.h"
#include <iostream>

int main(){

    tracker_init();
    while(1){
        for(uchar speed=10;speed<100;speed+=10){
            std::cout<<(int)speed<<std::endl;
            for(int steps=0;steps<100;speed+=1){
                controlMotor(1000,0,50,speed,0,1);
                usleep(100);
            }

        }
    }
    return 1;
}