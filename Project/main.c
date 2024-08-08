#include "RTE_Components.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include CMSIS_device_header
#include "Delay.h"

int main() {

  GPIO_InitTypeDef GPIO_InitStructure;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
  GPIO_Init(GPIOB, &GPIO_InitStructure);

  for (;;) {

    GPIO_Write(GPIOA, ~0x0001);
    Delay_ms(500);
    GPIO_Write(GPIOA, ~0x0002);
    Delay_ms(500);
    GPIO_Write(GPIOA, ~0x0004);
    Delay_ms(500);

    GPIO_ResetBits(GPIOB, GPIO_Pin_12);
    Delay_ms(500);
    GPIO_SetBits(GPIOB, GPIO_Pin_12);
    Delay_ms(500);
  }
}
