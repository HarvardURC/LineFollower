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
> - L78 voltage regulator

Logistics
------
Try and finish your bot over the coming week. We will have a competition for all the robots on Sunday, (9/23). If you don't finish your bot, it's ok. You are only required to put in effort.

Steps
------

We encourage you to read through all the steps before you start. It's a good idea to test the sensors and motors separately before putting them together!You can find datasheets for all the parts by clicking on the links above. 
- Construct gearbox (instructions on box)
- Attach wheels, battery holder, and breadboard to the gearbox - you can use the parts you designed in the Solidworks workshop, or come up with your own design!
- Solder the headers onto the teensys/motor driver if necessary. (Ask one of our current members to set you up with a soldering iron)
- You can program in the teensy using the Arduino IDE. ([Install here](https://www.arduino.cc/en/Main/Software))
- You will also need to download software to interface arduino and teensy. ([Download here](https://www.pjrc.com/teensy/td_download.html))
- Electrical components (should test separately on breadboard before attaching to robot):
    - Sensors to teensy 
    - Motor driver to teensy and motor
    - Battery power supply to 5V regulator, and regulator to rails 
    - See the circuit schematic below for more specific wiring
- Mount sensors
- Solder connections from motor driver to motor (there are two small metal contacts on each motor - see schematic.) Let one of our members know when you are ready to move onto this step and they will set you up with the soldering iron. Be careful not to break off the small metal tabs on the motors, they can be fragile.
- Upload code onto teensy (there is code in the github repo for you to use as a stepping-off point)!
- Ask our members if you have any questions!
- Have fun!

MAY THE BEST ROBOT WIN! (there is no prize - only glory)

[circuit schematic]
(https://github.com/HarvardURC/LineFollower/blob/master/linefollower_schematic.jpg)

Code Setup
-----------
To use the GitHub code as a starting point you'll need to install a library so your Teensy can interface with the reflectance sensor. Information on the library can be found [here](https://www.pololu.com/docs/0J19/2)

- We recommend running a sensor test to see that you are getting correct readings from your reflectance sensor. You can find a sample sensor reading sketch (QTRARawValuesExample) in the Arduino IDE under File > Examples > QTRSensors after you've installed your library (and restarted Arduino!).
- Once you're getting reasonable values from your sensors, you should be ready to start improving the provided handout code!
