# Player Tracking & Goal Alignment
This program keeps track of player location on the court and points the basketball returner towards the player, allowing them to retrieve it after shooting

#To-do
-Create dummy programs that will just transmit values so the mastertracking code can be tested fully



# Development tools used
-DigitalWriteFast library used to allow for accurate encoder readings https://github.com/NicksonYap/digitalWriteFast

-Breakout radio sensor library for arduino: https://github.com/sparkfun/RFM69HCW_Breakout/archive/master.zip

-ArduinoIDE: The official Arduino environment

-Git Bash: Used to manage this repository

# BackboardTracking
Allows the finding of generalized location of where a basketball hit on the backboard of a basketball goal.
This code is being developed to allow blind people to play basketball.

# Legacy
Legacy IR tracking methods can be found in the 'legacy' branch now

# VoltageMeasuring
Tool provided in folder to measure voltages from the analog pin a sensor is connected to. Tracking code is independant of this file. In other words, this isn't needed to run the main code.

# Debugging
To enable debugging (only on median code for now) hit control+F, find "//deb:", leave the replace field blank, and click replace all. Check serial monitor for debugging info
