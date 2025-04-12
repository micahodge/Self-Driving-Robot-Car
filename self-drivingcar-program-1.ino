int green1 = 53, green2 = 52, yellow = 51, red = 45, cat = 0, trig = 47, echo = 46, t = 0, d = 0; // initializing LED and sensor variables
int lin1 = 30, lin2 = 31, lin3 = 32, lin4 = 33, rin1 = 34, rin2 = 35, rin3 = 36, rin4 = 37, lpwm1 = 5, lpwm2 = 6, rpwm1 = 2, rpwm2 = 3; //initializing motor variables
int steppertime = 3, leftdistance = 0, rightdistance = 0, frontdistance = 0, stepperdistance = 150; // initializing distance variables
int switchmode = A0, switchnum = 0, switchprevious = 1, switchnum1 = 0, switchnum2 = 0, switchnum3 = 0, switchnum4 = 0, switchprevious1 = 0, switchprevious2 = 0, switchprevious3 = 0, switchprevious4 = 0; // iniitialzing switch variables

void setup() {
  pinMode(green1, OUTPUT); // sets first green LED as output
  pinMode(green2, OUTPUT);// sets second green LED as output
  pinMode(yellow, OUTPUT);// sets yellow LED as output
  pinMode(red, OUTPUT);// sets red LED as output
  pinMode(trig, OUTPUT); // sets trig on sensor as output
  pinMode(echo, INPUT);//sets echo on sensor as input
  pinMode(A0, INPUT); // sets switch as input
  DDRA = B11111111; // port programming using port A for the stepper motor
  Serial.begin(9600); // so the computer and arduino can communicate clearly
  {for (int i=0; i<600; i++) // for loop for the stepper motor to travel
  {clockwise(); // travel clockwise
  if (switchnum > 0 && switchprevious == 0) // if the switch is currently on and the last step shows that the switch was off
  {Serial.println("stop"); // print the word "stop"
    stepperdistance = 0; // stop the stepper motor
  break;}}} // break out of the loop
  delay(3000); // delay 3 seconds before the program starts
}

