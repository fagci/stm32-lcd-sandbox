#ifndef TEST2_CONTROL_H
#define TEST2_CONTROL_H

#include "config.h"
#include "commands.h"
#include "stm32f10x.h"

// <editor-fold desc="Functions">
#define TFT_DC_SET      GPIO_SetBits(GPIOA, TFT_DC_PIN);
#define TFT_DC_RESET    GPIO_ResetBits(GPIOA, TFT_DC_PIN);
#define TFT_RST_SET     GPIO_SetBits(GPIOA, TFT_RESET_PIN);
#define TFT_RST_RESET   GPIO_ResetBits(GPIOA, TFT_RESET_PIN);
#define TFT_CS_SET      GPIO_SetBits(GPIOA, TFT_CS_PIN);
#define TFT_CS_RESET    GPIO_ResetBits(GPIOA, TFT_CS_PIN);
#define TFT_LED_SET      GPIO_SetBits(GPIOA, TFT_LED_PIN);
#define TFT_LED_RESET    GPIO_ResetBits(GPIOA, TFT_LED_PIN);

#define ILI9341_COLOR(r, g, b)\
     ((((uint16_t)b) >> 3) |\
            ((((uint16_t)g) << 3) & 0x07E0) |\
            ((((uint16_t)r) << 8) & 0xf800))

// </editor-fold>

#endif //TEST2_CONTROL_H
