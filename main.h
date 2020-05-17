/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
	* @author			    :	Imran Khan (imran.khan@vvdntech.com)
  * @copyright		  :	(c) 2020-2021 , VVDN Technologies Pvt. Ltd.
 *								    Permission is hereby granted to everyone in VVDN Technologies
 *								    to use the Software without restriction, including without
 *								    limitation the rights to use, copy, modify, merge, publish,
 *								    distribute, distribute with modifications.
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
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include <stdlib.h>
#include <string.h>
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define FIX_VERSION 1.1
#define DEBUG 1
#define APP 2
#define IMP_ADC_CH 				3    			// ADC RES  1
#define VOL_ADC_CH 				6	   			// ADC VOLT 1
#define M_VOL_OUT_MAIN_2_ADC_CH 				12   			// ADC RES  2 
#define M_IMP_OUT_MAIN_2_ADC_CH 				13	 			// ADC VOLT 2
#define  IMP_LOW_SHORT 0
#define CH_1 1
#define CH_6 6
#define CH_2 2
#define CH_4 4
#define CH_3 3
#define CH_5 5
#define CH_7 7
#define CH_8 8
#define CH_9 9
#define CH_10 10
#define CH_11 11
#define CH_15 15
#define CH_18 18
#define CH_23 23
#define CH_25 25
#define ON 1
#define OFF 2
#define PASS 1
#define FAIL 2
#define TOGGLE 3
#define PROG 1
#define NORM 0
#define BL_DEBUG_MSG_EN
#define TRUE 1
#define FALSE 0
#define MUX_1 1
#define MUX_2 2
#define MUX_3 3
#define MUX_4 4
#define ALL_EN 5
#define ALL_DI 6
#define POWER_MUX 7
#define V5   1
#define V3V3 2
#define V1V8 3
#define TP210 1
#define TP37  2
#define TP215 3
#define TP12  4
/* STANDARD MACROS ARE DEFINE HERE */
#define TN55_Pin GPIO_PIN_4
#define TN55_GPIO_Port GPIOA
#define DUT_MAIN_PWR_EN_Pin GPIO_PIN_7
#define DUT_MAIN_PWR_EN_GPIO_Port GPIOA
#define V_IMP_MEMT_Pin GPIO_PIN_0
#define V_IMP_MEMT_GPIO_Port GPIOB
#define VOLT_RES_SEL_Pin GPIO_PIN_1
#define VOLT_RES_SEL_GPIO_Port GPIOG