void loop() {
  forwardmotion(); // car moves forward
  Serial.println("forward motion"); // print "forward motion"
  for(int i=0;i<120;i++) // for loop for the stepper motor
  counterclockwise(); // stepper motor travel counterclockwise
  switchnum = 0; // reset switchnum value to 0
  Serial.println("Left Distance: "); // print "Left Distance"
  delay(300); // delay .3 seconds
  distance(); // record distance
  leftdistance = d; // store distance as leftdistance
  //leftdistance = 110; // meant for testing purposes
  

  if (leftdistance <= 100 && leftdistance >= 0) // if a wall is less than 100 cm away on the left side of the car
  {
  digitalWrite(yellow, 1); // turn yellow LED on
  digitalWrite(green1, 0);// turn first green LED off
  digitalWrite(green2, 0); // turn second green LED off
  digitalWrite(red, 0); // turn red LED off
  analogWrite(lpwm1, 0); // sets left front motor speed to 0%
  digitalWrite(lin1, 1); // sets left front motor to go forward
  digitalWrite(lin2, 0);// sets left front motor to go forward
  analogWrite(lpwm2, 0); // sets back left motor speed to 0%
  digitalWrite(lin3, 1);// sets back left motor to go forward
  digitalWrite(lin4, 0);// sets back left motor to go forward
  analogWrite(rpwm1, 0); // sets right front motor speed to 0%
  digitalWrite(rin1, 1); // sets right front motor to go forward
  digitalWrite(rin2, 0);//sets right front motor to go forward
  analogWrite(rpwm2, 0);//sets right back motor speed to 0%
  digitalWrite(rin3, 1);//sets right back motor to go forward
  digitalWrite(rin4, 0); // sets right back motor to go forward
  delay(1200); // delay 1.2 seconds
  
  digitalWrite(red, 1); // turn red LED on
  digitalWrite(yellow, 0); // turn yellow LED off
  digitalWrite(green1, 1); // turn first green LED on
  digitalWrite(green2, 1); // turn second green LED on
  analogWrite(lpwm1, 191); // sets left front motor to 75% power
  digitalWrite(lin1, 1); // sets front left motor to go forward
  digitalWrite(lin2, 0);// sets front left motor to go forward
  analogWrite(lpwm2, 191); // sets back left motor to 75% power
  digitalWrite(lin3, 1);// sets back left motor to go forward
  digitalWrite(lin4, 0);// sets back left motor to go forward
  analogWrite(rpwm1, 191); // sets front right motor to 75% power
  digitalWrite(rin1, 0);// sets front right motor to go backwards
  digitalWrite(rin2, 1);// sets front right motor to go backwards
  analogWrite(rpwm2, 191); // sets back right motor to 75% power
  digitalWrite(rin3, 0);// sets back right motor to go backwards
  digitalWrite(rin4, 1);// sets back right motor to go backwards
  delay(450); // delay .45 seconds
  }

  forwardmotion(); // contunue to go forwards after it all even if the if clause is or is not met

  for(int i=0;i<180;i++) // for loop so the stepper motor can move 180 steps
  {clockwise(); // turn the stepper motor clockwise
  if (switchnum > 0 && switchprevious == 0) // if the switch is clicked and it wasnt clicked while on the stepper motors last step
  {for (int extra = 0; extra < 5; extra++) // turn the motor an extra 5 steps to center it
  {clockwise();} // turn the stepper motor clockwise
  break;}} // break out of the loop
  switchnum = 0; // reset the switchnum value back to 0
  Serial.println("Front Distance: "); // print "Front Distance:  "
  delay(300); // delay 1.5 seconds
  distance(); //record distance
  frontdistance = d;// store the distance in frontdistance
  //frontdistance = 150; // for testing purposes

  if (frontdistance <= 180 && frontdistance >= 0) //if the back wall is 180cm away or less
  {for (int stop = 0; stop < 0; stop++) // stop the stepper motor

  digitalWrite(yellow, 0); // turn the yellow LED off
  digitalWrite(green1, 1);//turn the frist green LED on
  digitalWrite(green2, 1);//turn the second green LED on
  digitalWrite(red, 0);//turn the red LED off
  analogWrite(lpwm1, 80);//turn the front left motor to 31% power
  digitalWrite(lin1, 1);//turn the front left motor forward
  digitalWrite(lin2, 0);//turn the front left motor forward
  analogWrite(lpwm2, 80);//turn the back left motor to 31% power
  digitalWrite(lin3, 1); // turn the back left motor forward
  digitalWrite(lin4, 0);//turn the back left motor forward
  analogWrite(rpwm1, 80); // turn the front right motor to 31% power
  digitalWrite(rin1, 1); // turn the front right motor forward
  digitalWrite(rin2, 0); // turn the front right motor forward
  analogWrite(rpwm2, 80); // turn the back right motor to 31% power
  digitalWrite(rin3, 1);// turn the back right motor forward
  digitalWrite(rin4, 0);// turn the back right motor forward
  delay(1500);  // delay 1.5 seconds
  distance(); // record distance again
  Serial.println(d); // print distance
  frontdistance = d; // store d in frontdistance
{
  if (frontdistance <= 110 && frontdistance >=55) // if the front distance is 55-110 cm away
  {delay(800); // delay .8 seconds
  digitalWrite(yellow, 1); // turn the yellow LED on
  digitalWrite(green1, 0);//turn the frist green LED off
  digitalWrite(green2, 0);//turn the second green LED off
  digitalWrite(red, 0);//turn the red LED off
  analogWrite(lpwm1, 0);//turn the front left motor to 0% power
  digitalWrite(lin1, 1);//turn the front left motor forward
  digitalWrite(lin2, 0);//turn the front left motor forward
  analogWrite(lpwm2, 0);//turn the back left motor to 0% power
  digitalWrite(lin3, 1); // turn the back left motor forward
  digitalWrite(lin4, 0);//turn the back left motor forward
  analogWrite(rpwm1, 0); // turn the front right motor to 0% power
  digitalWrite(rin1, 1); // turn the front right motor forward
  digitalWrite(rin2, 0); // turn the front right motor forward
  analogWrite(rpwm2, 0); // turn the back right motor to 0% power
  digitalWrite(rin3, 1);// turn the back right motor forward
  digitalWrite(rin4, 0);// turn the back right motor forward
  delay(1500); // delay 1.5 seconds
  
  digitalWrite(yellow, 0); // turn the yellow LED off
  digitalWrite(green1, 1); // turn the first green LEd on
  digitalWrite(green2, 1); // turn the second green LED on
  digitalWrite(red, 1); // turn the red LED on
  analogWrite(lpwm1, 255); // turn the left front motor to 100% power
  digitalWrite(lin1, 1); // turn the left front motor forward
  digitalWrite(lin2, 0); // turn the front left motor forward
  analogWrite(lpwm2, 255); // turn the left back motor to 100% power
  digitalWrite(lin3, 1); // turn the back left motor forward
  digitalWrite(lin4, 0); // turn the back left motor forward
  analogWrite(rpwm1, 255); // turn the front right motor to 100 % power
  digitalWrite(rin1, 0); // turn the front right motor backwards
  digitalWrite(rin2, 1); // turn the front right motor backwards
  analogWrite(rpwm2, 255); // turn the back right motor to 100% power
  digitalWrite(rin3, 0); // turn the back right motor bakcwards
  digitalWrite(rin4, 1); // tunr the back right motor backwards
  delay(2250);}//delay 2.25 seconds

  if (frontdistance < 55 && frontdistance >=0) // if the front distance is 0-55 cm away
  {digitalWrite(yellow, 1); // turn the yellow LED on
  digitalWrite(green1, 0);//turn the frist green LED off
  digitalWrite(green2, 0);//turn the second green LED off
  digitalWrite(red, 0);//turn the red LED off
  analogWrite(lpwm1, 0);//turn the front left motor to 0% power
  digitalWrite(lin1, 1);//turn the front left motor forward
  digitalWrite(lin2, 0);//turn the front left motor forward
  analogWrite(lpwm2, 0);//turn the back left motor to 0% power
  digitalWrite(lin3, 1); // turn the back left motor forward
  digitalWrite(lin4, 0);//turn the back left motor forward
  analogWrite(rpwm1, 0); // turn the front right motor to 0% power
  digitalWrite(rin1, 1); // turn the front right motor forward
  digitalWrite(rin2, 0); // turn the front right motor forward
  analogWrite(rpwm2, 0); // turn the back right motor to 0% power
  digitalWrite(rin3, 1);// turn the back right motor forward
  digitalWrite(rin4, 0);// turn the back right motor forward
  delay(1500); // delay 1.5 seconds
  
  digitalWrite(yellow, 0); // turn the yellow LED off
  digitalWrite(green1, 1); // turn the first green LEd on
  digitalWrite(green2, 1); // turn the second green LEd on
  digitalWrite(red, 1); // turn the red LED on
  analogWrite(lpwm1, 255); // turn the left front motor to 100% power
  digitalWrite(lin1, 1); // turn the left front motor forward
  digitalWrite(lin2, 0); // turn the front left motor forward
  analogWrite(lpwm2, 255); // turn the left back motor to 100% power
  digitalWrite(lin3, 1); // turn the back left motor forward
  digitalWrite(lin4, 0); // turn the back left motor forward
  analogWrite(rpwm1, 255); // turn the front right motor to 100 % power
  digitalWrite(rin1, 0); // turn the front right motor backwards
  digitalWrite(rin2, 1); // turn the front right motor backwards
  analogWrite(rpwm2, 255); // turn the back right motor to 100% power
  digitalWrite(rin3, 0); // turn the back right motor bakcwards
  digitalWrite(rin4, 1); // tunr the back right motor backwards
  delay(2250);}}} //delay 2.25 seconds

  forwardmotion(); // even after the if clause is done the car will move forward
  
  {for(int i=0;i<105;i++) // for loop so the stepper motor turns 135 steps
  clockwise(); // turn the stepper motor clockwise
  switchnum = 0; // reset the switchnum value to 0
  Serial.println("Right Distance: "); // print "Right Distance:  "
  delay(300); //delay .3 seconds
  distance(); // record distance
  rightdistance = d; // store the distance into rightdistance
  //rightdistance = 110; // for testing purposes
  }

  if (rightdistance <= 100 && rightdistance >=0) // if the car is less than 100 cm from the wall on its right
  {digitalWrite(yellow, 1); // turn the yellow LED on
  digitalWrite(green1, 0); // turn the first green LED off
  digitalWrite(green2, 0); // turn the second green LED off
  digitalWrite(red, 0); // turn the red LED off
  analogWrite(lpwm1, 0); // turn the front left motor to 0% power
  digitalWrite(lin1, 0); // turn the front left motor backwards
  digitalWrite(lin2, 1); // turn the front left motor backwards
  analogWrite(lpwm2, 0); // turn the back left motor to 0% power
  digitalWrite(lin3, 0); // turn the back left motor backwards
  digitalWrite(lin4, 1); // turn the back left motor backwards
  analogWrite(rpwm1, 0); // turn the front right motor to 0% power
  digitalWrite(rin1, 0); // turn the front right motor backwards
  digitalWrite(rin2, 1); // turn the front right motor backwards
  analogWrite(rpwm2, 0); // turn the back right motor to 0% power
  digitalWrite(rin3, 0); // turn the back right motor backwards
  digitalWrite(rin4, 1); // turn the back right motor backwards
  delay(1200); // delay 1.2 seconds
  
  digitalWrite(red, 1); // turn the red LED on
  digitalWrite(yellow, 0); // turn the yellow LED off
  digitalWrite(green1, 1); // turn the first green LED on
  digitalWrite(green2, 1); // turn the second green LED on
  analogWrite(lpwm1, 191); // turn the front left motor to 75% power 
  digitalWrite(lin1, 0); // turn the front left motor backwards
  digitalWrite(lin2, 1); // turn the front left motor backwards
  analogWrite(lpwm2, 191); // turn the back left motor to 75% power
  digitalWrite(lin3, 0); // turn the back left motor backwards
  digitalWrite(lin4, 1); // turn the back left motor backwards
  analogWrite(rpwm1, 191); // turn the right front motor to 75% power
  digitalWrite(rin1, 1); // turn the right front motor forwards
  digitalWrite(rin2, 0); // turn the right front motor forwards
  analogWrite(rpwm2, 191); // turn the right back motor to 75% power
  digitalWrite(rin3, 1); // turn the right back motor forwards
  digitalWrite(rin4, 0); // turn the right back motor forwards
  delay(450); // delay .45 a second
  }

  forwardmotion(); // move forward even after the if clause is done

  for(int i=0;i<180;i++) // for loop to turn the stepper motor 180 steps
  {counterclockwise(); // turn the stpper motor counterclockwise
  if (switchnum > 0 && switchprevious == 0) // if the switch is clicked while the previous step had the switch off
  {for (int extra = 0; extra < 35; extra++) // turn the motor an extra 35 steps to center it
  {counterclockwise();} // turn the stepper motor counterclockwise
  break;}} // break out of the loop
  switchnum = 0; // reset the switchnum value  eequal to 0
  Serial.println("Front Distance: "); // print "Front Distance:  "
  delay(300); // delay .3 seconds
  distance(); // record distance
  frontdistance = d; // store the distance into frontdistance
  //frontdistance = 150; // used for testing purposes
  
  if (frontdistance <= 180 && frontdistance >=0) // if the back wall is 0-180 cm away
  {for (int stop = 0; stop < 0; stop++) // stop the stepper motor
  
  digitalWrite(yellow, 0); // turn the yellow LED on
  digitalWrite(green1, 1);//turn the frist green LED off
  digitalWrite(green2, 1);//turn the second green LED off
  digitalWrite(red, 0);//turn the red LED off
  analogWrite(lpwm1, 80);//turn the front left motor to 31% power
  digitalWrite(lin1, 1);//turn the front left motor forward
  digitalWrite(lin2, 0);//turn the front left motor forward
  analogWrite(lpwm2, 80);//turn the back left motor to 31% power
  digitalWrite(lin3, 1); // turn the back left motor forward
  digitalWrite(lin4, 0);//turn the back left motor forward
  analogWrite(rpwm1, 80); // turn the front right motor to 31% power
  digitalWrite(rin1, 1); // turn the front right motor forward
  digitalWrite(rin2, 0); // turn the front right motor forward
  analogWrite(rpwm2, 80); // turn the back right motor to 31% power
  digitalWrite(rin3, 1);// turn the back right motor forward
  digitalWrite(rin4, 0);// turn the back right motor forward
  delay(1500); // delay 1.5 seconds
  distance(); // record distance again
  frontdistance = d; // store distance into frontdistance
{
  if (frontdistance <= 110 && frontdistance >= 55) // if the front wall is 55-100 cm away
  {delay(800); // delay .8 seconds
  digitalWrite(yellow, 1); // turn the yellow LED on
  digitalWrite(green1, 0); // turn the frist green LED off
  digitalWrite(green2, 0); // turn the second green LED off
  digitalWrite(red, 0); // turn the red LED off
  analogWrite(lpwm1, 0); // turn the front left motor to 0% power
  digitalWrite(lin1, 1); // turn the front left motor forwards
  digitalWrite(lin2, 0); // turn the front left motor forwards
  analogWrite(lpwm2, 0); // turn the back left motor to 0% power
  digitalWrite(lin3, 1); // turn the bakc left motor forwards
  digitalWrite(lin4, 0); // turne the back left motor forwards
  analogWrite(rpwm1, 0); // turn the right front motor to 0% power
  digitalWrite(rin1, 1); // turn the right front motor forwards 
  digitalWrite(rin2, 0);// turn the right front motor forwards
  analogWrite(rpwm2, 0); // turn the back right motor to 0% power
  digitalWrite(rin3, 1); // turn the back right motor forwards
  digitalWrite(rin4, 0); // turn the bakc right motor forwards
  delay(1500); // delay 1.5 seconds
  
  digitalWrite(yellow, 0); // turn the yellow LED off
  digitalWrite(green1, 1); // turn the first green LED on
  digitalWrite(green2, 1); // turn the seconds green LED on
  digitalWrite(red, 1); // turn the red LED off
  analogWrite(lpwm1, 255); // the front left motor to 100% power
  digitalWrite(lin1, 1); // turn the front left motor forwards
  digitalWrite(lin2, 0); // turn the front left motor forwards
  analogWrite(lpwm2, 255); // turn the bakc left motor to 100% power
  digitalWrite(lin3, 1); // turn the back left motor forwards
  digitalWrite(lin4, 0); // turn the back left motor forwards
  analogWrite(rpwm1, 255); // turn the front right motor to 100% power
  digitalWrite(rin1, 0); // turn the front right motor backwards
  digitalWrite(rin2, 1); // turn the front right motot backwards
  analogWrite(rpwm2, 255); // turn the back right motor to 100% power
  digitalWrite(rin3, 0); // turn the back right motor backwards
  digitalWrite(rin4, 1); // turn the back right motor backwards
  delay(2250);} //delay 2.25 seconds

  if (frontdistance < 55 && frontdistance >= 0) // if the back wall is 0-55 cm away
  {digitalWrite(yellow, 1); // turn the yellow LED on
  digitalWrite(green1, 0); // turn the frist green LED off
  digitalWrite(green2, 0); // turn the second green LED off
  digitalWrite(red, 0); // turn the red LED off
  analogWrite(lpwm1, 0); // turn the front left motor to 0% power
  digitalWrite(lin1, 1); // turn the front left motor forwards
  digitalWrite(lin2, 0); // turn the front left motor forwards
  analogWrite(lpwm2, 0); // turn the back left motor to 0% power
  digitalWrite(lin3, 1); // turn the bakc left motor forwards
  digitalWrite(lin4, 0); // turne the back left motor forwards
  analogWrite(rpwm1, 0); // turn the right front motor to 0% power
  digitalWrite(rin1, 1); // turn the right front motor forwards 
  digitalWrite(rin2, 0);// turn the right front motor forwards
  analogWrite(rpwm2, 0); // turn the back right motor to 0% power
  digitalWrite(rin3, 1); // turn the back right motor forwards
  digitalWrite(rin4, 0); // turn the bakc right motor forwards
  delay(1500); // delay 1.5 seconds
  
  digitalWrite(yellow, 0); // turn the yellow LED off
  digitalWrite(green1, 1); // turn the first green LED on
  digitalWrite(green2, 1); // turn the seconds green LED on
  digitalWrite(red, 1); // turn the red LED off
  analogWrite(lpwm1, 255); // the front left motor to 100% power
  digitalWrite(lin1, 1); // turn the front left motor forwards
  digitalWrite(lin2, 0); // turn the front left motor forwards
  analogWrite(lpwm2, 255); // turn the bakc left motor to 100% power
  digitalWrite(lin3, 1); // turn the back left motor forwards
  digitalWrite(lin4, 0); // turn the back left motor forwards
  analogWrite(rpwm1, 255); // turn the front right motor to 100% power
  digitalWrite(rin1, 0); // turn the front right motor backwards
  digitalWrite(rin2, 1); // turn the front right motot backwards
  analogWrite(rpwm2, 255); // turn the back right motor to 100% power
  digitalWrite(rin3, 0); // turn the back right motor backwards
  digitalWrite(rin4, 1); // turn the back right motor backwards
  delay(2250);}}} //delay 2.25 seconds}

  }
