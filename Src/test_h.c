/**
  ******************************************************************************
  * @file           : test_h.c
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
 
extern uint8_t Rx_Buffer[50];
extern uint8_t curr_Rx_index; 
extern uint8_t my_flag;


 STR_PTS * select_test_routine(STR_PTS * ob)

{
if(ob->pkt->keyword_len>0)
{
if(strncmp((char *)ob->pkt->keyword,"IMP",ob->pkt->keyword_len)==0)
{
		           if(strncmp((char *)ob->pkt->arg_1,"SETUP",ob->pkt->arg_1_len)==0)
		          {
																if(strncmp((char *)ob->pkt->arg_2,"MUX_1"  ,ob->pkt->arg_2_len)==0)
																{imp_setup_all(MUX_1); }	
                                else if(strncmp((char *)ob->pkt->arg_2,"MUX_2"  ,ob->pkt->arg_2_len)==0)
																{ imp_setup_all(MUX_2);}
																
                                																
																
							}
							else if(strncmp((char *)ob->pkt->arg_1,"READ",ob->pkt->arg_1_len)==0)
							{
																if(strncmp((char *)ob->pkt->arg_2,"ALL"  ,ob->pkt->arg_2_len)==0)
																{imp_read_all(); }
                                else if(strncmp((char *)ob->pkt->arg_2,"TN100"  ,ob->pkt->arg_2_len)==0)
																{sep_imp_read(1,1,"VREG_S2B_0P752(TN100)");}
																else if(strncmp((char *)ob->pkt->arg_2,"TN101"  ,ob->pkt->arg_2_len)==0)
																{sep_imp_read(2,1,"VREG_S3B_S4B(TN101)");}
																else if(strncmp((char *)ob->pkt->arg_2,"TN102"  ,ob->pkt->arg_2_len)==0)
																{sep_imp_read(3,1,"VREG_S5B_0P6(TN102)");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TN118"  ,ob->pkt->arg_2_len)==0)
																{sep_imp_read(4,1,"VREG_S1A(TN118)");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TN120"  ,ob->pkt->arg_2_len)==0)
																{sep_imp_read(5,1,"VREG_S1B(TN120)");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TN124"  ,ob->pkt->arg_2_len)==0)
																{sep_imp_read(6,1,"VREG_L13A(TN124)");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TN127"  ,ob->pkt->arg_2_len)==0)
																{sep_imp_read(7,1,"VREG_L9B(TN127)");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TN134"  ,ob->pkt->arg_2_len)==0)
																{sep_imp_read(8,1,"VREG_S2A_S3A(TN134)");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TN139"  ,ob->pkt->arg_2_len)==0)
																{sep_imp_read(9,1,"VREG_S5A(TN139)");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TN144"  ,ob->pkt->arg_2_len)==0)
																{sep_imp_read(10,1,"VREG_L3A(TN144)");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TN149"  ,ob->pkt->arg_2_len)==0)
																{sep_imp_read(11,1,"VREG_L5A(TN149)");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TN152"  ,ob->pkt->arg_2_len)==0)
																{sep_imp_read(12,1,"VREG_L17A(TN152)");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TN157"  ,ob->pkt->arg_2_len)==0)
																{sep_imp_read(13,1,"VREG_L2B(TN157)");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TN160"  ,ob->pkt->arg_2_len)==0)
																{sep_imp_read(14,1,"VREG_DBU1(TN160)");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TN161"  ,ob->pkt->arg_2_len)==0)
																{sep_imp_read(15,1,"VCC_3P3_STANDBY(TN161)");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TN164"  ,ob->pkt->arg_2_len)==0)
																{sep_imp_read(16,1,"VREG_S6A(TN164)");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TN167"  ,ob->pkt->arg_2_len)==0)
																{sep_imp_read(17,1,"VREG_L11A(TN167)");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TN175"  ,ob->pkt->arg_2_len)==0)
																{sep_imp_read(18,1,"VBATT_3P7(TN175)");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TN169"  ,ob->pkt->arg_2_len)==0)
																{sep_imp_read(19,1,"VREG_L1B(TN169)");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TN170"  ,ob->pkt->arg_2_len)==0)
																{sep_imp_read(20,1,"VREG_S4A(TN170)");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TN172"  ,ob->pkt->arg_2_len)==0)
																{sep_imp_read(21,1,"VREG_L10A(TN172)");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TN173"  ,ob->pkt->arg_2_len)==0)
																{sep_imp_read(22,1,"VREG_L15A(TN173)");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TN181"  ,ob->pkt->arg_2_len)==0)
																{sep_imp_read(23,1,"VREG_L1A(TN181)");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TN207"  ,ob->pkt->arg_2_len)==0)
																{sep_imp_read(24,1,"VREG_BOB(TN207)");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TN213"  ,ob->pkt->arg_2_len)==0)
																{sep_imp_read(25,1,"VPH_PWR(TN213)");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TN45"  ,ob->pkt->arg_2_len)==0)
																{sep_imp_read(26,1,"VREG_L8A(TN45)");}
																else if(strncmp((char *)ob->pkt->arg_2, "TN52"  ,ob->pkt->arg_2_len)==0)
																{sep_imp_read(27,1,"VREG_L4B(TN52)");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TN92"  ,ob->pkt->arg_2_len)==0)
																{sep_imp_read(28,1,"VREG_L7A(TN92)");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TN56"  ,ob->pkt->arg_2_len)==0)
																{sep_imp_read(29,1,"VREG_L19A(TN56)");}																																																											
																	else if(strncmp((char *)ob->pkt->arg_2,"TN57"  ,ob->pkt->arg_2_len)==0)
																{sep_imp_read(30,1,"VREG_L7B(TN57)");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TN74"  ,ob->pkt->arg_2_len)==0)
																{sep_imp_read(31,1,"VREG_L2A(TN74)");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TN75"  ,ob->pkt->arg_2_len)==0)
																{sep_imp_read(32,1,"VREG_L6A(TN75)");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TN78"  ,ob->pkt->arg_2_len)==0)
																{sep_imp_read(1,2,"VREG_L5B(TN78)");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TN87"  ,ob->pkt->arg_2_len)==0)
																{sep_imp_read(2,2,"VREG_L12A(TN87)");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TN88"  ,ob->pkt->arg_2_len)==0)
																{sep_imp_read(3,2,"VCC_6P0_V(TN88)");}
																	else if(strncmp((char *)ob->pkt->arg_2,"V_IMP"  ,ob->pkt->arg_2_len)==0)
																{sep_imp_read(4,2,"VCC_6P0_IMP(TN88_2)");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TN218"  ,ob->pkt->arg_2_len)==0)
																{sep_imp_read(5,2,"VCC_6P0_FAN_V(TN218)");}
																	else if(strncmp((char *)ob->pkt->arg_2,"FAN"  ,ob->pkt->arg_2_len)==0)
																{sep_imp_read(6,2,"VCC_6P0_FAN_IMP(TN218_2)");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TN70"  ,ob->pkt->arg_2_len)==0)
																{sep_imp_read(7,2,"VREG_L13A_1P8(TN70)");}
                                else if(strncmp((char *)ob->pkt->arg_2,"TN109"  ,ob->pkt->arg_2_len)==0)
																{sep_imp_read(8,2,"WLAN_SW(TN109)");}
                                else if(strncmp((char *)ob->pkt->arg_2,"USB"  ,ob->pkt->arg_2_len)==0)
																{sep_imp_read(9,2,"USB_VBUS_IMP");}	

		                            else if(strncmp((char *)ob->pkt->arg_2,"TN55"  ,ob->pkt->arg_2_len)==0)
																{sep_imp_read(10,2,"VREG_DBUG2_S3A_1P225");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TN176"  ,ob->pkt->arg_2_len)==0)
																{sep_imp_read(11,2,"VREG_L13A_1P8_R)");}
                                else if(strncmp((char *)ob->pkt->arg_2,"TN196"  ,ob->pkt->arg_2_len)==0)
																{sep_imp_read(12,2,"CAM0_PWRD(TN196)");}
                                else if(strncmp((char *)ob->pkt->arg_2,"TN60"  ,ob->pkt->arg_2_len)==0)
																{sep_imp_read(13,2,"LTC_CPGOOD(TN60)");}																
							}
							
	}

else if(strncmp((char *)ob->pkt->keyword,"VOL",ob->pkt->keyword_len)==0)
{
							if(strncmp((char *)ob->pkt->arg_1,"EN",ob->pkt->arg_1_len)==0)
							{
																if(strncmp((char *)ob->pkt->arg_2,"5V"  ,ob->pkt->arg_2_len)==0)
																{ load_switch_en(V5,ENABLE); }
																else if(strncmp((char *)ob->pkt->arg_2,"3V3"  ,ob->pkt->arg_2_len)==0)
																{load_switch_en(V3V3,ENABLE);}
																else if(strncmp((char *)ob->pkt->arg_2,"1V8"  ,ob->pkt->arg_2_len)==0)
																{load_switch_en(V1V8,ENABLE);}
																else if(strncmp((char *)ob->pkt->arg_2,"ALL"  ,ob->pkt->arg_2_len)==0)
																{volt_setup_all_32_1(MUX_1);}
							}
							else if(strncmp((char *)ob->pkt->arg_1,"DIS",ob->pkt->arg_1_len)==0)
							{
								                if(strncmp((char *)ob->pkt->arg_2,"5V"  ,ob->pkt->arg_2_len)==0)
																{ load_switch_en(V5,DISABLE); }
																else if(strncmp((char *)ob->pkt->arg_2,"3V3"  ,ob->pkt->arg_2_len)==0)
																{load_switch_en(V3V3,DISABLE);}
																else if(strncmp((char *)ob->pkt->arg_2,"1V8"  ,ob->pkt->arg_2_len)==0)
																{load_switch_en(V1V8,DISABLE);}
							}
							else if(strncmp((char *)ob->pkt->arg_1,"PRE",ob->pkt->arg_1_len)==0)
							{
                                if(strncmp((char *)ob->pkt->arg_2,"ALL"  ,ob->pkt->arg_2_len)==0)
								                {vol_read_all();}
							}
							else if(strncmp((char *)ob->pkt->arg_1,"POS",ob->pkt->arg_1_len)==0)
							{
                               if(strncmp((char *)ob->pkt->arg_2,"ALL"  ,ob->pkt->arg_2_len)==0)
								                {flash_vol_read_all();}
							}
							else if(strncmp((char *)ob->pkt->arg_1,"READ",ob->pkt->arg_1_len)==0)
							{
								                if(strncmp((char *)ob->pkt->arg_2,"ALL"  ,ob->pkt->arg_2_len)==0)
								                {vol_read_all();}
																else if(strncmp((char *)ob->pkt->arg_2,"TN100"  ,ob->pkt->arg_2_len)==0)
																{sep_vol_read(1,1,"VREG_S2B_0P752(TN100)");}
																else if(strncmp((char *)ob->pkt->arg_2,"TN101"  ,ob->pkt->arg_2_len)==0)
																{sep_vol_read(2,1,"VREG_S3B_S4B(TN101)");}
																else if(strncmp((char *)ob->pkt->arg_2,"TN102"  ,ob->pkt->arg_2_len)==0)
																{sep_vol_read(3,1,"VREG_S5B_0P6(TN102)");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TN118"  ,ob->pkt->arg_2_len)==0)
																{sep_vol_read(4,1,"VREG_S1A(TN118)");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TN120"  ,ob->pkt->arg_2_len)==0)
																{sep_vol_read(5,1,"VREG_S1B(TN120)");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TN124"  ,ob->pkt->arg_2_len)==0)
																{sep_vol_read(6,1,"VREG_L13A(TN124)");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TN127"  ,ob->pkt->arg_2_len)==0)
																{sep_vol_read(7,1,"VREG_L9B(TN127)");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TN134"  ,ob->pkt->arg_2_len)==0)
																{sep_vol_read(8,1,"VREG_S2A_S3A(TN134)");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TN139"  ,ob->pkt->arg_2_len)==0)
																{sep_vol_read(9,1,"VREG_S5A(TN139)");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TN144"  ,ob->pkt->arg_2_len)==0)
																{sep_vol_read(10,1,"VREG_L3A(TN144)");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TN149"  ,ob->pkt->arg_2_len)==0)
																{sep_vol_read(11,1,"VREG_L5A(TN149)");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TN152"  ,ob->pkt->arg_2_len)==0)
																{sep_vol_read(12,1,"VREG_L17A(TN152)");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TN157"  ,ob->pkt->arg_2_len)==0)
																{sep_vol_read(13,1,"VREG_L2B(TN157)");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TN160"  ,ob->pkt->arg_2_len)==0)
																{sep_vol_read(14,1,"VREG_DBU1(TN160)");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TN161"  ,ob->pkt->arg_2_len)==0)
																{sep_vol_read(15,1,"VCC_3P3_STANDBY(TN161)");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TN164"  ,ob->pkt->arg_2_len)==0)
																{sep_vol_read(16,1,"VREG_S6A(TN164)");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TN167"  ,ob->pkt->arg_2_len)==0)
																{sep_vol_read(17,1,"VREG_L11A(TN167)");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TN175"  ,ob->pkt->arg_2_len)==0)
																{sep_vol_read(18,1,"VBATT_3P7(TN175)");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TN169"  ,ob->pkt->arg_2_len)==0)
																{sep_vol_read(19,1,"VREG_L1B(TN169)");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TN170"  ,ob->pkt->arg_2_len)==0)
																{sep_vol_read(20,1,"VREG_S4A(TN170)");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TN172"  ,ob->pkt->arg_2_len)==0)
																{sep_vol_read(21,1,"VREG_L10A(TN172)");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TN173"  ,ob->pkt->arg_2_len)==0)
																{sep_vol_read(22,1,"VREG_L15A(TN173)");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TN181"  ,ob->pkt->arg_2_len)==0)
																{sep_vol_read(23,1,"VREG_L1A(TN181)");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TN207"  ,ob->pkt->arg_2_len)==0)
																{sep_vol_read(24,1,"VREG_BOB(TN207)");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TN213"  ,ob->pkt->arg_2_len)==0)
																{sep_vol_read(25,1,"VPH_PWR(TN213)");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TN45"  ,ob->pkt->arg_2_len)==0)
																{sep_vol_read(26,1,"VREG_L8A(TN45)");}
																else if(strncmp((char *)ob->pkt->arg_2, "TN52"  ,ob->pkt->arg_2_len)==0)
																{sep_vol_read(27,1,"VREG_L4B(TN52)");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TN92"  ,ob->pkt->arg_2_len)==0)
																{sep_vol_read(28,1,"VREG_L7A(TN92)");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TN56"  ,ob->pkt->arg_2_len)==0)
																{sep_vol_read(29,1,"VREG_L19A(TN56)");}																																																											
																	else if(strncmp((char *)ob->pkt->arg_2,"TN57"  ,ob->pkt->arg_2_len)==0)
																{sep_vol_read(30,1,"VREG_L7B(TN57)");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TN74"  ,ob->pkt->arg_2_len)==0)
																{sep_vol_read(31,1,"VREG_L2A(TN74)");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TN75"  ,ob->pkt->arg_2_len)==0)
																{sep_vol_read(32,1,"VREG_L6A(TN75)");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TN78"  ,ob->pkt->arg_2_len)==0)
																{sep_vol_read(1,2,"VREG_L5B(TN78)");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TN87"  ,ob->pkt->arg_2_len)==0)
																{sep_vol_read(2,2,"VREG_L12A(TN87)");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TN88"  ,ob->pkt->arg_2_len)==0)
																{sep_vol_read(3,2,"VCC_6P0_V(TN88)");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TN88_2"  ,ob->pkt->arg_2_len)==0)
																{sep_vol_read(4,2,"VCC_6P0_IMP(TN88_2)");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TN218"  ,ob->pkt->arg_2_len)==0)
																{sep_vol_read(5,2,"VCC_6P0_FAN_V(TN218)");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TN218_2"  ,ob->pkt->arg_2_len)==0)
																{sep_vol_read(6,2,"VCC_6P0_FAN_IMP(TN218_2)");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TN70"  ,ob->pkt->arg_2_len)==0)
																{sep_vol_read(7,2,"VREG_L13A_1P8(TN70)");}
                                else if(strncmp((char *)ob->pkt->arg_2,"TN109"  ,ob->pkt->arg_2_len)==0)
																{sep_vol_read(8,2,"WLAN_SW(TN109)");}
                                else if(strncmp((char *)ob->pkt->arg_2,"USB"  ,ob->pkt->arg_2_len)==0)
																{sep_vol_read(9,2,"USB_VBUS_IMP");}																
							}
		}
else if(strncmp((char *)ob->pkt->keyword,"MUX",ob->pkt->keyword_len)==0)
{
							if(strncmp((char *)ob->pkt->arg_1,"EN",ob->pkt->arg_1_len)==0)
							{
																if(strncmp((char *)ob->pkt->arg_2,"MUX1"  ,ob->pkt->arg_2_len)==0)
																{ mux_switch_EN_DI(MUX_1);}
							                  else if(strncmp((char *)ob->pkt->arg_2,"MUX2"  ,ob->pkt->arg_2_len)==0)
																{mux_switch_EN_DI(MUX_2);}
																else if(strncmp((char *)ob->pkt->arg_2,"MUX2"  ,ob->pkt->arg_2_len)==0)
																{mux_switch_EN_DI(MUX_3);}
																else if(strncmp((char *)ob->pkt->arg_2,"MUX4"  ,ob->pkt->arg_2_len)==0)
																{mux_switch_EN_DI(MUX_4);}
																else if(strncmp((char *)ob->pkt->arg_2,"ALL"  ,ob->pkt->arg_2_len)==0)
																{mux_switch_EN_DI(ALL_EN);}
							}
							else if(strncmp((char *)ob->pkt->arg_1,"DIS",ob->pkt->arg_1_len)==0)
							{
			                          if(strncmp((char *)ob->pkt->arg_2,"ALL"  ,ob->pkt->arg_2_len)==0)
					                      {mux_switch_EN_DI(ALL_DI);}
	            }
	}
	else if(strncmp((char *)ob->pkt->keyword,"MSP",ob->pkt->keyword_len)==0)
{
		           if(strncmp((char *)ob->pkt->arg_1,"INT",ob->pkt->arg_1_len)==0)
		          {
									   if(strncmp((char *)ob->pkt->arg_2,"TEST"  ,ob->pkt->arg_2_len)==0)
										 {
										   gpio_mspint();
										 }
																
						  }
}
																
                                																
																
							}			
else if(strncmp((char *)ob->pkt->keyword,"DUT",ob->pkt->keyword_len)==0)
{
							if(strncmp((char *)ob->pkt->arg_1,"POWER",ob->pkt->arg_1_len)==0)
							{
																if(strncmp((char *)ob->pkt->arg_2,"ON"  ,ob->pkt->arg_2_len)==0)
																{dut_pwr_on_OFF(ON);}
							                  else if(strncmp((char *)ob->pkt->arg_2,"OFF"  ,ob->pkt->arg_2_len)==0)
																{dut_pwr_on_OFF(OFF);}
							}
}
else if(strncmp((char *)ob->pkt->keyword,"0V8",ob->pkt->keyword_len)==0)
{
							if(strncmp((char *)ob->pkt->arg_1,"PWR",ob->pkt->arg_1_len)==0)
							{
																if(strncmp((char *)ob->pkt->arg_2,"ON"  ,ob->pkt->arg_2_len)==0)
																{HAL_GPIO_WritePin(GPIOD,GPIO_PIN_14,GPIO_PIN_SET);}
							                  else if(strncmp((char *)ob->pkt->arg_2,"OFF"  ,ob->pkt->arg_2_len)==0)
																{HAL_GPIO_WritePin(GPIOD,GPIO_PIN_14,GPIO_PIN_RESET);;}
							}
}
	else if(strncmp((char *)ob->pkt->keyword,"PWM",ob->pkt->keyword_len)==0)
{
							if(strncmp((char *)ob->pkt->arg_1,"DUTY",ob->pkt->arg_1_len)==0)
							{
																if(strncmp((char *)ob->pkt->arg_2,"FAN"  ,ob->pkt->arg_2_len)==0)
																{pwm_duty_cycle_measurment(1,CH_8);}
							                  else if(strncmp((char *)ob->pkt->arg_2,"IMU"  ,ob->pkt->arg_2_len)==0)
																{pwm_duty_cycle_measurment(2,CH_9);}
																else if(strncmp((char *)ob->pkt->arg_2,"CAM2"  ,ob->pkt->arg_2_len)==0)
																{pwm_duty_cycle_measurment(3,CH_10);}
																else if(strncmp((char *)ob->pkt->arg_2,"CAM0"  ,ob->pkt->arg_2_len)==0)
																{pwm_duty_cycle_measurment(4,CH_11);}
																else if(strncmp((char *)ob->pkt->arg_2,"FSYS"  ,ob->pkt->arg_2_len)==0)
																{pwm_duty_cycle_measurment(5,CH_11);}
							}
}
	else if(strncmp((char *)ob->pkt->keyword,"DEBUG",ob->pkt->keyword_len)==0)
	{
							if(strncmp((char *)ob->pkt->arg_1,"FLAG",ob->pkt->arg_1_len)==0)
							{
																if(strncmp((char *)ob->pkt->arg_2,"ON"  ,ob->pkt->arg_2_len)==0)
																{my_flag=DEBUG;
																printmsg ("DEBUG MODE ON\r\n");}													                
							}
	}
	else if(strncmp((char *)ob->pkt->keyword,"APP",ob->pkt->keyword_len)==0)
	{
							if(strncmp((char *)ob->pkt->arg_1,"FLAG",ob->pkt->arg_1_len)==0)
							{
																if(strncmp((char *)ob->pkt->arg_2,"ON"  ,ob->pkt->arg_2_len)==0)
																{my_flag=APP;
																printmsg ("APP MODE ON\r\n");}																															                
							}
	}
	else if(strncmp((char *)ob->pkt->keyword,"POST",ob->pkt->keyword_len)==0)
	{
							if(strncmp((char *)ob->pkt->arg_1,"VOL",ob->pkt->arg_1_len)==0)
							{
																if(strncmp((char *)ob->pkt->arg_2,"ALL"  ,ob->pkt->arg_2_len)==0)
																{flash_vol_read_all(); }
																else if(strncmp((char *)ob->pkt->arg_2,"MUX1"  ,ob->pkt->arg_2_len)==0)
																{post_vol_read_mux_1();}
																	else if(strncmp((char *)ob->pkt->arg_2,"MUX2"  ,ob->pkt->arg_2_len)==0)
																{post_vol_read_mux_rest(MUX_2,CH_2,"VREG_L12A_1P8(TP87)MUX_2");}
																	else if(strncmp((char *)ob->pkt->arg_2,"MUX3"  ,ob->pkt->arg_2_len)==0)
																{post_vol_read_mux_rest(MUX_3,CH_3,"CAM0_PWRTP(TP163)MUX_3");}
																	else if(strncmp((char *)ob->pkt->arg_2,"MUX4"  ,ob->pkt->arg_2_len)==0)
																{post_vol_read_mux_rest(MUX_4,CH_4,"EEPROM_WP(TP166)MUX_4");}															
				                
							}
	}
	else if(strncmp((char *)ob->pkt->keyword,"PWR",ob->pkt->keyword_len)==0)
	{
							if(strncmp((char *)ob->pkt->arg_1,"TEST",ob->pkt->arg_1_len)==0)
							{
																if(strncmp((char *)ob->pkt->arg_2,"TP161"  ,ob->pkt->arg_2_len)==0)
																{volt_check_usb_pwr_all(1); }
																else if(strncmp((char *)ob->pkt->arg_2,"TP175"  ,ob->pkt->arg_2_len)==0)
																{volt_check_usb_pwr_all(2); }
																else if(strncmp((char *)ob->pkt->arg_2,"TP213"  ,ob->pkt->arg_2_len)==0)
																{volt_check_usb_pwr_all(3); }
																else if(strncmp((char *)ob->pkt->arg_2,"TP88"  ,ob->pkt->arg_2_len)==0)
																{volt_check_usb_pwr_all(4); }
																else if(strncmp((char *)ob->pkt->arg_2,"TP218"  ,ob->pkt->arg_2_len)==0)
																{volt_check_usb_pwr_all(5); }
																else if(strncmp((char *)ob->pkt->arg_2,"ALL"  ,ob->pkt->arg_2_len)==0)
																{volt_check_usb_pwr_all(6); }
							                 
							}
	}
	
	else if(strncmp((char *)ob->pkt->keyword,"RESET",ob->pkt->keyword_len)==0)
	{
							if(strncmp((char *)ob->pkt->arg_1,"ALL",ob->pkt->arg_1_len)==0)
							{
																if(strncmp((char *)ob->pkt->arg_2,"STATE"  ,ob->pkt->arg_2_len)==0)
																{ }
							                 
							}
	}
	else if(strncmp((char *)ob->pkt->keyword,"EDL",ob->pkt->keyword_len)==0)
	{
							if(strncmp((char *)ob->pkt->arg_1,"MODE",ob->pkt->arg_1_len)==0)
							{
																if(strncmp((char *)ob->pkt->arg_2,"ON"  ,ob->pkt->arg_2_len)==0)
																{FAST_BT_EN;
																	AVCC_3V3_EN;
                                 printmsg ("EDL MODE ENABLED\r\n");}																
																else if(strncmp((char *)ob->pkt->arg_2,"OFF"  ,ob->pkt->arg_2_len)==0)
																{FAST_BT_DI;
																 printmsg ("EDL MODE DISABLED\r\n");
																}
							                 
							}
	}
	else if(strncmp((char *)ob->pkt->keyword,"GPIO",ob->pkt->keyword_len)==0)
	{
							if(strncmp((char *)ob->pkt->arg_1,"MSP_CAN_INT",ob->pkt->arg_1_len)==0)
							{
															  if(strncmp((char *)ob->pkt->arg_2,"ON"  ,ob->pkt->arg_2_len)==0)
															  {gpio_write_pin(TP12, ON);}
															  else if(strncmp((char *)ob->pkt->arg_2,"OFF"  ,ob->pkt->arg_2_len)==0)
															  {gpio_write_pin(TP12, OFF);}
							                 
							}
							else if(strncmp((char *)ob->pkt->arg_1,"MSP_IGN",ob->pkt->arg_1_len)==0)
							{
								                if(strncmp((char *)ob->pkt->arg_2,"ON"  ,ob->pkt->arg_2_len)==0)
																{gpio_write_pin(TP210, ON);}
																else if(strncmp((char *)ob->pkt->arg_2,"OFF"  ,ob->pkt->arg_2_len)==0)
																{gpio_write_pin(TP210, OFF);}
							}
							else if(strncmp((char *)ob->pkt->arg_1,"OBD_GPS",ob->pkt->arg_1_len)==0)
							{
								                if(strncmp((char *)ob->pkt->arg_2,"ON"  ,ob->pkt->arg_2_len)==0)
																{gpio_write_pin(TP215, ON);}
																else if(strncmp((char *)ob->pkt->arg_2,"OFF"  ,ob->pkt->arg_2_len)==0)
																{gpio_write_pin(TP215, OFF);}
							}
							else if(strncmp((char *)ob->pkt->arg_1,"CAM2_AVDD",ob->pkt->arg_1_len)==0)
							{
								                if(strncmp((char *)ob->pkt->arg_2,"ON"  ,ob->pkt->arg_2_len)==0)
																{gpio_write_pin(TP37, ON);}
																else if(strncmp((char *)ob->pkt->arg_2,"OFF"  ,ob->pkt->arg_2_len)==0)
																{gpio_write_pin(TP37, OFF);}
							}
	}
		else if(strncmp((char *)ob->pkt->keyword,"READ",ob->pkt->keyword_len)==0)
	{
							if(strncmp((char *)ob->pkt->arg_1,"GPIO",ob->pkt->arg_1_len)==0)
							{
																if(strncmp((char *)ob->pkt->arg_2,"TP201"  ,ob->pkt->arg_2_len)==0)
																{gpio_read_test(MUX_4, CH_6,"USER_BUTTON");}
																else if(strncmp((char *)ob->pkt->arg_2,"TP200"  ,ob->pkt->arg_2_len)==0)
																{gpio_read_test(MUX_4, CH_5,"CAM0_PWR_EN");}
																else if(strncmp((char *)ob->pkt->arg_2,"TP94"  ,ob->pkt->arg_2_len)==0)
																{gpio_read_test(MUX_3, CH_2,"LTC_PFO_N");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TP109"  ,ob->pkt->arg_2_len)==0)
																{gpio_read_test(MUX_2, CH_8,"WLAN_SW_CTRL");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TP133"  ,ob->pkt->arg_2_len)==0)
																{gpio_read_test(MUX_4, CH_8,"PHONE_ON_N");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TP143"  ,ob->pkt->arg_2_len)==0)
																{gpio_read_test(MUX_4, CH_7,"EN_3V3");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TP150"  ,ob->pkt->arg_2_len)==0)
																{gpio_read_test(MUX_4, CH_4,"MSP_SYS_INT");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TP153"  ,ob->pkt->arg_2_len)==0)
																{gpio_read_test(MUX_4, CH_1,"SPI_CS_SW_EN");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TP194"  ,ob->pkt->arg_2_len)==0)
																{gpio_read_test(MUX_3, CH_4,"QCS_FLASH_SPI_CS");}
																	else if(strncmp((char *)ob->pkt->arg_2,"TP46"  ,ob->pkt->arg_2_len)==0)
																{gpio_read_test(MUX_3, CH_6,"CDC_MIC_BIAS1");}
							                 
							}
	}
	else if(strncmp((char *)ob->pkt->keyword,"FBOOT",ob->pkt->keyword_len)==0)
	{
							if(strncmp((char *)ob->pkt->arg_1,"MODE",ob->pkt->arg_1_len)==0)
							{
																if(strncmp((char *)ob->pkt->arg_2,"ON"  ,ob->pkt->arg_2_len)==0)
																{ fast_boot_fun(ON);  }
																else if(strncmp((char *)ob->pkt->arg_2,"OFF"  ,ob->pkt->arg_2_len)==0)
																{ fast_boot_fun(OFF);}
							                 
							}
	}
	
	else if(strncmp((char *)ob->pkt->keyword,"PWR",ob->pkt->keyword_len)==0)
	{
							if(strncmp((char *)ob->pkt->arg_1,"BUTT",ob->pkt->arg_1_len)==0)
							{
																if(strncmp((char *)ob->pkt->arg_2,"ON"  ,ob->pkt->arg_2_len)==0)
																{ }
							                  else if(strncmp((char *)ob->pkt->arg_2,"OFF"  ,ob->pkt->arg_2_len)==0)
																{ }
							}
	}
	
	else if(strncmp((char *)ob->pkt->keyword,"SOFT",ob->pkt->keyword_len)==0)
	{
							if(strncmp((char *)ob->pkt->arg_1,"RST",ob->pkt->arg_1_len)==0)
							{
																if(strncmp((char *)ob->pkt->arg_2,"MCU"  ,ob->pkt->arg_2_len)==0)
																{ }
							                 
							}
	}
	

}	
	return ob;
	}

		/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

   /** @fun    01
  * @brief  Impedance and volatge channel are to be selected by this funtion
  * @param  channel Number 
  * @retval None
  */
