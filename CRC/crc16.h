/**
  ******************************************************************************
  * @File    crc16.h
  * @Author  王北洛 <beiluo.wang@139.com>
  * @Date    Tue May 19 11:20:49 2020
  * @Brief   CRC16 implementation according to CCITT standards.
  *
  * Name                       : "XMODEM", also known as "ZMODEM", "CRC-16/ACORN"
  * Width                      : 16 bit
  * Poly                       : 1021 (That is actually x^16 + x^12 + x^5 + 1)
  * Initialization             : 0000
  * Reflect Input byte         : False
  * Reflect Output CRC         : False
  * Xor constant to output CRC : 0000
  * Output for "123456789"     : 31C3
  *
  ******************************************************************************
  *                         Copyright (C) 2020 王北洛
  ******************************************************************************
  */

#ifndef __CRC16_H
#define __CRC16_H

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>

/* Exported typedef ----------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/

/* Exported functions --------------------------------------------------------*/
uint16_t crc16(const char *buf, int len);

#endif /* __CRC16_H */

/***********************************END OF FILE********************************/