#define BUZZER_STATUS_Pin GPIO_PIN_2
#define BUZZER_STATUS_GPIO_Port GPIOG
#define LED_DUT_Pin GPIO_PIN_3
#define LED_DUT_GPIO_Port GPIOG
#define LED_PTS_Pin GPIO_PIN_4
#define LED_PTS_GPIO_Port GPIOG
#define TIMER_2_EN_Pin GPIO_PIN_5
#define TIMER_2_EN_GPIO_Port GPIOG
#define MAIN_MUX_SELC_0_Pin GPIO_PIN_6
#define MAIN_MUX_SELC_0_GPIO_Port GPIOG
#define MAIN_MUX_SELC_1_Pin GPIO_PIN_7
#define MAIN_MUX_SELC_1_GPIO_Port GPIOG
#define MAIN_MUX_SELC_2_Pin GPIO_PIN_8
#define MAIN_MUX_SELC_2_GPIO_Port GPIOG
#define MAIN_MUX_SELC_3_Pin GPIO_PIN_9
#define MAIN_MUX_SELC_3_GPIO_Port GPIOG
#define MAIN_MUX_SELC_4_Pin GPIO_PIN_10
#define MAIN_MUX_SELC_4_GPIO_Port GPIOG
#define MUX_SEL_EN1_Pin  GPIO_PIN_11
#define MUX_SEL_EN1_GPIO_Port  GPIOG
#define MUX_SEL_EN2_Pin  GPIO_PIN_12
#define MUX_SEL_EN2_GPIO_Port  GPIOG
#define MUX_SEL_EN3_Pin GPIO_PIN_13
#define MUX_SEL_EN3_GPIO_Port GPIOG
#define MSP_CAN_INT_EN_Pin GPIO_PIN_14
#define MSP_CAN_INT_EN_GPIO_Port GPIOG
#define MSP_IGNITION_INT_EN_Pin GPIO_PIN_15
#define MSP_IGNITION_INT_EN_GPIO_Port GPIOG
#define LUMIA_GPS_PPS_Pin GPIO_PIN_4
#define LUMIA_GPS_PPS_GPIO_Port GPIOB
#define MSP_TMP_ALERT_Pin GPIO_PIN_5   // already implemented see in gpio file
#define MSP_TMP_ALERT_GPIO_Port GPIOB
#define IMU_INT_Pin GPIO_PIN_6
#define IMU_INT_GPIO_Port GPIOB
/* user define MACROS*/
#define FTDI_RST_Pin GPIO_PIN_11
#define FTDI_RST_GPIO_Port GPIOB
#define AVCC_5V_Pin GPIO_PIN_0
#define AVCC_5V_GPIO_Port GPIOD
#define AVCC_3V3_Pin GPIO_PIN_1
#define AVCC_3V3_GPIO_Port GPIOD
#define AVCC_1V8_Pin GPIO_PIN_2
#define AVCC_1V8_GPIO_Port GPIOD
#define QCS_LW_PWR_Pin GPIO_PIN_2
#define QCS_LW_PWR_GPIO_Port GPIOE
#define FAST_BT_Pin GPIO_PIN_6
#define FAST_BT_GPIO_Port GPIOE
#define USB3_5V_EN_PIN GPIO_PIN_2
#define USB3_5V_EN_PORT GPIOA 
#define USB3_MUX_EN_PIN GPIO_PIN_4
#define USB3_MUX_EN_PORT GPIOA 
/* END OF HERE*/
/* Macros for Enable or disable the respected pin*/
#define M_ENABLE_MAIN_RES_HIGH        HAL_GPIO_WritePin(VOLT_RES_SEL_GPIO_Port,VOLT_RES_SEL_Pin,GPIO_PIN_SET)
#define M_ENABLE_MAIN_RES_LOW         HAL_GPIO_WritePin(VOLT_RES_SEL_GPIO_Port,VOLT_RES_SEL_Pin,GPIO_PIN_RESET)
/* Macros for Enable or disable the DUT POWER*/
#define DUT_PWR_HIGH                  HAL_GPIO_WritePin(DUT_MAIN_PWR_EN_GPIO_Port,DUT_MAIN_PWR_EN_Pin,GPIO_PIN_SET)
#define DUT_PWR_LOW                   HAL_GPIO_WritePin(DUT_MAIN_PWR_EN_GPIO_Port,DUT_MAIN_PWR_EN_Pin,GPIO_PIN_RESET)
/* Macros for Enable or disable the MSMT  POWER*/
#define MSMT_PWR_HIGH                 HAL_GPIO_WritePin(V_IMP_MEMT_GPIO_Port,V_IMP_MEMT_Pin,GPIO_PIN_SET)
#define MSMT_PWR_LOW                  HAL_GPIO_WritePin(V_IMP_MEMT_GPIO_Port,V_IMP_MEMT_Pin,GPIO_PIN_RESET)
/* Macros for Enable or disable logic switch of for timer*/
#define TIMER_ENABLE                  HAL_GPIO_WritePin(TIMER_2_EN_GPIO_Port,TIMER_2_EN_Pin,GPIO_PIN_SET)
#define TIMER_DISABLE                 HAL_GPIO_WritePin(TIMER_2_EN_GPIO_Port,TIMER_2_EN_Pin,GPIO_PIN_RESET)
/* Macros for Enable or disable the MUX1,MUX2,MUX3,MUX4 */
#define MUX_1_DI                      HAL_GPIO_WritePin(MUX_SEL_EN1_GPIO_Port,MUX_SEL_EN1_Pin,GPIO_PIN_SET)
#define MUX_1_EN                      HAL_GPIO_WritePin(MUX_SEL_EN1_GPIO_Port,MUX_SEL_EN1_Pin,GPIO_PIN_RESET)
#define MUX_2_EN                      HAL_GPIO_WritePin(MUX_SEL_EN2_GPIO_Port,MUX_SEL_EN2_Pin,GPIO_PIN_SET)
#define MUX_2_DI                      HAL_GPIO_WritePin(MUX_SEL_EN2_GPIO_Port,MUX_SEL_EN2_Pin,GPIO_PIN_RESET)
#define MUX_3_EN                      HAL_GPIO_WritePin(MUX_SEL_EN3_GPIO_Port,MUX_SEL_EN3_Pin,GPIO_PIN_SET)
#define MUX_3_DI                      HAL_GPIO_WritePin(MUX_SEL_EN3_GPIO_Port,MUX_SEL_EN3_Pin,GPIO_PIN_RESET)
#define MUX_4_EN                      HAL_GPIO_WritePin(GPIOE,GPIO_PIN_15,GPIO_PIN_SET)
#define MUX_4_DI                      HAL_GPIO_WritePin(GPIOE,GPIO_PIN_15,GPIO_PIN_RESET)
/* Macros for Enable or disable MSP CAN Interuupt Pin */
#define MSP_CAN_EN                    HAL_GPIO_WritePin(MSP_CAN_INT_EN_Pin,MSP_CAN_INT_EN_Pin,GPIO_PIN_SET)
#define MSP_CAN_DI                    HAL_GPIO_WritePin(TIMER_2_EN_GPIO_Port,MSP_CAN_INT_EN_Pin,GPIO_PIN_RESET)
/* Macros for Enable or disable MSP Ignition Interuupt Pin */
#define MSP_IGN_EN                    HAL_GPIO_WritePin(MSP_IGNITION_INT_EN_GPIO_Port,MSP_IGNITION_INT_EN_Pin,GPIO_PIN_SET)
#define MSP_IGN_DI                    HAL_GPIO_WritePin(MSP_IGNITION_INT_EN_GPIO_Port,MSP_IGNITION_INT_EN_Pin,GPIO_PIN_RESET)
/* Macros for Enable or disable The Lumia PPS Signal Pin */
#define LUMIA_PPS_EN                  HAL_GPIO_WritePin(LUMIA_GPS_PPS_GPIO_Port,LUMIA_GPS_PPS_Pin,GPIO_PIN_SET)
#define LUMIA_PPS_DI                  HAL_GPIO_WritePin(LUMIA_GPS_PPS_GPIO_Port,LUMIA_GPS_PPS_Pin,GPIO_PIN_RESET)
/* Macros for Enable or disable The MSP TEMPRATURE Signal Pin */
#define MSP_TMP_EN                    HAL_GPIO_WritePin(MSP_TMP_ALERT_GPIO_Port,MSP_TMP_ALERT_Pin,GPIO_PIN_SET)
#define MSP_TMP_DI                    HAL_GPIO_WritePin(MSP_TMP_ALERT_GPIO_Port,MSP_TMP_ALERT_Pin,GPIO_PIN_RESET)
/* Macros for Enable or disable The IMU Interrupt  Pin */
#define IMU_INT_EN                    HAL_GPIO_WritePin(IMU_INT_GPIO_Port,IMU_INT_Pin,GPIO_PIN_SET)
#define IMU_INT_DI                    HAL_GPIO_WritePin(IMU_INT_GPIO_Port,IMU_INT_Pin,GPIO_PIN_RESET)
/* Macros for Enable or disable The FTDI RESET  Pin */
#define FTDI_RST_EN                   HAL_GPIO_WritePin(FTDI_RST_GPIO_Port,FTDI_RST_Pin,GPIO_PIN_SET)
#define FTDI_RST_DI                   HAL_GPIO_WritePin(FTDI_RST_GPIO_Port,FTDI_RST_Pin,GPIO_PIN_RESET)
/* Macros for Enable or disable The AVCC_5V  Pin */
#define AVCC_5V_EN                    HAL_GPIO_WritePin(AVCC_5V_GPIO_Port,AVCC_5V_Pin,GPIO_PIN_SET)
#define AVCC_5V_DI                    HAL_GPIO_WritePin(AVCC_5V_GPIO_Port,AVCC_5V_Pin,GPIO_PIN_RESET)
/* Macros for Enable or disable The AVCC_3V3  Pin */
#define AVCC_3V3_EN                   HAL_GPIO_WritePin(AVCC_3V3_GPIO_Port,AVCC_3V3_Pin,GPIO_PIN_SET)
#define AVCC_3V3_DI                   HAL_GPIO_WritePin(AVCC_3V3_GPIO_Port,AVCC_3V3_Pin,GPIO_PIN_RESET)
/* Macros for Enable or disable The AVCC_1V8  Pin */
#define AVCC_1V8_EN                   HAL_GPIO_WritePin(AVCC_1V8_GPIO_Port,AVCC_3V3_Pin,GPIO_PIN_SET)
#define AVCC_1V8_DI                   HAL_GPIO_WritePin(AVCC_1V8_GPIO_Port,AVCC_3V3_Pin,GPIO_PIN_RESET)
/* Macros for Enable or disable The QCS LOW POWER Pin */
#define QCS_PWR_EN                    HAL_GPIO_WritePin(QCS_LW_PWR_GPIO_Port,QCS_LW_PWR_Pin,GPIO_PIN_SET)
#define QCS_PWR_DI                    HAL_GPIO_WritePin(QCS_LW_PWR_GPIO_Port,QCS_LW_PWR_Pin,GPIO_PIN_RESET)
/* Macros for Enable or disable The FAST BOOT POWER Pin */
#define FAST_BT_EN                    HAL_GPIO_WritePin(FAST_BT_GPIO_Port,FAST_BT_Pin,GPIO_PIN_SET)
#define FAST_BT_DI                    HAL_GPIO_WritePin(FAST_BT_GPIO_Port,FAST_BT_Pin,GPIO_PIN_RESET)
/*=================== timer MACROS are here======================*/
#define TIMER4_START                  HAL_TIM_IC_Start_IT(&htim4, TIM_CHANNEL_2)
#define TIMER4_STOP                   HAL_TIM_IC_Stop_IT(&htim4, TIM_CHANNEL_2)

