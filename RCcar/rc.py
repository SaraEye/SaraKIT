from bottle import route, run, template
import spidev

bus=0
device=1
spi = spidev.SpiDev()
spi.open(bus, device)
spi.mode = 0b01
spi.max_speed_hz = 1000000


def setSpeed(speed):

    isRelative = 0b00100000
    direction=0
    steps=speed
    torque=50
    if steps<0:
        direction=0b00001000
        steps = steps * -1
	
    motor=0
    s=(steps>>8)&0x07
    header=isRelative|motor|direction|s
    buf1=steps&0xFF
    cmd=[header, buf1, torque, 100]

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