# **SaraKIt audio ZL38063 driver build **  
This is upgraded and modified driver for ZL38063 compatible with current kernel(5.10) releases 

# SaraKIt audio ZL38063 driver build instructions  
Install rpi-soure https://github.com/RPi-Distro/rpi-source
```
cd ~/linux
make oldconfig && make prepare && make -j4

```

Makefile in root (ZL38063_driver) only for preview

go to vproc_sdk
```
$ cd vproc_sdk
```
build all neceseary things
```
$ make hbilnx
```
all modules and overlays will be in libs dir

change /boot/config as is in vproc_sdk/sample_config.txt most important
```
uncomment:
dtparam=i2c_arm=on
dtparam=i2s=on
dtparam=spi=on

comment:
#dtparam=audio=on

add:
dtoverlay=spi0-2cs
dtoverlay=microsemi-spi-overlay
dtoverlay=microsemi-spi-multi-tw-overlay
dtoverlay=microsemi-dac-overlay
```
from vproc_sdk/libs install overlays(dtbo) in /boot/overlays
```
sudo install -m 0755 ./*.dtbo   /boot/overlays
```

from vproc_sdk/libs install modules replace
```
sudo mkdir /lib/modules/5.10.63-v8+/sarakit
sudo install -m 0755 ./*.ko   /lib/modules/5.10.63-v8+/sarakit/
sudo install -m 0755 ./lib/modules/5.10.63-v8+/extra/*.ko   /lib/modules/5.10.63-v8+/sarakit/

```

after reboot aplay should show device 
```
$ aplay -l
```

for testing
```
aplay -f S16_LE -r 16000 -c2 -Dhw:0,0 song.wav
arecord -d5 -f S16_LE -r 16000 -Dhw:0,0 -c2 recorded.wav
```

