/*
 * file         src/firmware/io/gpio.h
 * author       harlan waldrop <root@aboyandhisgnu.org>
 * date         2016-06-24
 * description  GPIO manipulation for STM32F407
 *
 */

#ifndef _FIRMWARE_GPIO_H_
#define _FIRMWARE_GPIO_H_

#ifdef __cplusplus
  extern "C" {
#endif

#include "stm32f4xx.h"

#include <stdint.h>

typedef enum
{
  GPIO_MODE_IN  = ((uint32_t)0x0),
  GPIO_MODE_OUT = ((uint32_t)0x1),
  GPIO_MODE_ALT = ((uint32_t)0x2),
  GPIO_MODE_ANI = ((uint32_t)0x3)
} gpio_mode_t;

typedef enum
{
  GPIO_TYPE_PP = ((uint16_t)0x0),
  GPIO_TYPE_OD = ((uint16_t)0x1)
} gpio_type_t;

typedef enum
{
  GPIO_SPEED_2MHZ  = ((uint32_t)0x0),
  GPIO_SPEED_10MHZ = ((uint32_t)0x1),
  GPIO_SPEED_50MHZ = ((uint32_t)0x3),
} gpio_speed_t;

typedef enum
{
  GPIO_PUPD_NONE = ((uint32_t)0x0),
  GPIO_PUPD_UP   = ((uint32_t)0x1),
  GPIO_PUPD_DOWN = ((uint32_t)0x2)
} gpio_pupd_t;

typedef struct
{
  uint32_t port;
  uint32_t pin;
  gpio_mode_t mode;
  gpio_type_t type;
  gpio_speed_t speed;
  gpio_pupd_t pupd;
} gpio_init_t;

#define GPIO_PIN_0  0x0
#define GPIO_PIN_1  0x1
#define GPIO_PIN_2  0x2
#define GPIO_PIN_3  0x3
#define GPIO_PIN_4  0x4
#define GPIO_PIN_5  0x5
#define GPIO_PIN_6  0x6
#define GPIO_PIN_7  0x7
#define GPIO_PIN_8  0x8
#define GPIO_PIN_9  0x9
#define GPIO_PIN_10 0xA
#define GPIO_PIN_11 0xB
#define GPIO_PIN_12 0xC
#define GPIO_PIN_13 0xD
#define GPIO_PIN_14 0xE
#define GPIO_PIN_15 0xF

void gpio_init(GPIO_TypeDef *gpiox, gpio_init_t *init);

#ifdef __cplusplus
  }
#endif

#endif // _FIRMWARE_GPIO_H_
