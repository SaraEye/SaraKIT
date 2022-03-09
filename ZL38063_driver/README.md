# **SaraKIT audio ZL38063 driver build **  
This is upgraded and modified driver for ZL38063 compatible with current kernel(5.10) releases 

# SaraKIT audio ZL38063 driver build instructions  
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

change /boot/config.txt as is in vproc_sdk/sample_config.txt most important
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

from vproc_sdk/libs install modules replace 5.10.63-v8+ by your kernel version
```
sudo mkdir /lib/modules/5.10.63-v8+/sarakit
sudo install -m 0755 ./*.ko   /lib/modules/5.10.63-v8+/sarakit/
sudo install -m 0755 ./lib/modules/5.10.63-v8+/extra/*.ko   /lib/modules/5.10.63-v8+/sarakit/

```
in /etc/rc.local add DSP and amplifier delayed startup script to eliminate POP effect
```
raspi-gpio set 4 op pn dh #disable class D amplifier
sleep 2 
raspi-gpio set 16 op pn dl #reset DSP processor
sleep 2
raspi-gpio set 16 op pn dh #enable DSP
sleep 2
raspi-gpio set 4 op pn dl #enable amplifier
```
copy asound.conf to /etc/
```
sudo cp asound.conf  /etc
```
after reboot aplay should show device 
```
$ aplay -l
```

for testing
```
aplay -f S16_LE -r 16000 -c2 -Dplug:dmixed song.wav
arecord -d5 -f S16_LE -r 16000 -Dplug:dsnooped -c2 recorded.wav
```

