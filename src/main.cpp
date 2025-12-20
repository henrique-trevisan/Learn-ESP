// Libraries to include
#include <Arduino.h>
#include <WiFi.h>
#include "secrets.h"

// Compiler defines

// Global variables


void setup() {
  
  Serial.begin(115200);  // Initialize the serial communication
  delay(200);  // Wait to ensure the setting

  Serial.printf("\nConnecting to SSID: %s\n", WIFI_SSID);
  WiFi.mode(WIFI_STA);  // Set the wifi as a station (client)
  WiFi.begin(WIFI_SSID, WIFI_PASS);  // Try to connect to the network using the SSID and password

  // Wait for the device to connect to Wi-Fi
  while (WiFi.status() != WL_CONNECTED) {
    delay(250);
    Serial.printf(".");
  }

  // Successfully connected to the WiFi with the given ip
  // Convert the local IPAddress object to an arduino string (the class string)
  // Convert the arduino string to a C language string (char*[])
  Serial.printf("\nConnected. IP = %s\n", WiFi.localIP().toString().c_str());
}

void loop() {
  // Delay for convinience
  delay(10);
}