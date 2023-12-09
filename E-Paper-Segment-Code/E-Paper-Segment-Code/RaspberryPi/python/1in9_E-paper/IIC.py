import time
import smbus
import RPi.GPIO as GPIO
import os


# Pin definition
RST_PIN         = 4
BUSY_PIN        = 17

# address
adds_com        = 0x3C
adds_data       = 0x3D

# adds_com        = 0x3E
# adds_data       = 0x3F

iic = smbus.SMBus(1)

def digital_write(pin, value):
    GPIO.output(pin, value)

def digital_read(pin):
    return GPIO.input(pin)

def delay_ms(delaytime):
    time.sleep(delaytime / 1000.0)

def IIC_writebyte_com(value):
    iic.write_byte(adds_com, value)

def IIC_writeblock_com(register, values):
    iic.write_block_data(adds_com, register, values)

def IIC_writebyte_data(value):
    iic.write_byte(adds_data, value)

def IIC_writeblock_data(register, values):
    iic.write_block_data(adds_data, register, values)
    
def IIC_Readbyte_com(register):
    while(1):
        try:
            iic.write_byte(adds_com, register)
            x = iic.read_byte(adds_com)
            if(x != None):
                return x
        except :
            pass
    
def IIC_Readbyte_data(register):
    while(1):
        try:
            iic.write_byte(adds_data, register)
            x = iic.read_byte(adds_data)
            if(x != None):
                return x
        except :
            pass

def module_Init():
    GPIO.setmode(GPIO.BCM)
    GPIO.setwarnings(False)
    GPIO.setup(RST_PIN, GPIO.OUT)
    GPIO.setup(BUSY_PIN, GPIO.IN) 
    GPIO.output(RST_PIN, 0)
    return 0
    
def module_exit():
    iic.close()
    GPIO.output(RST_PIN, 0)




