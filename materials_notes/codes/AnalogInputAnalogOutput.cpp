#include <LiquidCrystal.h>

// LCD pin connections: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// ADC input pin
const int sensorPin = A0;

// PWM output pin (must be PWM-capable)
const int pwmPin = 9;

void setup() {
  pinMode(sensorPin, INPUT);
  pinMode(pwmPin, OUTPUT);

  Serial.begin(9600);

  lcd.begin(16, 2);
  lcd.print("ADC to PWM");
  delay(2000);
  lcd.clear();
}

void loop() {
  // Read ADC value (10-bit: 0–1023 on Arduino Uno)
  int adcValue = analogRead(sensorPin);

  // Map ADC (0–1023) to PWM (0–255)
  int pwmValue = map(adcValue, 0, 1023, 0, 255);

  // Generate PWM output
  analogWrite(pwmPin, pwmValue);

  // Convert ADC to voltage (5V reference)
  float voltage = adcValue * (5.0 / 1023.0);

  // LCD Display
  lcd.setCursor(0, 0);
  lcd.print("ADC: ");
  lcd.print(adcValue);
  lcd.print("   ");

  lcd.setCursor(0, 1);
  lcd.print("PWM: ");
  lcd.print(pwmValue);
  lcd.print("   ");

  // Serial Monitor
  Serial.print("ADC: ");
  Serial.print(adcValue);
  Serial.print(" | PWM: ");
  Serial.print(pwmValue);
  Serial.print(" | Voltage: ");
  Serial.print(voltage, 2);
  Serial.println("V");

  delay(500);
}