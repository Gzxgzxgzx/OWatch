#include "stm32f4_discovery.h"
#include "stm32f4xx_conf.h"

#define BLINK_DELAY 0xEFFFFF

GPIO_InitTypeDef GPIO_InitStructure;

void delay(__IO uint32_t dt)
{
  while (dt--); 
}

int main(void)
{
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13| GPIO_Pin_14| GPIO_Pin_15;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOD, &GPIO_InitStructure);

  uint8_t i = 0;
  uint16_t p;
  while (1)
  {
    switch (i) {
      case 0:
          p = GPIO_Pin_12;
          break;
      case 1:
          p = GPIO_Pin_13;
          break;
      case 2:
          p = GPIO_Pin_14;
          break;
      case 3:
          p = GPIO_Pin_15;
          break;
    }

    GPIO_SetBits(GPIOD, p);
    delay(BLINK_DELAY);
    GPIO_ResetBits(GPIOD, p);
    delay(BLINK_DELAY);
 
    if (++i == 4) {
      i = 0;
    }
  }
}
