#include <Arduino.h>

void setup() {
  
  Serial.begin(115200);  // Initialize the serial communication
  delay(200);  // Wait to ensure the setting

  pinMode(LED_BUILTIN, OUTPUT);  // Declares the builtin led as an output
  Serial.println("Boot OK");

}

void loop() {
  // Declares an unsigned integer with 32bits and initialize it
  static uint32_t last = 0;
  
  // If 500ms passed
  if (millis() - last >= 500){
    // Update the current time
    last = millis();
    // Inverts the LED state
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    // Send through serial that the LED toggled
    Serial.println("Tick");
  }
}