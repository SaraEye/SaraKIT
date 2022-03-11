### Alexa in SaraKIT
this is modified repo of avs-device-sdk with embedded Porcupine keyword detector and prebuilt portaudio.

### Register an AVS device:
Before you can use the SDK, you must register an AVS device on the Amazon developer portal by following the instructions on [Register an AVS Product and Create a Security Profile](https://developer.amazon.com/en-US/docs/alexa/alexa-voice-service/register-a-product-with-avs.html).
After registering your device, you download a config.json file. This file contains your client ID and client secret. The client ID and client secret authorize your device to retrieve access tokens from AVS. Your config.json file facilitates the authorization calls between AVS and your device.
Save your config.json file somewhere accessible. You need to use it later in this tutorial to build and authorize your instance of the SDK.

### SaraKIT build Amazon Alexa sample:
Clone repository to /home/pi/

```
mkdir install build && cd build
```
```
 cmake ../AVS \
 -DGSTREAMER_MEDIA_PLAYER=ON \
 -DPORTAUDIO=ON \
 -DPORTAUDIO_LIB_PATH=/home/pi/saraKIT/third-party/portaudio/lib/libportaudio.so \
 -DPORTAUDIO_INCLUDE_DIR=/home/pi/saraKIT/third-party/portaudio/include \
 -DPORCUPINE_KEY_WORD_DETECTOR=ON \
 -DPORCUPINE_KEY_WORD_DETECTOR_LIB_PATH=/home/pi/saraKIT/third-party/porcupine/libpv_porcupine.so \
 -DPORCUPINE_KEY_WORD_DETECTOR_INCLUDE_DIR=/home/pi/saraKIT/third-party/porcupine/include \
 -DCMAKE_INSTALL_PREFIX=../install \
 -DBUILD_TESTING=OFF 
 ```
 ```
 make -j4 &&make install
 ```
 ### Set up your SDK configuration file:
 go to AVS\tools\Install and run
```
  ./genConfig.sh config.json 12345 \
 /home/pi/saraKIT/Alexa/db \
 /home/pi/saraKIT/Alexa/AVS \
 /home/pi/saraKIT/Alexa/build/Integration/AlexaClientSDKConfig.json \
 -DSDK_CONFIG_MANUFACTURER_NAME="saraKIT" \
 -DSDK_CONFIG_DEVICE_DESCRIPTION="saraKIT"
```
 
 ### run sample:
 ```
  PA_ALSA_PLUGHW=1 ./SampleApp ./AlexaClientSDKConfig.json /home/pi/saraKIT/third-party/porcupine DEBUG9
 ```