#define TIMER2_START                  HAL_TIM_IC_Start_IT(&htim2, TIM_CHANNEL_1)
#define TIMER2_STOP                   HAL_TIM_IC_Stop_IT(&htim2, TIM_CHANNEL_1)

typedef struct STR_PACKET
{
	uint8_t current_rec_ch;
	uint8_t pc_rx_buffer[50];
	uint8_t keyword[20];
	uint8_t keyword_len;
	uint8_t arg_1[10];
	uint8_t arg_1_len;
	uint8_t arg_2[10];
	uint8_t arg_2_len;
}STR_PACKET;
 
typedef struct STR_PTS
{
	STR_PACKET * pkt;
	float imp_val; 
	float vol_val;
	float _0v8_value_mcu;
	uint8_t dut_connected[5];
	float sep_vol;
	float sep_imp;
}STR_PTS; 

/*================== Funtion Protocol declare for system level Here ========================*/
	void 					SystemClock_Config	(void);
STR_PTS 		* select_test_routine	(STR_PTS * ob);
STR_PTS 		* init_str						(void	);//Will Create and initialize the Structure Object
void 					enable_rx_interrupt	(void	);
STR_PACKET * reset_packet_object(STR_PACKET * ob);
STR_PTS * print3(STR_PTS * ob);  // Just to check, Not in actually used 
STR_PACKET 	* get_packet_form_pc	(STR_PACKET * ob );
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart); 
void printmsg(char *format,...);

