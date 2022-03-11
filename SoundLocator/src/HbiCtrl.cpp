#include "HbiCtrl.hpp"
HbiCtrl::HbiCtrl(){
    deviceId=0;
    hbi_status_t status;
    hbi_dev_cfg_t cfg;
    cfg.pDevName=NULL;
    cfg.deviceId = deviceId;

    status=HBI_open(&handle,&cfg);
    if(status != HBI_STATUS_SUCCESS)
    {
        std::cout<<"Error in HBI_open()"<<std::endl;
    }else
        std::cout<<" HBI_open() success!"<<std::endl;
}
HbiCtrl::~HbiCtrl(){
    hbi_status_t status;
    
    status=HBI_close(handle);
    status=HBI_term();
}
int HbiCtrl::read(int reg, unsigned char* buf){
    hbi_status_t status=HBI_read(handle, reg, buf,2);
    unsigned char tmp=buf[0];
    buf[0]=buf[1];
    buf[1]=tmp;
    return status;
}
int HbiCtrl::write(int reg, unsigned char* buf){

    // unsigned char tmp=buf[0];
    // buf[0]=buf[1];
    // buf[1]=tmp;
    return HBI_write(handle, reg,buf,2);
}

int HbiCtrl::disableAEC(){
    uint8_t wBuf[2] = { 0x38, 0x98 };
    return write(0x300,wBuf);

}
int HbiCtrl::enableAEC(){
    uint8_t wBuf[2] = { 0x38, 0x88 };
    return write(0x300,wBuf);
}