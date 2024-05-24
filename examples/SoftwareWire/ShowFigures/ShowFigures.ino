// ПРИМЕР ВЫВОДА ПРИМИТИВОВ ПО МЕРЕ ИХ ПОСТУПЛЕНИЯ:                    //
// Требуется установить библиотеку <iarduino_I2C_Software.h>           // https://iarduino.ru/file/627.html
                                                                       //
// В данном примере примитивы выводятся на экран сразу после обращения //
// к функциям их вывода.                                               //
// В примере ShowFigures_Update выводятся те же примитивы, но не по    //
// порядку, а все сразу, благодаря функциям: autoUpdate() и update().  //
                                                                       //
// OLED экран 128×64 / 0,96" (Trema-модуль):                           // https://iarduino.ru/shop/displays/ekran-0-96-128x64-oled-i2c-belyy.html
// Информация о подключении модулей к шине I2C:                        // https://wiki.iarduino.ru/page/i2c_connection/
// Информация о модуле и описание библиотеки:                          // https://wiki.iarduino.ru/page/OLED_trema/
// Библиотека   iarduino_OLED_txt (текстовая  ) экономит ОЗУ:          // https://iarduino.ru/file/341.html
// Библиотека   iarduino_OLED     (графическая):                       // https://iarduino.ru/file/340.html
                                                                       //
#include <iarduino_I2C_Software.h>                                     // Подключаем библиотеку для работы с программной шиной I2C, до подключения библиотеки iarduino_OLED.
SoftTwoWire sWire(3,4);                                                // Создаём объект программной шины I2C указав выводы которым будет назначена роль линий: SDA, SCL.
                                                                       //
#include <iarduino_OLED.h>                                             // Подключаем библиотеку iarduino_OLED.
iarduino_OLED myOLED(0x3C);                                            // Объявляем объект myOLED, указывая адрес дисплея на шине I2C: 0x3C или 0x3D.
                                                                       //
void setup(){                                                          //
     myOLED.begin(&sWire);                                             // Инициируем работу с дисплеем, указав ссылку на объект для работы с шиной I2C на которой находится дисплей (по умолчанию &Wire).
}                                                                      // Объект основной аппаратной шины I2C (Wire) можно не указывать: myOLED.begin();
                                                                       //
void loop(){                                                           //
     myOLED.drawRect   (10, 10,  50, 50, true , true );                // Прорисовываем квадрат по двум точкам: 10x10, 50x50       , закрасить - true  (да) , цвет - true  (белый).
     myOLED.drawRect   (15, 15,  45, 45, true , false);                // Прорисовываем квадрат по двум точкам: 15x15, 45x45       , закрасить - true  (да) , цвет - false (черный).
     myOLED.drawLine   (10, 10,  50, 50,        false);                // Прорисовываем линию через две точки:  10x10, 50x50       ,                          цвет - false (черный).
     myOLED.drawLine   (10, 50,  50, 10,        false);                // Прорисовываем линию через две точки:  10x50, 50x10       ,                          цвет - false (черный).
     myOLED.drawCircle (30, 30,      10, false, true );                // Прорисовываем круг с центром с точке  30x30 и радиусом 10, закрасить - false (нет), цвет - true  (белый).
     myOLED.drawCircle (30, 30,       5, true , true );                // Прорисовываем круг с центром с точке  30x30 и радиусом 5 , закрасить - true  (да) , цвет - true  (белый).
     myOLED.drawPixel  (30, 30,                 false);                // Прорисовываем точку в координате      30x30,                                        цвет - false (черный).
     myOLED.drawRect   (60, 10, 100, 50, false, true );                // Прорисовываем квадрат по двум точкам: 60x10, 100x50      , закрасить - false (нет), цвет - true  (белый).
     myOLED.drawRect   (65, 15,  95, 45, true , true );                // Прорисовываем квадрат по двум точкам: 65x15,  95x45      , закрасить - true  (да) , цвет - true  (белый).
     myOLED.drawLine   (60, 10, 100, 50,        true );                // Прорисовываем линию через две точки:  60x10, 100x50      ,                          цвет - true  (белый).
     myOLED.drawLine   (60, 50, 100, 10,        true );                // Прорисовываем линию через две точки:  60x50, 100x10      ,                          цвет - true  (белый).
     myOLED.drawCircle (80, 30,      10, false, false);                // Прорисовываем круг с центром с точке  80x30 и радиусом 10, закрасить - false (нет), цвет - false (черный).
     myOLED.drawCircle (80, 30,       5, true,  false);                // Прорисовываем круг с центром с точке  80x30 и радиусом 10, закрасить - true  (да) , цвет - false (черный).
     myOLED.drawPixel  (80, 30,                 true );                // Прорисовываем точку в координате      80x30,                                        цвет - true  (белый).
     delay(2000);                                                      // Ждём 2 секунды.
     myOLED.clrScr();                                                  // Чистим экран.
     delay(1000);                                                      // Ждём 1 секунду.
}                                                                      //
                                                                       //
