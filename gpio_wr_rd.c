/**
  ******************************************************************************
  * File Name          : gpio_wr_rd.c
  * Description        : This file provides code for the read or writre the gpio related status for the DUT
  *        
	* @author			       :	Imran Khan (imran.khan@vvdntech.com)
  * @copyright		     :	(c) 2020-2021 , VVDN Technologies Pvt. Ltd.
 *								           Permission is hereby granted to everyone in VVDN Technologies
 *								           to use the Software without restriction, including without
 *								           limitation the rights to use, copy, modify, merge, publish,
 *								           distribute, distribute with modifications.
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

extern uint8_t my_flag;
const char *status_name[15] = {"FAN_CONN_PWM(TN105)","DISABLE_3V7(TN122)","PWM_RD(TN93)","LTC_PFO_N(TN94)","WLAN_SW_CTRL(TN109)","PHONE_ON_N(TN133)",\
	"EN_3V3(TN143)","MSP_SYS_INT(TN150)","SPI_CS_SW_EN(TN153)","QCS_FLASH_SPI_CS(TN194)","CDC_MIC_BIAS1(TN46)"};

/** @fun    01
  * @brief  funtion for read the status/ADC Value of the gpio of corresponding mux 1(32:1)
  * @param1 MUX STATE (EN/DI the Respected MUX)
	* @param2 Channel Number of the respectef MUX
  * @param3 Signal Name Of the Respected Channel
	* @retval None
  */
	void gpio_read_test(uint8_t mux_state, uint8_t channel,const char *str)
	{
	float output=0x00;
	volt_setup_all_32_1(mux_state);
	set_mux_ch(channel);  
	output= read_ip_status(str);
	printmsg("%s-%.1f\r\n",str,output);
	}

	/** @fun    02
    * @brief  funtion for read the status of the gpio of corresponding mux 2(16:1)
    * @param  cahnnel number 
    * @retval test name
  */
	/*
	void gpio_read_test_mux_2(uint8_t mux_state, uint8_t channel,const char *str)
	{ 
		float output=0x00;
	//1. respected mux enable
	//2. correspondinf channel select
	//3. read the adc value through the adc api
	//4. pass this value to app or make result here and pass the reslutant status to app
	   volt_setup_all_32_1(mux_state);
		  gpio_mux_16_1_sel(channel);
		  output= read_ip_status();
		  printmsg("%s-%.1f\r\n",str,output);
	}*/
	/** @fun    03
* @brief  funtion for read the status of the gpio of corresponding mux 3(16:1)
  * @param  cahnnel number 
  * @retval test name
  */
	/*
	void gpio_read_test_mux_3(uint8_t mux_state, uint8_t channel,const char *str)
	{
		float output=0x00;
	//1. respected mux enable
	//2. correspondinf channel select
	//3. read the adc value through the adc api
	//4. pass this value to app or make result here and pass the reslutant status to app
	   volt_setup_all_32_1(mux_state);
		  gpio_mux_16_1_sel(channel);
		  output= read_ip_status();
		  printmsg("%s-%.1f\r\n",str,output);
	}*/
	/** @fun    03
* @brief  funtion for read the status of the gpio of corresponding mux 4(16:1)
  * @param  cahnnel number 
  * @retval test name
  */
	/*
	void gpio_read_test_mux_4(uint8_t mux_state, uint8_t channel,const char *str)
	{
		float output=0x00;
	//1. respected mux enable
	//2. correspondinf channel select
	//3. read the adc value through the adc api
	//4. pass this value to app or make result here and pass the reslutant status to app
	   volt_setup_all_32_1(mux_state);
		  gpio_mux_16_1_sel(channel);
		  output= read_ip_status();
	    printmsg("%s-%.1f\r\n",str,output);
	}	*/	
	
	/** @fun    03
    * @brief  funtion for write the gpio of corresponding Pin
    * @param  cahnnel number 
    * @retval test name
  */
	void gpio_write_pin(uint8_t test_point, uint8_t state)
	{
		
		if(test_point==TP210)
		{
		if(state==ON)HAL_GPIO_WritePin(GPIOG,GPIO_PIN_15,GPIO_PIN_SET);//gpio high
		if(my_flag==DEBUG)printmsg("MSP_IGNITION_INT(TP210) GPIO HIGH\r\n");
		else if(state==OFF)HAL_GPIO_WritePin(GPIOG,GPIO_PIN_15,GPIO_PIN_RESET);	//gpio low	
    if(my_flag==DEBUG)printmsg("MSP_IGNITION_INT(TP210) GPIO LOW\r\n");			
		}
		else if(test_point==TP215)
		{
		if(state==ON)HAL_GPIO_WritePin(GPIOE,GPIO_PIN_10,GPIO_PIN_SET);	//gpio high
		if(my_flag==DEBUG)printmsg("OBD_LUMIA_GPS_PPS(TP215) GPIO HIGH\r\n");
		else if(state==OFF)HAL_GPIO_WritePin(GPIOE,GPIO_PIN_10,GPIO_PIN_RESET);//gpio low	
		if(my_flag==DEBUG)printmsg("OBD_LUMIA_GPS_PPS(TP215) GPIO LOW\r\n");
		}
		else if(test_point==TP37)
		{
		if(state==ON)HAL_GPIO_WritePin(GPIOD,GPIO_PIN_15,GPIO_PIN_SET);//gpio high	
		if(my_flag==DEBUG)printmsg("CAM2_AVDD_2P8_EN(TP37) GPIO HIGH\r\n");			
		else if(state==OFF)HAL_GPIO_WritePin(GPIOD,GPIO_PIN_15,GPIO_PIN_RESET);//gpio Low	
		if(my_flag==DEBUG)printmsg("CAM2_AVDD_2P8_EN(TP37) GPIO LOW\r\n");					
		}	
    else if(test_point==TP12)
		{
		if(state==ON)HAL_GPIO_WritePin(GPIOG,GPIO_PIN_14,GPIO_PIN_SET);//gpio high	
		if(my_flag==DEBUG)printmsg("MSP_CAN_IGNITION(TP12) GPIO HIGH\r\n");			
		else if(state==OFF)HAL_GPIO_WritePin(GPIOD,GPIO_PIN_15,GPIO_PIN_RESET);//gpio Low	
		if(my_flag==DEBUG)printmsg("MSP_CAN_IGNITION(TP12) GPIO LOW\r\n");					
		}				
	}
	/*========================ANother Important Gpio for High/Low Operation =======*/
	/*======================MSP TEMP ALERT SIGNAL ENABLE/DISABLE FUNTION DEFINATION===============*/	
	void MSP_Temp_alert(uint8_t state)
	{
	if(state==ON)HAL_GPIO_WritePin(GPIOB,GPIO_PIN_4,GPIO_PIN_SET);//gpio high
	else
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_4,GPIO_PIN_RESET);//gpio LOW	
	}
/*======================GPS_PPS SIGNAL ENABLE/DISABLE FUNTION DEFINATION===============*/	
	void gps_pps_signal(uint8_t state)
	{
	if(state==ON)HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,GPIO_PIN_SET);//gpio high
	else
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,GPIO_PIN_RESET);//gpio LOW	
	}	
/*======================IMU INTERRUPT SIGNAL ENABLE/DISABLE FUNTION DEFINATION===============*/	
	void IMU_Int_signal(uint8_t state)
	{
	if(state==ON)HAL_GPIO_WritePin(GPIOB,GPIO_PIN_6,GPIO_PIN_SET);//gpio high
	else
	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_6,GPIO_PIN_RESET);//gpio LOW	
	}		
	/*===========================END OF FILE======================================*/
		