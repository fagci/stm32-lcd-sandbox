#ifndef TEST2_CONFIG_H
#define TEST2_CONFIG_H

//<editor-fold desc="Pins & defaults">

#define TFT_LED_PIN     GPIO_Pin_0
#define TFT_RESET_PIN   GPIO_Pin_2
#define TFT_DC_PIN      GPIO_Pin_3
#define TFT_CS_PIN      GPIO_Pin_4

#define SPI_MASTER                   SPI1
#define SPI_MASTER_CLK               RCC_APB2Periph_SPI1
#define SPI_MASTER_GPIO              GPIOA
#define SPI_MASTER_GPIO_CLK          RCC_APB2Periph_GPIOA
#define SPI_MASTER_PIN_NSS           GPIO_Pin_4
#define SPI_MASTER_PIN_SCK           GPIO_Pin_5
#define SPI_MASTER_PIN_MISO          GPIO_Pin_6
#define SPI_MASTER_PIN_MOSI          GPIO_Pin_7

#define LCD_PIXEL_WIDTH       240
#define LCD_PIXEL_HEIGHT      320

//</editor-fold>

#endif //TEST2_CONFIG_H