void clockwise() // function for turning the stepper motor clockwise
{
PORTA = B00000001; // take the first step
switchprevious1 = analogRead(switchmode); // store the switch value into switchprevious1
switchnum1 = analogRead(switchmode); // store the switch value into switchnum1
if (switchnum1 > 0 && switchprevious4 == 0) // if the current switch is clicked and the previous switch is not clicked
{switchnum = switchnum1; // store this step value as switchnum
switchprevious = switchprevious4;}// store this step value as switchprevious
delay(steppertime); // delay until the next step
PORTA = B00000100; // take the second step
switchprevious2 = analogRead(switchmode);// store the switch value into switchprevious2
switchnum2 = analogRead(switchmode);// store the switch value into switchnum2
if (switchnum2 > 0 && switchprevious1 == 0)// if the current switch is clicked and the previous switch is not clicked
{switchnum = switchnum2;// store this step value as switchnum
switchprevious = switchprevious1;}// store this step value as switchprevious
delay(steppertime);// delay until the next step
PORTA = B00010000; // take the thrid step
switchprevious3 = analogRead(switchmode);// store the switch value into switchprevious3
switchnum3 = analogRead(switchmode);// store the switch value into switchnum3
if (switchnum3 > 0 && switchprevious2 == 0)// if the current switch is clicked and the previous switch is not clicked
{switchnum = switchnum3;// store this step value as switchnum
switchprevious = switchprevious2;}// store this step value as switchprevious
delay(steppertime);// delay until the next step
PORTA = B01000000; // take the fourth step
switchprevious4 = analogRead(switchmode);// store the switch value into switchprevious4
switchnum4 = analogRead(switchmode);// store the switch value into switchnum4
if (switchnum4 > 0 && switchprevious3 == 0)// if the current switch is clicked and the previous switch is not clicked
{switchnum = switchnum4;// store this step value as switchnum
switchprevious = switchprevious3;}// store this step value as switchprevious
delay(steppertime);// delay until the next step
Serial.println(switchnum); // print the switchnum current value
}

