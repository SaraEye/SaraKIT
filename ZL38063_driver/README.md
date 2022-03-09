# **SaraEyebuild**  
clone and run rpi-soure https://github.com/notro/rpi-source
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
#dtoverlay=ZL38063

change from #dtoverlay=spi0-1cs,cs0_pin=7 to: 
dtoverlay=spi0-2cs

//motor spi will be changed to spi0.1 need to fix in wiringpi


add:
dtoverlay=microsemi-spi-overlay
dtoverlay=microsemi-spi-multi-tw-overlay
dtoverlay=microsemi-dac-overlay
```
install overlays(dtbo) in /boot/overlays

go to vproc_sdk/libs and install modules 
```
sudo mkdir /lib/modules/5.10.63-v8+/microsemi
sudo install -m 0755 ./*.ko   /lib/modules/5.10.63-v8+/microsemi/
sudo install -m 0755 ./lib/modules/5.10.63-v8+/extra/*.ko   /lib/modules/5.10.63-v8+/microsemi/

```
in /etc/modules add lines:
```
hbi
snd-soc-zl380xx
snd-soc-microsemi-dac
```

or manually insmod modules:
```
sudo insmod hbi.ko
sudo insmod snd-soc-zl380xx.ko
sudo insmod snd-soc-microsemi-dac.ko
```

aplay should show device 
```
$ aplay -l
```

for testing
```
aplay -f S16_LE -r 16000 -c2 -Dhw:0,0 song.wav
arecord -d5 -f S16_LE -r 16000 -Dhw:0,0 -c2 recorded.wav
```

