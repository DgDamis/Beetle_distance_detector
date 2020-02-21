# Beetle_distance_detector
 Distance measuring with analogue sensors and Beetle, built in PlatformIO.

 This code reads the measurements from Sharp analogue sensors and sends them through serial line

This code has been built for a usage with microchip Beetle based on Arduino Leonardo platform.
<b> In theory it should work on any board </b> as long as you change the board settings in platformio.ini and it successfuly compiles.

<h3>Supported sensors:</h3> 
    - Sharp GP2Y0A21YK0F
    - Sharp GP2Y0A710K0F
<h4>Supported configuration (you need to specify in config.cpp file):</h4>
    - One sensor at the time
    - or both sensors simultaneously

