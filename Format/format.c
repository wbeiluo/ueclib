/**
  ******************************************************************************
  * @File    format.c
  * @Author  王北洛 <beiluo.wang@139.com>
  * @Date    Fri May 15 22:19:41 2020
  * @Brief   字符串格式化
  *
  *   轻量级字符串格式化函数。
  *
  ******************************************************************************
  *                         Copyright (C) 2020 王北洛
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "format.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables----------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Private functions----------------------------------------------------------*/

/* Public functions ----------------------------------------------------------*/

/**
  * @brief  转换fmt字符数组及参数至buf字符数组
  *
  * @param  buf:       转换结果字符数组
  * @param  maxbuflen: 转换结果字符数组buf的最大长度
  * @param  fmt:       需转换的原字符数组
  * @param  ...:       可变参数列表
  *
  * @retval 转换结果字符数组长度，若转换失败，返回 0
  */
uint32_t Fmt_sprintf(uint8_t *buf, uint32_t maxbuflen, const uint8_t *fmt, ...)
{
    uint32_t length = 0;
    va_list va;
    va_start(va, fmt);
    length = Fmt_vlength(fmt, va);
    va_end(va);

    if (length > maxbuflen)
        return 0;

    va_start(va, fmt);
    length = Fmt_vstring(buf, fmt, va);
    va_end(va);

    return length;
}

/**
  * @brief  将字符串fmt和可变参数va转换为buf字符串
  *
  * @param  buf:  转换结果字符数组
  * @param  fmt:  需转换字符数组
  * @param  va:   可变参数列表
  *
  * @retval 转换结果字符数组长度
  */
uint32_t Fmt_vstring(uint8_t *buf, const uint8_t *fmt, va_list va)
{
    uint8_t *start_buf = buf;
    while (*fmt)
    {
        /* Character needs formating? */
        if (*fmt == '%')
        {
            switch (*(++fmt))
            {
            case 'c':
                *buf++ = va_arg(va, int);
                break;
            case 'd':
            case 'i':
            {
                int32_t val = va_arg(va, int32_t);
                if (val < 0)
                {
                    val *= -1;
                    *buf++ = '-';
                }
                Fmt_itoa(&buf, val, 10);
            }
            break;
            case 's':
            {
                uint8_t *arg = va_arg(va, uint8_t *);
                while (*arg)
                {
                    *buf++ = *arg++;
                }
            }
            break;
            case 'u':
                Fmt_itoa(&buf, va_arg(va, uint32_t), 10);
                break;
            case 'x':
            case 'X':
                Fmt_itoa(&buf, va_arg(va, int32_t), 16);
                break;
            case '%':
                *buf++ = '%';
                break;
            }
            fmt++;
        }
        /* Else just copy */
        else
        {
            *buf++ = *fmt++;
        }
    }
    *buf = 0;

    return (int32_t)(buf - start_buf);
}

/**
  * @brief  从字符串fmt和不定参数va计算转换结果字符数组的最大长度
  *
  * @param  fmt:  转换字符数组
  * @param  va:   可变参数列表
  *
  * @retval 转换结果字符数组的最大长度
  */
uint32_t Fmt_vlength(const uint8_t *fmt, va_list va)
{
    uint32_t length = 0;
    while (*fmt)
    {
        if (*fmt == '%')
        {
            ++fmt;
            switch (*fmt)
            {
            case 'c':
                va_arg(va, int32_t);
                ++length;
                break;
            case 'd':
            case 'i':
            case 'u':
                /* 32 bits integer is max 11 characters with minus sign */
                length += 11;
                va_arg(va, int32_t);
                break;
            case 's':
            {
                uint8_t *str = va_arg(va, uint8_t *);
                while (*str++)
                    ++length;
            }
            break;
            case 'x':
            case 'X':
                /* 32 bits integer as hex is max 8 characters */
                length += 8;
                va_arg(va, uint32_t);
                break;
            default:
                ++length;
                break;
            }
        }
        else
        {
            ++length;
        }
        ++fmt;
    }
    return length;
}

/**
  * @brief  无符号整数转换为 ASCII 字符数组
  *
  * @param  buf:  转换结果字符指针数组
  * @param  d:    需转换的整数
  * @param  base: 转换进制
  *
  * @retval None
  */
void Fmt_itoa(uint8_t **buf, uint32_t d, uint32_t base)
{
    int32_t div = 1;
    while (d / div >= base)
        div *= base;

    while (div != 0)
    {
        int32_t num = d / div;
        d = d % div;
        div /= base;
        if (num > 9)
            *((*buf)++) = (num - 10) + 'A';
        else
            *((*buf)++) = num + '0';
    }
}


/***********************************END OF FILE********************************/
