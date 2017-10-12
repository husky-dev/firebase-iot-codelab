# Micro servo

To better demonstrate the algorithm for reading data from the database, we will use a servo drive.

![Servo](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image14.png)

The servo drive is a special engine that can only rotate 180 degrees. His main task is to keep the angle that you set to him. For example, if we set the angle to 45 degrees, then he will set this angle and will do everything to keep him, even if you try to bring it back by force.

WARNING! Please do not scroll the servo manually by hands. This can destroy the pinions of his gear.

An example of using a servo drive can be an elephant aircraft, which rises up and down by the pilot's command, and tries to keep the required angle. Of course, these planes use more sophisticated mechanisms than servo drives. But in radio-controlled models they use it.

![Wing](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image31.png)
 
## Connection

The servo has three outputs: `VCC` (power suply +5V, red), `GND` (ground, brown or black) and `DATA` (orange). Accordingly, the red one must be connected to the pin `3V` of our device, brown -> `G`, and orange to the control pin, in this example `D2` (`GPIO4`).

![Connect micro servo to the NodeMCU](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image19.png)

## Code

The library for servo control is already built in into the standard library for Arduino. Below is the minimum code for servo control. You can add it to an existing project or create a new one.

```c++
#include <Arduino.h>
#include <Servo.h>

#define SERVO_PIN 4

Servo myServo;

void setup(){
    // Starting serial port
    Serial.begin(115200);
    // Init servo
    myServo.attach(SERVO_PIN);
}
void loop(){
    Serial.println("Setting angle: 0");
    myServo.write(0);
    delay(2000);
    Serial.println("Setting angle: 90");
    myServo.write(90);
    delay(2000);
    Serial.println("Setting angle: 180");
    myServo.write(180);
    delay(2000);
}

In the example below, the servo will be rotated by two degrees every 100 ms and then returned to its original state:

```c++
for(int i = 0; i < 90; i++){
    myServo.write(i*2);
    delay(100);
    Serial.print("Setting angle: ");
    Serial.println(i * 2);
}
myServo.write(0);
delay(1000);
```

In the next section, we will learn how to control a servo with the Firebase.

[Next: Getting data from the Firebase](06-getting-data-from-firebase.md)
