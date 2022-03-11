### Saound Locator example
This sample shows how to get sound location info from audio.

### Build and run
in repository we prepared prebuild audio interface library. At first you need install it
```
./install.sh
```
next go to src and build project
```
make
```
for now you can run sample which print information of currend loudest sound direction from 0-360°
```
sudo ./soundLocator 
```