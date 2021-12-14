/**
  ******************************************************************************
  * @file    PWR/PWR_CurrentConsumption/stm32f7xx_lp_modes.h
  * @author  MCD Application Team
  * @brief   Header for stm32f7xx_lp_modes.c module
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
#ifndef __STM32F7xx_LP_MODES_H
#define __STM32F7xx_LP_MODES_H

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
#if !defined (SLEEP_MODE) && !defined (STOP_MODE) && !defined (STANDBY_MODE)\
 && !defined (STANDBY_RTC_MODE) && !defined (STANDBY_BKPSRAM_MODE)
/* Uncomment the corresponding line to select the STM32F7xx Low Power mode */
/*#define SLEEP_MODE*/
/*#define STOP_MODE*/
/*#define STANDBY_MODE*/
/*#define STANDBY_RTC_MODE*/
#define STANDBY_BKPSRAM_MODE
#endif

#if !defined (SLEEP_MODE) && !defined (STOP_MODE) && !defined (STANDBY_MODE)\
 && !defined (STANDBY_RTC_MODE) && !defined (STANDBY_BKPSRAM_MODE)
 #error "Please select first the target STM32F7xx Low Power mode to be measured (in stm32f7xx_lp_modes.h file)"
#endif

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void SleepMode_Measure(void);
void StopMode_Measure(void);
void StandbyMode_Measure(void);
void StandbyRTCMode_Measure(void);
void StandbyBKPSRAMMode_Measure(void);

uint32_t USB_ULPI_Read(uint32_t Addr);
uint32_t USB_ULPI_Write(uint32_t Addr, uint32_t Data);   
void USB_ULPI_MspInit(void);
void USB_PhyEnterLowPowerMode(void);
void USB_PhyExitFromLowPowerMode(void);
void ETH_PhyEnterPowerDownMode(void);
void ETH_PhyExitFromPowerDownMode(void);


#endif /* __STM32F7xx_LP_MODES_H */

