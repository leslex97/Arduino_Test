#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
const int trigPin = 9;
const int echoPin = 10;
const int button = 2;
long duration;
int distanceCm;
int distanceInch;
int value;
// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
	// initialize the LCD
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  digitalWrite(button,LOW);
  pinMode(button, INPUT);
  
  Serial.begin(9600);
  
	lcd.begin();
  
	lcd.backlight();
  lcd.noBlink();
}

void loop(){
  
  value = digitalRead(button);
  lcd.println(value);
  delay(500);
  lcd.clear();
  
}
void read_value(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distanceCm = duration * 0.034 / 2;
  distanceInch = duration * 0.0133 / 2;
  lcd.setCursor(0, 0); // Sets the location at which subsequent text written to the LCD will be displayed
  if(distanceCm<5){
    lcd.clear();
    lcd.print("Za blisko!");
    delay(1000);
    }
    else{
  lcd.print("Dystans: "); // Prints string "Distance" on the LCD
  lcd.print(distanceCm); // Prints the distance value from the sensor
  lcd.print(" cm");
  delay(100);
  lcd.setCursor(0, 1);
  lcd.print("Dystans: ");
  lcd.print(distanceInch);
  lcd.print(" inch");
  delay(100);
    }
}