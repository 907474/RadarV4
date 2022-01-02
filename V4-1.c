#include <Servo.h>
Servo Myservo;
int pos;
const int trigPin = 2;
const int echoPin = 1;
const int relay = 3;
void setup() {
Myservo.attach(0); 
pinMode (relay, OUTPUT);
Serial.begin(9600);
} 
void readradar(){
 long duration, inches, cm, mm;
pinMode(trigPin, OUTPUT); 
digitalWrite(trigPin, LOW); 
delayMicroseconds(2000); 
digitalWrite(trigPin, HIGH); 
delayMicroseconds(1000); 
digitalWrite(trigPin, LOW);
pinMode(echoPin, INPUT); 
duration = pulseIn(echoPin, HIGH);
inches = microsecondsToInches(duration); 
cm = microsecondsToCentimeters(duration);
mm = microsecondsToMillimeters(duration);
Serial.print(inches); 
Serial.print("in, "); 
Serial.print(cm);
Serial.print("cm, ");
Serial.print(mm);
Serial.print(" mm");
Serial.println(); 
delay(1000);
if (inches < 10){
  digitalWrite (relay, HIGH);
  delay (550);
  digitalWrite (relay, LOW); 
}
}
void loop(){
readradar();
Serial.println(1);
delay(500);
for(pos=30;pos<=60;pos++){
Myservo.write(pos);
delay(15);
}
readradar();
Serial.println(2);
delay(500);  
  for(pos=60;pos>=100;pos--){
Myservo.write(pos);
delay(15);
}
readradar();
Serial.println(3);
delay(500);
  for(pos=100;pos>=30;pos--){
Myservo.write(pos);
delay(15);
}

}
long microsecondsToInches(long microseconds)
{return microseconds / 74 / 2;}
long microsecondsToCentimeters(long microseconds)
{return microseconds / 29 / 2;}
long microsecondsToMillimeters(long microseconds)
{return microseconds / 2.9 / 2;}