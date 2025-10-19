# ESP32_Bus_Alert_System-SmartBusNotifier-
ESP32-based smart bus alert system using HC-SR04 ultrasonic sensor, LCD display, and Bluetooth communication


# 🚍 ESP32 Bus Alert System

A smart **bus detection system** using **ESP32**, **HC-SR04 ultrasonic sensor**, **16x2 I2C LCD**, and **Bluetooth communication**.  
When a bus (or object) is detected nearby, the system:
- Displays “Bus is coming!” on the LCD.
- Sends a Bluetooth message to a connected phone.
- Shows distance data in the Serial Monitor.

---

## 🧩 Components Used
| Component | Quantity | Description |
|------------|-----------|-------------|
| ESP32 Dev Board | 1 | Main microcontroller |
| HC-SR04 Ultrasonic Sensor | 1 | Distance detection |
| 16x2 I2C LCD Display | 1 | Display messages |
| Jumper Wires | — | Connections |
| Breadboard | 1 | Prototype setup |

---

## ⚙️ Circuit Connections

| Component | ESP32 Pin | Notes |
|------------|------------|-------|
| HC-SR04 VCC | 5V | Power |
| HC-SR04 GND | GND | Common ground |
| HC-SR04 TRIG | GPIO 5 | Output from ESP32 |
| HC-SR04 ECHO | GPIO 18 | Input to ESP32 |
| LCD SDA | GPIO 21 | I2C data |
| LCD SCL | GPIO 22 | I2C clock |
| LCD VCC | 5V | Power |
| LCD GND | GND | Ground |

*(You can include a circuit image in the `/images` folder later.)*

---

## 📲 Bluetooth Setup

1. Upload the `.ino` file to your ESP32.
2. Open Serial Monitor (`115200 baud`).
3. On your phone:
   - Open **Serial Bluetooth Terminal** app.
   - Pair and connect to **ESP32_Bus_Alert**.
4. When the sensor detects an object:
   - The LCD shows: `Bus is coming!`
   - Your phone receives: `🚍 Alert: Bus is coming!`

---

## 🔧 Optional Upgrades
- Add **RTC (DS3231)** to show date & time.
- Send **SMS or IoT alerts** using ESP32 Wi-Fi.
- Display live distance readings on LCD.
- Add a **buzzer** or LED for local alerts.

---

## 📜 License
MIT License — free to modify and share.
