#ifndef TEST2_INIT_COMMANDS_H
#define TEST2_INIT_COMMANDS_H

//<editor-fold desc="Init commands">

static const uint8_t init_commands[] = {
        2, LCD_POWER1, 0x23,
        2, LCD_POWER2, 0x10,

        /*
           0. Всегда 0
		   1. Всегда 0
	       2. Горизонтальная развертка
		     1 = Слева направо
		     0 = Справо налево
	       3. Переключение цвета
		     0 = RGB;
		     1 = BGR
	       4. Вертикальная развертка
		     1 = Сверху вниз
		     0 = Снизу вверх

		   5., 6., 7. биты задают MCU>GRAM направление чтения и записи

		   5. Обмен колонки/строки
		     0 = Нормальный режим
		     1 = Развернутый
	       6. Порядок адресации строки
	       7. Порядок адресации колонки
         */
        2, LCD_MAC, 0b01001000, // 0b 0100 1000
        2, LCD_PIXEL_FORMAT, 0x55,
        3, LCD_FRMCTR1, 0x00, 0x13,
        16, LCD_PGAMMA, 0x0F, 0x31, 0x2B, 0x0C, 0x0E, 0x08, 0x4E, 0xF1, 0x37, 0x07, 0x10, 0x03, 0x0E, 0x09, 0x00,
        16, LCD_NGAMMA, 0x00, 0x0E, 0x14, 0x03, 0x11, 0x07, 0x31, 0xC1, 0x48, 0x08, 0x0F, 0x0C, 0x31, 0x36, 0x0F,
        0
};

//static const uint8_t init_commands[] = {
//        4, 0xEF, 0x03, 0x80, 0x02,
//        4, LCD_POWERB, 0x00, 0XC1, 0X30,
//        5, LCD_POWER_SEQ, 0x64, 0x03, 0X12, 0X81,
//        4, LCD_DTCA, 0x85, 0x00, 0x78,
//        6, LCD_POWERA, 0x39, 0x2C, 0x00, 0x34, 0x02,
//        2, LCD_PRC, 0x20,
//        3, LCD_DTCB, 0x00, 0x00,
//        2, LCD_POWER1, 0x23,                        //Powercontrol
//        2, LCD_POWER2, 0x10,                        //Powercontrol
//        3, LCD_VCOM1, 0x3e, 0x28,                   //VCMcontrol
//        2, LCD_VCOM2, 0x86,                         //VCMcontrol2
//        2, LCD_MAC, 0x48,                           //MemoryAccessControl
//        2, LCD_PIXEL_FORMAT, 0x55,
//        3, LCD_FRMCTR1, 0x00, 0x18,
//        4, LCD_DFC, 0x08, 0x82, 0x27,               //DisplayFunctionControl
//        2, LCD_3GAMMA_EN, 0x00,                     //GammaFunctionDisable
//        2, LCD_GAMMA, 0x01,                         //Gammacurveselected
//        16, LCD_PGAMMA, 0x0F, 0x31, 0x2B, 0x0C, 0x0E, 0x08, 0x4E, 0xF1, 0x37, 0x07, 0x10, 0x03, 0x0E, 0x09, 0x00,
//        16, LCD_NGAMMA, 0x00, 0x0E, 0x14, 0x03, 0x11, 0x07, 0x31, 0xC1, 0x48, 0x08, 0x0F, 0x0C, 0x31, 0x36, 0x0F,
//        0
//};

//</editor-fold>

#endif //TEST2_INIT_COMMANDS_H
