from bottle import route, run, template
import spidev

bus=0
device=1
spi = spidev.SpiDev()
spi.open(bus, device)
spi.mode = 0b01
spi.max_speed_hz = 1000000


def setSpeed(speed):    
    direction=0
    spd=speed
    motorId=1
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
@route('/speed/<speed:int>')
def index(speed):
        setSpeed( speed=speed)
        return template('<b>speed {{speed}}</b>', speed=speed)
@route('/')
def index():
	return template('index')

run(host='<ip>', port=8080)