/*
   arduino-osc-blink

   Listens for serial messages and controls the
   the on-board LED according to the message.

   To be used with the Processing sketch
   processing_osc_to_arduino.pde

   Written by Becky Stewart 2022

   POOPY BUM BUM
*/
#include <Servo.h>

Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;

int pos=0;

// variable used for LED blink pattern
float blinkCode = 0.1;
int integer = 1;
//int case = (int)blinkCode;

void setup() {
  Serial.begin(9600);  // initialise the serial communication


  // initialize digital pin LED_BUILTIN as an output.
  myservo1.attach(9);   //tilt
  myservo2.attach(10);   //10 - up/down
  myservo3.attach(11);    //11 - up/down
  myservo4.attach(12);    //craw

  myservo1.write(90);
  myservo2.write(90);
  myservo3.write(90);
  myservo4.write(90);
}

void loop() {
  // wait for a message to arrive
  if (Serial.available()) {
    // save the message when it arrives
    blinkCode = Serial.read();
   
  }
   int integer = (int)blinkCode;
    Serial.print(integer);

  switch (integer) {
      case 1:                   //left tilt
        myservo1.write(0);  
        delay(400);      
        break;

      case 2:                   //right tilt
        myservo1.write(90);
        delay(400);
        break;

      case 3:                   //down 
        myservo3.write(180);    //11 
        delay(10);
        myservo2.write(180);    //10
        delay(400);          
        break;

      case 4:                   //up
        myservo2.write(pos);    //10
        delay(25);
        myservo3.write(pos);    //11
        delay(400);
        break;


      case 5: 
        myservo4.write(0);   //open claw
        delay(400);
        break;

      case 6: 
        myservo4.write(135);    //close claw
        delay(400);
        break;

      default:
      break;

}
}
   /* default:
      // default to on one second, off one second
      onDelay = 1000;
      offDelay = 1000;
      break;  */
  

  /*if (blinkCode > 0.5) {
    //digitalWrite(10, HIGH);
    servo.write((blinkCode))
  }
else if (blinkCode < 0.5) {
  //digitalWrite (10, LOW) ;
  } */
/*
  int val = blinkCode;            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  myservo1.write(val);                  // sets the servo position according to the scaled value

  myservo2.write(val);                  // sets the servo position according to the scaled value

  myservo3.write(val);                  // sets the servo position according to the scaled value
  
  myservo4.write(val);                  // sets the servo position according to the scaled value
  delay(2);   */
