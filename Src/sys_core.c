/**
  ******************************************************************************
  * @file           : sys_core.c
  * @brief          : funtion test body
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

#include "main.h"
extern UART_HandleTypeDef huart5;//Application Uart handler
extern uint8_t response[150];    //Buffer to transfer data to Application 
extern uint32_t step;						 //Step for Debug Option
extern ADC_HandleTypeDef hadc1;	 //ADC Handler
extern TIM_HandleTypeDef htim2;  //Timer Handler used for PPS Frequency
/**
  * @brief  Read the ADC value form ADC2 Module at a perticular channel.
  * @retval Return the ADC Value.
  */
uint32_t Get_ADC1_value(uint8_t adc_channel)
{
	uint32_t ADC1_Value;
	//ADC Mechanisum should be writen here
	ADC1_Value = 0;// Reset the Varible for New Converted Value
	
	ADC_ChannelConfTypeDef sConfig;
	
	//ADC_CHANNEL = channel_no;
	// Configure ADC regular channel 
  sConfig.Channel      = adc_channel								;//ADCx_CHANNEL;/* Sampled channel number */
  sConfig.Rank         = 1											;/* Rank of sampled channel number ADCx_CHANNEL */
  sConfig.SamplingTime = ADC_SAMPLETIME_480CYCLES;//ADC_SAMPLETIME_3CYCLES;//ADC_SAMPLETIME_15CYCLES;//ADC_SAMPLETIME_28CYCLES;//ADC_SAMPLETIME_3CYCLES;    /* Sampling time (number of clock cycles unit) */
  sConfig.Offset 			 = 0											;/* Parameter discarded because offset correction is disabled */

	if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
	
	
	 /*##-3- Start the conversion process #######################################*/
    if (HAL_ADC_Start(&hadc1) != HAL_OK)
    {
      /* Start Conversation Error */
      Error_Handler();
    }

    /*##-4- Wait for the end of conversion #####################################*/
    /*  Before starting a new conversion, you need to check the current state of
         the peripheral; if it�s busy you need to wait for the end of current
         conversion before starting a new one.
         For simplicity reasons, this example is just waiting till the end of the
         conversion, but application may perform other tasks while conversion
         operation is ongoing. */
    if (HAL_ADC_PollForConversion(&hadc1, 10) != HAL_OK)
    {
      /* End Of Conversion flag not set on time */
      Error_Handler();
    }

    if ((HAL_ADC_GetState(&hadc1) & HAL_ADC_STATE_EOC_REG) == HAL_ADC_STATE_EOC_REG)
    {
      /*##-5- Get the converted value of regular channel  ########################*/
      ADC1_Value = HAL_ADC_GetValue(&hadc1);
    }
	return ADC1_Value;
}
