from guizero import App, Slider, TextBox
from time import sleep
import RPi.GPIO as GPIO
from gpiozero import AngularServo
import time

correct1=0.4
correct2=0.4
maxPW=((2.0+correct1)/1000)
minPW=((1.0+correct2)/1000)

def slidervalchange1(slider_val):
    textbox.value = slider_val
    print(slider_val)
    servo1=AngularServo(17, min_pulse_width = minPW, max_pulse_width = maxPW, initial_angle=0, min_angle=-90, max_angle=90 )
    servo1.angle=int(slider_val)
    time.sleep(0.4)

def slidervalchange2(slider_val):
    textbox.value = slider_val
    print(slider_val)
    servo2=AngularServo(20, min_pulse_width = minPW, max_pulse_width = maxPW, initial_angle=0, min_angle=-90, max_angle=90 )
    servo2.angle=int(slider_val)
    time.sleep(0.4)

app=App()
slider=Slider(app,start=-90,end=90,width=400,command=slidervalchange1)
slider2=Slider(app,start=-90,end=90,width=400,command=slidervalchange2)
textbox=TextBox(app)

app.display()