/*================== Funtion Protocol declare for user level Here ========================*/

void 	transimit_str_to(uint8_t board,uint8_t * str,uint8_t strlen);
void uart_tx_data_to(uint8_t * data,uint8_t strlen); //funtion defination for UART4
uint32_t Get_ADC1_value(uint8_t adc_channel);        // sys_core.c
void dut_led_cnt(uint8_t state);
void pts_led_cnt(uint8_t state);
void set_mux_ch(uint8_t channel);         //mux for 32:1
void gpio_mux_16_1_sel(uint8_t channel); //mux for 16:1
/*===========IMP/VOLt Funtion Declare==========*/
void imp_setup_all(uint8_t mux_num);
void volt_setup_all_32_1(uint8_t mux_num);
void	imp_read_all(void);
void sep_imp_read(uint8_t channel,uint8_t mux_num,const char *str);
void sep_vol_read(uint8_t channel,uint8_t mux_num,const char *tp_name);
void vol_read_all(void);
void post_vol_read_mux_1(void);
void post_vol_read_mux_rest(uint8_t mux_num,uint8_t channel,const char *str);
void flash_vol_read_all(void);
void mux_2_pre_vol_test(void); 
void mux_3_pre_vol_test(void);
void mux_4_pre_vol_test(void);
void load_switch_en(uint8_t volt,uint8_t state);
void dut_pwr_on_OFF(uint8_t state);
float check_pwr_usb_plug_32_1(uint8_t channel);
float check_pwr_usb_plug_16_1(uint8_t channel);
void volt_check_usb_pwr_all(uint8_t mode);
 /*==============post volatge=========*/
 void post_vol_read_mux_1(void);
 void post_vol_read_mux_rest(uint8_t mux_num,uint8_t channel,const char *str);
/*===========TIMER Related Funtion Declare=======*/
void pwm_duty_cycle_measurment(uint8_t pwm, uint8_t channel);
void timer_mode_EN_DI_Pwm(uint8_t mode);
/*===========Mux Switching Funtion Declare=======*/
void mux_switch_EN_DI(uint8_t mode);
/* USER CODE END Private defines */
/*===========gpio status read funtion declare===========*/
void gpio_read_test(uint8_t mux_state, uint8_t channel,const char *str);
//void gpio_read_test_mux_2(uint8_t mux_state, uint8_t channel,const char *str);
//void gpio_read_test_mux_3(uint8_t mux_state, uint8_t channel,const char *str);
//void gpio_read_test_mux_4(uint8_t mux_state, uint8_t channel,const char *str);
void gpio_write_pin(uint8_t test_point, uint8_t state);
float read_ip_status(const char *signal);
/*=======================FASTBOOT PIN FUNTION==========*/
void fast_boot_fun(uint8_t state);

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