void counterclockwise() // function for turning the stepper motor counterclockwise
{
PORTA = B01000000; // take the first step
switchprevious1 = analogRead(switchmode);// store the switch value into switchprevious1
switchnum1 = analogRead(switchmode);// store the switch value into switchnum1
if (switchnum1 > 0 && switchprevious4 == 0)// if the current switch is clicked and the previous switch is not clicked
{switchnum = switchnum1;// store this step value as switchnum
switchprevious = switchprevious4;}// store this step value as switchprevious
delay(steppertime);// delay until the next step
PORTA = B00010000; // take the second step
switchprevious2 = analogRead(switchmode);// store the switch value into switchprevious2
switchnum2 = analogRead(switchmode);// store the switch value into switchnum2
if (switchnum2 > 0 && switchprevious1 == 0)// if the current switch is clicked and the previous switch is not clicked
{switchnum = switchnum2;// store this step value as switchnum
switchprevious = switchprevious1;}// store this step value as switchprevious
delay(steppertime);// delay until the next step
PORTA = B00000100; // take the third step
switchprevious3 = analogRead(switchmode);// store the switch value into switchprevious3
switchnum3 = analogRead(switchmode);// store the switch value into switchnum3
if (switchnum3 > 0 && switchprevious2 == 0)// if the current switch is clicked and the previous switch is not clicked
{switchnum = switchnum3;// store this step value as switchnum
switchprevious = switchprevious2;}// store this step value as switchprevious
delay(steppertime);// delay until the next step
PORTA = B00000001; // take the fourth step
switchprevious4 = analogRead(switchmode);// store the switch value into switchprevious4
switchnum4 = analogRead(switchmode);// store the switch value into switchnum4
if (switchnum4 > 0 && switchprevious3 == 0)// if the current switch is clicked and the previous switch is not clicked
{switchnum = switchnum4;// store this step value as switchnum
switchprevious = switchprevious3;}// store this step value as switchprevious
delay(steppertime);// delay until the next step
Serial.println(switchnum); // print the switchnum value
}

