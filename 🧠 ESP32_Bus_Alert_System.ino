#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "BluetoothSerial.h"

#define TRIG_PIN 5
#define ECHO_PIN 18

BluetoothSerial SerialBT;
LiquidCrystal_I2C lcd(0x27, 16, 2); // change if needed (use I2C Scanner)

void setup() {
  Serial.begin(115200);
  if (!SerialBT.begin("ESP32_Bus_Alert")) {
    Serial.println("❌ Bluetooth failed to start!");
    while (1);
  }
  Serial.println("✅ Bluetooth started. Ready to pair!");
  
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Bus Alert System");
  lcd.setCursor(0, 1);
  lcd.print("Initializing...");
  delay(2000);
  lcd.clear();

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  // Send pulse
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Measure distance
  long duration = pulseIn(ECHO_PIN, HIGH);
  float distance = duration * 0.034 / 2; // in cm

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance > 2 && distance < 30) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Bus is coming!");
    Serial.println("Bus is coming!");
    SerialBT.println("🚍 Alert: Bus is coming!");
  } else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("No bus detected");
  }

  delay(1000);
}
