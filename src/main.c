#include "stm32f4_discovery.h"
#include "stm32f4xx_conf.h"
#include "firmware/io/gpio.h"
#include "utils/regman.h"

#define LED_OKAY   ((uint16_t)0x1000)
#define LED_WARN   ((uint16_t)0x2000)
#define LED_ERROR  ((uint16_t)0x4000)
#define LED_STATUS ((uint16_t)0x8000)

#define BLINK_DELAY 0xEFFFFF

void delay(__IO uint32_t dt)
{
  while (dt--);
}

int main(void)
{
  //RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
  SET_WORD(RCC->AHB1ENR, 1UL, 3);

  gpio_init_t init = {
    .pin   = GPIO_PIN_12,
    .mode  = GPIO_MODE_OUT,
    .type  = GPIO_TYPE_OD,
    .speed = GPIO_SPEED_2MHZ,
    .pupd  = GPIO_PUPD_DOWN
  };

  gpio_init(GPIOD, &init);

  while (1)
  {
    GPIOD->BSRRL = LED_OKAY;
    delay(BLINK_DELAY);
    GPIOD->BSRRH = LED_OKAY;
    delay(BLINK_DELAY);
  }
}
