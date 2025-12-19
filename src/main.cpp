// Libraries to include
#include <Arduino.h>

// Compiler defines

// Global variables
static constexpr int ADC_PIN = 34;  // GPIO34 (ADC1)

void setup() {
  
  Serial.begin(115200);  // Initialize the serial communication
  delay(200);  // Wait to ensure the setting

  pinMode(LED_BUILTIN, OUTPUT);  // Declares the builtin led as an output
  pinMode(ADC_PIN, INPUT);  // Declares the ADC pin as input
  Serial.println("ADC test starting...");
}

void loop() {
  // Reads the raw ADC data
  int raw = analogRead(ADC_PIN);
  // Convert it to volts
  float volts = (raw / 4095.0f) * 3.3f;

  // Format and write the readings through serial
  Serial.printf("\rRaw: %4i \tVolts: %.2f", raw, volts);
  // Delay for convinience
  delay(1);
}