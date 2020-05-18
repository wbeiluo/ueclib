/**
  ******************************************************************************
  * @File    print.h
  * @Author  王北洛 <beiluo.wang@139.com>
  * @Date    Sat May 16 21:14:00 2020
  * @Brief   打印输出
  *
  *   类似printf函数，用于将数据按照一定格式通过指定接口发送给其他设备解析。
  *
  ******************************************************************************
  *                         Copyright (C) 2020 王北洛
  ******************************************************************************
  */

#ifndef __PRINT_H
#define __PRINT_H

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include <stdarg.h>
#include <string.h>

/* Exported typedef ----------------------------------------------------------*/

/*
 * 数据发送格式，总长度为8个字节，其中前两个字节为状态字节，后6个字节为数据。
 */
typedef union _FrameBuffer
{
    struct
    {
        uint8_t f_num:4;  /* 总帧数 */
        uint8_t f_no:4;   /* 当前帧序号 */
        uint8_t d_num:4;  /* 有效数据字节数 */
        uint8_t type:4;   /* 帧类型 */
        uint8_t data[6];  /* 数据 */
    } frame;

    uint8_t buffer[8];
} FrameBuffer, *pFrameBuffer;


/*
 * 数据发送类型，根据类型解析解析数据
 */
enum _PRINT_TYPES
{
    P_FORMAT = 0x00,
    P_INT
};

/* Exported types ------------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/

#ifdef USE_PRINT

  /* 发送数据缓冲区字节大小 */
  #define PRINT_BUFFER_SIZE  128

/* Exported functions---------------------------------------------------------*/

  void print_f(const uint8_t *fmt, ...);

  #define Print_fmt(_fmt, ...) print_f((uint8_t*)_fmt, ##__VA_ARGS__)

#else

  #define Print_fmt(_fmt, ...) ((void)0)

#endif /* USE_PRINT */

#endif /* __PRINT_H */

/***********************************END OF FILE********************************/