/*   ДОСТУПНЫЕ ШРИФТЫ:                                                 // Шрифты можно менять и добавлять в файле: src/DefaultFonts.h
 *   SmallFont                                                         // Маленький шрифт  6x8  ( 95 символов) только латиница
 *   SmallFontRus                                                      // Маленький шрифт  6x8  (176 символов) латиница и кириллица
 *   MediumFont                                                        // Средний   шрифт 12x16 ( 95 символов) только латиница
 *   MediumFontRus                                                     // Средний   шрифт 12x16 (176 символов) латиница и кириллица
 *   MediumNumbers                                                     // Средние   цифры 12x16 ( 13 символов) 0123456789./-
 *   BigNumbers                                                        // Большие   цифры 14x24 ( 13 символов) 0123456789./-
 *   MegaNumbers                                                       // Большие   цифры 24x40 ( 13 символов) 0123456789./-
 *                                                                     //
 *   ДОСТУПНЫЕ КАРТИНКИ:                                               // Картинки можно менять и добавлять в файле: src/DefaultImage.h
 *   Img_Alarm, Img_Antenna, Img_Bluetooth, Img_Light, Img_Logo        // Будильник (9x8), Антенна (10x8), Значок Bluetooth (5x8), Свет (9x8), Логотип iArduino (27x16).
 *   Img_Check, Img_Melody, Img_Message, Img_Settings                  // Галочка (7x8), Мелодия звонка (4x8), Сообщение (10x8), Настройки (8x8).
 *   Img_Arrow_down, Img_Arrow_left, Img_Arrow_right, Img_Arrow_up     // Стрелки (8x8): вниз, влево, вправо, вверх.
 *   Img_Battery_0, Img_Battery_1, Img_Battery_2, Img_Battery_3        // Батарейки (13x8): с зарядом 0,1,2,3.
 *   Img_Battery_charging, Img_Battery_low, Img_BigBattery_low         // Батарейки (13x8): заряжается, разряжена, Большая батарейка разряжена (23x8).
 *   Img_Level_1, Img_Level_2, Img_Level_3, Img_Level_4                // Уровень приёма (11x8): 1,2,3,4.
 *   Img_Netlevel_1, Img_Netlevel_2, Img_Netlevel_3                    // Уровень приёма сети (8x8): 1,2,3.
 *   Img_Call, Img_Call_in, Img_Call_out                               // Звонок вызова (8x8): без направления, входящий, исходящий.
 *   Img_Checkbox_off, Img_Checkbox_on, Img_Radio_off, Img_Radio_on    // Пункты выбора (8x8): флажёк и точка.
 *   Img_Dynamic, Img_Dynamic_off, Img_Dynamic_on                      // Динамик (10x8): без дополнений, выключен, включён.
 */
