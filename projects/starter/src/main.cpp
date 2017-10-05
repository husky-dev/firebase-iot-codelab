#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WebServer.h>
#include <FirebaseArduino.h>
#include <DHT.h>

// Sensor configs
#define DHTPIN 5
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
// WiFi configs
#define WIFI_SSID "SSID"
#define WIFI_PASSWORD "PASSWORD"
// Firebase configs
#define FIREBASE_HOST "example.firebaseio.com"

void setup(){
  // Starting serial port
  Serial.begin(115200);
  // Connect to the WiFi
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("Connected: ");
  Serial.println(WiFi.localIP());
  // Connecting to the Firebase
  Firebase.begin(FIREBASE_HOST);
  // Start listening DHT sernsor
  Serial.println("Starting DHT sernsor");
  dht.begin();
}

void loop(){
  // Init delay for gave time for the sensor
  // to prepare data
  delay(3000);
  // Reading data
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  // Cheis ck is data is correct
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  // Showing reveived data
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(", temperature: ");
  Serial.println(t);
  // Writing data to the Firebase
  Firebase.setFloat("temperature", t);
  if (Firebase.failed()) {
      Serial.print("Setting data failed");
      return;
  }
  Firebase.setFloat("humidity", h);
  if (Firebase.failed()) {
      Serial.print("Setting data failed");
      return;
  }
  Serial.println("Data has been updated");
}
