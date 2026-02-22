#include <Servo.h>

Servo myServoLeft;
Servo myServoRight;

int pos = 0;
const int initial_pos = 110;
const int angle = 40;

int averageLight;

void recalibrate() {
  int n = 1000;
  unsigned long lightSum = 0;
  for (int i = 0; i < n; i++) {
    int val = analogRead(A0);
    lightSum += val;
    Serial.print(i);
    Serial.print(" ");
    Serial.print(val);
    Serial.print(" ");
    Serial.println(lightSum);
    delay(10);
  } 
  averageLight = lightSum / n;
}

void setup() {
  // put your setup code here, to run once:
  pinMode(8, INPUT_PULLUP);
  pinMode(13, OUTPUT);
  myServoLeft.attach(A0);
  myServoRight.attach(A1);
  Serial.begin(9600);

  //recalibrate();
  Serial.print("FINAL AVERAGE: ");
  Serial.println(averageLight);
}

void loop() {
  // put your main code here, to run repeatedly:

  //Serial.println(value);
  int pressed = digitalRead(8);
  Serial.println(pressed);
  if (pressed) {
    //recalibrate();
  }
  //Serial.println("reset");
  //int value = analogRead(A0);
  if (/* value < averageLight - 10 */1) {
    //myServoLeft.write(180);
    //Serial.println(INPUT);
    //myServoLeft.write(0);
    //digitalWrite(13, HIGH);
    //delay(300);
    //Serial.println("Writing");
    for (int i = 0; i < 3; i++) {
      for (pos = initial_pos; pos <= initial_pos + angle; pos++) {
        myServoLeft.write(pos);
        myServoRight.write(pos);
        delay(10);
      }
      delay(150);
      for (pos = initial_pos + angle; pos >= initial_pos; pos--) {
        myServoLeft.write(pos);
        myServoRight.write(pos);
        delay(10);
      }
      /* for (pos = initial_pos; pos >= 15; pos--) {
        myServoLeft.write(pos);
        myServoRight.write(pos);
        delay(10);
      }
      delay(150);
      for (pos = 15; pos <= initial_pos; pos++) {
        myServoLeft.write(pos);
        myServoRight.write(pos);
        delay(10);
      } */
      delay(250);
    }
  } else {
    digitalWrite(13, LOW);
    //delay(300);
  }
  delay(500);
}
