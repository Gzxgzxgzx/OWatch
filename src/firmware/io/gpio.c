/*
 * file         src/firmware/gpio.c
 * author       harlan waldrop <root@aboyandhisgnu.org>
 * date         2016-06-24
 * description  GPIO manipulation for STM32F407
 *
 */

#include "gpio.h"

#include "utils/regman.h"

/*
 * description  Initializes the GPIO peripheral for port x
 * note         Bit masking multiple pins is not supported                   (!)
 * param        gpiox: Selects a port where x can be [A, I]
 * param        init: Pointer to a structure containing initialization
                settings for the specified port.
 * retval       -
 */
void gpio_init(GPIO_TypeDef *gpiox, gpio_init_t *init)
{
  /* FUNC        REGISTER              CONFIG BITS       PIN NUMBER */
  CLR_DWORD      (gpiox->MODER,        /* MASK */        init->pin);
  SET_DWORD      (gpiox->MODER,        init->mode,       init->pin);
  CLR_WORD       (gpiox->OTYPER,       /* MASK */        init->pin);
  CLR_DWORD      (gpiox->OSPEEDR,      /* MASK */        init->pin);
  SET_DWORD      (gpiox->OSPEEDR,      init->speed,      init->pin);
  CLR_DWORD      (gpiox->PUPDR,        /* MASK */        init->pin);
  SET_DWORD      (gpiox->PUPDR,        init->pupd,       init->pin);
}
