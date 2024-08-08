#include "RTE_Components.h"
#include "stm32f10x_gpio.h"
#include <stdio.h>
#include CMSIS_device_header
#include "Delay.h"
int main() {
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
  GPIO_InitTypeDef GPIO_InitStructure;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  // GPIO_ResetBits(GPIOA, GPIO_Pin_0);

  for (;;) {
    GPIO_ResetBits(GPIOA, GPIO_Pin_0); // 点亮
    Delay_ms(500);
    GPIO_SetBits(GPIOA, GPIO_Pin_0); // 熄灭
    Delay_ms(500);

    GPIO_WriteBit(GPIOA, GPIO_Pin_0, 1);   // 点亮LED
    Delay_ms(500);                               // 延时
    GPIO_WriteBit(GPIOA, GPIO_Pin_0, Bit_RESET); // 熄灭LED
    Delay_ms(500);
  }
}
