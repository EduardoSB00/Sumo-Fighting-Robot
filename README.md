# Sumo-Fighting-Robot

This project contains the code for a sumo fighting robot inted to compete in a tournament against similar robots with a 5 x 5 cm^2 limitation (no height restriction). 

Its hardware contained an ultrasonic sensor, two infrared sensors and two gear motors with an integrated circuit to control their polarity. No weapons where allowed for only body on body contact would count to throw the oponent of the ring.

The code is based on a simple recognition algorithm where it would initially run forward until it detected the edge of the ring, then it would rotate 30 degree and repeat until cathing a nearby body with the ultrasonic sensor. After finding its oponent it will then provide more energy to the motors by changing the PWM function to create a bigger impact. 

The entire code will run with the arduino microprocessor but some parameters such as the light levels of the ring will need to be adjusted for correct operation.
