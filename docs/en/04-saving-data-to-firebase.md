# Saving data to the Firebase

We need to create a new project in Firebase. Go to the link [https://console.firebase.google.com](https://console.firebase.google.com) and click "Add project".

![Add firebase project](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image47.png)

Specify any project name (for example MyFirebaseProject) and choose your region. Click "Create Project". You will see the your dashboard.

Previously, Friebase was just NoSQL database. For now it's a big set of the services such as: authorization, hosting, file storage, analytics, etc. This set will allow you to create your own applications and server side for IoT devices without having to worry about writing code. In this codelab we will basically use the database. Click the Database tab.

![Firebse database](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image10.png)

Click the "Rules" tab and change the access rules to the rules below. Do not forget to click "PUBLISH" to save the changes.

![Publish rules](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image40.png)

These rules will disable the need to authenticate for read/write data. The process of authorizing the device is more complex, so it goes beyond the topic of this lab. But keep in mind: anyone with off authorization will be able to write and read your data.

We will use the already configured project with the installed and slightly modified library for working with Firebase. Download the repository at the link: [https://github.com/snipter/firebase-iot-codelab](https://github.com/snipter/firebase-iot-codelab).

![Repo](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image6.png)

Download and unzip files. Go back to Atom. You can close the previous project by clicking on it with the right button.

![Remove unneded projects](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image61.png)

By using the button in the toolbar, go to the PlatformIO home page and click "Open Project".

![Open project](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image33.png)

Open the project that is located at `%repository%/projects/firebase-termo-sensor`. The project should appear at the project panel:

![Projects list](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image52.png)

Compile the project and make sure it does not have any error. There is a library in the lib folder that makes it easier for us to work with Firebase. The library for working with the temperature sensor should be installed from the previous section (it is installed globally).

![Firebase lib](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image37.png)

View the code and read the comments. Here comes the connection to the WiFi network and writing data to the Firebase . In order to connect to the WiFi access point, you need to change `WIFI_SSID` and` WIFI_PASSWORD` to the corresponding values. For example:

```c++
#define WIFI_SSID "WiFiNetworkName"
#define WIFI_PASSWORD "WiFiNetworkPassword"
```

Next you need to specify a reference to the database in the constant `FIREBASE_HOST`. To do this, just copy the ID of your project from the Firebase admin panel. In my case it is `myfirebaseproject-a5af3`.

![Project link](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image43.png)

Then insert this ID instead of the word `example`, and leave a part of ".firebaseio.com". You must have a code like this:

```C++
#define FIREBASE_HOST "myfirebaseproject-a5af3.firebaseio.com"
```

Compile the project, upload it to your device, and run the serial interface monitor. If everything is ok then you will see that the device connects to the WiFi network and sends the data:

![Connection data](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image21.png)

If you see only a few rows with dots, then check your Wi-Fi data again. If you will receive data from the sensor but  will see an error writing the data to Firebase - check the correctness of the link to your database. From time to time you can see an error reading data from the sensor. The reason for this may be different factors - instability of the power supply, the disconnection of contacts, external barriers. If the data will be read out continuously, check the reliability of the sensor connection and reboot the device.

Go to the admin panel. If you have configured everything correctly, then you will see the data in your database:

![Data in the Firebase](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image29.png)
 
Change the temperature of the sensor by heating it, and you will see how the data in the database changes respectively. You can clear the database by clicking on the "close" button next to the root key of the base. The next update will reappear data.

![Remove all data](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image28.png)

In the same way, you can delete individual records in the database.

![Remove some key](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image12.png)

Our code can be improved. Currently, every time when we call the `Firebase.setFloat()` command, our device makes an HTTP request to the database. Queries can be combined. Since the entire Firebase database is simply a JSON object, then the data in it can be written in JSON format. Change the code which sending data to the Firebase to the next one:

```c++
// Writing data to the Firebase
String serverTimestamp = "{\".sv\": \"timestamp\"}";
String temperatureStr = String(t);
String humidityStr = String(h);
String dataJson = "{\"temperature\": " + temperatureStr + ", \"humidity\": " + humidityStr + ", \"updated\": " + serverTimestamp + "}";
Serial.println("Sending JSON data: " + dataJson);
Firebase.setJsonString("sensor/current", dataJson);
if (Firebase.failed()) {
    Serial.print("Setting data failed");
    return;
}
Serial.println("Data has been updated");
```

Compile and run the code. Open the terminal and look what data we send through the variable `dataJson`. Sting `{".sv": "timestamp"}` will be replaced in the Firebase to `timestamp` - the value of the date and time recorded in the integer format. In this way, by using field `updated` we will always know when was the last update.
Also It would be nice to keep a history of changes in temperature and humidity. To do this, Firebase has a special method `push`. Add the following code at the end of the function `loop`, upload firmware to your device and look the result in the base.

```c++
Firebase.pushJsonString("sensor/history", dataJson);
if (Firebase.failed()) {
    Serial.print("Pushing data failed");
    return;
}
```

Now you can not only find out the current temperature, but also see the history of temperature changes. Each record stored with a unique ID, which is generated by the database itself.

![Data history](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image49.png)

[Next: Micro servo](05-micro-servo.md)
