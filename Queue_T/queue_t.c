/**
  ******************************************************************************
  * @File    queue_t.c
  * @Author  王北洛 <beiluo.wang@139.com>
  * @Date    Tue May 19 10:11:51 2020
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
  * @attention
  *   该队列的实现采用静态数组存储队列数据，因此在队列初始化的时候也要初始化数据数组。
  *
  ******************************************************************************
  *                         Copyright (C) 2020 王北洛
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "queue_t.h"

#include "../Asserts/asserts.h"
#include "../Print/print.h"


/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
static int Loop(pQueue_T queue, uint32_t value);

/* Private functions ---------------------------------------------------------*/

/**
 * @Brief 队列索引循环
 *
 * @param queue  队列
 * @param value  队列元素索引值
 *
 * @return 增加的索引值
 */
static int Loop(pQueue_T queue, uint32_t value)
{
    Asserts_param(queue != NULL);

    if (++value == queue->capacity)
        value = 0;

    return value;
}

/* Public functions ----------------------------------------------------------*/

/**
  * @brief  队列初始化
  *
  *     使用该函数初始化队列：设置队列大小，设置队列元素大小，并初始化存储数据的数组。
  *
  * @param  queue      队列
  * @param  length     队列长度
  * @param  data_size  队列中单个元素的大小
  * @param  data_ary   队列存储数据的数组
  *
  * @retval 无
  */
void Queue_init(pQueue_T queue, uint32_t length, uint32_t data_size, void *data_ary)
{
    Asserts_param(queue != NULL);
    Asserts_param((length > 0) && (data_size > 0));
    Asserts_param(data_ary != NULL);

    Array_init(&queue->array, length, data_size, data_ary);
    queue->capacity = length;
    queue->size = 0;
    queue->front = 1;
    queue->rear = 0;
}

/**
  * @brief  添加元素elem到队尾
  *
  *   注意：当队列已满时，会覆盖队头的元素。
  *
  * @param  queue  队列
  * @param  elem   元素
  *
  * @retval None.
  */
void Queue_push(pQueue_T queue, const void *elem)
{
    Asserts_param(queue != NULL);
    Asserts_param(elem != NULL);

    if (queue->size == queue->capacity)
    {
        Print_fmt("Warning: Queue is out of range. The front elem was overwritten.\r\n");
        //队列溢出，覆盖队列最前位置的值
        queue->front = Loop(queue, queue->front);
    }
    else
    {
        queue->size++;
    }

    queue->rear = Loop(queue, queue->rear);
    Array_put(&queue->array, queue->rear, elem);
}

/**
  * @brief  返回队头元素并从队列中删除
  *
  * @param  queue  队列
  *
  * @retval 返回队头元素
  *         若队列为空，则返回NULL
  */
void *Queue_pop(pQueue_T queue)
{
    void *result;

    Asserts_param(queue != NULL);

    if (Queue_empty(queue))
    {
        result = Array_get(&queue->array, queue->front);
        queue->size--;
        queue->front = Loop(queue, queue->front);
        return result;
    }
    else
    {
        Print_fmt("Warning: Queue is empty.\r\n");
        return NULL;
    }
}

/**
  * @brief  返回队头元素但不从队列删除
  *
  * @param  queue  队列
  *
  * @retval 返回队头元素
  *         若队列为空，则返回NULL
  */
void *Queue_front(pQueue_T queue)
{
    Asserts_param(queue != NULL);

    if (Queue_empty(queue))
    {
        return Array_get(&queue->array, queue->front);

    }
    else
    {
        Print_fmt("Warning: Queue is empty.\r\n");
        return NULL;
    }
}

/**
  * @brief  返回队尾元素
  *
  * @param  queue  队列
  *
  * @retval 队尾元素
  *         若队列为空，则返回NULL
  */
void *Queue_back(pQueue_T queue)
{
    Asserts_param(queue != NULL);

    if (Queue_empty(queue))
    {
        return Array_get(&queue->array, queue->rear);
    }
    else
    {
        Print_fmt("Warning: Queue is empty.\r\n");
        return NULL;
    }
}

/**
  * @brief  返回当前队列元素个数
  *
  * @param  queue  队列
  *
  * @retval 当前队列元素个数
  */
uint32_t Queue_size(pQueue_T queue)
{
    Asserts_param(queue != NULL);

    return queue->size;
}

/**
  * @brief  返回当前队列是否为空
  *
  * @param  queue  队列
  *
  * @retval 1 队列为空
  *         0 队列非空
  */
uint32_t Queue_empty(pQueue_T queue)
{
    Asserts_param(queue != NULL);

    return queue->size == 0;
}


/***********************************END OF FILE********************************/
