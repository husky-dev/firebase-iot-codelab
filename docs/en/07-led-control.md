# LED control

Our next task - learn how to control a RGB LED through the Firebase.

![Led pins](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image32.png)

We will use a three-color LED with a common anode. It can be imagined in the form of three LEDs, which has shared "+", but disconnected "-". In order to turn on the required LED, you must submit for its output "-", and for all other "+". The longest output is the common +, the shorter the right is red, the first to the left is blue, the second to the left is green. Install LED on breadbord and connect four wires. For convenience, in our example, we connected yellow wire to the total "+" (the longest output), and red, green, and blue - to the corresponding LED outputs. The same is recommended for you.

![Led connection](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image15.png)

Power on your board. Connect the common wire (yellow) to any pin of the board labled "3V" (3.3V). Connect one by one each of the other LEDs to the output of the `G` (minus) of the device. If everything was done correctly, different colors will turn on.

Now let's move on to the task our. First of all, we need to connect the LED to our board. You can select for this three any GPIO outputs. In the example below we chose `D5` (` GPIO14`), `D6` (` GPIO12`), `D7` (` GPIO13`). The common wire (yellow) we connected to the neighboring output `3V`.

![Led connection](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image23.png)

Let's write a small program to check if everything is working.

```c++
#include <Arduino.h>

// Constans with the numbers of pins
#define RED_PIN 13
#define GREEN_PIN 14
#define BLUE_PIN 12

// help function for turning on the LED
// as we have a LED with a common anode then
// for its turning on it is necessary to set it to
// minus (zero)
void ledOn(byte pin){
    digitalWrite(pin, LOW);
}

// accordingly for the exception it is necessary to set
// plus 3.3V (one)
void ledOff(byte pin){
    digitalWrite(pin, HIGH);
}

// function for turning off all LEDs
void ledsOff(){
    ledOff(RED_PIN);
    ledOff(GREEN_PIN);
    ledOff(BLUE_PIN);
    Serial.println("All leds OFF");
}

// turn on red
void redLedOn(){
    ledOn(RED_PIN);
    Serial.println("Red led ON");
}

// turn on green
void greenLedOn(){
    ledOn(GREEN_PIN);
    Serial.println("Green led ON");
}

// turn on blue
void blueLedOn(){
    ledOn(BLUE_PIN);
    Serial.println("Blue led ON");
}

void setup(){
    // Set up serial port
    Serial.begin(115200);
    // Configure pins for output
    pinMode(RED_PIN, OUTPUT);
    pinMode(GREEN_PIN, OUTPUT);
    pinMode(BLUE_PIN, OUTPUT);
    // just in case, turn off all pins
    ledsOff();
}

void loop(){
    // turn on red and wait 1s
    redLedOn();
    delay(1000);
    // turn off all
    ledsOff();
    // turn on green and wait 1s
    greenLedOn();
    delay(1000);
    // turn off all
    ledsOff();
    // turn on blue and wait 1s
    blueLedOn();
    delay(1000);
    // turn off all
    ledsOff();
    // start from the beginning
}
```

Run the program and check that everything is working.

Now it's time to connect the device to Firebase and get the color of the LED from there. Open the Firebase admin panel and add a new entry:

![Adding new record](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image44.png)

You can copy the connection code to the WiFi and Firebase from the previous project or from the folder `%repository%/projects/firebase-rgb-led` downloaded from the repository. The basic code will look like this:

```c++
// Here we will save the previous value
// received from the Firebse so you do not switch the LEDs
// every time when we get the same data from Firebase
String prevLedVal;

void loop(){
    // Get a string that is stored
    // at path /led
    String val = Firebase.getString("led");
    // Check for errors
    if (Firebase.failed()) {
        Serial.println("Getting data failed");
        delay(2000);
        return;
    }
    // If the new value is different from the previous one
    // then update the state of the LED
    if(val != prevLedVal){
        Serial.println("New value: ");
        Serial.println(val);
        // Turn off all the LEDs
        ledsOff();
        // Check the obtained value and turning on
        // the necessary LED
        if(val == "red"){
            redLedOn();
        }else if(val == "green"){
            greenLedOn();
        }else if(val == "blue"){
            blueLedOn();
        }
        // Keep received value in order to avoid repeating
        prevLedVal = val;
    }
}
```

Change the record value in the database to `red`, `blue`, `off` and check if everything works correctly.
