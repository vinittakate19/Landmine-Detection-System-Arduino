# Landmine-Detection-System-Arduino
An Arduino-based smart landmine detection system using sensors, buzzer, LCD, and GPS logic


# 💣 Arduino-Based Landmine Detection System

This project presents a **Smart Landmine Detection System** using Arduino UNO, designed to detect underground metal objects (representing landmines) and alert users through a buzzer and LCD display. It also simulates GPS-based location tracking when a landmine is detected.

---

## 🔧 Technologies & Components Used

- **Arduino UNO**
- **Metal Detector Sensor** (via analog input A0)
- **16x2 I2C LCD Display**
- **Buzzer**
- **Simulated GPS Coordinates** (predefined in code)
- **Arduino IDE**

---

## 🚀 Working Principle

1. The system constantly reads analog values from a metal detector sensor.
2. If the sensor value indicates metal presence (value = 0), it triggers an alert:
   - Displays a **"Landmine Found"** warning on the LCD
   - Activates the buzzer for 3 seconds
   - Displays predefined **GPS coordinates** of the detected location
3. If no metal is found, it resets to **"System Normal"** state.

---

## 📟 LCD Messages

- On system start:

SYSTEM READY
No Landmine found
- On detection:

** ALERT ACTIVE **
Landmine Found!

- Coordinates:
Lat: 18.4691°
Lon: 73.8945°


- When clear:
SYSTEM NORMAL
No metal found


---

## 🔔 Alert Logic


if (sensorValue == 0) {
  metalDetected = true;
  lcd.print("Landmine Found!");
  digitalWrite(buzzerPin, HIGH);
  delay(3000);
  digitalWrite(buzzerPin, LOW);
  lcd.print("Lat: 18.4691, Lon: 73.8945");
}

🛠 Future Improvements
Integrate real GPS Module (e.g., NEO-6M)

Add LoRa or GSM module for remote alerts

Implement data logging using SD card

Use robotic platform for real-time area scanning

👨‍💻 Developed By
Vinit Takate
🛠️ Mechanical Engineering Student | Arduino Enthusiast
📍 India

📜 License
This project is licensed under the MIT License.

https://www.linkedin.com/posts/vinit-takate-815939252_smartdefense-landminedetection-arduinoprojects-activity-7340240920761520130-vY-C?utm_source=share&utm_medium=member_desktop&rcm=ACoAAD5uQFEBSlHJUOZNCuPio20o-1n93C2tNCI


