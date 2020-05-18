/**
  ******************************************************************************
  * @file           : query.c
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
#include <stdio.h>
#include "main.h"
extern UART_HandleTypeDef huart5;
extern UART_HandleTypeDef huart4;
extern uint8_t response[150];
extern uint32_t step;
extern ADC_HandleTypeDef hadc2;	 //ADC Handler
extern uint8_t my_flag;
extern uint8_t my_data[10];     // this variable use to recieve the data from uart recieved data uart4
extern uint8_t arri_buffer[30]; // this variable use to extract the data from uart recieved data uart4
extern uint8_t orignal_data[12]; // this is variable to recieve the data from uart4
extern uint8_t num_index;    //this is the variable for count for uart4
extern uint8_t byte_cmplt;
 /**
* @brief  Led funtion for control the DUT LED 
* @param  State of the led (ON/OFF) 
* @retval None
*/ 
void dut_led_cnt(uint8_t state)
{
if(state==ON		)      HAL_GPIO_WritePin            (LED_DUT_GPIO_Port,LED_DUT_Pin,GPIO_PIN_RESET     );
else if(state==OFF		)HAL_GPIO_WritePin            (LED_DUT_GPIO_Port,LED_DUT_Pin,GPIO_PIN_SET       );
else if(state==TOGGLE) HAL_GPIO_TogglePin           (LED_DUT_GPIO_Port,LED_DUT_Pin                    );
}
/**
* @brief  Led funtion for control the PTS LED 
* @param  State of the led (ON/OFF) 
* @retval None
*/ 
void pts_led_cnt(uint8_t state)
{if(state==ON		)      HAL_GPIO_WritePin            (LED_PTS_GPIO_Port,LED_PTS_Pin,GPIO_PIN_RESET      );
else if(state==OFF		)HAL_GPIO_WritePin            (LED_PTS_GPIO_Port,LED_PTS_Pin,GPIO_PIN_SET        );
else if(state==TOGGLE) HAL_GPIO_TogglePin           (LED_PTS_GPIO_Port,LED_PTS_Pin                     );
}	
/**
* @brief  funtion for Read the State of the signal through the ADC  
* @param  None
* @retval state of the signal
*/

/**
* @brief  funtion for setup the condition for impedance  
* @param  None
* @retval state of the signal
*/
void imp_setup_all(uint8_t mux_num)
{
	//AVCC_5V_DI;                                           //PD0 it must be disable before test the impedance
	//AVCC_3V3_DI;                                          //PD1 it must be disable before test the impedance
	//AVCC_1V8_DI;                                          //PD2  it must be disable before test the impedance
	FTDI_RST_DI;                                         //FTDI CHIP DISABLE -it must be disable before test the impedance
	DUT_PWR_LOW;
	//DUT POWER OFF (it must be disable before test the impedance)
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_14,GPIO_PIN_SET); //0V8 Enable for impedance
	M_ENABLE_MAIN_RES_LOW;                             //2:1 MUX TRACK SET for Impedance test
	mux_switch_EN_DI(mux_num);                         //enable the mux_1 of 32:1
	if(my_flag==DEBUG)printmsg("2:1 MUX LOW|MUX[%d]Enable|FTDI CHIP DISABLE|DUTPWR OFF\r\n",mux_num);
	}
	
	
	/**
* @brief  funtion for setup the condition for voltage  
* @param  None
* @retval state of the signal
*/
void volt_setup_all_32_1(uint8_t mux_num)
{
	FTDI_RST_EN;                                         // ftdi chip enable here
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_14,GPIO_PIN_RESET); //0V8 Disable for impedance
	AVCC_5V_EN;                                          //PD_0
	AVCC_3V3_EN;                                         //PD_1
	AVCC_1V8_EN;                                         //PD_2
	M_ENABLE_MAIN_RES_HIGH;
	                                        
	mux_switch_EN_DI(mux_num);                           //enable the mux_1/mux_2/mux_3/mux_4
	if(my_flag==DEBUG)printmsg("mux[%d]enable|:1 MUX HIGH,AVCC_5V_EN,AVCC_3V3_EN,AVCC_1V8_EN have enable\r\n",mux_num);	
}
	/**
* @brief  funtion for setup or Enable the load switch for diffrent voltage like 5V,3V3,1V8 
* @param  None
* @retval state of the signal
*/
 void load_switch_en(uint8_t volt,uint8_t state)
 {
 if(volt==V5)
 {
	if(state==ENABLE)AVCC_5V_EN;
	else if (state==DISABLE)AVCC_5V_DI;
 }
 else if(volt==V3V3)
 {
	if(state==ENABLE)AVCC_3V3_EN;
	else if(state==DISABLE) AVCC_3V3_DI;
 }	 
 else if(volt==V1V8)
 {
	if(state==ENABLE)AVCC_1V8_EN; 
  else if(state==DISABLE)AVCC_1V8_DI;
 }
 }
