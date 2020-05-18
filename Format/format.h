/**
  ******************************************************************************
  * @File    format.h
  * @Author  王北洛 <beiluo.wang@139.com>
  * @Date    Fri May 15 22:19:28 2020
  * @Brief   字符串格式化
  *
  *   轻量级字符串格式化函数。
  *
  ******************************************************************************
  *                         Copyright (C) 2020 王北洛
  ******************************************************************************
  */

#ifndef __FORMAT_H
#define __FORMAT_H

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include <stdarg.h>

/* Exported typedef ----------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/

/* Exported functions---------------------------------------------------------*/

uint32_t Fmt_sprintf(uint8_t *buf, uint32_t maxbuflen, const uint8_t *fmt, ...);
uint32_t Fmt_vstring(uint8_t *buf, const uint8_t *fmt, va_list va);
uint32_t Fmt_vlength(const uint8_t *fmt, va_list va);
void Fmt_itoa(uint8_t **buf, uint32_t d, uint32_t base);

#endif /* __FORMAT_H */

/***********************************END OF FILE********************************/
