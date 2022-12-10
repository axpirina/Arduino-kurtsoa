/*
This code records the temperature through testing the mV put out by the sensor.
It records in both Celcius and Fahrenheit. 
It can only detect from -40 degrees C to 125 degrees C or -40 degrees F 
to 257 degrees F
The Humidity is simulated by a soil humidity sensor by being mapped into percentages
*/

// include the library code:
#include <LiquidCrystal.h>
#include <DHT.h>
 
// Definimos el pin digital donde se conecta el sensor
#define DHTPIN 2
// Dependiendo del tipo de sensor
#define DHTTYPE DHT11
 
// Inicializamos el sensor DHT11
DHT dht(DHTPIN, DHTTYPE);
 
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
   // Comenzamos el sensor DHT
  dht.begin();
}

void loop() {
  // Esperamos 5 segundos entre medidas
  delay(2000);
 
  // Leemos la humedad relativa
  float h = dht.readHumidity();
  // Leemos la temperatura en grados centígrados (por defecto)
  float t = dht.readTemperature();
  // Leemos la temperatura en grados Fahreheit
  float f = dht.readTemperature(true);
 
  // Calcular el índice de calor en grados centígrados
  float hic = dht.computeHeatIndex(t, h, false);
 
  Serial.print("Humedad: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print(f);
  Serial.print(" *F\t");
  Serial.print("Índice de calor: ");
  Serial.print(hic);
  Serial.print(" *C ");
  

  
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
