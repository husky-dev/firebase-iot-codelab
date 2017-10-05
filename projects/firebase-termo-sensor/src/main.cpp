#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WebServer.h>
#include <FirebaseArduino.h>
#include <DHT.h>

// WiFi configs
#define WIFI_SSID "SSID"
#define WIFI_PASSWORD "PASSWORD"
// Firebase configs
// Change "example" to the ID of the project
// If you link to the admin panel looking like this
// https://console.firebase.google.com/project/myfirebaseproject-b6c78/overview
// then FIREBASE_HOST will look like this
// "myfirebaseproject-b6c78.firebaseio.com"
#define FIREBASE_HOST "example.firebaseio.com"
// Sensor configs
#define DHT_PIN 5
#define DHT_TYPE DHT11
DHT dht(DHT_PIN, DHT_TYPE);

void setup(){
  // Starting serial port
  Serial.begin(115200);
  // Connecting to the WiFi
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    // Printing single dot to the console and waiting
    // while status will changed to the WL_CONNECTED
    Serial.print(".");
    delay(500);
  }
  // Printing local IP address
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
  delay(2000);
  // Reading sensor data
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  // Check if is data is correct
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    // If not - making delay and trying agatin
    return;
  }
  // Printing received data to the console
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(", temperature: ");
  Serial.println(t);
  // Writing temperature to the Firebase with path "/temperature"
  Firebase.setFloat("temperature", t);
  // Check if operation succeed
  if (Firebase.failed()) {
      Serial.print("Setting data failed");
      return;
  }
  // Writing humidity to the Firebase with path "/humidity"
  Firebase.setFloat("humidity", h);
  // Check if operation succeed
  if (Firebase.failed()) {
      Serial.print("Setting data failed");
      return;
  }
  Serial.println("Data has been updated");
}
