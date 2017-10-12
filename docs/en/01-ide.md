# Setting up the environment

We can use the standard Arduino editor for writing code for ESP8266. But this editor is far from those editors that we used to use in our daily work. Therefore, to improve code work, we will use the Atom + plugin for PlatformIO.

[PlatformIO](http://platformio.org/) in its original form it was a simple console utility that allowed you to compile your C++ code into the firmware and upload it to your device. The utility supports a large list of chips, including ESP8266. The main idea of the platform is the ability to write code once and use it at the various platforms. The utility is written in Python, so it can be used both on the local computer and at the server ([continuous integration](https://en.wikipedia.org/wiki/Continuous_integration)).

PlatformIO has a specialized plug-in for the Atom editor, which transforms it into a complete IDE for IoT devices. That is what we will use for our codelab.

Please check the ["Possible errors"](#Possible-errors) section before installing all software. This can save you time. For more details, the process of installing the plugin for all operating systems is described on the PlatformIO website:  [http://docs.platformio.org/en/latest/ide/atom.html](http://docs.platformio.org/en/latest/ide/atom.html)

## Windows

Download and install Atom from the official site [https://atom.io/](https://atom.io/). Launch the editor. Click "Install a Package" and "Open Installer".

![Atom](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image36.png)

Find the "platformio-ide" plug-in in the search and install it. If the editor will ask you to install Clang - click "Disable Code Completion" (you can install it later). Install all the necessary dependencies if the editor will prompt some. Reboot the editor.

![Atom](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image3.png)

### Driver setup

If you are using Windows 10 and you have Windows Update Automatic Driver Finder enabled, you probably do not need to install the driver manually. But it's better to check it.

1. Plug the board into your computer.
2. Click `Win + R` (або "Start" - "Run"), type command `devmgmt.msc`, and click OK.

![win-perform](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image4.png)

3. Find the section "Ports (COM and LPT)" and make sure you see the device with named "USB-SERIAL CH340 (COM*)" (you can have different COM port number).

![win-device](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image60.png)

If you did not find the port of the device - most likely the driver is not installed and does not downloaded from Windows Update, and you can see in the device manager like this:

![win-unknow-device](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image13.png)
        
4. Follow the link [https://github.com/nodemcu/nodemcu-devkit/blob/master/Drivers/CH341SER_WINDOWS.zip](https://github.com/nodemcu/nodemcu-devkit/blob/master/Drivers/CH341SER_WINDOWS.zip), download and install the driver (download the archive, unpack it and run the driver installation file (there's only one there), it will ask the administrator premissions - agree, and click "INSTALL" in the driver installation main window).

![win-driver](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image45.png)

Repeat steps 1-3 to check if the driver is inserted.

## MacOS

Download and install Atom from the official site [https://atom.io/](https://atom.io/). Launch the editor. Click "Install a Package" and "Open Installer".

![atom](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image9.png)

Find the "platformio-ide" plug-in in the search and install it. If the editor will ask you to install Clang - click "Disable Code Completion" (you can install it later). Install all the necessary dependencies if the editor will prompt some. Reboot the editor.

![atom](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image16.png)

### Driver setup

In order to connect to our board, we will need a specialized driver:

1. Go to the driver repository page CH340: [https://github.com/adrianmihalko/ch340g-ch34g-ch34x-mac-os-x-driver](https://github.com/adrianmihalko/ch340g-ch34g-ch34x-mac-os-x-driver)
2. Download the `CH34x_Install_V1.3.pkg` file from the repository.
3. Run the terminal.
4. Just in case, run the next commands to clear the previous version of the driver:

```bash
sudo rm -rf /System/Library/Extensions/usb.kext
sudo rm -rf /Library/Extensions/usbserial.kext
```

5. Restart your computer.
6. Double-click on the file `CH34x_Install_V1.3.pkg`. Install the driver.
7. Restart your computer.

## Linux

Go to the Atom editor site [https://atom.io/](https://atom.io/) and download the version according to your distribution:

- DEB - for Ubuntu, Mint, Debian, etc.
- RPM - for Fedora, Red Hat, OpenSUSE, etc.

For other distributions, the package can be found here: [https://github.com/atom/atom/releases/tag/v1.21.0](https://github.com/atom/atom/releases/tag/v1.21.0).

If you are using an ArchLinux-like distribution (ArchLinux, Manjaro, Antergos, Alpine) you can install Atom from a custom repository:

```bash
yaourt -S atom-editor-bin
```

If you have Gentoo - you have to now how to install Atom by your self :)

Linux does not require installation of additional drivers. When you will connect the board to your computer, Linux will create a device file in `/dev/ttyUSB0`.

Plug in the board and make sure that everything is working:

```bash
ls /dev | grep -i ttyusb
```

Also, depending on the distribution and the device access settings, you can receive an errors during the uploading  code to the device due to the lack of rights to write to the device. As a "hot fix" you can grant free access rights to all users to the device:

```bash
sudo chmod 666 /dev/ttyUSB0
```

Launch the editor. Click "Install a Package" and "Open Installer".

![atom](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image9.png)

Find the "platformio-ide" plug-in in the search and install it. If the editor will ask you to install Clang - click "Disable Code Completion" (you can install it later). Install all the necessary dependencies if the editor will prompt some. Reboot the editor.

![atom](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image16.png)

## Possible errors

After installing the plugin, Atom may ask to install Clang for auto-completion of the code. In this codelub you can ignore this message.

![clang-err](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image41.png)

You can ignore this by clicking "Remind Later".

You can also get the following error:

![atom-err](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image5.png)

You can ignore it.

More about how to install Clang under your operating system can be found here: [http://docs.platformio.org/en/latest/ide/atom.html#ii-clang-for-intelligent-code-completion](http://docs.platformio.org/en/latest/ide/atom.html#ii-clang-for-intelligent-code-completion).

## First project

Connect your device to the computer.

![nodemcu-connect](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image11.png)

Launch Atom and create a new PlatformIO project:

![platformio-new-project](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image53.png)

As a board choose "NodeMCU 1.0 (ESP-12E Module)".

![atom-nodemcu](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image26.png)

After creating of the project, you can close all unneeded tabs windows. Open the file `src/main.cpp`:

![atom-main](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image34.png)

Our next step is to write the simplest program and upload it to our device.

Another point worth mentioning before starting to write a code. You can see that each pin of our scheme has a label (`A0`, `G`, `VU`, `D0` - `D8` etc.):

![node-pins](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image30.png)

Each output has its own function. To know exactly what function of the pin we will need this scheme (googling by a phrase "nodemcu v3 pinout"):

![nodemcu-pinout](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image22.png)

[[open image]](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image22.png)

In this lab we will actively use GPIO outputs (General-purpose input / output). If we in the code using pin number 2, it's means that we are using `GPIO2` (`D4` at the board), but not `D2`. `D0`-`D8` - this is names of the border pins, but not the chip. Therefore, whenever you use pin numbers in the code, check with this scheme (or better save it). Pins `D#` can confuse you.

To test our code will blink with the LED on the board. It is connected to `GPIO2`. Replace the default code with the one below. Read the comments if you are work with the code for Arduino first time:

```c++
// Connect the standard Arduino library
// which allows us using the
// standart methods and constants
#include <Arduino.h>
// define - allows us to create a constant
// It's bad idea to use raw numbers in the code.
// it can be confusing.
// During the compilation
// compilator will exchange the name of the constant by it's value.
// Our led connected to the GPIO2 of our board
#define ONBOARD_LED_PIN 2
// There are two main functions in the code for Arduino - setup and loop.
// Code in the setup will perform right after receiving the power.
// Usually it performs various initialization
void setup(){
    // To use any of the pins
    // you have to initialize it and set the mode in which it will
    // work: input or output. If we want to control led -
    // it should be configured as output. For reading the data
    // of the button (pressed or not) we have to configure pin to the input.
    // INPUT and OUTPUT - usual constans (0 and 1) which defined by #define directive
    // in the Arduino.h file
    pinMode(ONBOARD_LED_PIN, OUTPUT);
}
// Code in the loop will run right after setup.
// This method has the main firmware code.
// As you can understand from the name, the method will
// repeat after it completion again, again and again
void loop(){
    // For the setting the value at the pin
    // you have to use digitalWrite(pin, value) method
    // HIGH, LOW - it's a usefull constants from the Arduino.h (1 and 0 respectively).
    // when we are setting pin to 1 - it's will receive the power (+3.3V)
    // when turning off the power will disappears (GND)
    digitalWrite(ONBOARD_LED_PIN, HIGH);
    // delay - stops the program for the time specified in milliseconds
    // 1s = 1000ms
    delay(1000);
    // Turn off the LED
    digitalWrite(ONBOARD_LED_PIN, LOW);
    // Waiting for one seccond
    delay(1000);
    // After completion, the program will re-launch the loop function
    // and the program will start again
}
```

Click the compilation button and wait until your code is compiled. If you did not make any mistakes, you will see a message about successful compilation:

![success-compilation](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image56.png)

Then click the button to upload the firmware:

![success-compilation](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image8.png)

If everything was set up correctly, you will see how the board starts flashing and yow will see the uploading process at the bottom of the editor.

After successful flashing, the device restarts and starts blinking once a second.

[Next: Debugging](02-debugging.md)
