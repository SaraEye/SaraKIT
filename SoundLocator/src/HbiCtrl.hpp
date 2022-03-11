#ifndef _HBICTRL_HPP_
#define _HBICTRL_HPP_

#include <iostream>

extern "C" {
    #include "hbi/typedefs.h"
    #include "hbi/zl380xx_tw.h"
    #include "hbi/hbi.h"
}

class HbiCtrl{
public:
    HbiCtrl();
    ~HbiCtrl();
    int enableAEC();
    int disableAEC();
    int read(int reg, unsigned char* buf);
    int write(int reg, unsigned char* buf);
private:
    hbi_device_id_t deviceId;
    hbi_handle_t handle;
};
#endif  