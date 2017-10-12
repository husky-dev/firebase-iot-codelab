# Налаштування середовища

Для написання коду для ESP8266 ми можемо використовувати стандартний редактор Arduino. Але даний редактор далекий від тих редакторів, котрі ми звикли використовувати у нашій повсякденній роботі. Тому для покращення роботи з кодом ми будемо використовувати редактор Atom + плагін для роботи з PlatformIO.

[PlatformIO](http://platformio.org/) у своєму первинному вигляді була звичайною консольною утилітою, котра дозволяла компілювати ваш C код в прошивку і завантажувати її на ваш пристрій. Утиліта підтримує досить великий список мікросхем, в тому числі і ESP8266. Основна ідея платформи - можливість написати код один раз і використовувати його в різних мікросхемах. Утиліта написана на Python, тому її можна використовувати як на локальному комп’ютері так і на сервері ([continuous integration](https://en.wikipedia.org/wiki/Continuous_integration)).

PlatformIO має спеціалізований плагін для редактора Atom, котрий перетворює його у повноцінну IDE для пристроїв. Саме його ми і будемо використовувати для нашої лабораторної.

Перегляньте розділ "Можливі помилки" перш ніж встановлювати все програмне забезпечення. Це може зекономити ваш час. Більш детально процес інсталяції плагіну для всіх операційних системи описано на сайті PlatformIO:  [http://docs.platformio.org/en/latest/ide/atom.html](http://docs.platformio.org/en/latest/ide/atom.html)

## Windows

Завантажте та встановіть Atom з офіційного сайту [https://atom.io/](https://atom.io/). Запустіть редактор. Натисніть "Install a Package" та "Open Installer".

![Atom](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image36.png)

У пошуку знайдіть плагін "platformio-ide" та встановіть його. Якщо редактор запропонує встановити Clang - натисніть "Disable Code Completion" (ви можете встановити його пізніше). Встановіть всі необхідні залежності, якщо цього попросить редактор. Перезавантажте редактор.

![Atom](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image3.png)

### Налаштування драйверу

Якщо ви використовуєте Windows 10 та у вас увімкнена служба автоматичного пошуку драйверів у Windows Update - скоріш за все вам не потрібно встановлювати драйвер вручну. Але краще це перевірити.

1. Підключіть плату до вашого комп’ютера.
2. Натисніть `Win + R` (або "Пуск" - "Виконати"), введіть команду `devmgmt.msc`, та натисніть ОК.

![win-perform](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image4.png)

3. Знайдіть розділ "Порти (COM і LPT)" та переконайтеся що бачите підключену плату під назвою "USB-SERIAL CH340 (COM*)" (номер COM порта у вас может бути іншим).

![win-device](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image60.png)

Якщо порту плати ви не знайшли - скоріш за все драйвер не встановлений та не підтягнувся з Windows Update і ви маєте бачити в диспетчері пристроїв таке:

![win-unknow-device](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image13.png)
        
4. Перейдіть за посиланням [https://github.com/nodemcu/nodemcu-devkit/blob/master/Drivers/CH341SER_WINDOWS.zip](https://github.com/nodemcu/nodemcu-devkit/blob/master/Drivers/CH341SER_WINDOWS.zip), скачайте та встановіть драйвер (скачати архів, розпакувати його та запустити файл встановлення драйверу (він там всього один), він попросить доступ адміна - погодитися, та в головному вікні встановлення драйверу натиснути "INSTALL").

![win-driver](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image45.png)

Повторіть пункти 1-3 щоб перевірити, чи вставлений драйвер.

## MacOS

Завантажте та встановіть Atom з офіційного сайту [https://atom.io/](https://atom.io/). Запустіть редактор. Натисніть "Install a Package" та "Open Installer".

![atom](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image9.png)

У пошуку знайдіть плагін "platformio-ide" та встановіть його. Якщо редактор запропонує встановити Clang - натисніть "Disable Code Completion" (ви можете встановити його пізніше). Встановіть всі необхідні залежності, якщо цього попросить редактор. Перезавантажте редактор.

![atom](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image16.png)

### Налаштування драйверу

Для підключення до нашої плати нам знадобиться спеціалізований драйвер:

1. Зайдіть на сторінку репозиторію драйвера CH340: [https://github.com/adrianmihalko/ch340g-ch34g-ch34x-mac-os-x-driver](https://github.com/adrianmihalko/ch340g-ch34g-ch34x-mac-os-x-driver)
2. Завантажте файл `CH34x_Install_V1.3.pkg` з репозиторію.
3. Запустіть термінал
4. На всяк випадок виконайте наступні команди, щоб очистити минулі версії драйверу:

```bash
sudo rm -rf /System/Library/Extensions/usb.kext
sudo rm -rf /Library/Extensions/usbserial.kext
```

5. Перезавантажте комп’ютер
6. Двічі клікніть на файлі `CH34x_Install_V1.3.pkg`. Встановіть драйвер.
7. Перезавантажте комп’ютер.

## Linux

Перейдіть на офійійний сайт редактора Atom [https://atom.io/](https://atom.io/) та скачайте версію відповідно до свого дистрибутива:

- DEB - для Ubuntu, Mint, Debian, etc.
- RPM - для Fedora, Red Hat, OpenSUSE, etc.

Для інших дистрибутивів пакет можна знайти тут: [https://github.com/atom/atom/releases/tag/v1.21.0](https://github.com/atom/atom/releases/tag/v1.21.0).

Якщо ви використовуєте ArchLinux-подібний дистрибутив (ArchLinux, Manjaro, Antergos, Alpine) ви можете встановити Atom з користувацького репозиторія:

```bash
yaourt -S atom-editor-bin
```

Якщо у вас Gentoo - та ви й самі знаєте як встановити Atom :)

Linux не потребує встановлення додаткових драйверів. При підключенні плати до вашого комп’ютера Linux створить файл пристрою в `/dev/ttyUSB0`.

Підключіть плату та переконайтесь що все працює:

```bash
ls /dev | grep -i ttyusb
```

Також залежно від дистрибутиву та налаштувань доступу до пристроїв користувачам ви можете мати помилки завантаженя скомпільованого коду до плати у зв’язку з відсутністю прав писати в пристрій. Як "гаряче рішення" в рамках кодлаби можете надати вільні права всім користувачам на доступ до пристрою:

```bash
sudo chmod 666 /dev/ttyUSB0
```

Запустіть редактор. Натисніть "Install a Package" та "Open Installer".

![atom](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image9.png)

У пошуку знайдіть плагін "platformio-ide" та встановіть його. Якщо редактор запропонує встановити Clang - натисніть "Disable Code Completion" (ви можете встановити його пізніше). Встановіть всі необхідні залежності, якщо цього попросить редактор. Перезавантажте редактор.

![atom](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image16.png)

## Можливі помилки

Після інсталяції плагіну Atom може прохати встановити Clang для автодоповнення коду. В рамках цієї кодлаби ви можете ігнорувати це повідомлення.

![clang-err](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image41.png)

Можете ігнорувати це, натискаючи "Remind Later".

В процесі роботи ви також можете отримати наступну помилку:

![atom-err](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image5.png)

Можете проігнорувати її.

Детальніше про те як встановити Clang під вашу операційну систему можна прочитати тут: [http://docs.platformio.org/en/latest/ide/atom.html#ii-clang-for-intelligent-code-completion](http://docs.platformio.org/en/latest/ide/atom.html#ii-clang-for-intelligent-code-completion).

## Перший проект

Підключіть плату до комп’ютера.

![nodemcu-connect](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image11.png)

Запустіть Atom та створіть новий проект PlatformIO:

![platformio-new-project](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image53.png)

У якості плати виберіть "NodeMCU 1.0 (ESP-12E Module)".

![atom-nodemcu](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image26.png)

Після створення проекту можете закрити всі можете зачинити всі непотрібні вікна редактора. Відкрийте фал `src/main.cpp`:

![atom-main](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image34.png)

Наступним нашим кроком буде написання найпростішої програми і завантаження її в наш пристрій.

Ще один момент про який варто згадати перед початком написання коду. Ви можете побачити, що кожен вивід нашої схеми має позначку (`A0`, `G`, `VU`, `D0` - `D8` і т.п.):

![node-pins](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image30.png)

Кожен вивід має свою функцію. Щоб знати яку саме нам знадобиться ця схема (гуглится за фразою "nodemcu v3 pinout"):

![nodemcu-pinout](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image22.png)

В цій лабі ми будемо активно використовувати виводи GPIO (General-purpose input/output - виводи для загальних операцій вводу/виводу). Якщо ми в коді вказуємо вивід з номером 2, це означає що ми використовуємо `GPIO2` (`D4` на платі), а не `D2`. `D0`-`D8` - це назви виводів плати, але не самої мікросхеми. Тому кожного разу коли в коді будете використовувати номери пінів, весь час звіряйтесь з цією схемою (а краще її збережіть). Піни `D#` можуть вас заплутати.

Для перевірки наш код буде блимати світлодіодом, котрий знаходиться на платі. Він при’єднаний до `GPIO2`. Замініть код за замовчуванням на той, що нижче. Прочитайте коментарі, якщо ви перший раз працюєте з кодом для Arduino:

```c++
// Підключаємо стандартну бібліотеку Arduino
// Котра дозволяє нам використовувати
// Стандартні методи та константи
#include <Arduino.h>
// define - дозволяє нам створювати константу
// в програмувані не дуже схвалюють, якщо
// в коді використовують голі числа без пояснення
// звідки вони взялись і що означають. Під час компіляції
// компілятор замінить назву константи на її значення.
// Наш світлодіод знаходиться на виводі GPIO2 нашої схеми
#define ONBOARD_LED_PIN 2
// В коді для Arduino два головні методи - setup і loop.
// Код в setup виконується як тільки ви подаєте живлення на
// вашу схему. Зазвичай в ньому виконують різні ініціалізації
void setup(){
    // Щоб використовувати будь-який пін треба
    // його спочатку ініціалізувати вказавши буде він працювати
    // на вхід чи на віихід. Якщо ми хочемо керувати світлодіодом -
    // він повинен бути налаштован на вихід. Для зчитування значень
    // кнопки (натиснута чи ні) ми повинні налаштувати пін на вхід
    // INPUT і OUTPUT - це звичайні константи (0 та 1) прописані через #define
    // в файлі Arduino.h
    pinMode(ONBOARD_LED_PIN, OUTPUT);
}
// Код в loop виконується відразу після виконання setup.
// В цьому методі знаходится основний код прошивки.
// Як можна зрозуміти з назви (loop - петля) функція після свого
// Завершення перезапускається і виконується знову, і знову, і знову.
void loop(){
    // Для встановлення значення на піні використовується
    // метод digitalWrite(пін, значення).
    // HIGH, LOW - це теж зручні константи з Arduino.h (1 та 0) відповідно
    // коли ми встановлюємо пін в 1 - на ньому з’являеться живлення (+3.3V)
    // коли вимикаємо живлення зникає (GND)
    digitalWrite(ONBOARD_LED_PIN, HIGH);
    // delay - зупиняє програму на час заданий в мілісекундах
    // 1с = 1000мс
    delay(1000);
    // Вимикаємо світлодіод
    digitalWrite(ONBOARD_LED_PIN, LOW);
    // Чекаємо секунду
    delay(1000);
    // Після завершення програма знову запустить функцію loop
    // і програма почне виконуватись заново
}
```

Натисніть кнопку компіляції та почекайте доки ваш код зкомпілюється. Якщо ви не помилились, то побачите повідомлення про успішну компіляцію:

![success-compilation](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image56.png)

Після цього натисніть кнопку для завантаження прошивки:

![success-compilation](https://github.com/snipter/firebase-iot-codelab/blob/master/docs/assets/image8.png)

Якщо все було вірно налаштовано, то ви побачите як плата почне блимати, а знизу редактора побачите процес завантаження. 

Після успішного прошивання пристрій перезавантажиться і почне блимати раз в секунду.

[Далі: Налагодження програми](02-debugging.md)
