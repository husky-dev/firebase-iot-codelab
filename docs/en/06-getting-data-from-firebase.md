# Getting data from the Firebase

Перейдіть в адмін панель Firebase та створіть новий запис з шляхом `servo/angle` зі значенням `0`. Це можна зробити натиснувши "+" поруч з коренем бази:

![Add new key](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image1.png)

Після чого натисніть "ADD". З’явиться відповідний запис в базі.

![Add new value](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image39.png)

![Add new value](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image57.png)

Наша задача - отримувати значення поля "servo/angle" та повертати наш сервопривід на відповідний кут.

```c++
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WebServer.h>
#include <FirebaseArduino.h>
#include <Servo.h>

// WiFi configs
#define WIFI_SSID "SomeSSID"
#define WIFI_PASSWORD "SomePass"

// Firebase configs
#define FIREBASE_HOST "example.firebaseio.com"

// Servo
#define SERVO_PIN 4
Servo myServo;
int angle = 0;
int lastAngle = 0;

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
    // Servo
    myServo.attach(SERVO_PIN);
    myServo.write(0);
}

void loop(){
    angle = Firebase.getInt("servo/angle");
    if(Firebase.failed()) {
        Serial.println("Getting data from Firebase failed");
        delay(1000);
    }else if(angle != lastAngle){
        Serial.print("Angle changed: ");
        Serial.println(angle);
        myServo.write(angle);
        lastAngle = angle;
  }
}
```

Скомпілюйте код та завантажте його на девайс. Змініть значення змінної в Firebase через адмін-панель. Якщо все було зроблено правильно - ваш девайс "оживе" і сервопривід почне повертатись на заданий кут.

![Servo angle in the Firebase](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image46.png)

![Changin servo angle](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image54.png)

[Next: LED control](07-led-control.md)
