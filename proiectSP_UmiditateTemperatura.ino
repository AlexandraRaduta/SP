#include <DHT.h>
#include <LiquidCrystal.h>
#include <Adafruit_Sensor.h>


#define DHTPIN 2     
#define DHTTYPE DHT22   
DHT dht(DHTPIN, DHTTYPE);


float hum;  
float temp; 


LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup() {
lcd.begin(16, 2);
lcd.print("Temp.:");
lcd.setCursor(0, 1);
lcd.print("Umid.:");
}

void loop() {
lcd.setCursor(15, 0);
lcd.print(" ");
delay(1000);
hum = dht.readHumidity();
temp= dht.readTemperature();
lcd.setCursor(7, 0);
lcd.print(temp);
lcd.print("C");
lcd.setCursor(7, 1);
lcd.print(hum);
lcd.print("%");
lcd.setCursor(15, 0);
lcd.print("*");
delay(1000);
}


