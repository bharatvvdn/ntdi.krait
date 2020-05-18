/**
  ******************************************************************************
  * File Name          : gpio.c
  * Description        : This file provides code for the configuration
  *                      of all used GPIO pins.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "gpio.h"
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/** Configure pins as 
        * Analog 
        * Input 
        * Output
        * EVENT_OUT
        * EXTI
*/
void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOG_CLK_ENABLE();
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2|GPIO_PIN_4|TN55_Pin|DUT_MAIN_PWR_EN_Pin|GPIO_PIN_15, GPIO_PIN_RESET);
	
  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, V_IMP_MEMT_Pin|LUMIA_GPS_PPS_Pin|MSP_TMP_ALERT_Pin|IMU_INT_Pin|FTDI_RST_Pin, GPIO_PIN_RESET);
	
	/*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, AVCC_5V_Pin|AVCC_3V3_Pin|AVCC_1V8_Pin|GPIO_PIN_15|GPIO_PIN_14, GPIO_PIN_RESET); //PD15(CAM2_AVDD_2P8_EN),0v8 Enable

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOG, VOLT_RES_SEL_Pin|BUZZER_STATUS_Pin|LED_DUT_Pin|LED_PTS_Pin 
                          |TIMER_2_EN_Pin|MAIN_MUX_SELC_0_Pin|MAIN_MUX_SELC_1_Pin|MAIN_MUX_SELC_2_Pin 
                          |MAIN_MUX_SELC_3_Pin|MAIN_MUX_SELC_4_Pin|MUX_SEL_EN1_Pin|MUX_SEL_EN2_Pin 
                          |MUX_SEL_EN3_Pin|MSP_CAN_INT_EN_Pin|MSP_IGNITION_INT_EN_Pin, GPIO_PIN_RESET);
/*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOE, QCS_LW_PWR_Pin|GPIO_PIN_15|GPIO_PIN_10, GPIO_PIN_RESET); //mux en_4 PE15//

  /*Configure GPIO pins : PAPin PAPin */
  GPIO_InitStruct.Pin = GPIO_PIN_2|GPIO_PIN_4|TN55_Pin|DUT_MAIN_PWR_EN_Pin|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PBPin PBPin PBPin PBPin */
  GPIO_InitStruct.Pin = V_IMP_MEMT_Pin|LUMIA_GPS_PPS_Pin|MSP_TMP_ALERT_Pin|IMU_INT_Pin|FTDI_RST_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
	
	/*Configure GPIO pins : PDPin PDPin PDPin PDPin */
  GPIO_InitStruct.Pin = AVCC_5V_Pin|AVCC_3V3_Pin|AVCC_1V8_Pin|GPIO_PIN_15|GPIO_PIN_14;  //CAM2_AVDD_2P8_EN(PD_15),0v8 Enable(PD_14)
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);
/*Configure GPIO pins : PEPin PAPin */
  GPIO_InitStruct.Pin =  QCS_LW_PWR_Pin|FAST_BT_Pin|GPIO_PIN_15|GPIO_PIN_10;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);
  /*Configure GPIO pin : PG0 */
  GPIO_InitStruct.Pin = GPIO_PIN_0;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);
	
	  GPIO_InitStruct.Pin = GPIO_PIN_11;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

  /*Configure GPIO pins : PGPin PGPin PGPin PGPin 
                           PGPin PGPin PGPin PGPin 
                           PGPin PGPin PGPin PGPin 
                           PGPin PGPin PGPin */
  GPIO_InitStruct.Pin = VOLT_RES_SEL_Pin|BUZZER_STATUS_Pin|LED_DUT_Pin|LED_PTS_Pin 
                          |TIMER_2_EN_Pin|MAIN_MUX_SELC_0_Pin|MAIN_MUX_SELC_1_Pin|MAIN_MUX_SELC_2_Pin 
                          |MAIN_MUX_SELC_3_Pin|MAIN_MUX_SELC_4_Pin|MUX_SEL_EN2_Pin 
                          |MUX_SEL_EN3_Pin|MSP_CAN_INT_EN_Pin|MSP_IGNITION_INT_EN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

}

/* USER CODE BEGIN 2 */

/* USER CODE END 2 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
