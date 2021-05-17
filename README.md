# mltrennung

## Discription 

MLtrennung is a machine learning prototype to classify litter and determine in wich bin it has to go. 


## Status

This is a work in progress.
Currently attemting to prove concept.

## Installation 

### Tested environment of the prototype 

We did only use the code on a M1 Macbook with high sierra, but it should work fine with older MacOS and Windos aswell 

### Used software 

You need to install:
- Wekinator
- Processing 
    - oscP5. library 
- Arduino IDE
    - Node MCU 1.0 software
    - OSC library by CNMAT

### Provided Code

- Trained model for wekinator 
- Videosketch to get USC packages into wekinator for processing 
- Arduino code to controll the LED

## How to use? 

### Processing videotool 

- select your camera 
```
insert number (0,1,2,3,...) to select camera, in case you have mulriple
default is 0 
line 40: > video = new Capture(this, width, height, cameras[x]); <
```

### Setting up wekinator

- apple controll bar 
    - File -> open -> select the contained model
- train 
- run 

### Setting up arduino 

- compile and upload 

## Diagrams

### Node MCU wiring

## Theoretical extentions

### Architecture 

For a commercial use we would use a Raspberrypie and Node MCU for the button, LEDs and preparing the data to be sent with TCP.
On the recieving end, in the cloud, it would be converted to UDP for compatibility reasons and the results would be interpreted by a database to determine in wich region the litter would go in wich bin. The information is sent back to the Rasp wich then sets of the right LED relative to its local trash management. 

### Image 1 

