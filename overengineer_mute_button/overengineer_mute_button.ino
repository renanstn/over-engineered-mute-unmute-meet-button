#include "WifiCredentials.h"
#include <ArduinoJson.h>
#include <WiFi.h>
#include <HTTPClient.h>


const int SERIAL_SPEED = 115200;
const int LED_BUILTIN = 2;
const int BUTTON_PIN = 15;
const char* serverName = "http://192.168.1.40:5000/shortcut";

WiFiClient wifiClient;


void setupWifi() {
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print("Connecting to WiFi:");
    Serial.println(WIFI_SSID);
  }
  Serial.println("Connected to the WiFi network");
  Serial.println();
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}


void sendRequest() {
  // Init http client
  HTTPClient http;
  http.begin(wifiClient, serverName);
  // Create JSON using ArduinoJson lib
  StaticJsonDocument<200> doc;
  doc["command"] = "mute_unmute_meet";
  String requestBody;
  serializeJson(doc, requestBody);
  // Add header and send request
  http.addHeader("Content-Type", "application/json");
  int httpResponseCode = http.POST(requestBody);
}


void setup()
{
  // Set PIN modes
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  // Start serial (only for debug)
  Serial.begin(SERIAL_SPEED);
  setupWifi();
}


void loop() {
  // Check connection
  if (WiFi.status() != WL_CONNECTED) {
     setupWifi();
  }
  // Check button
  int buttonState = digitalRead(BUTTON_PIN);
  if (buttonState == HIGH) {
    digitalWrite(LED_BUILTIN, HIGH);
    sendRequest();
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
  }
}
