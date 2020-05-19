/**
  ******************************************************************************
  * @File    cocktailsort.c
  * @Author  王北洛 <beiluo.wang@139.com>
  * @Date    Tue May 19 11:37:50 2020
  * @Brief   定向冒泡排序算法
  *
  *
  *
  ******************************************************************************
  *                         Copyright (C) 2020 王北洛
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "cocktailsort.h"
#include "swap.h"

#include <string.h>

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Private functions ---------------------------------------------------------*/

/* Public functions ----------------------------------------------------------*/

/**
  * @brief  对长度为length的浮点数组进行从小到大排序。
  *
  *     算法：定向冒泡排序算法
  *     方式：从小到大排序
  *     平均时间复杂度：O(n^2)
  *
  * @param  value   被排序数组
  * @param  length  被排序数组大小
  *
  * @retval 1   排序成功
  *         0   排序失败
  */
int32_t CocktailSort(float *value, uint32_t length)
{
    /* 初始化边界 */
    uint32_t left = 0;
    uint32_t right = length - 1;
    uint32_t i = 0;

    if ((value == NULL) || (length == 0))
        return 0;

    if (length == 1)
        return length;

    while (left < right)
    {
        for (i = left; i < right; ++i) /* 前半轮将最大元素放到后面 */
        {
            if (*(value + i) > *(value + i + 1))
            {
                if (Swap_float_ary(value, length, i, i + 1) != 1)
                    return 0;
            }
        }
        --right;
        for (i = right; i > left; --i) /* 后半轮将最小元素放到前面 */
        {
            if (*(value + i - 1) > *(value + i))
            {
                if (Swap_float_ary(value, length, i - 1, i) != 1)
                    return 0;
            }
        }
        ++left;
    }

    return 1;
}

/***********************************END OF FILE********************************/
