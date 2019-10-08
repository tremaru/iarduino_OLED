[![](https://iarduino.ru/img/logo.svg)](https://iarduino.ru)[![](https://wiki.iarduino.ru/img/git-shop.svg?3)](https://iarduino.ru) [![](https://wiki.iarduino.ru/img/git-wiki.svg?2)](https://wiki.iarduino.ru) [![](https://wiki.iarduino.ru/img/git-lesson.svg?2)](https://lesson.iarduino.ru)[![](https://wiki.iarduino.ru/img/git-forum.svg?2)](http://forum.trema.ru)

# iarduino_OLED

**This is a library for Arduino IDE. It allows to control [OLED dislay 128x64](https://iarduino.ru/shop/Displei/ekran-0-96-128x64-oled-i2c-belyy.html) Trema-module made by iArduino.ru**

**Данная библиотека для Arduino IDE позвляет управлять Trema-модулем [OLED экран 128x64](https://iarduino.ru/shop/Displei/ekran-0-96-128x64-oled-i2c-belyy.html)**

> Подробнее про установку библиотеки читайте в нашей [инструкции](https://wiki.iarduino.ru/page/Installing_librari/).

> Подробнее про подключение к [Arduino UNO](https://iarduino.ru/shop/boards/arduino-uno-r3.html)/[Piranha UNO](https://iarduino.ru/shop/boards/piranha-uno-r3.html) читайте на нашей [wiki](https://wiki.iarduino.ru/page/OLED_trema/)


| Модель | Ссылка на магазин |
|--|--|
| ![](https://wiki.iarduino.ru/img/resources/830/830.svg) | https://iarduino.ru/shop/Displei/ekran-0-96-128x64-oled-i2c-belyy.html |


## Примеры:

**Вывод текста Кириллицей с указанием разных кодировок**

```C++
#include <iarduino_OLED.h>                                 // Подключаем библиотеку iarduino_OLED.
iarduino_OLED myOLED(0x3C);                                // Объявляем объект myOLED, указывая адрес дисплея на шине I2C: 0x3C или 0x3D.
                                                           //
extern uint8_t SmallFontRus[];                             // Подключаем шрифт SmallFontRus.
                                                           //
void setup(){                                              //
    myOLED.begin();                                        // Инициируем работу с дисплеем.
    myOLED.setFont(SmallFontRus);                          // Указываем шрифт который требуется использовать для вывода цифр и текста.
}                                                          //
void loop(){                                               //
//  Вывод текста в кодировке UTF-8:                        //
    myOLED.clrScr();                                       // Чистим экран.
    myOLED.print("UTF8", 0, 7);                            // Выводим текст начиная с координаты 0x7 (нижняя левая точка текста).
    myOLED.setCoding(TXT_UTF8);                            // Меняем кодировку на UTF-8 (по умолчанию).
    myOLED.print("Ардуино iArduino", OLED_C, 39);          // Выводим текст по центру экрана, координата нижней части текста по оси Y равна 39.
    delay (5000);                                          // Ждём 5 секунд.
                                                           //
//  Вывод текста в кодировке CP866:                        //
    myOLED.clrScr();                                       // Чистим экран.
    myOLED.print("CP866", 0, 7);                           // Выводим текст начиная с координаты 0x7 (нижняя левая точка текста).
    myOLED.setCoding(TXT_CP866);                           // Меняем кодировку на CP866.
    myOLED.print("Ардуино iArduino", OLED_C, 39);          // Выводим текст по центру экрана, координата нижней части текста по оси Y равна 39.
    delay (5000);                                          // Ждём 5 секунд.
                                                           //
//  Вывод текста в кодировке WINDOWS-1251:                 //
    myOLED.clrScr();                                       // Чистим экран.
    myOLED.print("WIN1251", 0, 7);                         // Выводим текст начиная с координаты 0x7 (нижняя левая точка текста).
    myOLED.setCoding(TXT_WIN1251);                         // Меняем кодировку на WINDOWS-1251.
    myOLED.print("Ардуино iArduino", OLED_C, 39);          // Выводим текст по центру экрана, координата нижней части текста по оси Y равна 39.
    delay (5000);                                          // Ждём 5 секунд.
```

**Вывод чисел**

```C++
#include <iarduino_OLED.h>                                 // Подключаем библиотеку iarduino_OLED.
iarduino_OLED myOLED(0x3C);                                // Объявляем объект myOLED, указывая адрес дисплея на шине I2C: 0x3C или 0x3D.
                                                           //
extern uint8_t SmallFontRus[];                             // Подключаем шрифт SmallFontRus.
                                                           // Если Вы не используете Кириллицу, то лучше подключить шрифт SmallFont, он займет меньше места в памяти программ.
void setup(){                                              //
    myOLED.begin();                                        // Инициируем работу с дисплеем.
    myOLED.setFont(SmallFontRus);                          // Указываем шрифт который требуется использовать для вывода цифр и текста.
                                                           //
    myOLED.print( 123456789 , 0, 7 );                      // Выводим целое положительное число начиная с координаты 0x0.
    myOLED.print(-123456789 , 0, 15);                      // Выводим целое отрицательное число начиная с координаты 0x15.
    myOLED.print( 123456789 , 0, 23, HEX);                 // Выводим целое положительное число начиная с координаты 0x23, в 16-ричной системе счисления.
    myOLED.print( 123456789 , 0, 31, OCT);                 // Выводим целое положительное число начиная с координаты 0x31, в 8-ричной системе счисления.
    myOLED.print(-123.456789, 0, 39);                      // Выводим число с плавающей точкой  начиная с координаты 0x39, по умолчанию отобразится 2 знака после запятой.
    myOLED.print( 123.456789, 0, 47, 3);                   // Выводим число с плавающей точкой  начиная с координаты 0x47, указывая 3 знака после запятой.
    myOLED.print( 123       , 0, 55, BIN);                 // Выводим целое положительное число начиная с координаты 0x55, в 2-ичной системе счисления.
    myOLED.print( 123       , 0, 63, 12);                  // Выводим целое положительное число начиная с координаты 0x63, в 12-ричной системе счисления.
}                                                          //
                                                           //
void loop(){}                                              //
```

---
## Больше примеров на нашей [wiki](https://wiki.iarduino.ru/page/OLED_trema/#h3_6)


## Назначение функций и переменных 

**Подключаем библиотеку:**

```C++
#include <iarduino_OLED.h> // Подключаем библиотеку.
iarduino_OLED ОБЪЕКТ ( [ АДРЕС_I2C ] ); // Создаём объект (адрес по умолчанию 0x3C).
```

**Инициализация** 

```C++
ОБЪЕКТ.begin(); // Инициализация работы с дисплеем.
```

**Очистка экрана** 

```C++
ОБЪЕКТ.clrScr( [ ЗАЛИТЬ ] ); // Очистка экрана дисплея (параметр - флаг разрешающий залить дисплей).
```

**Заливка дисплея** 

```C++
ОБЪЕКТ.fillScr( [ ЦВЕТ ] ); // Заливка дисплея (параметр - цвет. 0-чёрный, 1-белый).
```

**Инверсия экрана**

```C++
ОБЪЕКТ.invScr( [ ФЛАГ ] ); // Инверсия цветов экрана (параметр - флаг разрешающий инверсию).
```

**Инверсия текста**

```C++
ОБЪЕКТ.invText( [ ФЛАГ ] ); // Инверсия цветов выводимого текста (параметр - флаг разр. инверсию).
```

**Управление фоном текста**

```C++
ОБЪЕКТ.bgText( [ ФЛАГ ] ); // Управление наличием фона у выводимого текста.
```

**Управление фоном изображений**

```C++
ОБЪЕКТ.bgImage( [ ФЛАГ ] ); // Управление наличием фона у выводимых изображений.
```

**Выбор шрифта** 

```C++
ОБЪЕКТ.setFont( ШРИФТ ); // Выбор шрифта для выводимого текста (параметр - название шрифта).
```

**Получение ширины символов** 

```C++
ОБЪЕКТ.getFontWidth(); // Получение ширины символов выбранного шрифта.
```

**Получение высоты символов** 

```C++
ОБЪЕКТ.getFontHeight(); // Получение высоты символов выбранного шрифта.
```

**Указание кодировки** 

```C++
ОБЪЕКТ.setCoding( [КОДИРОВКА] ); // Указание кодировки текста в скетче.
```

**Установка курсора** 

```C++
ОБЪЕКТ.setCursor( X , Y ); // Установка курсора в указанную позицию на экране.
```

**Сдвиг курсора** 

```C++
ОБЪЕКТ.setCursorShift( X , Y ); // Сдвиг курсора на указанное количество пикселей.
```

**Вывод текста** 

```C++
ОБЪЕКТ.print( ТЕКСТ/ЧИСЛО [ , X ] [ , Y ] [ , ПАРАМЕТР ] ); // Вывод текста или числа в указанную позицию.
```

**Вывод изображения** 

```C++
ОБЪЕКТ.drawImage( КАРТИНКА [ , X ] [ , Y ] [ , ТИП_ПАМЯТИ ] ); // Вывод изображения в указанную позицию.
```

**Получение ширины изображения**

```C++
ОБЪЕКТ.getImageWidth( КАРТИНКА [ , ТИП_ПАМЯТИ ] ); // Получение ширины изображения.
```

**Получение высоты изображения**

```C++
ОБЪЕКТ.getImageHeight( КАРТИНКА [ , ТИП_ПАМЯТИ ] ); // Получение высоты изображения.
```

**Вывод точки** 

```C++
ОБЪЕКТ.drawPixel( X , Y [ , ЦВЕТ ] ); // Вывод точки в указанную позицию на экране.
```

**Получение цвета точки**

```C++
ОБЪЕКТ.getPixel( X , Y ); // Получение цвета точки в указанной позиции экрана.
```

**Вывод линии**

```C++
ОБЪЕКТ.drawLine( X1,Y1 , X2,Y2 [ , ЦВЕТ] ); // Вывод линии через две точки на экране.
```

**Вывод прямоугольника**

```C++
ОБЪЕКТ.drawRect( X1,Y1 , X2,Y2 [ , ЗАЛИТЬ] [ , ЦВЕТ] ); // Вывод прямоугольника через две точки на экране.
```

**Вывод круга**

```C++
ОБЪЕКТ.drawCircle( X, Y [ , ЗАЛИТЬ] [ , ЦВЕТ] ); // Вывод круга в указанную точку на экране.
```

**Управление обновлением**

```C++
ОБЪЕКТ.autoUpdate( [ ФЛАГ ] ); // Управление обновлением (параметр - флаг разр. автообновление экрана).
```

**Принудительное обновление данных на экране дисплея.**

```C++
ОБЪЕКТ.update(); // Принудительное обновление данных на экране дисплея.
```

**Текущая позиция курсора по оси X.**

```C++
Переменная ОБЪЕКТ.numX // Принимает и возвращает текущую позицию курсора по оси X.
```

**Текущая позиция курсора по оси Y.**

```C++
Переменная ОБЪЕКТ.numY// Принимает и возвращает текущую позицию курсора по оси Y.
```

**Для вывода только текстов и чисел, воспользуйтесь библиотекой [iarduino\_OLED\_txt](https://github.com/tremaru/iarduino_OLED_txt).**
