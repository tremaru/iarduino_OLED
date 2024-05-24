//	Библиотека для вывода текста и графики на OLED дисплеи: http://iarduino.ru/shop/Displei/ekran-0-96-128x64-oled-i2c-belyy.html
//  Версия: 1.2.2
//  Последнюю версию библиотеки Вы можете скачать по ссылке: http://iarduino.ru/file/340.html
//  Для вывода только текста (без графики) воспользуйтесь библиотекой «iarduino_OLED_txt»: http://iarduino.ru/file/341.html
//  Подробное описание функции бибилиотеки доступно по ссылке: http://wiki.iarduino.ru/page/OLED_trema/
//  Библиотека является собственностью интернет магазина iarduino.ru и может свободно использоваться и распространяться!
//  При публикации устройств или скетчей с использованием данной библиотеки, как целиком, так и её частей,
//  в том числе и в некоммерческих целях, просим Вас опубликовать ссылку: http://iarduino.ru
//  Автор библиотеки: Панькин Павел.
//  Если у Вас возникли технические вопросы, напишите нам: shop@iarduino.ru
																														//
#ifndef iarduino_OLED_h																									//
#define iarduino_OLED_h																									//
																														//
#if defined(ARDUINO) && (ARDUINO >= 100)																				//
#include	<Arduino.h>																									//
#else																													//
#include	<WProgram.h>																								//
#endif																													//
																														//
#include	"DefaultFonts.h"																							//	Подключаем файл DefaultFonts.h - хранящий шрифты.
#include	"DefaultImage.h"																							//	Подключаем файл DefaultImage.h - хранящий изображения.
#include	"iarduino_OLED_I2C.h"																						//	Подключаем библиотеку выбора реализации шины I2C.
																														//
#if defined(TwoWire_h) || defined(__ARDUINO_WIRE_IMPLEMENTATION__) || defined(__AVR_ATmega328__) || defined(__AVR_ATmega32U4__) || defined(__AVR_ATmega1284P__) || defined(__AVR_ATmega2560__) || defined(ESP8266) || defined(ESP32) || defined(ARDUINO_ARCH_RP2040) || defined(RENESAS_CORTEX_M4) // Если подключена библиотека Wire или платы её поддерживают...
#include	<Wire.h>																									//	Разрешаем использовать библиотеку Wire в данной библиотеке.
#endif																													//
#if defined( iarduino_I2C_Software_h )																					//	Если библиотека iarduino_I2C_Software подключена в скетче...
#include	<iarduino_I2C_Software.h>																					//	Разрешаем использовать библиотеку iarduino_I2C_Software в данной библиотеке.
#endif																													//
																														//
#define		OLED_T									250																	//	Выравнивание по верхнему краю.
#define		OLED_B									251																	//	Выравнивание по нижнему краю.
#define		OLED_L									252																	//	Выравнивание по левому краю.
#define		OLED_C									253																	//	Выравнивание по центру.
#define		OLED_R									254																	//	Выравнивание по правому краю.
#define		OLED_N									255																	//	Оставить текущее значение строки/столбца.
#define		IMG_RAM									0																	//	Тип памяти в которой хранится массив изображения - ОЗУ
#define		IMG_ROM									1																	//	Тип памяти в которой хранится массив изображения - ПЗУ
#define		TXT_CP866								0																	//	Название кодировки в которой написан текст для функции print.
#define		TXT_UTF8								1																	//	Название кодировки в которой написан текст для функции print.
#define		TXT_WIN1251								2																	//	Название кодировки в которой написан текст для функции print.
																														//
