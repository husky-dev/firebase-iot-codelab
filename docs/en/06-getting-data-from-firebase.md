# Getting data from the Firebase

Go to the admin panel and create a new entry with the path `servo/angle` with the value `0`. You can do this by clicking "+" next to the root of the database:

![Add new key](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image1.png)

Then click "ADD". A corresponding entry will be displayed in the database.

![Add new value](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image39.png)

![Add new value](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image57.png)

Our task is to get the value of the field "servo / angle" and turn our servo to the appropriate angle.

```c++
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WebServer.h>
#include <FirebaseArduino.h>
#include <Servo.h>

// WiFi configs
#define FIREBASE_HOST "*******************************.firebaseio.com" 
#define FIREBASE_AUTH "***************************"//Your Firebase Database Secret goes here
#define WIFI_SSID "Your_ssid"                                    //your WiFi SSID for which yout NodeMCU connects
#define WIFI_PASSWORD "Your_password"                              //Password of your wifi network 

// Servo
#define SERVO_PIN 4
Servo myServo;
int angle = 0;
int lastAngle = 0;

void setup(){
    // Starting serial port
    Serial.begin(9600);
    // Connect to the WiFi
    WiFi.begin(WIFI_SSID,WIFI_PASSWORD);
    Serial.print("Connecting");
    while (WiFi.status() != WL_CONNECTED) {
        Serial.print(".");
        delay(500);
    }
    Serial.println();
    Serial.print("Connected: ");
    Serial.println(WiFi.localIP());
    // Connecting to the Firebase
    Firebase.begin(FIREBASE_HOST,FIREBASE_AUTH);
    // Servo
    myServo.attach(SERVO_PIN);
   // myServo.write(0);
}
void firebasereconnect()
{
  Serial.println("Trying to reconnect");
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  }
void loop(){
   if (Firebase.failed())
      {
      Serial.print("setting number failed:");
      Serial.println(Firebase.error());
      firebasereconnect();
      return;
      }
    angle=Firebase.getString("servo/angle").toInt();
    /*if(Firebase.failed()) {
        Serial.println("Getting data from Firebase failed");
        delay(1000);
    }else*/ if (angle != lastAngle){
        Serial.print("Angle changed: ");
        Serial.println(angle);
        myServo.write(angle);
        lastAngle = angle;
  }
}
```

Compile the code and upload it to the device. Change the variable value in the Firebase through the admin panel. If everything was done correctly - your device will become "alive" and the servo drive will turn to a given angle.

![Servo angle in the Firebase](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image46.png)

![Changin servo angle](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image54.png)

[Next: LED control](07-led-control.md)
