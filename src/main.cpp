#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>
#include "secrets.h"

static constexpr int ADC_PIN = 34;          // ADC1 pin (Wi-Fi safe)
WebServer server(80);

int readAdcRaw() {
  return analogRead(ADC_PIN);              // 0..4095 (typical)
}

float rawToVolts(int raw) {
  return (raw / 4095.0f) * 3.3f;           // rough conversion
}

void handleRoot() {
  int raw = readAdcRaw();
  float v = rawToVolts(raw);

  // Tiny HTML response
  String html;
  html += "<!doctype html><html><head><meta charset='utf-8'>";
  html += "<meta name='viewport' content='width=device-width, initial-scale=1'>";
  html += "<title>ESP32 ADC</title></head><body>";
  html += "<h1>ESP32 ADC</h1>";
  html += "<p>Raw: " + String(raw) + "</p>";
  html += "<p>Volts (approx): " + String(v, 3) + " V</p>";
  html += "<p><a href='/'>Refresh</a></p>";
  html += "</body></html>";

  server.send(200, "text/html", html);
}

void setup() {
  Serial.begin(115200);
  delay(200);

  pinMode(ADC_PIN, INPUT);

  Serial.printf("\nConnecting to SSID: %s\n", WIFI_SSID);
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASS);

  while (WiFi.status() != WL_CONNECTED) {
    delay(250);
    Serial.print(".");
  }

  Serial.print("\nConnected. IP = ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.begin();
  Serial.println("HTTP server started (port 80).");
}

void loop() {
  server.handleClient();   // this is essential: processes incoming HTTP requests
}
