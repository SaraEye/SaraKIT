import numpy as np
import cv2
import spidev

bus=0
device=1
spi = spidev.SpiDev()
spi.open(bus, device)
spi.mode = 0b01
spi.max_speed_hz = 1000000


def setSpeed(speed,motor):    
    direction=0
    spd=speed
    motorId=motor
    torque=50
    if speed<0:
        direction=0b10
        spd = speed * -1
	
    header=0b01110000
    cfg=motorId|direction
    cmd = [header, cfg, torque, spd]
    to_send=[]
    to_send.extend(cmd)
    for i in range(0,len(to_send),4):
        ts=[to_send[i],to_send[i+1],to_send[i+2],to_send[i+3]]
        spi.xfer(ts)


video_capture = cv2.VideoCapture(0)
video_capture.set(3, 160)
video_capture.set(4, 120)

while(True):
    ret, frame = video_capture.read()
    crop_img = frame[60:120, 0:160]
    gray = cv2.cvtColor(crop_img, cv2.COLOR_BGR2GRAY)
    blur = cv2.GaussianBlur(gray,(5,5),0)
    ret,thresh1 = cv2.threshold(blur,60,255,cv2.THRESH_BINARY_INV)
    mask = cv2.erode(thresh1, None, iterations=2)
    mask = cv2.dilate(mask, None, iterations=2)
    contours,hierarchy = cv2.findContours(mask.copy(), 1, cv2.CHAIN_APPROX_NONE)
    if len(contours) > 0:
        c = max(contours, key=cv2.contourArea)
        M = cv2.moments(c)
        cx = int(M['m10']/M['m00'])
        cy = int(M['m01']/M['m00'])
        cv2.line(crop_img,(cx,0),(cx,720),(255,0,0),1)
        cv2.line(crop_img,(0,cy),(1280,cy),(255,0,0),1)
        cv2.drawContours(crop_img, contours, -1, (0,255,0), 1)
        print cx
        print cy

 

        if cx >= 120:
            setSpeed(100,0)
            setSpeed(25,1)
        if cx < 120 and cx > 50:
            setSpeed(100,0)
            setSpeed(100,1)
        if cx <= 50:
            setSpeed(25,0)
            setSpeed(100,1)

    else:
            setSpeed(0,0)
            setSpeed(0,1)

   if cv2.waitKey(1) & 0xFF == ord('q'):
        break