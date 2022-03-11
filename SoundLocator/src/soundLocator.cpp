#include "HbiCtrl.hpp"
#include <unistd.h>


int main(){
HbiCtrl hbic;
    uint8_t rBuf[2] = { 0 };
    int reg=0x0A0;//Sound locator register
    while(1){
        hbic.read(reg,rBuf);
        uint16_t angle=rBuf[1]<<8|rBuf[0];
        printf("Sound location is %u\n",, angle);
        sleep(1);
    }
}
