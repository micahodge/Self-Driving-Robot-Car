<h1>Self-Driving Robot Car</h1>

 ### [YouTube Demonstration of Self-Driving Robot Car Program 1](https://youtube.com/shorts/d5qk52JwSSc)
 ### [YouTube Demonstration of Self-Driving Robot Car Program 2](https://www.youtube.com/shorts/iS299p30utc)

<h2>Description</h2>
There are two different programs for this car:
<br><br>
Program 1: This program tells this self-driving robot car to guide its way down a hallway while avoiding the walls, and then, when it reaches the end wall, turn around and come back to you. This car uses an Arduino Mega 2560 to control its abilities. This car uses four small DC motors connected to two L298N motor controllers for movement. There is one L298N motor controller connected to the left motors and another motor controller connected to the right motors. An ultrasonic sensor mounted on a small stepper motor is used to detect the robot's surroundings. The stepper motor swivels the ultrasonic sensor left and right, scanning the area. The stepper motor can drift sometimes, so a microswitch is used to zero out the ultrasonic sensor's position to ensure it does not drift. There is also a breadboard in the back that has four LED lights (two green, one yellow, and one red). When the car is moving forward, both green LEDs turn on; when the car is stopped, the yellow LED turns on; when the car is turning, both green and red LEDs turn on.
<br><br>
Program 2: This program tells the car to drive one meter and then turn left. It does this four times and should end up in the same spot that it started. The ultrasonic sensor, stepper motor, and microswitch are not used in this program. It instead uses precise timing in the program. It uses the L298N motor controllers and Arduino Mega 2560 to control its movement. It also uses the breadboard to turn on the LEDs as explained in the first program.
<br />

<h2>Sensors and Electronics Used</h2>

- <b>Arduino Mega 2560</b> 
- <b>2 L298N motor controllers</b>
- <b>Ultrasonic Sensor</b>
- <b>Stepper Motor</b>
- <b>Microswitch</b>

<h2>Challenges and Solutions</h2>
During this project, I ran into 2 major problems, and I ended up finding solutions to all of them. This is an explanation of my problems and how I solved them. <br><br>

Problem 1: At the beginning of this project, I started out trying to code the robot car so that it would continuously have the ultrasound sensor stay straight ahead and not turn.  Whenever it gets close to a side wall, it's supposed to correct itself and keep going, but once it gets to the back wall, it is supposed to turn around completely and come back. The main problem I ran into was that the sensor had no way of differentiating the back wall from the side walls. For about 3 days, I tried to find a way for the sensor to know whether it had detected a side wall or the back wall, but I could not figure it out. So instead, after 3 days of trying to solve that, I went with a different approach. Instead, I would have the sensor constantly turning left and right and recording distances along the way. It would turn left, record the "left distance", turn right to the middle, record "straight ahead" distance, turn right again, record the "right distance", and then turn left again to the middle, and record the "straight ahead" distance again. This gave the robot car the ability to distinguish which recorded distances were the side walls ("left" and "right" distances) and which recorded distance was the back wall ("straight ahead" distance). <br><br>

Problem 2: The stepper motor that I had the ultrasonic sensor mounted on started to drift every once in a while, and it was unpredictable. So to fix that, I needed a hardware piece on the outside of the stepper motor that would let it know when it has perfectly reached the center, so the motor would stop and record the true "straight ahead" distance. So I mounted a microswitch next to the motor so whenever it would turn and get to a certain point, it would click the switch, which would let the Arduino know to stop the motor from turning. However, the stepper motor's shaft did not have enough of an indentation to reliably click the switch. So, I had to make an exaggerated version that would reliably click the switch every time. At first, I tried to put super stiff cardboard around the bottom of the shaft and have that click the switch, but over time, the cardboard would bend and not be reliable. So, I ended up finding some aircraft-grade aluminum that my brother-in-law had and using that. I cut a small piece that could easily click the switch, and I drilled two holes in the sheet of metal. The two holes, which were side by side, were equal to about 5mm in length, and, with a little bit of shaving on the sides, I made them about 3.5mm wide. This ended up being the perfect size to fit onto the stepper motor. Having this on the stepper motor meant I now had a reliable piece of hardware that could easily click the switch, that was also thin enough to where I still had room to mount the ultrasonic sensor on the stepper motor.

<h2>Car Photos</h2>

<p align="center">
Top View: <br/>
<img src="https://i.imgur.com/KvjHBDK.jpeg" height="50%" width="50%"/>
<br />
<br />
Front View:  <br/>
<img src="https://i.imgur.com/FGQVoM7.jpeg" height="50%" width="50%"/>
<br />
<br />
Side View: <br/>
<img src="https://i.imgur.com/SDfULTQ.jpeg" height="50%" width="50%"/>
