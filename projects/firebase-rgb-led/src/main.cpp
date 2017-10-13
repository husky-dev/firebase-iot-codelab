#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WebServer.h>
#include <FirebaseArduino.h>

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

#define RED_PIN 13
#define GREEN_PIN 14
#define BLUE_PIN 12

String prevLedVal;

void ledOn(byte pin){
  digitalWrite(pin, LOW);
}

void ledOff(byte pin){
  digitalWrite(pin, HIGH);
}

void ledsOff(){
  ledOff(RED_PIN);
  ledOff(GREEN_PIN);
  ledOff(BLUE_PIN);
  Serial.println("All leds OFF");
}

void redLedOn(){
  ledOn(RED_PIN);
  Serial.println("Red led ON");
}

void greenLedOn(){
  ledOn(GREEN_PIN);
  Serial.println("Green led ON");
}

void blueLedOn(){
  ledOn(BLUE_PIN);
  Serial.println("Blue led ON");
}

void setup(){
  // Starting serial port
  Serial.begin(115200);
  // Init pin
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  ledsOff();
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
}

void loop(){
  String val = Firebase.getString("led");
  // Check if operation succeed
  if (Firebase.failed()) {
      Serial.println("Getting data failed");
      delay(2000);
      return;
  }
  if(val != prevLedVal){
    Serial.print("New value: ");
    Serial.println(val);
    ledsOff();
    if(val == "red"){
      redLedOn();
    }else if(val == "green"){
      greenLedOn();
    }else if(val == "blue"){
      blueLedOn();
    }
    prevLedVal = val;
  }
}
