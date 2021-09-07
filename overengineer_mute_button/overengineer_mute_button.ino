#include <ArduinoJson.h>
#include <WiFi.h>
#include <HTTPClient.h>


const char* WIFI_SSID = "ssid";
const char* WIFI_PASSWORD = "pass";
const int SERIAL_SPEED = 115200;
const int LED_BUILTIN = 2;
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


void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(SERIAL_SPEED);
  setupWifi();
  HTTPClient http;
  http.begin(wifiClient, serverName);
  http.addHeader("Content-Type", "application/json");
  // Create JSON using ArduinoJson lib
  StaticJsonDocument<200> doc;
  doc["command"] = "mute_unmute_meet";
  String requestBody;
  serializeJson(doc, requestBody);
  // Send request
  int httpResponseCode = http.POST(requestBody);
}

void loop() {}

// void loop()
// {
//   if (WiFi.status() != WL_CONNECTED) {
//     setupWifi();
//   }

//   digitalWrite(LED_BUILTIN, HIGH);
//   delay(1000);
//   digitalWrite(LED_BUILTIN, LOW);
//   delay(1000);
// }