void set_mux_ch(uint8_t channel) // To select the MUX  for Voltage and impedance test MUX
 { 
	switch(channel)
	{
		case 1:   
		//	HAL_Delay(100);
							HAL_GPIO_WritePin(MAIN_MUX_SELC_0_GPIO_Port,MAIN_MUX_SELC_0_Pin,GPIO_PIN_RESET);//0
							HAL_GPIO_WritePin(MAIN_MUX_SELC_1_GPIO_Port,MAIN_MUX_SELC_1_Pin,GPIO_PIN_RESET);//0
							HAL_GPIO_WritePin(MAIN_MUX_SELC_2_GPIO_Port,MAIN_MUX_SELC_2_Pin,GPIO_PIN_RESET);//0 
							HAL_GPIO_WritePin(MAIN_MUX_SELC_3_GPIO_Port,MAIN_MUX_SELC_3_Pin,GPIO_PIN_RESET);//0
		          HAL_GPIO_WritePin(MAIN_MUX_SELC_4_GPIO_Port,MAIN_MUX_SELC_4_Pin,GPIO_PIN_RESET);//0
		          HAL_Delay(500);
			break;
		case 2:
							HAL_GPIO_WritePin(MAIN_MUX_SELC_0_GPIO_Port,MAIN_MUX_SELC_0_Pin,GPIO_PIN_SET);   //1
							HAL_GPIO_WritePin(MAIN_MUX_SELC_1_GPIO_Port,MAIN_MUX_SELC_1_Pin,GPIO_PIN_RESET);  //0
							HAL_GPIO_WritePin(MAIN_MUX_SELC_2_GPIO_Port,MAIN_MUX_SELC_2_Pin,GPIO_PIN_RESET);  //0 
							HAL_GPIO_WritePin(MAIN_MUX_SELC_3_GPIO_Port,MAIN_MUX_SELC_3_Pin,GPIO_PIN_RESET);  //0
		          HAL_GPIO_WritePin(MAIN_MUX_SELC_4_GPIO_Port,MAIN_MUX_SELC_4_Pin,GPIO_PIN_RESET);  //0
		          HAL_Delay(1000);
			break;
		case 3:
							HAL_GPIO_WritePin(MAIN_MUX_SELC_0_GPIO_Port,MAIN_MUX_SELC_0_Pin,GPIO_PIN_RESET);//0
							HAL_GPIO_WritePin(MAIN_MUX_SELC_1_GPIO_Port,MAIN_MUX_SELC_1_Pin,GPIO_PIN_SET);//1
							HAL_GPIO_WritePin(MAIN_MUX_SELC_2_GPIO_Port,MAIN_MUX_SELC_2_Pin,GPIO_PIN_RESET);//0 
							HAL_GPIO_WritePin(MAIN_MUX_SELC_3_GPIO_Port,MAIN_MUX_SELC_3_Pin,GPIO_PIN_RESET);//0
		          HAL_GPIO_WritePin(MAIN_MUX_SELC_4_GPIO_Port,MAIN_MUX_SELC_4_Pin,GPIO_PIN_RESET);//0
		          HAL_Delay(2000);
			break;
		case 4:
							HAL_GPIO_WritePin(MAIN_MUX_SELC_0_GPIO_Port,MAIN_MUX_SELC_0_Pin,GPIO_PIN_SET);//1
							HAL_GPIO_WritePin(MAIN_MUX_SELC_1_GPIO_Port,MAIN_MUX_SELC_1_Pin,GPIO_PIN_SET);//1
							HAL_GPIO_WritePin(MAIN_MUX_SELC_2_GPIO_Port,MAIN_MUX_SELC_2_Pin,GPIO_PIN_RESET);//0 
							HAL_GPIO_WritePin(MAIN_MUX_SELC_3_GPIO_Port,MAIN_MUX_SELC_3_Pin,GPIO_PIN_RESET);//0
		          HAL_GPIO_WritePin(MAIN_MUX_SELC_4_GPIO_Port,MAIN_MUX_SELC_4_Pin,GPIO_PIN_RESET);//0
		          HAL_Delay(500);
			break;
		case 5:	
		          HAL_GPIO_WritePin(MAIN_MUX_SELC_0_GPIO_Port,MAIN_MUX_SELC_0_Pin,GPIO_PIN_RESET);//0
							HAL_GPIO_WritePin(MAIN_MUX_SELC_1_GPIO_Port,MAIN_MUX_SELC_1_Pin,GPIO_PIN_RESET);//0
							HAL_GPIO_WritePin(MAIN_MUX_SELC_2_GPIO_Port,MAIN_MUX_SELC_2_Pin,GPIO_PIN_SET);//1 
							HAL_GPIO_WritePin(MAIN_MUX_SELC_3_GPIO_Port,MAIN_MUX_SELC_3_Pin,GPIO_PIN_RESET);//0
		          HAL_GPIO_WritePin(MAIN_MUX_SELC_4_GPIO_Port,MAIN_MUX_SELC_4_Pin,GPIO_PIN_RESET);//0
		          HAL_Delay(500);
			break;
		case 6:
							HAL_GPIO_WritePin(MAIN_MUX_SELC_0_GPIO_Port,MAIN_MUX_SELC_0_Pin,GPIO_PIN_SET);//1
							HAL_GPIO_WritePin(MAIN_MUX_SELC_1_GPIO_Port,MAIN_MUX_SELC_1_Pin,GPIO_PIN_RESET);//0
							HAL_GPIO_WritePin(MAIN_MUX_SELC_2_GPIO_Port,MAIN_MUX_SELC_2_Pin,GPIO_PIN_SET);//1 
							HAL_GPIO_WritePin(MAIN_MUX_SELC_3_GPIO_Port,MAIN_MUX_SELC_3_Pin,GPIO_PIN_RESET);//0
		          HAL_GPIO_WritePin(MAIN_MUX_SELC_4_GPIO_Port,MAIN_MUX_SELC_4_Pin,GPIO_PIN_RESET);//0
		          HAL_Delay(1000);
			break;
		case 7:
							HAL_GPIO_WritePin(MAIN_MUX_SELC_0_GPIO_Port,MAIN_MUX_SELC_0_Pin,GPIO_PIN_RESET);//0
							HAL_GPIO_WritePin(MAIN_MUX_SELC_1_GPIO_Port,MAIN_MUX_SELC_1_Pin,GPIO_PIN_SET);//1
							HAL_GPIO_WritePin(MAIN_MUX_SELC_2_GPIO_Port,MAIN_MUX_SELC_2_Pin,GPIO_PIN_SET);//1 
							HAL_GPIO_WritePin(MAIN_MUX_SELC_3_GPIO_Port,MAIN_MUX_SELC_3_Pin,GPIO_PIN_RESET);//0
		          HAL_GPIO_WritePin(MAIN_MUX_SELC_4_GPIO_Port,MAIN_MUX_SELC_4_Pin,GPIO_PIN_RESET);//0
		          HAL_Delay(1000);
			break;
		case 8:
							HAL_GPIO_WritePin(MAIN_MUX_SELC_0_GPIO_Port,MAIN_MUX_SELC_0_Pin,GPIO_PIN_SET);//1
							HAL_GPIO_WritePin(MAIN_MUX_SELC_1_GPIO_Port,MAIN_MUX_SELC_1_Pin,GPIO_PIN_SET);//1
							HAL_GPIO_WritePin(MAIN_MUX_SELC_2_GPIO_Port,MAIN_MUX_SELC_2_Pin,GPIO_PIN_SET);//1 
							HAL_GPIO_WritePin(MAIN_MUX_SELC_3_GPIO_Port,MAIN_MUX_SELC_3_Pin,GPIO_PIN_RESET);//0
		          HAL_GPIO_WritePin(MAIN_MUX_SELC_4_GPIO_Port,MAIN_MUX_SELC_4_Pin,GPIO_PIN_RESET);//0
		          HAL_Delay(700);
			break;
		case 9:
							HAL_GPIO_WritePin(MAIN_MUX_SELC_0_GPIO_Port,MAIN_MUX_SELC_0_Pin,GPIO_PIN_RESET);//0
							HAL_GPIO_WritePin(MAIN_MUX_SELC_1_GPIO_Port,MAIN_MUX_SELC_1_Pin,GPIO_PIN_RESET);//0
							HAL_GPIO_WritePin(MAIN_MUX_SELC_2_GPIO_Port,MAIN_MUX_SELC_2_Pin,GPIO_PIN_RESET);//0 
							HAL_GPIO_WritePin(MAIN_MUX_SELC_3_GPIO_Port,MAIN_MUX_SELC_3_Pin,GPIO_PIN_SET);//1
		          HAL_GPIO_WritePin(MAIN_MUX_SELC_4_GPIO_Port,MAIN_MUX_SELC_4_Pin,GPIO_PIN_RESET);//0
		          HAL_Delay(500);
			break;
		case 10:
							HAL_GPIO_WritePin(MAIN_MUX_SELC_0_GPIO_Port,MAIN_MUX_SELC_0_Pin,GPIO_PIN_SET);//1
							HAL_GPIO_WritePin(MAIN_MUX_SELC_1_GPIO_Port,MAIN_MUX_SELC_1_Pin,GPIO_PIN_RESET);//0
							HAL_GPIO_WritePin(MAIN_MUX_SELC_2_GPIO_Port,MAIN_MUX_SELC_2_Pin,GPIO_PIN_RESET);//0 
							HAL_GPIO_WritePin(MAIN_MUX_SELC_3_GPIO_Port,MAIN_MUX_SELC_3_Pin,GPIO_PIN_SET);//1
		          HAL_GPIO_WritePin(MAIN_MUX_SELC_4_GPIO_Port,MAIN_MUX_SELC_4_Pin,GPIO_PIN_RESET);//0
		          HAL_Delay(500);
			break;
	case 11:   //-------1 
							HAL_GPIO_WritePin(MAIN_MUX_SELC_0_GPIO_Port,MAIN_MUX_SELC_0_Pin,GPIO_PIN_RESET);//0
							HAL_GPIO_WritePin(MAIN_MUX_SELC_1_GPIO_Port,MAIN_MUX_SELC_1_Pin,GPIO_PIN_SET);//1
							HAL_GPIO_WritePin(MAIN_MUX_SELC_2_GPIO_Port,MAIN_MUX_SELC_2_Pin,GPIO_PIN_RESET);//0 
							HAL_GPIO_WritePin(MAIN_MUX_SELC_3_GPIO_Port,MAIN_MUX_SELC_3_Pin,GPIO_PIN_SET);//1
		          HAL_GPIO_WritePin(MAIN_MUX_SELC_4_GPIO_Port,MAIN_MUX_SELC_4_Pin,GPIO_PIN_RESET);//0
	            HAL_Delay(1000);
			break;
		case 12:
							HAL_GPIO_WritePin(MAIN_MUX_SELC_0_GPIO_Port,MAIN_MUX_SELC_0_Pin,GPIO_PIN_SET);//1
							HAL_GPIO_WritePin(MAIN_MUX_SELC_1_GPIO_Port,MAIN_MUX_SELC_1_Pin,GPIO_PIN_SET);//1
							HAL_GPIO_WritePin(MAIN_MUX_SELC_2_GPIO_Port,MAIN_MUX_SELC_2_Pin,GPIO_PIN_RESET);//0 
							HAL_GPIO_WritePin(MAIN_MUX_SELC_3_GPIO_Port,MAIN_MUX_SELC_3_Pin,GPIO_PIN_SET);//1
		          HAL_GPIO_WritePin(MAIN_MUX_SELC_4_GPIO_Port,MAIN_MUX_SELC_4_Pin,GPIO_PIN_RESET);//0
		          HAL_Delay(5000);
			break;
		case 13:
							HAL_GPIO_WritePin(MAIN_MUX_SELC_0_GPIO_Port,MAIN_MUX_SELC_0_Pin,GPIO_PIN_RESET);//0
							HAL_GPIO_WritePin(MAIN_MUX_SELC_1_GPIO_Port,MAIN_MUX_SELC_1_Pin,GPIO_PIN_RESET);//0
							HAL_GPIO_WritePin(MAIN_MUX_SELC_2_GPIO_Port,MAIN_MUX_SELC_2_Pin,GPIO_PIN_SET);//1 
							HAL_GPIO_WritePin(MAIN_MUX_SELC_3_GPIO_Port,MAIN_MUX_SELC_3_Pin,GPIO_PIN_SET);//1
		          HAL_GPIO_WritePin(MAIN_MUX_SELC_4_GPIO_Port,MAIN_MUX_SELC_4_Pin,GPIO_PIN_RESET);//0
		          HAL_Delay(1000);
			break;
		case 14:
							HAL_GPIO_WritePin(MAIN_MUX_SELC_0_GPIO_Port,MAIN_MUX_SELC_0_Pin,GPIO_PIN_SET);//1
							HAL_GPIO_WritePin(MAIN_MUX_SELC_1_GPIO_Port,MAIN_MUX_SELC_1_Pin,GPIO_PIN_RESET);//0
							HAL_GPIO_WritePin(MAIN_MUX_SELC_2_GPIO_Port,MAIN_MUX_SELC_2_Pin,GPIO_PIN_SET);//1 
							HAL_GPIO_WritePin(MAIN_MUX_SELC_3_GPIO_Port,MAIN_MUX_SELC_3_Pin,GPIO_PIN_SET);//1
		          HAL_GPIO_WritePin(MAIN_MUX_SELC_4_GPIO_Port,MAIN_MUX_SELC_4_Pin,GPIO_PIN_RESET);//0
		          HAL_Delay(500);
			break;
		case 15:	
		          HAL_GPIO_WritePin(MAIN_MUX_SELC_0_GPIO_Port,MAIN_MUX_SELC_0_Pin,GPIO_PIN_RESET);//0
							HAL_GPIO_WritePin(MAIN_MUX_SELC_1_GPIO_Port,MAIN_MUX_SELC_1_Pin,GPIO_PIN_SET);//1
							HAL_GPIO_WritePin(MAIN_MUX_SELC_2_GPIO_Port,MAIN_MUX_SELC_2_Pin,GPIO_PIN_SET);//1 
							HAL_GPIO_WritePin(MAIN_MUX_SELC_3_GPIO_Port,MAIN_MUX_SELC_3_Pin,GPIO_PIN_SET);//1
		          HAL_GPIO_WritePin(MAIN_MUX_SELC_4_GPIO_Port,MAIN_MUX_SELC_4_Pin,GPIO_PIN_RESET);//0
		          HAL_Delay(1000);
			break;
		case 16:
							HAL_GPIO_WritePin(MAIN_MUX_SELC_0_GPIO_Port,MAIN_MUX_SELC_0_Pin,GPIO_PIN_SET);//1
							HAL_GPIO_WritePin(MAIN_MUX_SELC_1_GPIO_Port,MAIN_MUX_SELC_1_Pin,GPIO_PIN_SET);//1
							HAL_GPIO_WritePin(MAIN_MUX_SELC_2_GPIO_Port,MAIN_MUX_SELC_2_Pin,GPIO_PIN_SET);//1 
							HAL_GPIO_WritePin(MAIN_MUX_SELC_3_GPIO_Port,MAIN_MUX_SELC_3_Pin,GPIO_PIN_SET);//1
		          HAL_GPIO_WritePin(MAIN_MUX_SELC_4_GPIO_Port,MAIN_MUX_SELC_4_Pin,GPIO_PIN_RESET);//0
		          HAL_Delay(500);
			break;
		case 17:
							HAL_GPIO_WritePin(MAIN_MUX_SELC_0_GPIO_Port,MAIN_MUX_SELC_0_Pin,GPIO_PIN_RESET);//0
							HAL_GPIO_WritePin(MAIN_MUX_SELC_1_GPIO_Port,MAIN_MUX_SELC_1_Pin,GPIO_PIN_RESET);//0
							HAL_GPIO_WritePin(MAIN_MUX_SELC_2_GPIO_Port,MAIN_MUX_SELC_2_Pin,GPIO_PIN_RESET);//0 
							HAL_GPIO_WritePin(MAIN_MUX_SELC_3_GPIO_Port,MAIN_MUX_SELC_3_Pin,GPIO_PIN_RESET);//0
		          HAL_GPIO_WritePin(MAIN_MUX_SELC_4_GPIO_Port,MAIN_MUX_SELC_4_Pin,GPIO_PIN_SET);//1
		          HAL_Delay(500);
			break;
		case 18:
							HAL_GPIO_WritePin(MAIN_MUX_SELC_0_GPIO_Port,MAIN_MUX_SELC_0_Pin,GPIO_PIN_SET);//1
							HAL_GPIO_WritePin(MAIN_MUX_SELC_1_GPIO_Port,MAIN_MUX_SELC_1_Pin,GPIO_PIN_RESET);//0
							HAL_GPIO_WritePin(MAIN_MUX_SELC_2_GPIO_Port,MAIN_MUX_SELC_2_Pin,GPIO_PIN_RESET);//0 
							HAL_GPIO_WritePin(MAIN_MUX_SELC_3_GPIO_Port,MAIN_MUX_SELC_3_Pin,GPIO_PIN_RESET);//0
		          HAL_GPIO_WritePin(MAIN_MUX_SELC_4_GPIO_Port,MAIN_MUX_SELC_4_Pin,GPIO_PIN_SET);//1
		          HAL_Delay(200);
			break;
		case 19:
							HAL_GPIO_WritePin(MAIN_MUX_SELC_0_GPIO_Port,MAIN_MUX_SELC_0_Pin,GPIO_PIN_RESET);//0
							HAL_GPIO_WritePin(MAIN_MUX_SELC_1_GPIO_Port,MAIN_MUX_SELC_1_Pin,GPIO_PIN_SET);//1
							HAL_GPIO_WritePin(MAIN_MUX_SELC_2_GPIO_Port,MAIN_MUX_SELC_2_Pin,GPIO_PIN_RESET);//0 
							HAL_GPIO_WritePin(MAIN_MUX_SELC_3_GPIO_Port,MAIN_MUX_SELC_3_Pin,GPIO_PIN_RESET);//0
		          HAL_GPIO_WritePin(MAIN_MUX_SELC_4_GPIO_Port,MAIN_MUX_SELC_4_Pin,GPIO_PIN_SET);//1
		          HAL_Delay(200);
			break;
		case 20:
							HAL_GPIO_WritePin(MAIN_MUX_SELC_0_GPIO_Port,MAIN_MUX_SELC_0_Pin,GPIO_PIN_SET);//1
							HAL_GPIO_WritePin(MAIN_MUX_SELC_1_GPIO_Port,MAIN_MUX_SELC_1_Pin,GPIO_PIN_SET);//1
							HAL_GPIO_WritePin(MAIN_MUX_SELC_2_GPIO_Port,MAIN_MUX_SELC_2_Pin,GPIO_PIN_RESET);//0 
							HAL_GPIO_WritePin(MAIN_MUX_SELC_3_GPIO_Port,MAIN_MUX_SELC_3_Pin,GPIO_PIN_RESET);//0
		          HAL_GPIO_WritePin(MAIN_MUX_SELC_4_GPIO_Port,MAIN_MUX_SELC_4_Pin,GPIO_PIN_SET);//1
		          HAL_Delay(200);
		          break;
		case 21:
							HAL_GPIO_WritePin(MAIN_MUX_SELC_0_GPIO_Port,MAIN_MUX_SELC_0_Pin,GPIO_PIN_RESET);//0
							HAL_GPIO_WritePin(MAIN_MUX_SELC_1_GPIO_Port,MAIN_MUX_SELC_1_Pin,GPIO_PIN_RESET);//0
							HAL_GPIO_WritePin(MAIN_MUX_SELC_2_GPIO_Port,MAIN_MUX_SELC_2_Pin,GPIO_PIN_SET);//1 
							HAL_GPIO_WritePin(MAIN_MUX_SELC_3_GPIO_Port,MAIN_MUX_SELC_3_Pin,GPIO_PIN_RESET);//0
		          HAL_GPIO_WritePin(MAIN_MUX_SELC_4_GPIO_Port,MAIN_MUX_SELC_4_Pin,GPIO_PIN_SET);//1
		          HAL_Delay(200); 
			break;
		case 22:
							HAL_GPIO_WritePin(MAIN_MUX_SELC_0_GPIO_Port,MAIN_MUX_SELC_0_Pin,GPIO_PIN_SET);//1
							HAL_GPIO_WritePin(MAIN_MUX_SELC_1_GPIO_Port,MAIN_MUX_SELC_1_Pin,GPIO_PIN_RESET);//0
							HAL_GPIO_WritePin(MAIN_MUX_SELC_2_GPIO_Port,MAIN_MUX_SELC_2_Pin,GPIO_PIN_SET);//1 
							HAL_GPIO_WritePin(MAIN_MUX_SELC_3_GPIO_Port,MAIN_MUX_SELC_3_Pin,GPIO_PIN_RESET);//0
		          HAL_GPIO_WritePin(MAIN_MUX_SELC_4_GPIO_Port,MAIN_MUX_SELC_4_Pin,GPIO_PIN_SET);//1
		          HAL_Delay(200);
			break;
		case 23:
							HAL_GPIO_WritePin(MAIN_MUX_SELC_0_GPIO_Port,MAIN_MUX_SELC_0_Pin,GPIO_PIN_RESET);//0
							HAL_GPIO_WritePin(MAIN_MUX_SELC_1_GPIO_Port,MAIN_MUX_SELC_1_Pin,GPIO_PIN_SET);//1
							HAL_GPIO_WritePin(MAIN_MUX_SELC_2_GPIO_Port,MAIN_MUX_SELC_2_Pin,GPIO_PIN_SET);//1 
							HAL_GPIO_WritePin(MAIN_MUX_SELC_3_GPIO_Port,MAIN_MUX_SELC_3_Pin,GPIO_PIN_RESET);//0
		          HAL_GPIO_WritePin(MAIN_MUX_SELC_4_GPIO_Port,MAIN_MUX_SELC_4_Pin,GPIO_PIN_SET);//1
		          HAL_Delay(200);
			break;
	case 24:   //-------1 
							HAL_GPIO_WritePin(MAIN_MUX_SELC_0_GPIO_Port,MAIN_MUX_SELC_0_Pin,GPIO_PIN_SET);//1
							HAL_GPIO_WritePin(MAIN_MUX_SELC_1_GPIO_Port,MAIN_MUX_SELC_1_Pin,GPIO_PIN_SET);//1
							HAL_GPIO_WritePin(MAIN_MUX_SELC_2_GPIO_Port,MAIN_MUX_SELC_2_Pin,GPIO_PIN_SET);//1 
							HAL_GPIO_WritePin(MAIN_MUX_SELC_3_GPIO_Port,MAIN_MUX_SELC_3_Pin,GPIO_PIN_RESET);//0
		          HAL_GPIO_WritePin(MAIN_MUX_SELC_4_GPIO_Port,MAIN_MUX_SELC_4_Pin,GPIO_PIN_SET);//1
	            HAL_Delay(200);
			break;
		case 25:
							HAL_GPIO_WritePin(MAIN_MUX_SELC_0_GPIO_Port,MAIN_MUX_SELC_0_Pin,GPIO_PIN_RESET);//0
							HAL_GPIO_WritePin(MAIN_MUX_SELC_1_GPIO_Port,MAIN_MUX_SELC_1_Pin,GPIO_PIN_RESET);//0
							HAL_GPIO_WritePin(MAIN_MUX_SELC_2_GPIO_Port,MAIN_MUX_SELC_2_Pin,GPIO_PIN_RESET);//0 
							HAL_GPIO_WritePin(MAIN_MUX_SELC_3_GPIO_Port,MAIN_MUX_SELC_3_Pin,GPIO_PIN_SET);//1
		          HAL_GPIO_WritePin(MAIN_MUX_SELC_4_GPIO_Port,MAIN_MUX_SELC_4_Pin,GPIO_PIN_SET);//1
		          HAL_Delay(200);
			break;
		case 26:
							HAL_GPIO_WritePin(MAIN_MUX_SELC_0_GPIO_Port,MAIN_MUX_SELC_0_Pin,GPIO_PIN_SET);//1
							HAL_GPIO_WritePin(MAIN_MUX_SELC_1_GPIO_Port,MAIN_MUX_SELC_1_Pin,GPIO_PIN_RESET);//0
							HAL_GPIO_WritePin(MAIN_MUX_SELC_2_GPIO_Port,MAIN_MUX_SELC_2_Pin,GPIO_PIN_RESET);//0 
							HAL_GPIO_WritePin(MAIN_MUX_SELC_3_GPIO_Port,MAIN_MUX_SELC_3_Pin,GPIO_PIN_SET);//1
		          HAL_GPIO_WritePin(MAIN_MUX_SELC_4_GPIO_Port,MAIN_MUX_SELC_4_Pin,GPIO_PIN_SET);//1
		          HAL_Delay(200);
			break;
		case 27:
							HAL_GPIO_WritePin(MAIN_MUX_SELC_0_GPIO_Port,MAIN_MUX_SELC_0_Pin,GPIO_PIN_RESET);//0
							HAL_GPIO_WritePin(MAIN_MUX_SELC_1_GPIO_Port,MAIN_MUX_SELC_1_Pin,GPIO_PIN_SET);//1
							HAL_GPIO_WritePin(MAIN_MUX_SELC_2_GPIO_Port,MAIN_MUX_SELC_2_Pin,GPIO_PIN_RESET);//0 
							HAL_GPIO_WritePin(MAIN_MUX_SELC_3_GPIO_Port,MAIN_MUX_SELC_3_Pin,GPIO_PIN_SET);//1
		          HAL_GPIO_WritePin(MAIN_MUX_SELC_4_GPIO_Port,MAIN_MUX_SELC_4_Pin,GPIO_PIN_SET);//1
		          HAL_Delay(200);
			break;
		case 28:	
		          HAL_GPIO_WritePin(MAIN_MUX_SELC_0_GPIO_Port,MAIN_MUX_SELC_0_Pin,GPIO_PIN_SET);//1
							HAL_GPIO_WritePin(MAIN_MUX_SELC_1_GPIO_Port,MAIN_MUX_SELC_1_Pin,GPIO_PIN_SET);//1
							HAL_GPIO_WritePin(MAIN_MUX_SELC_2_GPIO_Port,MAIN_MUX_SELC_2_Pin,GPIO_PIN_RESET);//0 
							HAL_GPIO_WritePin(MAIN_MUX_SELC_3_GPIO_Port,MAIN_MUX_SELC_3_Pin,GPIO_PIN_SET);//1
		          HAL_GPIO_WritePin(MAIN_MUX_SELC_4_GPIO_Port,MAIN_MUX_SELC_4_Pin,GPIO_PIN_SET);//1
		          HAL_Delay(200);
			break;
		case 29:
							HAL_GPIO_WritePin(MAIN_MUX_SELC_0_GPIO_Port,MAIN_MUX_SELC_0_Pin,GPIO_PIN_RESET);//0
							HAL_GPIO_WritePin(MAIN_MUX_SELC_1_GPIO_Port,MAIN_MUX_SELC_1_Pin,GPIO_PIN_RESET);//0
							HAL_GPIO_WritePin(MAIN_MUX_SELC_2_GPIO_Port,MAIN_MUX_SELC_2_Pin,GPIO_PIN_SET);//1 
							HAL_GPIO_WritePin(MAIN_MUX_SELC_3_GPIO_Port,MAIN_MUX_SELC_3_Pin,GPIO_PIN_SET);//1
		          HAL_GPIO_WritePin(MAIN_MUX_SELC_4_GPIO_Port,MAIN_MUX_SELC_4_Pin,GPIO_PIN_SET);//1
		          HAL_Delay(200);
			break;
		case 30:
							HAL_GPIO_WritePin(MAIN_MUX_SELC_0_GPIO_Port,MAIN_MUX_SELC_0_Pin,GPIO_PIN_SET);//1
							HAL_GPIO_WritePin(MAIN_MUX_SELC_1_GPIO_Port,MAIN_MUX_SELC_1_Pin,GPIO_PIN_RESET);//0
							HAL_GPIO_WritePin(MAIN_MUX_SELC_2_GPIO_Port,MAIN_MUX_SELC_2_Pin,GPIO_PIN_SET);//1 
							HAL_GPIO_WritePin(MAIN_MUX_SELC_3_GPIO_Port,MAIN_MUX_SELC_3_Pin,GPIO_PIN_SET);//1
		          HAL_GPIO_WritePin(MAIN_MUX_SELC_4_GPIO_Port,MAIN_MUX_SELC_4_Pin,GPIO_PIN_SET);//1
		          HAL_Delay(200);
			break;
		case 31:
							HAL_GPIO_WritePin(MAIN_MUX_SELC_0_GPIO_Port,MAIN_MUX_SELC_0_Pin,GPIO_PIN_RESET);//0
							HAL_GPIO_WritePin(MAIN_MUX_SELC_1_GPIO_Port,MAIN_MUX_SELC_1_Pin,GPIO_PIN_SET);//1
							HAL_GPIO_WritePin(MAIN_MUX_SELC_2_GPIO_Port,MAIN_MUX_SELC_2_Pin,GPIO_PIN_SET);//1 
							HAL_GPIO_WritePin(MAIN_MUX_SELC_3_GPIO_Port,MAIN_MUX_SELC_3_Pin,GPIO_PIN_SET);//1
		          HAL_GPIO_WritePin(MAIN_MUX_SELC_4_GPIO_Port,MAIN_MUX_SELC_4_Pin,GPIO_PIN_SET);//1
		          HAL_Delay(200);
		   break;
		case 32:
							HAL_GPIO_WritePin(MAIN_MUX_SELC_0_GPIO_Port,MAIN_MUX_SELC_0_Pin,GPIO_PIN_SET);//1
							HAL_GPIO_WritePin(MAIN_MUX_SELC_1_GPIO_Port,MAIN_MUX_SELC_1_Pin,GPIO_PIN_SET);//1
							HAL_GPIO_WritePin(MAIN_MUX_SELC_2_GPIO_Port,MAIN_MUX_SELC_2_Pin,GPIO_PIN_SET);//1 
							HAL_GPIO_WritePin(MAIN_MUX_SELC_3_GPIO_Port,MAIN_MUX_SELC_3_Pin,GPIO_PIN_SET);//1
		          HAL_GPIO_WritePin(MAIN_MUX_SELC_4_GPIO_Port,MAIN_MUX_SELC_4_Pin,GPIO_PIN_SET);//1
		          HAL_Delay(200);
			break;
		
		default:
						 
			break;
	}
	            //sprintf((char *)response,"mux channel[%d]\n\r",channel);     //for debug purpose
						 // transimit_str_to(1,response,strlen((char *)response));
}
 /************************ *****END OF FILE****/
  /** @fun    03
  * @brief  GPIO status channel are to be selected by this funtion
  * @param  channel Number 
  * @retval None
  */