void distance () // function for recording distance
{ digitalWrite(trig, 0); //0 equals LOW, turns the trigger off
  delayMicroseconds(2); // delays 2 microseconds
  digitalWrite(trig, 1); //1 equals HIGH,  turns on trigger
  delayMicroseconds(10);// delays 10 microseconds
  digitalWrite(trig, 0); //turn trigger off
  t = pulseIn(echo, 1); // stores the duration of the echo into t
  d = (t * 0.034) / 2; // finds the distnace through this equation and stores it
  Serial.print("distance: "); //prints the word "distance: "
  Serial.print(d); // prints the value of d
  Serial.println(" cm"); // prints the phrase " cm"
}

void forwardmotion() // function for moving forward
{
  digitalWrite(green1, 1); // turn the first green LED on 
  digitalWrite(green2, 1); // turn the second green LED on
  digitalWrite(yellow, 0);// turn the yellow LED off
  digitalWrite(red, 0); // turn the red LED off
  analogWrite(lpwm1, 90); // turn the front left motor to 35% power
  digitalWrite(lin1, 1); // turn the front left motor forwards
  digitalWrite(lin2, 0); // turn the front left motor forwards
  analogWrite(lpwm2, 90); // turn the left back motor to 35% power
  digitalWrite(lin3, 1); // turn the left back motor forwards
  digitalWrite(lin4, 0); // turn the left back motor forwards
  analogWrite(rpwm1, 90); // turn the right front motor to 35% power
  digitalWrite(rin1, 1); // turn the right front motor forwards
  digitalWrite(rin2, 0); // turn the right front motor forwards
  analogWrite(rpwm2, 90); // turn the back right motor to 35% power
  digitalWrite(rin3, 1); // turn the right back motor forwards
  digitalWrite(rin4, 0); // turn the right back motor forwards
}