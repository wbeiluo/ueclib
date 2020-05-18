/**
  ******************************************************************************
  * @File    array_t.c
  * @Author  王北洛 <beiluo.wang@139.com>
  * @Date    Thu May 14 22:50:13 2020
  * @Brief   抽象数组
  *
  *    抽象数组是对数组行为的抽象，无关数据类型。数组大小、元素大小以及存储元素的静态
  * 数组在初始化时指定。
  *    抽象数组的元素以字节序列的方式存储，以当前元素首地址+元素大小的方式进行读取。
  *
  ******************************************************************************
  *                         Copyright (C) 2020 王北洛
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "array_t.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables----------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Private functions----------------------------------------------------------*/

/* Public functions ----------------------------------------------------------*/

/**
  * @brief  初始化 Array_T
  * @param  无
  * @retval 无
  */
void Array_init(pArray_T array, uint32_t length, uint32_t size, void *ary)
{
    if ((array == NULL) || (ary == NULL)
        || (length == 0) || (size == 0))
    {
        length = 0;
        size = 0;
        return;
    }

    array->length = length;
    array->size = size;
    array->array = ary;
}

/**
  * @brief  获取数组中的第i个元素
  * @param  array  指定数组
  * @param  i      第i个元素(从0开始)
  *
  * @retval 第i个元素
  */
void *Array_get(pArray_T array, uint32_t i)
{
    if (array == NULL)
        return NULL;
    if (i >= array->length)
        return NULL;

    return array->array + i * array->size;
}

/**
  * @brief  将元素elem存入数组索引i的位置
  * @param  array  指定数组
  * @param  i      第i个元素(从0开始)
  * @param  elem   存入的元素
  *
  * @retval 无
  */
void *Array_put(pArray_T array, uint32_t i, const void *elem)
{
    if ((array == NULL) || (elem == NULL))
        return NULL;
    if (i >= array->length)
        return NULL;

    return memcpy(array->array + i * array->size, elem, array->size);
}

/**
  * @brief  返回数组的长度
  * @param  array  指定数组
  *
  * @retval 数组的长度
  */
uint32_t Array_length(pArray_T array)
{
    if (array == NULL)
        return 0;

    return array->length;
}

/**
  * @brief  返回数组单个元素的大小
  * @param  array  指定数组
  *
  * @retval 元素的大小
  */
uint32_t Array_size(pArray_T array)
{
    if (array == NULL)
        return 0;

    return array->size;
}


/***********************************END OF FILE********************************/
