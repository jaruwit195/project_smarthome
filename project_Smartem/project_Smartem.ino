#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

LiquidCrystal_I2C lcd (0x27, 16, 2);
DHT dht_2_DHT11 (2, DHT11);

void setup() {
  pinMode(5, OUTPUT);
  pinMode(6,OUTPUT);
  lcd.init();
  lcd.backlight();
  // lcd.noCursor(); 
  lcd.noBlink();
  dht_2_DHT11.begin(); 
}
void loop() {
lcd.clear(); 
lcd.setCursor(0,0);
if (dht_2_DHT11.readTemperature() > 35){
  digitalWrite(6,HIGH);
  tone(5,440);
  lcd.print((String("Temp: ") + String ((int) (dht_2_DHT11.readTemperature ())) + String(" *c")));
  delay(1000);
  lcd.clear();

  lcd.print("Warning temp too high!");
  for (int i = 0;i < 23;i++){
    lcd.scrollDisplayLeft();
    delay(150);
  }
  for (int i = 0;i < 39; i++){
    lcd.scrollDisplayLeft();
    delay(150);
  }
}
else {
  digitalWrite(6,LOW);
  noTone(5);
  lcd.print((String("Temp: ") + String ((int) (dht_2_DHT11.readTemperature ())) + String(" *c"))); 
  delay(1000);
  lcd.clear();

  lcd.print("Normal temperature");
  for (int i = 0;i < 20;i++){
    lcd.scrollDisplayLeft();
    delay(300);
  }
  for (int i = 0;i < 38; i++){
    lcd.scrollDisplayLeft();
    delay(300);
  }
}
// lcd.print((String ("Humid: ") + String ((int) (dht_2_DHT11.readHumidity())) + String(" ")));
// lcd.setCursor(0,1);
// lcd.print((String("Temp: ") + String ((int) (dht_2_DHT11.readTemperature ())) + String(" *c"))); 
// delay(1000);
}