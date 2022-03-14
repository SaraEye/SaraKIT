#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include "MNN_UltraFace.hpp"
#include <iostream>
#include <stdio.h>
using namespace cv;
using namespace std;
int main(int, char**)
{
    Mat frame;
    VideoCapture cap;
    UltraFace ultraface("MNN_models/slim-320-quant-ADMM-50.mnn", 320, 240, 4, 0.65); // config model input
    // open selected camera using selected API
    cap.open(0);
    // check if we succeeded
    if (!cap.isOpened()) {
        cerr << "ERROR! Unable to open camera\n";
        return -1;
    }
    //--- GRAB AND WRITE LOOP
    cout << "Start grabbing" << endl
        << "Press any key to terminate" << endl;
    for (;;)
    {
        // wait for a new frame from camera and store it into 'frame'
        cap.read(frame);
        // check if we succeeded
        if (frame.empty()) {
            cerr << "ERROR! blank frame grabbed\n";
            break;
        }
        vector<FaceInfo> face_info;
        ultraface.detect(frame, face_info);
        for(auto face : face_info)
            rectangle(frame,Rect(face.x1,face.y1, face.x2 - face.x1,face.y2 - face.y1),Scalar(0,255,0));
        // show live and wait for a key with timeout long enough to show images
        imshow("FaceDetection", frame);
        if (waitKey(5) >= 0)
            break;
    }
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}