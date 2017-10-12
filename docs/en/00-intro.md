# Intro

The popularity of the global network and lower prices for equipment gave the life for the concept of "Internet of Things".

Internet of things is a network consisting of interconnected physical objects (things) or devices. In fact, IoT device can be considered a device which is connected to a network and which can receive or provide the data. Usually, this devices connected to the one central server. But in more advanced networks, devices can communicate directly with each other.

Not so long time ago, with the creation of IoT at home were the following problems:

- Price of the devices.
- The complexity of writing a firmware.
- The need to write code for the server.
- The need to solder schemes.

Thanks to laziness, globalization and mass production, all these problems are resolved. The cost of IoT devices dropped to $ 2 - $ 4 per piece. There are many application development environments for the devices, and languages that make it much easier to write the firmware. I started my way to the IoT by writing code in assembler, and believe me - there was not much fun with it. =) . Now, everything is much easier.

The need to write code for the server also disappeared! For basic things, you will be enough to use already exists tools, such as [Firebase](https://firebase.google.com/). You no longer need a soldering iron and soldering ability in order to build a prototype of your device. For now, it's enough to have a breadboard and a bundle of wires.

The purpose of this code lab is to show that creating an IoT device is not a complicated task.

## Hardware

There are many ready-made devices and development kits for creating your own IoT device: Raspberry, Intel Edison, Intel Joule, NXP i.MX7D etc. These are high-end computers with relatively good processing power. But they have one drawback - the price. The use of these devices would be economically unprofitable in order to create simple IoT devices with a simple functionality. Therefore, we will use a simpler but no less functional WiFi module - ESP8266.

![ESP8266](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image58.png)

In fact, ESP8266 - is WiFi chip, which depending on the requirements can be found in different buildings and with different functionality.

![Varieties of ESP8266](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image48.png)

With a basic firmware, you can use this module to work with Wi-Fi and Internet by using [AT-commands](https://en.wikipedia.org/wiki/Hayes_command_set). Therefore, this module is often used as a WiFi module for Arduino. But the true steepness of this module is that you can upload your firmware and execute your program with it while being able to connect to the WiFi and exchange data with the server.

The module can work in three modes: WiFi client, access point, and both at once. In this lab, your device will have data for connecting to the WiFi router directly in your code. In more advanced versions, the device can start with its own access point in order to initialize the network connection. Next, the user connects to this access point and uses the mobile application or web page in order to enter the WiFi credentials. After a successful connection, the device turning off access point and goes into the client mode.

The manufacturer provides the SDK for writing firmware in C, so you can use it. But for more easier code writing, we will use a library that duplicates all Arduino library functions and methods. Therefore, the firmware code for ESP8266 will not be different from the code for Arduino.

ESP8266 is only a chip. We need additional electronic components and chips in order to provide power, usable USB connectivity and the ability to connect other devices. To avoid soldering, we will use an already-made board with all of this, based on ESP8266 - NodeMCU V3.

![NodeMCU V3](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image2.png)

All code in this lab is done in C.

## Requirements

In order to complete this lab, you will need:

- Computer (Mac/Win/Linux).
- NodeMCU V3.
- Temperature and humidity sensor DHT11.
- Micro servo.
- LED.
- Breadboard.
- Wires.

[Next: Setting up the environment](01-ide.md)