void gpio_mux_16_1_sel(uint8_t channel)
{switch(channel)
	{
		case 1:   
		//	HAL_Delay(100);
							HAL_GPIO_WritePin(MAIN_MUX_SELC_0_GPIO_Port,MAIN_MUX_SELC_1_Pin,GPIO_PIN_RESET);//0
							HAL_GPIO_WritePin(MAIN_MUX_SELC_0_GPIO_Port,MAIN_MUX_SELC_1_Pin,GPIO_PIN_RESET);//0
							HAL_GPIO_WritePin(MAIN_MUX_SELC_0_GPIO_Port,MAIN_MUX_SELC_1_Pin,GPIO_PIN_RESET);//0 
							HAL_GPIO_WritePin(MAIN_MUX_SELC_0_GPIO_Port,MAIN_MUX_SELC_1_Pin,GPIO_PIN_RESET);//0	          
		         // HAL_Delay(500);
			break;
		case 2:
							HAL_GPIO_WritePin(MAIN_MUX_SELC_0_GPIO_Port,MAIN_MUX_SELC_1_Pin,GPIO_PIN_SET);   //1
							HAL_GPIO_WritePin(MAIN_MUX_SELC_0_GPIO_Port,MAIN_MUX_SELC_1_Pin,GPIO_PIN_RESET);  //0
							HAL_GPIO_WritePin(MAIN_MUX_SELC_0_GPIO_Port,MAIN_MUX_SELC_1_Pin,GPIO_PIN_RESET);  //0 
							HAL_GPIO_WritePin(MAIN_MUX_SELC_0_GPIO_Port,MAIN_MUX_SELC_1_Pin,GPIO_PIN_RESET);  //0		          
		          // HAL_Delay(500);
			break;
		case 3:
							HAL_GPIO_WritePin(MAIN_MUX_SELC_0_GPIO_Port,MAIN_MUX_SELC_0_Pin,GPIO_PIN_RESET);//0
							HAL_GPIO_WritePin(MAIN_MUX_SELC_1_GPIO_Port,MAIN_MUX_SELC_1_Pin,GPIO_PIN_SET);//1
							HAL_GPIO_WritePin(MAIN_MUX_SELC_2_GPIO_Port,MAIN_MUX_SELC_2_Pin,GPIO_PIN_RESET);//0 
							HAL_GPIO_WritePin(MAIN_MUX_SELC_3_GPIO_Port,MAIN_MUX_SELC_3_Pin,GPIO_PIN_RESET);//0		          
		          // HAL_Delay(500);
			break;
		case 4:
							HAL_GPIO_WritePin(MAIN_MUX_SELC_0_GPIO_Port,MAIN_MUX_SELC_0_Pin,GPIO_PIN_SET);//1
							HAL_GPIO_WritePin(MAIN_MUX_SELC_1_GPIO_Port,MAIN_MUX_SELC_1_Pin,GPIO_PIN_SET);//1
							HAL_GPIO_WritePin(MAIN_MUX_SELC_2_GPIO_Port,MAIN_MUX_SELC_2_Pin,GPIO_PIN_RESET);//0 
							HAL_GPIO_WritePin(MAIN_MUX_SELC_3_GPIO_Port,MAIN_MUX_SELC_3_Pin,GPIO_PIN_RESET);//0		          
		          // HAL_Delay(500);
			break;
		case 5:	
		          HAL_GPIO_WritePin(MAIN_MUX_SELC_0_GPIO_Port,MAIN_MUX_SELC_0_Pin,GPIO_PIN_RESET);//0
							HAL_GPIO_WritePin(MAIN_MUX_SELC_1_GPIO_Port,MAIN_MUX_SELC_1_Pin,GPIO_PIN_RESET);//0
							HAL_GPIO_WritePin(MAIN_MUX_SELC_2_GPIO_Port,MAIN_MUX_SELC_2_Pin,GPIO_PIN_SET);//1 
							HAL_GPIO_WritePin(MAIN_MUX_SELC_3_GPIO_Port,MAIN_MUX_SELC_3_Pin,GPIO_PIN_RESET);//0		         
		          // HAL_Delay(500);
			break;
		case 6:
							HAL_GPIO_WritePin(MAIN_MUX_SELC_0_GPIO_Port,MAIN_MUX_SELC_0_Pin,GPIO_PIN_SET);//1
							HAL_GPIO_WritePin(MAIN_MUX_SELC_1_GPIO_Port,MAIN_MUX_SELC_1_Pin,GPIO_PIN_RESET);//0
							HAL_GPIO_WritePin(MAIN_MUX_SELC_2_GPIO_Port,MAIN_MUX_SELC_2_Pin,GPIO_PIN_SET);//1 
							HAL_GPIO_WritePin(MAIN_MUX_SELC_3_GPIO_Port,MAIN_MUX_SELC_3_Pin,GPIO_PIN_RESET);//0	          
		          // HAL_Delay(500);
			break;
		case 7:
							HAL_GPIO_WritePin(MAIN_MUX_SELC_0_GPIO_Port,MAIN_MUX_SELC_0_Pin,GPIO_PIN_RESET);//0
							HAL_GPIO_WritePin(MAIN_MUX_SELC_1_GPIO_Port,MAIN_MUX_SELC_1_Pin,GPIO_PIN_SET);//1
							HAL_GPIO_WritePin(MAIN_MUX_SELC_2_GPIO_Port,MAIN_MUX_SELC_2_Pin,GPIO_PIN_SET);//1 
							HAL_GPIO_WritePin(MAIN_MUX_SELC_3_GPIO_Port,MAIN_MUX_SELC_3_Pin,GPIO_PIN_RESET);//0	         
		          // HAL_Delay(500);
			break;
		case 8:
							HAL_GPIO_WritePin(MAIN_MUX_SELC_0_GPIO_Port,MAIN_MUX_SELC_0_Pin,GPIO_PIN_SET);//1
							HAL_GPIO_WritePin(MAIN_MUX_SELC_1_GPIO_Port,MAIN_MUX_SELC_1_Pin,GPIO_PIN_SET);//1
							HAL_GPIO_WritePin(MAIN_MUX_SELC_2_GPIO_Port,MAIN_MUX_SELC_2_Pin,GPIO_PIN_SET);//1 
							HAL_GPIO_WritePin(MAIN_MUX_SELC_3_GPIO_Port,MAIN_MUX_SELC_3_Pin,GPIO_PIN_RESET);//0	          
		          // HAL_Delay(500);
			break;
		case 9:
							HAL_GPIO_WritePin(MAIN_MUX_SELC_0_GPIO_Port,MAIN_MUX_SELC_0_Pin,GPIO_PIN_RESET);//0
							HAL_GPIO_WritePin(MAIN_MUX_SELC_1_GPIO_Port,MAIN_MUX_SELC_1_Pin,GPIO_PIN_RESET);//0
							HAL_GPIO_WritePin(MAIN_MUX_SELC_2_GPIO_Port,MAIN_MUX_SELC_2_Pin,GPIO_PIN_RESET);//0 
							HAL_GPIO_WritePin(MAIN_MUX_SELC_3_GPIO_Port,MAIN_MUX_SELC_3_Pin,GPIO_PIN_SET);//1		          
		          // HAL_Delay(500);
			break;
		case 10:
							HAL_GPIO_WritePin(MAIN_MUX_SELC_0_GPIO_Port,MAIN_MUX_SELC_0_Pin,GPIO_PIN_SET);//1
							HAL_GPIO_WritePin(MAIN_MUX_SELC_1_GPIO_Port,MAIN_MUX_SELC_1_Pin,GPIO_PIN_RESET);//0
							HAL_GPIO_WritePin(MAIN_MUX_SELC_2_GPIO_Port,MAIN_MUX_SELC_2_Pin,GPIO_PIN_RESET);//0 
							HAL_GPIO_WritePin(MAIN_MUX_SELC_3_GPIO_Port,MAIN_MUX_SELC_3_Pin,GPIO_PIN_SET);//1		          
		          // HAL_Delay(500);
			break;
	case 11:   //-------1 
							HAL_GPIO_WritePin(MAIN_MUX_SELC_0_GPIO_Port,MAIN_MUX_SELC_0_Pin,GPIO_PIN_RESET);//0
							HAL_GPIO_WritePin(MAIN_MUX_SELC_1_GPIO_Port,MAIN_MUX_SELC_1_Pin,GPIO_PIN_SET);//1
							HAL_GPIO_WritePin(MAIN_MUX_SELC_2_GPIO_Port,MAIN_MUX_SELC_2_Pin,GPIO_PIN_RESET);//0 
							HAL_GPIO_WritePin(MAIN_MUX_SELC_3_GPIO_Port,MAIN_MUX_SELC_3_Pin,GPIO_PIN_SET);//1		         
	            // HAL_Delay(500);
			break;
		case 12:
							HAL_GPIO_WritePin(MAIN_MUX_SELC_0_GPIO_Port,MAIN_MUX_SELC_0_Pin,GPIO_PIN_SET);//1
							HAL_GPIO_WritePin(MAIN_MUX_SELC_1_GPIO_Port,MAIN_MUX_SELC_1_Pin,GPIO_PIN_SET);//1
							HAL_GPIO_WritePin(MAIN_MUX_SELC_2_GPIO_Port,MAIN_MUX_SELC_2_Pin,GPIO_PIN_RESET);//0 
							HAL_GPIO_WritePin(MAIN_MUX_SELC_3_GPIO_Port,MAIN_MUX_SELC_3_Pin,GPIO_PIN_SET);//1		         
		          // HAL_Delay(500);
			break;
		case 13:
							HAL_GPIO_WritePin(MAIN_MUX_SELC_0_GPIO_Port,MAIN_MUX_SELC_0_Pin,GPIO_PIN_RESET);//0
							HAL_GPIO_WritePin(MAIN_MUX_SELC_1_GPIO_Port,MAIN_MUX_SELC_1_Pin,GPIO_PIN_RESET);//0
							HAL_GPIO_WritePin(MAIN_MUX_SELC_2_GPIO_Port,MAIN_MUX_SELC_2_Pin,GPIO_PIN_SET);//1 
							HAL_GPIO_WritePin(MAIN_MUX_SELC_3_GPIO_Port,MAIN_MUX_SELC_3_Pin,GPIO_PIN_SET);//1		          
		          // HAL_Delay(500);
			break;
		case 14:
							HAL_GPIO_WritePin(MAIN_MUX_SELC_0_GPIO_Port,MAIN_MUX_SELC_0_Pin,GPIO_PIN_SET);//1
							HAL_GPIO_WritePin(MAIN_MUX_SELC_1_GPIO_Port,MAIN_MUX_SELC_1_Pin,GPIO_PIN_RESET);//0
							HAL_GPIO_WritePin(MAIN_MUX_SELC_2_GPIO_Port,MAIN_MUX_SELC_2_Pin,GPIO_PIN_SET);//1 
							HAL_GPIO_WritePin(MAIN_MUX_SELC_3_GPIO_Port,MAIN_MUX_SELC_3_Pin,GPIO_PIN_SET);//1
		          // HAL_Delay(500);
			break;
		case 15:	
		          HAL_GPIO_WritePin(MAIN_MUX_SELC_0_GPIO_Port,MAIN_MUX_SELC_0_Pin,GPIO_PIN_RESET);//0
							HAL_GPIO_WritePin(MAIN_MUX_SELC_1_GPIO_Port,MAIN_MUX_SELC_1_Pin,GPIO_PIN_SET);//1
							HAL_GPIO_WritePin(MAIN_MUX_SELC_2_GPIO_Port,MAIN_MUX_SELC_2_Pin,GPIO_PIN_SET);//1 
							HAL_GPIO_WritePin(MAIN_MUX_SELC_3_GPIO_Port,MAIN_MUX_SELC_3_Pin,GPIO_PIN_SET);//1		          
		          // HAL_Delay(500);
			break;
		case 16:
							HAL_GPIO_WritePin(MAIN_MUX_SELC_0_GPIO_Port,MAIN_MUX_SELC_0_Pin,GPIO_PIN_SET);//1
							HAL_GPIO_WritePin(MAIN_MUX_SELC_1_GPIO_Port,MAIN_MUX_SELC_1_Pin,GPIO_PIN_SET);//1
							HAL_GPIO_WritePin(MAIN_MUX_SELC_2_GPIO_Port,MAIN_MUX_SELC_2_Pin,GPIO_PIN_SET);//1 
							HAL_GPIO_WritePin(MAIN_MUX_SELC_3_GPIO_Port,MAIN_MUX_SELC_3_Pin,GPIO_PIN_SET);//1		          
		          // HAL_Delay(500);
			break;
	   default:			 
			break;
	
	}
	}
