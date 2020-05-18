/**
 * @file				:	main.c
 * @brief				:	This file contains the main function and System initializations
 * @author			:	Imran Khan (imran.khan@vvdntech.com)
 * @copyright		:	(c) 2020-2021 , VVDN Technologies Pvt. Ltd.
 *								Permission is hereby granted to everyone in VVDN Technologies
 *								to use the Software without restriction, including without
 *								limitation the rights to use, copy, modify, merge, publish,
 *								distribute, distribute with modifications.
 */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>
#include <string.h>
#include "main.h"
#include "adc.h"
#include "i2c.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
#define D_UART   &huart5
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */
uint8_t response[700];

uint8_t ftoc[50];
uint32_t step=0;
uint8_t pack_received_cmplt=0;
uint8_t long_press_no=0;	
uint8_t current_rx_ch=0;
uint8_t Rx_Buffer[50];
uint8_t curr_Rx_index=0;
uint8_t arri_buffer[30]; // this variable use to extract the data from uart recieved data
uint8_t orignal_data[12]; // this is variable to recieve the data from uart4
uint8_t num_index=0;
uint8_t my_flag;
uint8_t byte_cmplt;


/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();
  /* Configure the system clock */
  SystemClock_Config();
  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_UART4_Init();
  MX_ADC1_Init();
  MX_I2C2_Init();
  MX_TIM2_Init();
  MX_TIM4_Init();
  MX_UART5_Init();
	
  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
 	STR_PTS * obj=NULL;    //Create Structure Ptr Object 
	obj=init_str();        //Provide Memory and initialize the Structure Object
	sprintf((char *)response,"\n\r");     //ob->imp_val
  transimit_str_to(1,response,strlen((char *)response));
	printmsg("\033[H\033[J");	/*clear screen*/
	printmsg("\r\n****************************************************");
	printmsg("\r\n*                                                  *");
	printmsg("\r\n*    NTDI MAIN BOARD PRODUCTION TESTING SYSTEM     *");
	printmsg("\r\n*                                                  *");
	printmsg("\r\n****************************************************\r\n");
	printmsg ("**************firmware version: 2.10.2**************\r\n");
	dut_led_cnt(OFF);
	pts_led_cnt(OFF);	
		MUX_1_DI;  //DISABLING MUX 1.
		load_switch_en(V5,ENABLE); //ENABLING 5V FOR VCC OF THE MUX.
/*=================Code will Start Here===============================*/
/* this code will be run infinitely in this loop untill it recieve the interrupt*/		
	while (1)
	{
if(pack_received_cmplt==1)        //If Command Received Completed
{  																//If Yes
obj->pkt=reset_packet_object(obj->pkt);  //Packet consist Keyword, Arg1 and Arg2 make it reset
obj->pkt=get_packet_form_pc(obj->pkt);   //Extract Received String into Packet (Keyword, Arg1 and Arg2)
pack_received_cmplt	= 0;
curr_Rx_index				= 0;  
obj=select_test_routine(obj); 
obj->pkt=reset_packet_object(obj->pkt);  //
printmsg("\n\r");
}
// obj=sw_test(obj,1);
enable_rx_interrupt(); 
 } 
return 0;
 }



/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage 
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 180;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 2;
  RCC_OscInitStruct.PLL.PLLR = 2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Activate the Over-Drive mode 
  */
  if (HAL_PWREx_EnableOverDrive() != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV4;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}
/* prints formatted string to console over UART */
 void printmsg(char *format,...)
 {
#ifdef BL_DEBUG_MSG_EN
	char str[80];

	/*Extract the the argument list using VA apis */
	va_list args;
	va_start(args, format);
	vsprintf(str, format,args);
	HAL_UART_Transmit(D_UART,(uint8_t *)str, strlen(str),HAL_MAX_DELAY);
	va_end(args);
#endif
 }
/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
