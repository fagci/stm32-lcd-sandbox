#include "graph.h"

void LCD_fillRect(u16 x1, u16 y1, u16 w, u16 h, u16 color) {
    u32 count = w * h;
    LCD_setAddressWindow(x1, y1, (u16) (x1 + w - 1), (u16) (y1 + h - 1));

    TFT_CS_RESET;

    LCD_sendCommand8(LCD_RAMWRITE);
    LCD_setSpi16();
    while (count--) {
        LCD_sendData16(color);
    }
    LCD_setSpi8();

    TFT_CS_SET;
}

void LCD_readPixels(u16 x1, u16 y1, u16 x2, u16 y2, u16 *buf) {
    u8  red, green, blue;
    u32 count = (u32) ((x2 - x1 + 1) * (y2 - y1 + 1));

    LCD_setAddressWindow(x1, y1, x2, y2);
    TFT_CS_RESET;
    LCD_sendCommand8(LCD_RAMREAD);
    TFT_DC_SET;
    LCD_spiRW8(0xFF); // empty

    for (int i = 0; i < count; ++i) {
        red   = LCD_spiRW8(0xFF);
        green = LCD_spiRW8(0xFF);
        blue  = LCD_spiRW8(0xFF);

        buf[i] = (u16) ILI9341_COLOR(red, green, blue);
    }

    TFT_CS_SET;
}
