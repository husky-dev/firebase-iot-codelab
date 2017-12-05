# Сенсор температури та вологості

Для отримання даних про температуру і вологість навколишнього середовища ми будемо використовувати сенсор DHT11.

![DHT11](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image25.png)

Як ви можете бачити у нього три виводи (підписи біля ніжок): VCC (+5V), GND (мінус або земля), DATA (вивід передачі даних). Для легкості підключення і збирання схеми ми будемо використовувати монтажну плату.

![breadboard](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image35.png)

Схема нижче дозволить вам краще зрозуміти, як вона працює. Червоними, синіми та чорними лініями показано, як поєднані між собою виводи.

![breadboard](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image18.png)

Зі схеми можна зрозуміти, що для того щоб підключити якийсь дріт до нашої плати, необхідно його ввімкнути поруч з відповідним виводом.

Для підключення сенсора в нашому прикладі необхідно підключити вивід `VCC` сенсора до виводу `3V` (живлення 3.3V) плати, `GND` з виводом `G` (мінус), а `DATA` з `D1` (`GPIO5`). Зазвичай для сенсорів і інших зовнішніх пристроїв обирають кольорові дроти, щоб було легше їх з’єднувати. Щоб полегшити задачу, найсвітліший використовують для дротів живлення (білий в прикладі), найтемніший - для `GND` (чорний), а інші для виводів керування та передачі даних. Підключаємо сенсор до плати.

![DHT11 connect](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image59.png)

![DHT11 breadboard connect](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image38.png)

Якщо все підключено правильно і плата увімкнена в USB - світлодіод на сенсорі засвітиться.

Переходимо до коду. Для роботи з сенсором нам необхідно встановити відповідну бібліотеку. Натисніть кнопку "Home" на панелі інструментів.

![platformio home](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image20.png)

Потім у новому вікні оберіть вкладку "Libraries".

![libraries](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image50.png)

За допомогою пошуку знайдіть бібліотеку "DHT sensor library" автора "Adafruit Industries":

![adafruit DHT11 library](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image51.png)

Натисніть на бібліотеку і встановіть її:

![install library](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image55.png)

Таким же чином необхідно встановити бібліотеку `Adafruit Unified Sensor`:

![Adafruit Unified Sensor](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image66.png)

Поверніться до вашого файлу main.cpp та додайте в нього наступний код:

```c++
#include <Arduino.h>
// Підключаємо бібліотеку котра допоможе нам
// з легкістю використовувати сенсор
#include <Adafruit_Sensor.h>
#include <DHT.h>
// Створюємо константи з номером піну
// на якому знаходиться наш сенсор та з його моделлю
#define DHT_PIN 5
#define DHT_TYPE DHT11
// Створюємо об’єкт класу DHT та зберігаємо
// у змінній dht. У якості параметрів передаємо номер піну
// та тип нашого сенсору
DHT dht(DHT_PIN, DHT_TYPE);

void setup(){
    Serial.begin(115200);
    Serial.println("DHTxx test!");
    // Запускаємо сканування сенсора
    dht.begin();
}

void loop(){
    // Робимо затримку між вимірами
    delay(2000);
    // Читання даних з сенсору займає 250мс!
    // Дані можуть бути застарілі на 2 секунди (це досить повільний сенсор).
    // Зчитуємо процент вологості
    float h = dht.readHumidity();
    // Зчитуємо температуру в Цельсіях (за замовчуванням)
    float t = dht.readTemperature();
    // Зчитуєм температуру в Фарингейтах (isFahrenheit = true)
    float f = dht.readTemperature(true);
    // Перевіряємо чи всі виміри вірні. Якщо
    // стається помилка зчитування, то код повертає значення
    // NaN (not a number - не число)
    // Помилки зчитування не рідкість. Існує багато факторів, котрі
    // можуть їх спричинити
    if (isnan(h) || isnan(t) || isnan(f)) {
        Serial.println("Failed to read from DHT sensor!");
        // Якщо хоч один з вимірі не вірний, то закінчуємо програму раніше
        // щоб зробити виміри заново
        return;
    }
    // Вираховуємо індекс нагрівання в Фарингейтах (за замовчуванням)
    float hif = dht.computeHeatIndex(f, h);
    // Вираховуємо індекс нагрівання в Цельсіях (isFahreheit = false)
    float hic = dht.computeHeatIndex(t, h, false);
    Serial.print("Humidity: ");
    Serial.print(h);
    Serial.print(" %\t");
    Serial.print("Temperature: ");
    Serial.print(t);
    Serial.print(" *C ");
    Serial.print(f);
    Serial.print(" *F\t");
    Serial.print("Heat index: ");
    Serial.print(hic);
    Serial.print(" *C ");
    Serial.print(hif);
    Serial.println(" *F");
}
```

Відкрийте монітор послідовного порту. Якщо все було зроблено правильно і все працює, то ви побачите наступну картину:

![sensor data](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image42.png)

Для перевірки роботи сенсора затисніть його в долоні і подуйте теплим повітрям. Через декілька секунд ви побачите що дані температури та вологості почнуть змінюватись.

В наступній частині ми навчимось зберігати дані температури та вологості в Firebase.

[Далі: Зберігання даних в Firebase](04-saving-data-to-firebase.md)
