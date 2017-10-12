# Debugging

The serial interface built into ESP8266 allows you to transfer data from the device to your computer and vice versa. We will actively use this interface to debug our programs.

The ESP8266 uses the UART interface for the data exchange. It is more commonly known as the COM port, which could be found on older computers. CH340 allows you to convert UART interface to USB.

For using the interface, we need to slightly modify our program:

```c++
#include <Arduino.h>

#define ONBOARD_LED_PIN 2

void setup(){
    pinMode(ONBOARD_LED_PIN, OUTPUT);
    // Initializing the serial interfase. We have to provide
    // interface speed to the begin method.
    // If you will see the strange symbols in the terminal -
    // it's can be coused by setting different speed in the
    // code and IDE
    Serial.begin(115200);
}

void loop(){
    digitalWrite(ONBOARD_LED_PIN, HIGH);
    // Serial.println displays a string in the console with a hyphen sign
    // at the end of the row. Try to use Serial.print (without ln) and
    // see the difference
    Serial.println("led on");
    delay(1000);
    digitalWrite(ONBOARD_LED_PIN, LOW);
    Serial.println("led off");
    delay(1000);
}
```

Compile and upload the program as we did before. Open the serial interface monitoring window by clicking this button:

![serial-monitor](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image24.png)

Make sure that the correct port is selected  (may not appear immediately) and that the selected speed matches the speed you specified in the program code.

![select-port](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image7.png)

This will open a window where you can view the log of your program's execution.

![termo-data](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image17.png)

[Next: Temperature and humidity sensor](03-temperature-and-humidity-sensor.md)
