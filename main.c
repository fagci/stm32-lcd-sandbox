#include "stm32f10x.h"

uint16_t delay_count;

void SysTick_Handler(void) {
    if (delay_count > 0) delay_count--;
}

void delay_ms(uint16_t delay_temp) {
    delay_count = delay_temp;
    while (delay_count);
}

void pin_ini(void) {
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
    GPIO_Init(GPIOC, &GPIO_InitStructure);
}

int main(void) {
    SysTick_Config(SystemCoreClock / 1000);
    pin_ini();
    while (1) {
        GPIOC->BSRR = GPIO_Pin_13;
        delay_ms(1000);
        GPIOC->BRR = GPIO_Pin_13;
        delay_ms(1000);
    }
}
