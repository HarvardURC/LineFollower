Line Follow Build Directions!
============================

> **Parts List:**
> - Dual Gearmotor (3-6V power)
> - Motor Driver https://www.pololu.com/product/2130
> - 40mm Wheel Pair
> - .5" Ball Caster (size may change)
> - Teensy LC (3.3V) https://www.pjrc.com/teensy/teensyLC.html
> - 4 AA holder (6V output max -> 4V) w/ switch
> - 4 AA batteries
> - Breadboard 
> - Micro USB Cable
> - IR Sensor https://www.pololu.com/product/2456

Steps
------

We encourage you to read through all the steps before you start. It's a good idea to test the sensors and motors separately before putting them together!You can find datasheets for all the parts by clicking on the links above. 
- Construct gearbox (instructions on box)
- Attach wheels and battery holder to gearbox (the battery holder will double as a chassis - you can use the hot glue gun to attach the attach it. We have an example video of the robot, ask to see it if you are unsure!) 
- Solder the headers onto the teensys/motodriver if necessary. (Ask one of our current members to set you up with a soldering iron)
- You can program in the teensy using the Arduino IDE. (Install here: https://www.arduino.cc/en/Main/Software)
- You will also need to download software to interface arduino and teensy. (Download here: https://www.pjrc.com/teensy/td_download.html)
- Electrical components (should test separately on breadboard before attaching to robot):
    - Sensors to teensy (sensors run on 5V so will need to add voltage divider to signal lines since teensy inputs are 3.3V)
        - Vout = (R1/[R1 + R2]) * Vin.  R1 = 3.3KOhm, R2 = 1.7KOhm should work. 
    - Motor driver to teensy and motor
    - Battery power supply to rails 
    - Sensor has 5v output - use voltage divider (resistors) to drop this to 3.3v for the teensy. 
    - Circuit schematic below
- Mount sensors
- Solder connections from motor driver to motor (there are two small metal contacts on each motor - see schematic.) Let one of our members know when you are ready to move onto this step and they will set you up with the soldering iron
- Upload code onto teensy (there is code in the github repo but we used different sensors! use this code as a reference only- it will not work with your bot)
- Ask our members if you have any questions!
- Have fun!


![circuit schematic]
(https://github.com/HarvardURC/LineFollower/blob/master/IMG_2298.JPG)

MAY THE BEST ROBOT WIN! (there is no prize - only glory)