#define		SSD1306_ADDRESS							0x3C																//	Установка контрастности. За данной командой должен быть отправлен байт контрастности от 00 до FF (по умолчанию 7F=127).
//			Базовые команды:																							//
#define		SSD1306_SET_CONTRAST					0x81																//	Установка контрастности. За данной командой должен быть отправлен байт контрастности от 00 до FF (по умолчанию 7F=127).
#define		SSD1306_RAM_ON							0xA4																//	Включить  изображение. Разрешить отображать содержимое RAM памяти.
#define		SSD1306_RAM_OFF							0xA5																//	Выключить изображение. Запретить отображать содержимое RAM памяти.
#define		SSD1306_INVERT_OFF						0xA6																//	Активный бит данных = 1. Пиксель установленный в 1 будет светиться.
#define		SSD1306_INVERT_ON						0xA7																//	Активный бит данных = 1. Пиксель установленный в 1 будет выключен.
#define		SSD1306_DISPLAY_OFF						0xAE																//	Выключить дисплей (спящий режим).
#define		SSD1306_DISPLAY_ON						0xAF																//	Включить  дисплей (нормальный режим).
#define		SSD1306_NOP								0xE3																//	Пустая команда (как NOP в Ассемблере).
//			Команды прокрутки:																							//
#define		SSD1306_SCROLL_HORIZONTAL_RIGHT			0x26																//	Настройка непрерывной горизонтальной прокрутки вправо. За данной командой должны быть отправлены 6 байт настроек
#define		SSD1306_SCROLL_HORIZONTAL_LEFT			0x27																//	Настройка непрерывной горизонтальной прокрутки влево.  За данной командой должны быть отправлены 6 байт настроек
#define		SSD1306_SCROLL_DIAGONAL_RIGHT			0x29																//	Настройка непрерывной диагональной   прокрутки вправо. За данной командой должны быть отправлены 5 байт настроек
#define		SSD1306_SCROLL_DIAGONAL_LEFT			0x2A																//	Настройка непрерывной диагональной   прокрутки влево.  За данной командой должны быть отправлены 5 байт настроек
#define		SSD1306_SCROLL_OFF						0x2E																//	Включить  прокрутку.
#define		SSD1306_SCROLL_ON						0x2F																//	Выключить прокрутку.
#define		SSD1306_SCROLL_VERTICAL					0xA3																//	Настройка непрерывной вертикальной прокрутки.  За данной командой должны быть отправлены 2 байта настроек
//			Команды адресации:																							//
#define		SSD1306_ADDR_COLUMN_LBS					0x00																//	Установка младшей части адреса колонки на странице. У данной команды младщие 4 бита должны быть изменены на младшие биты адреса. Комадна предназначена только для режима страничной адресации.
#define		SSD1306_ADDR_COLUMN_MBS					0x10																//	Установка старшей части адреса колонки на странице. У данной команды младщие 4 бита должны быть изменены на старшие биты адреса. Комадна предназначена только для режима страничной адресации.
#define		SSD1306_ADDR_MODE						0x20																//	Выбор режима адресации. За данной командой должен быть отправлен байт младшие биты которого определяют режим: 00-горизонтальная (с переходом на новую страницу (строку)) / 01-вертикальная (с переходом на новую колонку) / 10-страничная (только по выбранной странице).
#define		SSD1306_ADDR_COLUMN						0x21																//	Установка адреса колонки. За данной командой должны быть отправлены 2 байта: начальный адрес, конечный адрес. Так можно определить размер экрана в колонках по ширине.
#define		SSD1306_ADDR_PAGE						0x22																//	Установка адреса страницы. За данной командой должны быть отправлены 2 байта: начальный адрес, конечный адрес. Так можно определить размер экрана в строках по высоте.
#define		SSD1306_ADDR_ONE_PAGE					0xB0																//	Установка номера страницы которая будет выбрана для режима страничной адресации. У данной команды младщие 3 бита должны быть изменены на номер страницы. Комадна предназначена только для режима страничной адресации.
//			Команды аппаратной настройки:																				//
#define		SSD1306_SET_START_LINE					0x40																//	Установить начальный адрес ОЗУ (смещение памяти). У данной команды младщие 6 битов должны быть изменены на начальный адрес ОЗУ.
#define		SSD1306_SET_REMAP_R_TO_L				0xA0																//	Установить режим строчной развёртки справа-налево
#define		SSD1306_SET_REMAP_L_TO_R				0xA1																//	Установить режим строчной развёртки слева-направо
#define		SSD1306_SET_MULTIPLEX_RATIO				0xA8																//	Установить multiplex ratio (количество используемых выводов COM для вывода данных на дисплей). За данной командой должны быть отправлен 1 байт с указанием количества COM выводов (от 15 до 63).
#define		SSD1306_SET_REMAP_D_TO_T				0xC0																//	Установить режим кадровой развёртки снизу-верх
#define		SSD1306_SET_REMAP_T_TO_D				0xC8																//	Установить режим кадровой развёртки сверху-вниз
#define		SSD1306_SET_DISPLAY_OFFSET				0xD3																//	Установить смещение дисплея. За данной командой должны быть отправлен 1 байт с указанием вертикального сдвига чтения выходов COM (от 0 до 63).
#define		SSD1306_SET_COM_PINS					0xDA																//	Установить тип аппаратной конфигурации COM выводов. За данной командой должны быть отправлен 1 байт, у которого 4-ый бит: 0-последовательная / 1-альтернативная, 5-ой бит: 0-отключить COM Left/Right remap / 1-включить COM Left/Right remap.
//			Команды тайминга и схемы управления:																		//
#define		SSD1306_SET_DISPLAY_CLOCK				0xD5																//	Установить частоту обновления дисплея. За данной командой должны быть отправлен 1 байт, старшие 4 бита которого определяют частоту, а младшие делитель.
#define		SSD1306_SET_PRECHARGE_PERIOD			0xD9																//	Установить Фазы DC/DC преобразователя. За данной командой должны быть отправлен 1 байт, старшие 4 бита которого определяют период, а младшие период.
#define		SSD1306_SET_VCOM_DESELECT				0xDB																//	Установить VcomH (влияет на яркость).  За данной командой должны быть отправлен 1 байт, старшие 4 бита которого определяют напряжение (пример: 0000 - VcomH=0.65Vcc, 0010 - VcomH=0.77Vcc, 0011 - VcomH=0.83Vcc и т.д.).
#define		SSD1306_CHARGE_DCDC_PUMP				0x8D																//	Управление DC/DC преобразователем.     За данной командой должны быть отправлен 1 байт: 0x10 - отключить (VCC подается извне), 0x14 - запустить внутренний DC/DC.
//			Статусный регистр:																							//
//			-X------																									//	Доступен для чтения и содержит только 1 значащий бит X: 1-выкл / 0-вкл дисплей
//			Контрольный байт:																							//	Байт который следует после отправки байта адреса дисплея, до байта команды или данных. Другими словами это байт который мы отправляем вместо адреса регистра, при работе с другими модулями на шине I2C.
#define		SSD1306_SHIFT_DC						0x06																//	Положение бита DC в командном байте. Этот бит указывает что следующим байтом будет: 0-команда, 1-данные.
#define		SSD1306_SHIFT_CO						0x07																//	Положение бита Co в командном байте. Этот бит указывает что после следующего байта (команды или данных) будет следовать (если будет): 0-байт данных, 1-новый командный байт.
																														//
