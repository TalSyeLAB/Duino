#include <Servo.h>

volatile long A;

float checkdistance_11_10() {
  digitalWrite(11, LOW);
  delayMicroseconds(2);
  digitalWrite(11,  HIGH);
  delayMicroseconds(10);
  digitalWrite(11, LOW);

  float distance = pulseIn(10, HIGH) / 58.00;
  delay(10);
  
  return distance;
}

Servo servo_3;
Servo servo_6;
Servo servo_9;

void setup() {
  // put your setup code here, to run once:
  A = 0;
  
  pinMode(11, OUTPUT);
  pinMode(10, INPUT);
  pinMode(12, OUTPUT);

  servo_3.attach("INSERT PIN NUMBER"); 
  servo_6.attach("INSERT PIN NUMBER");
  servo_9.attach("INSERT PIN NUMBER");

  // pick three pins to connect to servo
}

void loop() {
  // pick what distance the sensor will initiate the program (Between 25 and 35 preferred)
  if (checkdistance_11_10() < "PICK DISTANCE FROM MOTION") {
    A = random(0,4);
    switch (A) {
      case 1:
      tone(12, 131);
      delay(100);
      noTone(12);
      servo_3.write(179);
      delay(1000);
      servo_3.write("ANGLE"); //Pick a rotation angle  between 89 and 120
      delay(500);
      break;

      case 2:
      tone(12, 131);
      delay(100);
      noTone(12);
      servo_6.write(179);
      delay(1000);
      servo_6.write('ANGLE"); //Pick a rotation angle  between 89 and 120
      delay(500);
      break;

      case 3:
      tone(12, 131);
      delay(100);
      noTone(12);
      servo_9.write(179);
      delay(1000);
      servo_9.write("ANGLE"); //Pick a rotation angle  between 89 and 120
      delay(500);
      break;
      
      //We have three different cases, each representing a possible outcome of the game
    }
  }
}
