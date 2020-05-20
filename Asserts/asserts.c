/**
  ******************************************************************************
  * @File    asserts.c
  * @Author  王北洛 <beiluo.wang@139.com>
  * @Date    Fri May 15 21:28:19 2020
  * @Brief   Assert.
  *
  *
  *
  ******************************************************************************
  *                         Copyright (C) 2020 王北洛
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "asserts.h"
#include "../Print/print.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables----------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Private functions----------------------------------------------------------*/

/* Public functions ----------------------------------------------------------*/

#ifdef USE_ASSERTS

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void asserts_failed(uint8_t* file, uint32_t line)
{
    Print_fmt("%s:%d: Params Assert Failed.\n", file, line);

    while (1)
    { }
}

#endif /* USE_ASSERTS */

/***********************************END OF FILE********************************/
