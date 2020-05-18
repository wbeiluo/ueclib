/**
  ******************************************************************************
  * @File    asserts.h
  * @Author  王北洛 <beiluo.wang@139.com>
  * @Date    Fri May 15 21:28:00 2020
  * @Brief   Assert.
  *
  *
  *
  ******************************************************************************
  *                         Copyright (C) 2020 王北洛
  ******************************************************************************
  */

#ifndef __ASSERTS_H
#define __ASSERTS_H

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>

/* Exported typedef ----------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/

#ifdef  USE_ASSERTS

/**
  * @brief  The assert_param macro is used for function's parameters check.
  * @param  expr: If expr is false, it calls assert_failed function which reports
  *         the name of the source file and the source line number of the call
  *         that failed. If expr is true, it returns no value.
  * @retval None
  */
  #define Asserts_param(expr) ((expr) ? (void)0 : asserts_failed((uint8_t *)__FILE__, __LINE__))

/* Exported functions---------------------------------------------------------*/
  void asserts_failed(uint8_t* file, uint32_t line);

#else

  #define Asserts_param(expr) ((void)0)

#endif /* USE_ASSERTS */


#endif /* __ASSERTS_H */

/***********************************END OF FILE********************************/
