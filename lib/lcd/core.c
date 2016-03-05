#include <stm32f10x_spi.h>
#include "core.h"

//<editor-fold desc="RW Functions">

__always_inline u16 LCD_spiRW16(u16 data) {
    SPI_I2S_SendData(SPI_MASTER, data);
    while (SPI_I2S_GetFlagStatus(SPI_MASTER, SPI_I2S_FLAG_TXE) == RESET); // wait while is not ready to tx
    while (SPI_I2S_GetFlagStatus(SPI_MASTER, SPI_I2S_FLAG_BSY) == SET);   // wait while tx line is busy
    if (SPI_I2S_GetFlagStatus(SPI_MASTER, SPI_I2S_FLAG_RXNE) == SET)
        return SPI_I2S_ReceiveData(SPI_MASTER);
    return 0;
}

__always_inline u8 LCD_spiRW8(u8 data) {
    return (u8) LCD_spiRW16(data);
}

__always_inline void LCD_sendCommand8(u8 cmd) {
    TFT_DC_RESET;
    LCD_spiRW8(cmd);
}

__always_inline void LCD_sendData8(u8 d) {
    TFT_DC_SET;
    LCD_spiRW8(d);
}

__always_inline void LCD_sendData16(u16 d) {
    TFT_DC_SET;
    LCD_spiRW16(d);
}

__always_inline void LCD_setSpi8(void) {
    SPI_MASTER->CR1 &= ~SPI_CR1_SPE; // DISABLE SPI
    SPI_MASTER->CR1 &= ~SPI_CR1_DFF; // SPI 8
    SPI_MASTER->CR1 |= SPI_CR1_SPE;  // ENABLE SPI
}

__always_inline void LCD_setSpi16(void) {
    SPI_MASTER->CR1 &= ~SPI_CR1_SPE; // DISABLE SPI
    SPI_MASTER->CR1 |= SPI_CR1_DFF;  // SPI 16
    SPI_MASTER->CR1 |= SPI_CR1_SPE;  // ENABLE SPI
}

//</editor-fold>

//<editor-fold desc="LCD operations">

u16 screen_height,
    screen_width;

void LCD_pinsInit() {
    SPI_InitTypeDef  spiStructure;
    GPIO_InitTypeDef gpioStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2ENR_AFIOEN, ENABLE);
    RCC_APB2PeriphClockCmd(SPI_MASTER_GPIO_CLK | SPI_MASTER_CLK, ENABLE);

    // default speed
    gpioStructure.GPIO_Speed = GPIO_Speed_50MHz;

    // CS/DC/LED/RESET
    gpioStructure.GPIO_Pin  = TFT_CS_PIN | TFT_DC_PIN | TFT_RESET_PIN | TFT_LED_PIN;
    gpioStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(GPIOA, &gpioStructure);

    // SPI
    gpioStructure.GPIO_Pin  = SPI_MASTER_PIN_SCK | SPI_MASTER_PIN_MOSI | SPI_MASTER_PIN_NSS;
    gpioStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(SPI_MASTER_GPIO, &gpioStructure);

    gpioStructure.GPIO_Pin  = SPI_MASTER_PIN_MISO;
    gpioStructure.GPIO_Mode = GPIO_Mode_IPU; // Input pull-up
    GPIO_Init(SPI_MASTER_GPIO, &gpioStructure);

    SPI_StructInit(&spiStructure);
    spiStructure.SPI_Mode              = SPI_Mode_Master;
    spiStructure.SPI_CPOL              = SPI_CPOL_High;
    spiStructure.SPI_CPHA              = SPI_CPHA_2Edge;
    SPI_Init(SPI_MASTER, &spiStructure);

    SPI_SSOutputCmd(SPI_MASTER, ENABLE);
    SPI_Cmd(SPI_MASTER, ENABLE);
}

__always_inline void LCD_reset() {
    TFT_RST_SET;
    delay_ms(10);
    TFT_RST_RESET;
    delay_ms(10);
    TFT_RST_SET;
    delay_ms(150);
}

__always_inline void LCD_exitStandby() {
    TFT_CS_RESET;
    LCD_sendCommand8(LCD_SLEEP_OUT);
    delay_ms(150);
    LCD_sendCommand8(LCD_DISPLAY_ON);
    TFT_CS_SET;
}

__always_inline u16 LCD_getWidth() {
    return screen_width;
}

__always_inline u16 LCD_getHeight() {
    return screen_height;
}

__always_inline void LCD_setOrientation(u8 o) {
    if (o == ORIENTATION_LANDSCAPE || o == ORIENTATION_LANDSCAPE_MIRROR) {
        screen_height = LCD_PIXEL_WIDTH;
        screen_width  = LCD_PIXEL_HEIGHT;
    } else {
        screen_height = LCD_PIXEL_HEIGHT;
        screen_width  = LCD_PIXEL_WIDTH;
    }
    TFT_CS_RESET;
    LCD_sendCommand8(LCD_MAC);
    LCD_sendData8(o);
    TFT_CS_SET;
}

__always_inline void LCD_setAddressWindow(u16 x1, u16 y1, u16 x2, u16 y2) {
    TFT_CS_RESET;
    LCD_sendCommand8(LCD_COLUMN_ADDR);
    LCD_setSpi16();
    LCD_sendData16(x1);
    LCD_sendData16(x2);
    LCD_setSpi8();

    LCD_sendCommand8(LCD_PAGE_ADDR);
    LCD_setSpi16();
    LCD_sendData16(y1);
    LCD_sendData16(y2);
    LCD_setSpi8();
    TFT_CS_SET;
}

void LCD_configure() {
    u8 count;
    u8 *address = (u8 *) init_commands;

    TFT_CS_RESET;
    while (1) {
        count = *(address++);
        if (count-- == 0) break;
        LCD_sendCommand8(*(address++));
        while (count-- > 0) {
            LCD_sendData8(*(address++));
        }
    }
    TFT_CS_SET;
    LCD_setOrientation(0);
    LCD_setAddressWindow(0, 0, screen_width, screen_height);
}

void LCD_init() {
    LCD_pinsInit();
    LCD_reset();
    LCD_exitStandby();
    LCD_configure();
    TFT_LED_SET;
}

//</editor-fold>
