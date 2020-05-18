/**
  ******************************************************************************
  * @File    array_t.h
  * @Author  王北洛 <beiluo.wang@139.com>
  * @Date    Thu May 14 22:45:56 2020
  * @Brief   抽象数组
  *
  *    抽象数组是对数组行为的抽象，无关数据类型。数组大小、元素大小以及存储元素的静态
  * 数组在初始化时指定。
  *
  * 函数说明：
  *   Array_init    初始化数组
  *   Array_length  数组大小
  *   Array_size    元素大小
  *   Array_get     获取数组元素
  *   Array_put     存储数据元素至数组
  *
  ******************************************************************************
  *                         Copyright (C) 2020 王北洛
  ******************************************************************************
  */

#ifndef __ARRAY_T_H
#define __ARRAY_T_H

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include <string.h>

/* Exported typedef ----------------------------------------------------------*/

/* 数组结构 */
typedef struct _ARRAY_T
{
    uint32_t length;  /* 数组大小 */
    uint32_t size;    /* 元素大小 */
    uint8_t *array;   /* 实际存储数据的数组 */
} Array_t, *pArray_T;

/* Exported types ------------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/

/* Exported functions---------------------------------------------------------*/
void Array_init(pArray_T array, uint32_t length, uint32_t size, void* ary);
uint32_t Array_length(pArray_T array);
uint32_t Array_size(pArray_T array);
void *Array_get(pArray_T array, uint32_t i);
void *Array_put(pArray_T array, uint32_t i, const void* elem);


#endif /* __ARRAY_T_H */

/***********************************END OF FILE********************************/