#define		SSD1306_COMMAND							(0<<SSD1306_SHIFT_CO) | (0<<SSD1306_SHIFT_DC)						// (CO=0, DC=0) => 0x00	Контрольный байт после которого следует байт команды
#define		SSD1306_DATA							(0<<SSD1306_SHIFT_CO) | (1<<SSD1306_SHIFT_DC)						// (CO=0, DC=1) => 0x40	Контрольный байт после которого следует байт данных
																														//
class iarduino_OLED{																									//
	public:																												//
	/**	Конструктор класса **/																							//
		iarduino_OLED						(uint8_t address=0x3C){														//	Конструктор класса										(Параметр: адрес дисплея на шине I2C)
											if(address==0x78){	address=0x3C;}											//	Корректируем адрес введённый с учётом бита RW.
											if(address==0x7A){	address=0x3D;}											//	Корректируем адрес введённый с учётом бита RW.
							dispAddr	=	address;																	//	Сохраняем переданный адрес дисплея
							selI2C		=	new iarduino_I2C_Select;													//	Переопределяем указатель selI2C на объект производного класса iarduino_I2C_Select.
		}																												//
	/**	Пользовательские функции **/																					//
		#if defined(TwoWire_h) || defined(__ARDUINO_WIRE_IMPLEMENTATION__)												//
		void				begin			(TwoWire* i=&Wire ){ selI2C->begin(i); _begin(); }							//	Определяем функцию инициализации модуля								(Параметр:  объект для работы с аппаратной шиной I2C).
		#endif																											//
		#if defined(iarduino_I2C_Software_h)																			//
		void				begin			(SoftTwoWire* i   ){ selI2C->begin(i); _begin(); }							//	Определяем функцию инициализации модуля								(Параметр:  объект для работы с программной шиной I2C).
		#endif																											//
		void				clrScr			(bool=false																);	//	Объявляем  функцию очистки дисплея						(Параметр:  флаг закрашивания экрана в белый цвет)
		void				fillScr			(bool i=true	){	clrScr(i);											}	//	Определяем функцию заливки дисплея						(Параметр:  флаг закрашивания экрана в белый цвет)
		void				invScr			(bool=true																);	//	Объявляем  функцию инвертирования цвета дисплея			(Параметр:  флаг инвертирования - да/нет)
		void				invText			(bool i=true	){	insFont.inverted=i;									}	//	Определяем функцию инвертирования цвета текста			(Параметр:  флаг инвертирования - да/нет)
		void				bgText			(bool i=true	){	insFont.background=i;								}	//	Определяем функцию определяющую наличие фона у текста	(Параметр:  флаг наличия фона   - да/нет)
		void				bgImage			(bool i=true	){	flgImgBG=i;											}	//	Определяем функцию определяющую наличие фона у картинок	(Параметр:  флаг наличия фона   - да/нет)
		void				setFont			(const uint8_t*															);	//	Объявляем  функцию выбора шрифта для вывода текста		(Параметр:  название шрифта)
		uint8_t				getFontWidth	(void			){	return insFont.width;								}	//	Определяем функцию возвращающую ширину символов шрифта	(Параметр:  отсутствует)
		uint8_t				getFontHeight	(void			){	return insFont.height;								}	//	Определяем функцию возвращающую высоту символов шрифта	(Параметр:  отсутствует)
		void				setCoding		(uint8_t i=false){	codingName=i;										}	//	Определяем функцию указывающую тип кодировки для print	(Параметры: название кодировки текста для функции print)
		void				setCursor		(					int=OLED_N, int=OLED_N								);	//	Объявляем  функцию установки курсора					(Параметры:        № колонки, № строки)
		void				setCursorShift	(					int x=0   , int y=0	){	numX+=x;numY+=y;			}	//	Определяем функцию сдвига курсора						(Параметры:        № колонки, № строки)
#ifdef RENESAS_CORTEX_M4																								//
		void				print			(int            ,	int=OLED_N, int=OLED_N, int=DEC						);	//	Объявляем  функцию вывода чисел							(Параметры: число, № колонки, № строки, система счисления)
		void				print			(unsigned int   ,	int=OLED_N, int=OLED_N, int=DEC						);	//	Объявляем  функцию вывода чисел							(Параметры: число, № колонки, № строки, система счисления)
#else																													//
		void				print			(int8_t			,	int=OLED_N, int=OLED_N, int=DEC						);	//	Объявляем  функцию вывода чисел							(Параметры: число, № колонки, № строки, система счисления)
		void				print			(uint8_t		,	int=OLED_N, int=OLED_N, int=DEC						);	//	Объявляем  функцию вывода чисел							(Параметры: число, № колонки, № строки, система счисления)
		void				print			(int16_t		,	int=OLED_N, int=OLED_N, int=DEC						);	//	Объявляем  функцию вывода чисел							(Параметры: число, № колонки, № строки, система счисления)
		void				print			(uint16_t		,	int=OLED_N, int=OLED_N, int=DEC						);	//	Объявляем  функцию вывода чисел							(Параметры: число, № колонки, № строки, система счисления)
#endif																													//
		void				print			(int32_t		,	int=OLED_N, int=OLED_N, int=DEC						);	//	Объявляем  функцию вывода чисел							(Параметры: число, № колонки, № строки, система счисления)
		void				print			(uint32_t		,	int=OLED_N, int=OLED_N, int=DEC						);	//	Объявляем  функцию вывода чисел							(Параметры: число, № колонки, № строки, система счисления)
		void				print			(double			,	int=OLED_N, int=OLED_N, int=2						);	//	Объявляем  функцию вывода чисел							(Параметры: число, № колонки, № строки, количество знаков после запятой)
		void				print			(char*			,	int=OLED_N, int=OLED_N								);	//	Объявляем  функцию вывода текста						(Параметры: текст, № колонки, № строки)
		void				print			(const char*	,	int=OLED_N, int=OLED_N								);	//	Объявляем  функцию вывода текста						(Параметры: текст, № колонки, № строки)
		void				print			(String			,	int=OLED_N, int=OLED_N								);	//	Объявляем  функцию вывода текста						(Параметры: текст, № колонки, № строки)
		void				drawImage		(const uint8_t* ,	int=OLED_N, int=OLED_N, uint8_t=IMG_ROM				);	//	Объявляем  функцию прорисовки изображения				(Параметры: изображение, № колонки, № строки, тип памяти)
		uint8_t				getImageWidth	(const uint8_t*	,							uint8_t=IMG_ROM				);	//	Объявляем  функцию возвращающую ширину изображения		(Параметры: изображение, тип памяти)
		uint8_t				getImageHeight	(const uint8_t*	,							uint8_t=IMG_ROM				);	//	Объявляем  функцию возвращающую высоту изображения		(Параметры: изображение, тип памяти)
		void				drawPixel		(					int,		int,							bool=1	);	//	Объявляем  функцию прорисовки пикселя					(Параметры: № колонки, № строки, цвет)
		bool				getPixel		(					int,		int										);	//	Объявляем  функцию возвращающую цвет пикселя			(Параметры: № колонки, № строки)
		void				drawLine		(					int,		int,		int, int,			bool=1	);	//	Объявляем  функцию прорисовки линии по двум точкам		(Параметры: № колонки начала, № строки начала, № колонки окончания, № строки окончания, цвет)
		void				drawLine		(           		int,		int,							bool=1	);	//	Объявляем  функцию прорисовки линии по одной точке		(Параметры: № колонки окончания, № строки окончания, цвет)
		void				drawRect		(					int,		int,		int, int,	bool=0, bool=1	);	//	Объявляем  функцию прорисовки прямоугольника			(Параметры: № колонки начала, № строки начала, № колонки окончания, № строки окончания, закрасить, цвет)
		void				drawCircle		(					int,		int,		uint8_t,	bool=0, bool=1	);	//	Объявляем  функцию прорисовки круга						(Параметры: № колонки, № строки, радиус, закрасить, цвет)
		void				autoUpdate		(bool i			){	flgUpdate=i;										}	//	Определяем функцию автоматического вывода изображения	(Параметр:  флаг разрашающий автоматический вывод прорисованного изображения на дисплей)
		void				update			(void			){	_sendBuffer();										}	//	Определяем функцию вывода прорисованного изображения	(Параметр:  отсутствует)
																														//
	/**	Переменные доступные для пользователя **/																		//
		int					numX;																						//	Объявляем  переменную для хранения № колонки начиная с которой должен выводиться текст
		int					numY;																						//	Объявляем  переменную для хранения № строки  на которой должен выводиться текст
																														//
	private:																											//
	/**	Внутренние переменные **/																						//
		iarduino_I2C_VirtualSelect* selI2C;																				//	Объявляем  указатель  на  объект полиморфного класса iarduino_I2C_VirtualSelect, но в конструкторе текущего класса этому указателю будет присвоена ссылка на производный класс iarduino_I2C_Select.
		uint8_t				dispAddr;																					//	Объявляем  переменную для хранения адреса дисплея на шине I2C.
		uint8_t				codingName	=	TXT_UTF8;																	//	Определяем переменную для хранения текущей кодировки.
		uint8_t			    arrBuffer		[1024];																		//	Объявляем  массив хранящий копию изображения экрана.
		bool				flgUpdate	=	true;																		//	Определяем флаг разрешающий автоматический вывод прорисованного изображения на дисплей (устанавливается/сбрасывается функцией autoUpdate).
		bool				flgImgBG	=	true;																		//	Определяем флаг указывающий на то, что у изображений есть фон.
		uint8_t			    numPageS	=	0;																			//	Определяем номер младшей страницы, значения которой требуется обновить из буфера arrBuffer.
		uint8_t			    numPageP	=	0;																			//	Определяем номер старшей страницы, значения которой требуется обновить из буфера arrBuffer.
		uint8_t			    numCellS	=	0;																			//	Определяем номер младшей ячейки,   значения которой требуется обновить из буфера arrBuffer.
		uint8_t			    numCellP	=	0;																			//	Определяем номер старшей ячейки,   значения которой требуется обновить из буфера arrBuffer.
		struct{																											//	Определяем структуру параметров используемого шрифта:
			uint8_t*		font;																						//	-          указатель на первый байт массива шрифта.
			uint8_t			width		=	0;																			//	-          ширина каждого символа шрифта (в пикселях).
			uint8_t			height		=	0;																			//	-          высота каждого символа шрифта (в пикселях).
			uint8_t			firstSymbol	=	0;																			//	-          код ASCII первого символа в массиве шрифта (шрифт может состоять, например, только цифр, значит первый символ шрифта, это "0", его код = 48).
			uint8_t			sumSymbol	=	0;																			//	-          количество символов имеющихся в используемом в шрифте (если шрифт состоит только из цифр, то количество симолов шрифта равно 10).
			bool			inverted	=	false;																		//	-          флаг указывающий на необходимость вывода шрифта с инвертированием его цвета. Флаг устанавливается/сбрасывается функцией invText().
			bool			background	=	true;																		//	-          флаг указывающий на то, что у шрифта есть фон.
			bool			setFont		=	false;																		//	-          флаг указывающий на то, что шрифт выбран.
			uint8_t			startSpace		[3];																		//	-          начальная позиция пустых интервалов в массиве символов.
			uint8_t			sumSpace		[3];																		//	-          количество отсутсвующих символов (ширина пустых интервалов).
		}					insFont;																					//	Имя структуры.
	/**	Внутренние функции **/																							//
		void				_begin			(void);																		//	Объявляем  функцию инициализации дисплея				(Параметр:  отсутствует)
		void				_print			(char*, int=255, int=255);													//	Объявляем  функцию вывода текста						(Параметры: текст, № строки, № колонки)
		char*				_codingCP866	(char*);																	//	Объявляем  функцию преобразования кодировки в CP866		(Параметр:  строка в кодировке UTF-8)
		char				_ItoAa			(uint8_t);																	//	Объявляем  функцию преобразования одной цифры в символ	(Параметр:  цифра от 0 до 15)
		void				_drawPixel		(int, int,           bool=1);												//	Объявляем  функцию прорисковки одного пикселя в буффере	(Параметры: x, y, цвет)
		void				_drawLine		(int, int, int, int, bool=1);												//	Объявляем  функцию прорисковки линии в буффере			(Параметры: x1, y1, x2, y2, цвет)
		void				_sendCommand	(uint8_t);																	//	Объявляем  функцию отправки байта команды				(Параметр:  код команды)
		void				_sendData		(uint8_t*, uint8_t);														//	Объявляем  функцию отправки байта данных				(Параметры: указатель на начало массива данных, количество передаваемых байт)
		void				_sendBuffer		(void);																		//	Объявляем  функцию отправки буфера в дисплей			(Параметр: отсутствует)
};																														//
																														//
#endif																													//
