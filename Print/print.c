/**
  ******************************************************************************
  * @File    print.c
  * @Author  王北洛 <beiluo.wang@139.com>
  * @Date    Sat May 16 21:13:47 2020
  * @Brief   打印输出
  *
  *   类似printf函数，用于将数据按照一定格式通过指定接口发送给其他设备解析。
  *
  ******************************************************************************
  *                         Copyright (C) 2020 王北洛
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "print.h"
#include "transmit_conf.h"
#include "../Format/format.h"

#ifdef USE_PRINT

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables----------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
static uint16_t print_puts(enum _PRINT_TYPES type, uint8_t *buf, uint16_t len);


/* Private functions----------------------------------------------------------*/

/**
  * @brief  数据传输
  *   根据实际传输数据长度，分组传输数据。
  *
  * @param  buf   数据数组
  * @param  len   数据长度
  *
  * @retval 发送的数据长度
  */
static uint16_t print_puts(enum _PRINT_TYPES type,uint8_t *buf, uint16_t len)
{
    if ((buf == NULL) || (len == 0))
        return 0;

    FrameBuffer frame;     /* 帧格式 */
    uint8_t num = 0;       /* 总帧数 */
    uint8_t no = 0;        /* 帧序号 */
    uint16_t position = 0; /* 发送数据的数组位置 */

    /* 计算总帧数 */
    num = len / 6;
    if ((len % 6) > 0)
        num++;

    /* 连续发送数据 */
    for (no = 0; no < num; no++)
    {
        frame.frame.type = type;
        frame.frame.f_num = num;
        frame.frame.f_no = no;
        /* 设置每帧发送的数据字节数 */
        if ((len - position) >= 6)
        {
            frame.frame.d_num = 6;
        }
        else
        {
            frame.frame.d_num = len - position;
        }

        /* 复制数据 */
        memcpy(frame.frame.data, &buf[position], frame.frame.d_num);

        /* 记录发送位置 */
        position += frame.frame.d_num;

        /* 数据发送 */
        transmit(frame.buffer, TRANSMIT_LENGTH);
    }

    return position;
}

/* Public functions ----------------------------------------------------------*/


/**
  * @brief  打印字符串。
  *
  * @param  fmt   字符数组
  * @param  ...   可变参数列表
  * @retval 无
  */
void print_f(const uint8_t *fmt, ...)
{
    uint8_t buffer[PRINT_BUFFER_SIZE];
    uint16_t length = 0;
    va_list va;

    va_start(va, fmt);
    length = Fmt_vlength(fmt, va);
    va_end(va);

    if ((length == 0) || (length > PRINT_BUFFER_SIZE))
        return;

    va_start(va, fmt);
    length = Fmt_vstring(buffer, fmt, va);
    va_end(va);

    print_puts(P_FORMAT, buffer, length);
}

#endif /* USE_PRINT */

/***********************************END OF FILE********************************/
