#include "lib/lcd/graph.h"




int main(void) {
    LCD_init();

    LCD_fillRect(0, 0, LCD_getWidth(), LCD_getHeight(), RED);

    u16 c[1];
    TFT_CS_RESET;
    LCD_readPixels(0, 0, 0, 0, c);
    TFT_CS_SET;

    LCD_fillRect(0, 0, LCD_getWidth(), LCD_getHeight(), GREEN);
    LCD_fillRect(0, 0, LCD_getWidth(), LCD_getHeight(), BLUE);
    while (1);
}
