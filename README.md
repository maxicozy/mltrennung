# mltrennung

## Description 

MLtrennung is a machine learning prototype to classify litter and determine in wich bin it has to go. 


## Status

This is a work in progress protoype.

## Installation 

### Tested environment of the prototype 

We did only use the code on a M1 Macbook with high sierra, but it should work fine with older MacOS and Windows aswell 

### Used hardware

- Node MCU 
- 5 jumpers 
- 4 220 Ω resistors 
- 4 leds
- breadboard
- webcam

### Used software 

You need to install:
- Wekinator
- Processing 
    - oscP5. library 
- Arduino IDE
    - Node MCU 1.0 software
    - OSC library by CNMAT

### Provided Code

- Videosketch to get OSC packages into wekinator (adjusted example code)
- Arduino code to control the LED (adjusted code from OSC library by CNMAT)

## How to use? 

### Processing videotool 

- select your camera 
```
insert number (0,1,2,3,...) to select camera, in case you have multiple
default is 0 
line 40: > video = new Capture(this, width, height, cameras[x]); <
```
- run sketch

### Setting up Node MCU 

- enter ssid and pw for WiFi 
- compile and upload 
- open serial monitor for ip address

### Setting up wekinator

- Setup:
    - port to listen: 6448
    - input message: /wek/inputs
    - inputs: 12720
    - output message: /led
    - outputs: 1 
    - Host: enter ip address from serial monitor of Node MCU 
    - Port: 8888
    - Type: all Classifiers (5 Classes)
- Training:
    - select class
    - start recording desired object
    - repeat for all classes
    - train 
    - run

## Wiring Diagram

### Node MCU wiring

<img src="./Aufbau LEDs.png" width="500">

## Theoretical extentions

### Architecture 

For a commercial use we would use a Raspberry Pi and Node MCU for the button, LEDs and preparing the data to be sent with TCP.
On the recieving end, in the cloud, it would be converted to UDP for compatibility reasons and the results would be interpreted by a database to determine in which region the litter would go in which bin. The information is sent back to the Rasp which then sets of the right LED relative to its local trash management. 
