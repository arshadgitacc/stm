/**
  ******************************************************************************
  * @file    Cortex/CORTEXM_Cache/Inc/main.h 
  * @author  MCD Application Team
  * @brief   Header for main.c module
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2016 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

/* Includes ------------------------------------------------------------------*/
#include "string.h"
#include "stm32f7xx_hal.h"
#include "stm32f769i_eval.h"
#include "stm32_mpu.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Uncomment the corresponding line to select the MPU configuration */
//#define MPU_WRITE_THROUGH
#define MPU_WRITE_BACK_WRITE_ALLOCATE
//#define MPU_WRITE_BACK_NO_WRITE_ALLOCATE

#define DMA_INSTANCE               DMA2_Stream0
#define DMA_CHANNEL                DMA_CHANNEL_0
#define DMA_INSTANCE_IRQ           DMA2_Stream0_IRQn

#define BUFFER_SIZE                640   /* 80 Cache Lines */

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

#endif /* __MAIN_H */

