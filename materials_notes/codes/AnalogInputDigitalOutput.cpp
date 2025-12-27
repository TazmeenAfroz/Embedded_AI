#include <LiquidCrystal.h>

// LCD pin connections: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// 12-bit ADC sensor pin (analog input)
const int sensorPin = A0;

void setup() {
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);

  lcd.begin(16, 2);
  lcd.print("12-bit ADC");
  delay(2000);
  lcd.clear();
}

void loop() {
  // Read analog value (12-bit: 0-4095)
  // Note: Standard Arduino has 10-bit ADC, for true 12-bit
  int sensorValue = analogRead(sensorPin);

  // For 12-bit ADC
  float voltage = sensorValue * (3.3 / 4095.0);  // Assuming

  // Display on LCD
  lcd.setCursor(0, 0);
  lcd.print("Raw: ");
  lcd.print(sensorValue);
  lcd.print("    ");  // Clear extra chars

  lcd.setCursor(0, 1);
  lcd.print("V: ");
  lcd.print(voltage, 2);
  lcd.print("V   ");

  // Serial Monitor output
  Serial.print("12-bit ADC - Raw: ");
  Serial.print(sensorValue);
  Serial.print(" | Voltage: ");
  Serial.print(voltage, 2);
  Serial.println("V");

  delay(500);
}
