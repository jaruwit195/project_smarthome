#include <Servo.h>
Servo servo_3;
void setup() {
pinMode(6, OUTPUT);
pinMode(5, OUTPUT);
pinMode(4, OUTPUT); pinMode(3, INPUT);
servo 3.attach(2);
}
void loop() {
if (digitalRead(3) == HIGH) {
digitalWrite(6, HIGH);
digitalWrite(5, HIGH);
digitalWrite(4, HIGH); servo 3.write(95);
}
else {
digitalWrite(6, LOW);
digitalWrite(5, LOW);
digitalWrite(4, LOW);
servo 3.write(0);
}
}