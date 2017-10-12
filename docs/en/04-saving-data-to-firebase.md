# Saving data to the Firebase

Для початку нам необхідно створити новий проект в Firebase. Переходимо по посиланню [https://console.firebase.google.com](https://console.firebase.google.com) і тиснемо "Add project".

![Add firebase project](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image47.png)

Вкажіть будь-яке ім’я для проекту (наприклад MyFirebaseProject) і оберіть ваш регіон. Натисніть "Create Project". Перед вами відкриється панель керування вашим проектом.

Раніше під назвою Firebase розумілась тільки NoSQL база даних. Наразі це цілий набір сервісів таких як: авторизація, хостинг, зберігання файлів, аналітика, тощо. Цей набір дозволить вам створювати свої додатки та серверну частину для IoT пристроїв без зайвих думок про написання коду. У цій лабораторній роботі в основному ми будемо використовувати саме базу даних. Перейдіть на вкладку Database.

![Firebse database](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image10.png)

Перейдіть на вкладку "Rules" і змініть правила доступу на приведені нижче. Не забудьте натиснути "PUBLISH" щоб зберігти зміни.

![Publish rules](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image40.png)

Дані правила відключать необхідність авторизуватись, щоб зчитувати/записувати дані. Процес авторизації пристрою більш складний, тому виходить за рамки цієї лабараторної. Але майте на увазі: з вимкненою авторизацією будь-хто зможе записувати і зчитувати ваші дані.

Надалі ми будемо використовувати вже налаштований проект з встановленою та трохи модифікованою бібліотекою для роботи з Firebase. Завантажте репозиторій за посиланням: [https://github.com/snipter/firebase-iot-codelab](https://github.com/snipter/firebase-iot-codelab).

![Repo](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image6.png)

Завантажте та разархівуйте файли. Перейдіть назад в Atom. Можете закрити попередній проект, клікнувши на ньому правою кнопкою.

![Remove unneded projects](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image61.png)

За допомогою кнопки у панелі інструментів перейдіть на домашню сторінку PlatformIO та натисніть "Open Project".

![Open project](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image33.png)

Відкрийте проект, який знаходиться `%папка_репозиторію%/projects/firebase-termo-sensor`. Проект повинен з’явитись зліва на панелі проектів:

![Projects list](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image52.png)

Скомпілюйте проект та перевірте, щоб він не видавав помилок. В даному проекті в папці lib лежить бібліотека, яка полегше нам роботу з Firebase. Бібліотека для роботи з датчиком температури повинна бути встановлена ще з минулого кроку (вона встановлюється глобально).

![Firebase lib](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image37.png)

Перегляньте код та прочитайте коментарі. Тут з’являється код підключення до мережі WiFi та запису даних в базу Firebase. Для того, щоб підключитись до точки доступу WiFi, вам треба змінити `WIFI_SSID` та `WIFI_PASSWORD` на відповідні значення. Наприклад:

```c++
#define WIFI_SSID "WiFiNetworkName"
#define WIFI_PASSWORD "WiFiNetworkPassword"
```

Далі вам необхідно вказати посилання на базу даних в константі `FIREBASE_HOST`. Для цього просто скопіюйте ID вашого проекту з адмін-панелі Firebase. У моєму випадку це `myfirebaseproject-a5af3`.

![Project link](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image43.png)

Далі вставте цей ID замість слова example, а частину з ".firebaseio.com" залиште. У вас повинен вийти рядок наступного вигляду:

```C++
#define FIREBASE_HOST "myfirebaseproject-a5af3.firebaseio.com"
```

Скомпілюйте проект,  завантажте його на свій пристрій та запустіть монітор послідовного інтерфейсу.  Якщо все ок, то ви побачите, що девайс підключився до WiFi мережі і відправляє дані:

![Connection data](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image21.png)

Якщо ви будете бачити лише ряд крапок, то ще раз перевірте дані підключення до WiFi. У випадку, якщо дані з датчика будуть зчитуватись, але буде виникати помилка запису даних до Firebase - перевірте правильність написання посилання до вашої бази. Час від часу може виникати помилка зчитування даних з сенсору температури. Причиною цього можуть бути різні фактори - нестабільність живлення, відходження контактів, зовнішні перешкоди. Якщо дані будуть постійно зчитуватись з помилкою - перевірте надійність підключення сенсору та перезавантажте пристрій.

Перейдіть до адмін-панелі. Якщо ви все сконфігурували вірно, то побачите дані в своїй базі даних:

![Data in the Firebase](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image29.png)
 
Змініть температуру сенсора, нагрівши його, і ви побачите, як відповідно змінюються дані в базі. Можете очистити базу, клікнувши на кнопку "закрити" поруч з коренем бази. При наступному оновлені дані знову з’являться.

![Remove all data](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image28.png)

Таким же чином можна видаляти і окремі записи в базі.

![Remove some key](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image12.png)

Наш код можна покращити. Наразі кожного разу коли ми викликаємо команду Firebase.setFloat наш пристрій робить HTTP запит до бази. Запити можна об’єднувати. Так як вся база Firebase - це просто JSON об’єкт, то і дані в неї можна записувати в JSON форматі. Замініть код відправки даних в Firebase на наступний:

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

Скомпілюйте і запустіть код. Відкрийте термінал і подивіться які дані ми відправляємо через змінну `dataJson`. Строка `{".sv": "timestamp"}` в Firebase замінюється на `timestamp` - значення дати та часу записаного у форматі цілого числа. Таким чином, за допомогою поля `updated` ми завжди будемо знати, коли в останнє оновлювались дані.
Ще було б непогано зберігати історію зміни температури та вологості. Для цього в Firebase є спеціальний метод `push`. Додайте наступний код в кінець функції `loop`, прошийте свій девайс та перегляньте результат в базі.

```c++
Firebase.pushJsonString("sensor/history", dataJson);
if (Firebase.failed()) {
    Serial.print("Pushing data failed");
    return;
}
```

Тепер ви не тільки зможете дізнатись поточну температуру, але і переглянути історію зміни температури. Кожен запис зберігається з унікальним ID, котрий генерується самою базою.

![Data history](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image49.png)

[Next: Micro servo](05-micro-servo.md)
