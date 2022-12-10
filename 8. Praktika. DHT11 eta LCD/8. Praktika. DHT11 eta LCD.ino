/*
This code records the temperature through testing the mV put out by the sensor.
It records in both Celcius and Fahrenheit. 
It can only detect from -40 degrees C to 125 degrees C or -40 degrees F 
to 257 degrees F
The Humidity is simulated by a soil humidity sensor by being mapped into percentages
*/

// include the library code:
#include <LiquidCrystal.h>

const int analogIn = A0;
int humiditysensorOutput = 0;
// Defining Variables
int RawValue= 0;
double Voltage = 0;
double tempC = 0;

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
}

void loop() {
  RawValue = analogRead(analogIn);
  Voltage = (RawValue / 1023.0) * 5000; // 5000 to get millivots.
  tempC = (Voltage-500) * 0.1; // 500 is the offset 
  humiditysensorOutput = analogRead(A1);
  humiditysensorOutput=map(humiditysensorOutput,0,921,0,100);

  delay(0);  //iterate every 5 seconds
  
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 0);
  // print the number of seconds since reset:
  lcd.print("Tenp eta Hezetaz");
  lcd.setCursor(0, 1);
  lcd.print(tempC);
  lcd.setCursor(5, 1);
  lcd.print("c");
  lcd.setCursor(8, 1);
  lcd.print("-  %");
  lcd.setCursor(12, 1);
  lcd.print(humiditysensorOutput);
}
