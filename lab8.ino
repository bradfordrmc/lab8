#include <Servo.h>  // add servo library
 
Servo myservo;  // create servo object to control a servo
Servo myservo2;  // create servo object to control a servo
 
int pot = 0;  // pin connected the 1st potentiometer
int val;    // variable to store value from the pot
int pot2 = 1;  // pin connected to the 2nd potentiometer
int val2;    // variable to store value from the 2nd pot

 
void setup() {
  myservo.attach(9);  //  the 1st servo is attached to pin 9 
  myservo2.attach(8);  //  the 2nd servo is attached to pin 9 
}
 
void loop() {
  val = analogRead(pot);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  myservo.write(val);                  // sets the servo position according to the scaled value
  val2 = analogRead(pot2);            // reads the value of the potentiometer (value between 0 and 1023)
  val2 = map(val2, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  myservo2.write(val2);                  // sets the servo position according to the scaled value
  delay(15);                           // waits for the servo to get there
}
