# Player Tracking & Goal Alignment
This program keeps track of player location on the court and points the basketball returner towards the shooter, allowing them to retrieve it after shooting

#To-do
- Develop code for playertracking slave arduinos as well as modify existing code on the master to support receiving grid coordinates

- Modify and fully test code for the motor (adjusting the encoder readout for the gear ratio between the motor and lazy susan)

# Development tools used
-DigitalWriteFast library used to allow for accurate encoder readings

-Breakout radio sensor library for arduino: https://github.com/sparkfun/RFM69HCW_Breakout/archive/master.zip

-UnoArduSim V1.6.3: Used and allowed me to see exactly where my code decided to run awry. Would highly reccommend. Its fairly intuitive as well.

-ArduinoIDE: Pretty self explanatory. Just the official Arduino environment

-Github: Used to manage this repository

# BackboardTracking
Allows the finding of generalized location of where a basketball hit on the backboard of a basketball goal.
This code is being developed to allow blind people to play basketball. You can learn more about the rest of the project here: https://prodigiousmelon.github.io/index.html

# Legacy
Legacy ir tracking methods can be found in the 'legacy' branch now

# VoltageMeasuring
Tool provided in folder to measure voltages from the analog pin a sensor is connected to. Tracking code is independant of this file. In other words, this isn't needed to run the main code.

# Debugging
To enable debugging (only on median code for now) hit control+F, find "//deb:", leave the replace field blank, and click replace all. Check serial monitor for debugging info
