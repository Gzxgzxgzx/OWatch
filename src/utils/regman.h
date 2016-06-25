/*
 * file         src/firmware/regman.h
 * author       harlan waldrop <root@aboyandhisgnu.org>
 * date         2016-06-24
 * description  Register manipulation for STM32F407
 *
 */

#ifndef _FIRMWARE_IO_REGISTER_H_
#define _FIRMWARE_IO_REGISTER_H_

#ifdef __cplusplus
  extern "C" {
#endif

#define CLR_DWORD(REG, PIN)      REG &= ~((3UL << 2*PIN))
#define SET_DWORD(REG, SET, PIN) REG |=  ((SET << 2*PIN))

#define CLR_WORD(REG, PIN)      REG &= ~((1UL << PIN))
#define SET_WORD(REG, SET, PIN) REG |=  ((SET << PIN))

#ifdef __cplusplus
  }
#endif

#endif // _FIRMWARE_IO_REGISTER_H_
