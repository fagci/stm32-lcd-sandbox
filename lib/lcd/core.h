#ifndef TEST2_CORE_H
#define TEST2_CORE_H

#include "colors.h"
#include "../delay.h"
#include "control.h"
#include "init_commands.h"

#define __always_inline inline __attribute__((always_inline))

void LCD_init();

u16 LCD_getWidth();
u16 LCD_getHeight();

u8  LCD_spiRW8(u8 data);
u16 LCD_spiRW16(u16 data);

void LCD_setSpi8(void);
void LCD_setSpi16(void);

void LCD_sendCommand8(u8 cmd);
void LCD_sendData8(u8 data);
void LCD_sendData16(u16 data);

void LCD_setOrientation(u8 o);
void LCD_setAddressWindow(u16 x1, u16 y1, u16 x2, u16 y2);

#endif //TEST2_CORE_H