/**
* @brief  funtion for Read the State of the signal through the ADC  
* @param  None
* @retval state of the signal
*/
float read_ip_status(const char *signal)
{   
 uint32_t raw_value=0;
 float volt_value=0;
 raw_value=Get_ADC1_value(VOL_ADC_CH);  // To read the adc value from relevant channel of ADC module
 volt_value=(float)raw_value*3.3f;
 volt_value/=4096;
 volt_value*=2;
	if(my_flag==DEBUG)printmsg("GPIO[%s]-%.1f\r\n",signal,volt_value);
  return volt_value;
 }
/**
* @brief  funtion for Mux Enable/disable Switching   
* @param  mux number to be en/di
* @retval 1/0
*/
 void mux_switch_EN_DI(uint8_t mode)
 {
 switch(mode)
 {
	 case MUX_1:
		 MUX_1_EN;  //mux 1(32:1 are enable)
	   MUX_2_DI;  //mux 1(16:1 are disable)
	   MUX_3_DI;  //mux 1(16:1 are disable)
	   MUX_4_DI;  //mux 1(16:1 are disable)
	 TIMER_ENABLE;   //ENABLED BECAUSE OF VOLTAGE DROP DURING VOLT MEASSUREMENT.
	   if(my_flag==DEBUG)printmsg("MUX1 enable and disable rest of\r\n"); 
		 break;
	 case MUX_2:
		 MUX_1_DI;  //mux 1(32:1 are disable)
	   MUX_2_EN;  //mux 1(16:1 are enable)
	   MUX_3_DI;  //mux 1(8:1 are disable)
	   MUX_4_DI;  //mux 1(16:1 are disable)
	  TIMER_ENABLE;   //ENABLED BECAUSE OF VOLTAGE DROP DURING VOLT MEASSUREMENT.
	   if(my_flag==DEBUG)
	    printmsg("MUX2 enable and disable rest of\r\n");
		 break;
	 case MUX_3:
		 MUX_1_DI;  //mux 1(32:1 are disable)
	   MUX_2_DI;  //mux 1(16:1 are disable)
	   MUX_3_EN;  //mux 1(8:1 are enable)
	   MUX_4_DI;  //mux 1(16:1 are disable)
	  TIMER_DISABLE;   //ENABLED BECAUSE OF VOLTAGE DROP DURING VOLT MEASSUREMENT.
	 if(my_flag==DEBUG)
	    printmsg("MUX3 enable and disable rest of\r\n");
		 break;
	 case MUX_4:
		 MUX_4_EN;  //mux 1(16:1 are disable)
		 MUX_1_DI;  //mux 1(32:1 are disable)
	   MUX_2_DI;  //mux 1(16:1 are disable)
	   MUX_3_DI;  //mux 1(8:1 are disable)
	  TIMER_DISABLE;   //ENABLED BECAUSE OF VOLTAGE DROP DURING VOLT MEASSUREMENT.
	   if(my_flag==DEBUG)
	    printmsg("MUX4 enable and disable rest of\r\n");
		 break;
	 case ALL_EN:
		 MUX_1_EN;  //mux 1(32:1 are enable)
	   MUX_2_EN;  //mux 1(16:1 are enable)
	   MUX_3_EN;  //mux 1(8:1 are enable)
	   MUX_4_EN;  //mux 1(16:1 are disable)
	   if(my_flag==DEBUG)
	    printmsg("ALL MUX are enable \r\n");
		 break;
	 case ALL_DI:
		 MUX_1_DI;  //mux 1(32:1 are enable)
	   MUX_2_DI;  //mux 1(16:1 are enable)
	   MUX_3_DI;  //mux 1(8:1 are enable)
	   MUX_4_DI;  //mux 1(16:1 are disable)
	    if(my_flag==DEBUG)
	    printmsg("ALL MUX are disable \r\n");
		 break;
	 case POWER_MUX:
		 MUX_1_EN;  //mux 1(32:1 are enable)
	   MUX_2_EN;  //mux 1(16:1 are enable)
	   break;
	 default:
		 break;
 } 
 }  
 /**
* @brief  funtion for Turn on/off the Dut power   
* @param  Sttae(ON/OFF)
* @retval None
*/
void dut_pwr_on_OFF(uint8_t state)
{
if(state==ON)
{
	DUT_PWR_HIGH;
 dut_led_cnt(ON);	
}
else
{
DUT_PWR_LOW;
dut_led_cnt(OFF);	
	}
}
/** @fun    
  * @brief  to enable or switch the mode from adc to timer of respected mux
  * @param  Enable/Disable 
  * @retval None 
  */
void timer_mode_EN_DI_Pwm(uint8_t mode)
{
if(mode==ON)
	TIMER_ENABLE;
if(my_flag==DEBUG)printmsg("timer mode ON\r\n");
else
TIMER_DISABLE;
if(my_flag==DEBUG)printmsg("timer mode OFF\r\n");
	
}

void fast_boot_fun(uint8_t state)
{
if(state==ON)
	{
HAL_GPIO_WritePin(FAST_BT_GPIO_Port,FAST_BT_Pin,GPIO_PIN_SET);//gpio high
	}
else
{
HAL_GPIO_WritePin(FAST_BT_GPIO_Port,FAST_BT_Pin,GPIO_PIN_RESET);//gpio high
if(my_flag==DEBUG)printmsg("FAST BOOT PIN DISABLE\r\n");
}	

}
