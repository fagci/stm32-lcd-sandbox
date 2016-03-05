#include "lib/lcd/graph.h"
#include "lib/usart/usart.h"

int main(void) {
    LCD_init();
    usartInit();

    usartPrintLn("BEGIN");
    LCD_fillRect(0, 0, LCD_getWidth(), LCD_getHeight(), RED);

    u16 c[1];
    usartPrintLn("start read");
    LCD_readPixels(0, 0, 0, 0, c);
    usartPrintLn("end read");

    LCD_fillRect(0, 0, LCD_getWidth(), LCD_getHeight(), GREEN);
    LCD_fillRect(0, 0, LCD_getWidth(), LCD_getHeight(), BLUE);
    usartPrintLn("END");
    while (1);
}
