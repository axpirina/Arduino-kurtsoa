/*
* Ultrasonic Sensor HC-SR04 and Arduino Tutorial
* by Dejan Nedelkovski,
* www.HowToMechatronics.com
* modyfied by Axpi
*/
#include <Servo.h>
int angelua = 90;
Servo serboa; // serboa objetua sortzen du

// defines pins numbers
const int trigPin = 7;
const int echoPin = 8;
// defines variables
long duration;
int distance;

void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
serboa.attach(9); // Serboa konektatutzen du Arduinoko 9. Pin-era
serboa.write(angelua);
Serial.begin(9600); // Starts the serial communication
}

void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
  if(distance > 100){
    angelua=180;
    serboa.write(angelua);
    Serial.println("Serboa 180º tara eraman");
  }
  else if(distance <= 100){
    angelua=90;
    serboa.write(angelua); 
    Serial.println("Serboa 90º tara eraman");
  } 
}
