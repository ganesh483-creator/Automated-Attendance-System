#include <WiFiClientSecure.h>
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <WiFiClientSecureBearSSL.h>


const char* ssid = "Shanmukha";
const char* password = "$king007$1";
const char* web_app_url = "https://script.google.com/macros/s/AKfycbwhi1khkiK4zNZFKSkeH2OF2ac9qnr21HU8uDh7mf5dIFnbklwnZoIn_xQtQ7D-LRCi_w/exec";


void setup() {
Serial.begin(115200);
WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED) {
delay(1000);
Serial.println("Connecting to WiFi...");
}
Serial.println("Connected to WiFi");
}
void loop() {
int num_networks = WiFi.scanNetworks();
Serial.println("Scanning for WiFi networks...");
if (num_networks == 0) {
Serial.println("No WiFi networks found");
return;
}
for (int i = 0; i < num_networks; i++) {
String network_name = WiFi.SSID(i);
String mac_address = WiFi.BSSIDstr(i);
Serial.print("Network name: "); Serial.println(network_name);
Serial.print("MAC address: "); Serial.println(mac_address);
String url = web_app_url + "?data1=" + network_name + "&data2=" + mac_address;
Serial.println(url);
Serial.println("Sending data to Google Sheets...");


std::unique_ptr<BearSSL::WiFiClientSecure> client(new BearSSL::WiFiClientSecure);
client->setInsecure();
HTTPClient https;
if (https.begin(*client, (String)url)) {
int httpCode = https.GET();
if (httpCode > 0) {
Serial.printf("[HTTPS] GET... code: %d\n", httpCode);
} else {
Serial.printf("[HTTPS] GET... failed, error: %s\n", https.errorToString(httpCode).c_str());
}
https.end();
delay(1000);
} else {
Serial.printf("[HTTPS] Unable to connect\n");
}
}
}