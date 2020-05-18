/**
  ******************************************************************************
  * @file           : init.c
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
extern UART_HandleTypeDef huart5;
extern uint8_t response[150];
extern uint32_t step;
extern uint8_t pack_received_cmplt;
extern uint8_t current_rx_ch;
extern uint8_t Rx_Buffer[50];
extern uint8_t curr_Rx_index; 
 

STR_PTS * init_str(void)//Will Create and initialize the Structure Object
{
	//------------Create  and Assigning memory to pointer
	STR_PTS * ob;
	ob 			=(STR_PTS 	 *)malloc(sizeof(STR_PTS		));
	ob->pkt	=(STR_PACKET *)malloc(sizeof(STR_PACKET	)); 
 
	//-------------Initialize the structure member by a initial value-------------------
  //memset(ob			,0,sizeof(STR_PTS		));
	//memset(ob->pkt,0,sizeof(STR_PACKET));
	//memset(ob->flg,0,sizeof(STR_FLAG	));

	
	
	return ob;
}
