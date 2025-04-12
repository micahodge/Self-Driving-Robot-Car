int green1 = 53, green2 = 52, yellow = 51, red = 45; // initializing LED variables
int lin1 = 30, lin2 = 31, lin3 = 32, lin4 = 33, rin1 = 34, rin2 = 35, rin3 = 36, rin4 = 37, lpwm1 = 5, lpwm2 = 6, rpwm1 = 2, rpwm2 = 3; // initializing the motor variables
void setup() {
  pinMode(green1, OUTPUT); // set the frist green LED as output
  pinMode(green2, OUTPUT); // set second green LED as output
  pinMode(yellow, OUTPUT); // set the yellow LED as output
  pinMode(red, OUTPUT); // set the red LED as output
  Serial.begin(9600); // so the computer and Arduino can communicate smoothly when testing
  delay(5000); // delay the program 5 seconds at startup
}

void loop() {
  for (int i=0; i<4; i++) // for loop so that the car only turns 4 times
  {forwardmotion(); // calling of forward motion function
  Serial.println("Move forward one meter"); // print "Move forward one meter"
  Serial.println(i); // print the value of 'i' (which turn it is)
  delay(1900); //the car runs forward for 1.9 seconds (one meter)
  //car stopping
  digitalWrite(yellow, 1); // turn the yellow LEd on
  digitalWrite(green1, 0); // turn first green LED off
  digitalWrite(green2, 0); // turn second green LED off
  digitalWrite(red, 0); // turn red LEd off
  Serial.println("stop"); // print "stop"
  analogWrite(lpwm1, 0); // turn the front left motor to 0% power
  digitalWrite(lin1, 1);//turn the front left motor forwards
  digitalWrite(lin2, 0); // turn the front left motor forwards
  analogWrite(lpwm2, 0); // turn the back left motor to 0% power
  digitalWrite(lin3, 1); // turn the back left motor forwards
  digitalWrite(lin4, 0); // turn the back left motor backwards
  analogWrite(rpwm1, 0); // turn the front right motor to 0% power
  digitalWrite(rin1, 1); // turn the front right motor forwards
  digitalWrite(rin2, 0); // turn the front right motor forwards
  analogWrite(rpwm2, 0); // turn the back right motor to 0% power
  digitalWrite(rin3, 1); // turn the back right motor forwards
  digitalWrite(rin4, 0);//turn the back right motor forwards
  delay(1000); // delay 1 second (stop the car for 1 second)
  //car turning
  digitalWrite(red, 1); // turn the red LED on
  digitalWrite(yellow, 0); // turn the yellow LED off
  digitalWrite(green1, 1); // turn the first green LED on
  digitalWrite(green2, 1); // turn the second green LED on
  Serial.println("turn left"); // print "turn left"
  analogWrite(lpwm1, 191); // turn the front left motor to 75% power
  digitalWrite(lin1, 0); // turn the front left motor backwards
  digitalWrite(lin2, 1); // turn the front left motor backwards
  analogWrite(lpwm2, 191); // turn the back left motor to 75 % power
  digitalWrite(lin3, 0); // turn the back left motor backwards
  digitalWrite(lin4, 1); // turn the back left motor backwards
  analogWrite(rpwm1, 191); // turn the front right motor to 75 % power
  digitalWrite(rin1, 1); // turn the front right motor forwards
  digitalWrite(rin2, 0); // turn the front right motor forwards
  analogWrite(rpwm2, 191); // turn the back right motor to 75 % power
  digitalWrite(rin3, 1); // turn the right back motor forwards
  digitalWrite(rin4, 0); // turn the back right motor forwards
  delay(1470); // delay 1.39 seconds (car turning for 1.29 seconds)
  
  digitalWrite(yellow, 1); // turn the yellow LEd on
  digitalWrite(green1, 0); // turn first green LED off
  digitalWrite(green2, 0); // turn second green LED off
  digitalWrite(red, 0); // turn red LEd off
  Serial.println("stop"); // print "stop"
  analogWrite(lpwm1, 0); // turn the front left motor to 0% power
  digitalWrite(lin1, 1);//turn the front left motor forwards
  digitalWrite(lin2, 0); // turn the front left motor forwards
  analogWrite(lpwm2, 0); // turn the back left motor to 0% power
  digitalWrite(lin3, 1); // turn the back left motor forwards
  digitalWrite(lin4, 0); // turn the back left motor backwards
  analogWrite(rpwm1, 0); // turn the front right motor to 0% power
  digitalWrite(rin1, 1); // turn the front right motor forwards
  digitalWrite(rin2, 0); // turn the front right motor forwards
  analogWrite(rpwm2, 0); // turn the back right motor to 0% power
  digitalWrite(rin3, 1); // turn the back right motor forwards
  digitalWrite(rin4, 0);//turn the back right motor forwards
  delay(1000);} // delay 1 second (stop the car for 1 second)

  delay(1000000); // delay the program 1000 seconds (essentially stopping the program)
}

void forwardmotion() // function for the car moving forward
{
  digitalWrite(green1, 1); // first green LED on
  digitalWrite(green2, 1); // turn second green LED on
  digitalWrite(yellow, 0); // turn the yellow LED off
  digitalWrite(red, 0); // turn the red LED off
  analogWrite(lpwm1, 255); // turn the front left motor to 100% power
  digitalWrite(lin1, 1); // turn the front left motor forwards
  digitalWrite(lin2, 0); // turn the front left motor forwards
  analogWrite(lpwm2, 255); // turn the back left motor to 100% power
  digitalWrite(lin3, 1); // turn the back left motor forwards
  digitalWrite(lin4, 0); // turn the back left motor forwards
  analogWrite(rpwm1, 255); // turn the front right motor to 100% power
  digitalWrite(rin1, 1); // turn the front right motor forwards
  digitalWrite(rin2, 0); // turn the front right motor forwards
  analogWrite(rpwm2, 255); // turn the back right motor to 100% power
  digitalWrite(rin3, 1); // turn the back right motor forwards
  digitalWrite(rin4, 0); // turn the back right motor forwards
}