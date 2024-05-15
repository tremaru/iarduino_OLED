// ПРИМЕР ВЫВОДА ТЕКСТА С ФОНОМ И БЕЗ:                                 //
                                                                       //
// OLED экран 128×64 / 0,96" (Trema-модуль):                           // https://iarduino.ru/shop/displays/ekran-0-96-128x64-oled-i2c-belyy.html
// Информация о подключении модулей к шине I2C:                        // https://wiki.iarduino.ru/page/i2c_connection/
// Информация о модуле и описание библиотеки:                          // https://wiki.iarduino.ru/page/OLED_trema/
// Библиотека   iarduino_OLED_txt (текстовая  ) экономит ОЗУ:          // https://iarduino.ru/file/341.html
// Библиотека   iarduino_OLED     (графическая):                       // https://iarduino.ru/file/340.html
                                                                       //
#include <Wire.h>                                                      // Подключаем библиотеку для работы с аппаратной шиной I2C, до подключения библиотеки iarduino_OLED.
#include <iarduino_OLED.h>                                             // Подключаем библиотеку iarduino_OLED.
iarduino_OLED myOLED(0x3C);                                            // Объявляем объект myOLED, указывая адрес дисплея на шине I2C: 0x3C или 0x3D.
                                                                       //
void setup(){                                                          //
     myOLED.begin(&Wire); // &Wire1, &Wire2 ...                        // Инициируем работу с дисплеем, указав ссылку на объект для работы с шиной I2C на которой находится дисплей (по умолчанию &Wire).
     myOLED.setFont(MediumFontRus);                                    // Указываем шрифт который требуется использовать для вывода цифр и текста.
}                                                                      //
                                                                       //
void loop(){                                                           //
     myOLED.bgText(false);                                             // Указываем что у текста нет фона.
     myOLED.clrScr();                                                  // Чистим экран.
     myOLED.print("arduino", 0, 32);                                   // Выводим текст начиная с координаты 0x32.
     myOLED.print("arduino", 5, 39);                                   // Выводим текст начиная с координаты 0x39. Этот текст частично наложится на предыдущий, но не закрасит его.
     delay(5000);                                                      // 
     myOLED.bgText(true);                                              // Указываем что у текста есть фон (по умолчанию).
     myOLED.clrScr();                                                  // Чистим экран.
     myOLED.print("arduino", 0, 32);                                   // Выводим текст начиная с координаты 0x32.
     myOLED.print("arduino", 5, 39);                                   // Выводим текст начиная с координаты 0x39. Этот текст частично наложится на предыдущий, и закрасит его своим чёрным фоном.
     delay(5000);                                                      // 
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
