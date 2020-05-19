/**
  ******************************************************************************
  * @File    queue_t.h
  * @Author  王北洛 <beiluo.wang@139.com>
  * @Date    Tue May 19 10:11:31 2020
  * @Brief   抽象队列
  *
  *   队列是一种先进先出（First in First Out）的线性表，允许在一端（队尾）进行插入操作，而在
  * 另一端（队头）进行删除操作。
  *
  * 函数接口：
  *   Queue_init  初始化队列
  *   Queue_push  添加元素至队尾
  *   Queue_pop   取出队头元素，并从队列中删除该元素
  *   Queue_front 取出队头元素，但不删除该元素
  *   Queue_back  取出队尾元素，但不删除该元素
  *   Queue_size  返回队列中元素的个数
  *   Queue_empty 判断队列是否为空，为空返回true
  *
  *
  ******************************************************************************
  *                         Copyright (C) 2020 王北洛
  ******************************************************************************
  */

#ifndef __QUEUE_T_H
#define __QUEUE_T_H

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>

#include "../Array_T/array_t.h"

/* Exported typedef ----------------------------------------------------------*/

/* 定义队列的数据结构 */
typedef struct _QUEUE_T
{
    uint32_t capacity; /* 队列容量，即队列最大存储数据个数 */
    uint32_t size;     /* 当前队列大小，即队列内存在的数据个数 */
    uint32_t front;    /* 队列前端位置 */
    uint32_t rear;     /* 队列末尾位置 */
    Array_t  array;    /* 存储队列数据的数组 */
} Queue_T, *pQueue_T;

/* Exported types ------------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/

/* Exported functions --------------------------------------------------------*/

void Queue_init(pQueue_T queue, uint32_t length, uint32_t data_size, void *data_ary);
void Queue_push(pQueue_T queue, const void *elem);
void *Queue_pop(pQueue_T queue);
void *Queue_front(pQueue_T queue);
void *Queue_back(pQueue_T queue);
uint32_t Queue_size(pQueue_T queue);
uint32_t Queue_empty(pQueue_T queue);

#endif /* __QUEUE_T_H */

/***********************************END OF FILE********************************/
