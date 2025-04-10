<h1>Self-Driving Robot Car</h1>

 ### [YouTube Demonstration of Self-Driving Robot Car Program 1](https://youtube.com/shorts/d5qk52JwSSc)
 ### [YouTube Demonstration of Self-Driving Robot Car Program 2](https://www.youtube.com/shorts/iS299p30utc)

<h2>Description</h2>
There are two different programs for this car:
<br><br>
Program 1: This program tells this self-driving robot car to guide its way down a hallway while avoiding the walls, and then, when it reaches the end wall, turn around and come back to you. This car uses an Arduino Mega 2560 to control its abilities. For movement, this car uses four small DC motors connected to two L298N motor controllers. There is one L298N motor controller connected to the left motors and another motor controller connected to the right motors. An ultrasonic sensor mounted on a small stepper motor is used to detect the robot's surroundings. The stepper motor swivels the ultrasonic sensor left and right, scanning the area. The stepper motor can drift sometimes, so a microswitch is used to zero out the ultrasonic sensor's position to ensure it does not drift. There is also a breadboard in the back that has four LED lights (two green, one yellow, and one red). When the car is moving forward, both green LEDs turn on; when the car is stopped, the yellow LED turns on; when the car is turning, both green and red LEDs turn on.
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
During this project, I ran into 3 major problems, and I ended up finding solutions to all of them. This is an explanation of my problems and how I solved them. 


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
