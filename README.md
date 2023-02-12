# x-marks-the-spot
#1 rated Watchy watch face in North America  
2x award winning

## Source modified from skully
https://github.com/charlesrocket/skully

## Face for Watchy watch  
https://watchy.sqfmi.com

## Latest verified Watchy firmware
1.4.0

## Notes
Until the Arduino board library >2.0.2 gets a fix for the Watchy boot loop, you have to use version 2.0.2 and set your board version in the ***config.h*** file of the Watchy library.

### Options are
ARDUINO_WATCHY_V10 //version 1.0  
ARDUINO_WATCHY_V15 //version 1.5  
ARDUIONO_WATCHY_V20 //version 2.0  

## Features
### Choose temperature in Fh or C
Update ```TEMP_UNIT``` in ***settings.h***

### Choose time offset for NTP
Update ```GMT_OFFSET_SEC``` in ***settings.h***

## Preview
![](https://github.com/cbrookins/x-marks-the-spot/raw/main/x.gif "X marks the spot")