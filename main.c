#include "lib/lcd/graph.h"
#include "lib/usart/usart.h"

int main(void) {
    LCD_init();
    usartInit();

    u16 testColor = RED;

    usartPrintLn("BEGIN");
    LCD_fillRect(0, 0, LCD_getWidth(), LCD_getHeight(), testColor);

    u16 c[1];
    usartPrintLn("start read");

    LCD_readPixels(0, 0, 0, 0, c);
    if (c[0] == testColor) usartPrintLn("COLORS SAME!");
    usartPrint("0x"), usartPrintNum(c[0], 16), usartPrintLn("");

    usartPrintLn("end read");

    LCD_fillRect(0, 0, LCD_getWidth(), LCD_getHeight(), GREEN);
    usartPrintLn("END");
    while (1);
}
