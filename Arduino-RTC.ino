#include <LiquidCrystal_I2C.h>
#include <Wire.h>


// Initialize the I2C LCD with address 0x27 and size 16x2
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int buzzerPin = 7;
bool metalDetected = false;

void setup() {
  Serial.begin(9600);              // Start serial communication
  lcd.init();                      // Initialize the LCD
  lcd.backlight();                 // Turn on backlight
  pinMode(buzzerPin, OUTPUT);      // Buzzer pin as output

  // Initial message
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" SYSTEM READY ");
  lcd.setCursor(0, 1);
  lcd.print("No Landmine found");
}

void loop() {
  int sensorValue = analogRead(A0);  // Read analog value from A0
  Serial.print("Analog value at A0: ");
  Serial.println(sensorValue);       // Print to Serial Monitor

  if (sensorValue == 0) {
    if (!metalDetected) {
      metalDetected = true;

      // Alert message
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("** ALERT ACTIVE **");
      lcd.setCursor(0, 1);
      lcd.print("Landmine Found!");

      digitalWrite(buzzerPin, HIGH);
      delay(3000);                  // Buzzer ON for 3 seconds
      digitalWrite(buzzerPin, LOW);

      // Show coordinates
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Lat:18.4691");
      lcd.setCursor(0, 1);
      lcd.print("Lon:73.8945");
      delay(4000);  // Show coordinates for 4 seconds
    }
  } else {
    if (metalDetected) {
      metalDetected = false;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(" SYSTEM NORMAL ");
      lcd.setCursor(0, 1);
      lcd.print("No metal found");
    }
  }

  delay(500);  // Delay for stability
}