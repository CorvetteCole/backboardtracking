# IrSensorTracking
Allows the finding of generalized location of where a basketball hit on the backboard of a basketball goal.

# LegacyIrSensorTracking
Legacy tracking methods can be found in the 'legacy' branch now

# VoltageMeasuring
Tool provided in folder to measure voltages from the analog pin a sensor is connected to. Tracking code is independant of this file. In other words, this isn't needed to run the main code.

# To-do
-Fully scale code to support as many sensors as we need (4 at the moment?)

-Change variables to arrays so that we don't need to declare 8 different variables

-Update legacy sensor tracking code to support the 'only run when in range' method. This way is now working on the median code and only runs the main bulk of the code when something falls within the sensor range. On the median code this also allows for a 2 step failsafe to eliminate false positives. The main median code only runs when something is within sensor range. From there, it takes two more readings and if those are outside of sensor range it will disregard it as an anomaly and just continue. Really quite simple. 


# Development tools used
UnoArduSim V1.6.3: Used and allowed me to see exactly where my code was decided to run awry. Would highly reccommend. Its fairly intuitive as well.
ArduinoIDE: Pretty self explanatory. Just the official Arduino environment
Github: Used to manage this repository

# Debugging
To enable debugging (only on median code for now) hit control+F, find "//deb:", leave the replace field blank, and click replace all. Check serial monitor for debugging info
