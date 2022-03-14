### Face Detectiin example
This sample shows how to detect faces on images from cam0. Detector is based on MNN

### Build and run
in repository we prepared prebuild MNN library. At first you need install it
```
cd libs 
sudo dpkg -i mnn_20211215-1_arm64.deb
```
next go to src and build project
```
make
```
for now you can run sample which display farame with face in rect.
```
sudo ./facedetector 
```