/**
  ******************************************************************************
  * @file           : cmd_h.c
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
#include "tim.h"
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
extern uint8_t status_flag;
extern uint32_t Duty_Cycle;
uint32_t AdcVal=0x00;
float volt=0; 
const char *test_name[32] =       {"VREG_S2B(TN100)","VREG_S3B_S4B_0P752(TN101)","VREG_S5B_0P6(TN102)","VREG_S1A_0P752(TN118)","VREG_S1B_0P752(TN120)","VREG_L13A_1P8(TN124)",\
															   "VREG_L9B_0P8(TN127)","VREG_S2A_S3A(TP134)","VREG_S5A_0P752(TP139)","VREG_L3A_1P0(TP144)","VREG_L5A_0P8(TP149)","VREG_L17A_1P8(TP152)","VREG_L2B_1P8(TP157)","VREG_DBU1_1P225(TP160)","VCC_3P3_STANDBY(TP161)","VREG_S6A_1P35(TN164)","VREG_L11A_1P8(TN167)","VBATT_3P7(TN175)","VREG_L1B_0P88(TP169)","VREG_S4A_2P04(TP170)","VREG_L10A_1P8(TP172)","VREG_L15A_1P8(TP173)",\
                                 "VREG_L1A_1P2(TP181)","VREG_BOB_3P3(TP207)","VPH_PWR_3P7(TP213)","VREG_L8A_1P8(TP45)","VREG_L4B_2P95(TP52)","VREG_L7A_1P2(TP92)","VREG_L19A_3P3(TP56)","VREG_L7B_3P125(TP57)","VREG_L2A_1P0(TP74)",\
                                 "VREG_L6A_1P3(TP75)"};

const char *gpio_status_16_1[11] =       {"VREG_L5B_2P95(TN78)","VREG_L12A_1P8(TN87)","VCC_6P0_V(TN92)","VCC_6P0_IMP(TN88)","VCC_6P0_FAN_V(TN218)","VCC_6P0_FAN_IMP(TN218)","VREG_VMSMT(TN70)","WLAN_SW_CTRL(TN109)","USB_VBUS_IMP","VREG_DBU2_S3A_1P225","VREG_L13A_1P8_R"};
const char *test_name_mux_3[1] =         {"USB_VBUS(TN61)"};
const char *camera_status[9] =          {"VBATT_3P7(TN175)","Disable_3V7(TN122)","LTC_PFO_N(TN94)","CAM0_PWR(TN163)","CAM0_RST_N(TN196)","CAM0_PWRD(TN197)","QCS_FLASH_SPI_CS(TN194)","CAM2_AVDD_2P8_EN(TN37)","CDC_MIC_BIAS1(TN46)"};


  /** @fun    01
  * @brief  Impedance test through the diffrent input signal
  * @param  structure type pointer 
  * @retval None
  */
void	imp_read_all(void)
{
	imp_setup_all(MUX_1); // here all the condition are execute one by one according to impedance setup for MUX_1
  uint8_t i,j=0;
	float vcc=3.3;
	float oldVolt=0.805;
	float newVolt=0; 
	float impLow=0;
	float impUp=10;
	float volt_diff=0;
  sprintf((char *)response,"\n\r");     //ob->imp_val
  transimit_str_to(1,response,strlen((char *)response));
  HAL_Delay(100);
  sprintf((char *)response,"N_I@");     //ob->imp_val
  transimit_str_to(1,response,strlen((char *)response));
  for(i=1;i<=32;i++)
{ 
  //respected mux enable	
	set_mux_ch(i);
	AdcVal=Get_ADC1_value(IMP_ADC_CH);
	newVolt=(float)AdcVal*vcc;
	newVolt/=4096;	
  if(i == 6 || i == 15 || i == 22 || i == 15) continue;		
	volt_diff=oldVolt-newVolt;
	if(volt_diff>0)
  impLow=newVolt*impUp/volt_diff;
	else
  impLow=IMP_LOW_SHORT;
  sprintf((char *)response," %.2f,",impLow);
  transimit_str_to(1,response,strlen((char *)response));
	if(my_flag==DEBUG)
	{								
	sprintf((char *)response,"%s-|AdcVal-%d |newVolt-%f |volt_diff-%f|impLow-%.2f KOHM\n\r",test_name[i-1],AdcVal,newVolt,volt_diff,impLow);     //ob->imp_val
	transimit_str_to(1,response,strlen((char *)response));
	}
	impLow=0;
	}
  imp_setup_all(MUX_2); // here all the condition are execute one by one according to impedance setup for MUX_2 
   for(j=1;j<=11;j++)
  { 
		if(i == 3 || i == 5 || i == 7 || i == 8) continue;
	gpio_mux_16_1_sel(j); // Here we have seprate funtion for selecting the mux channel for MUX_2
	AdcVal=Get_ADC1_value(IMP_ADC_CH);
	newVolt=(float)AdcVal*vcc;
	newVolt/=4096;			      
	volt_diff=oldVolt-newVolt;
	if(volt_diff>0)
  impLow=newVolt*impUp/volt_diff;
	else
  impLow=IMP_LOW_SHORT;    // imp type short type.
  sprintf((char *)response," %.2f,",impLow);
  transimit_str_to(1,response,strlen((char *)response));
	if(my_flag==DEBUG)
	{								
	sprintf((char *)response,"%s-|AdcVal-%d |newVolt-%f |volt_diff-%f|impLow-%.2f KOHM\n\r",gpio_status_16_1[j-1],AdcVal,newVolt,volt_diff,impLow);     //ob->imp_val
	transimit_str_to(1,response,strlen((char *)response));
	}
	impLow=0;
		
	}
	sprintf((char *)response,"IMP READ DONE");     //ob->imp_val
  transimit_str_to(1,response,strlen((char *)response));
}
/** @fun    2.0
  * @brief  PRE voltage test through the diffrent input signal before the flash the board for MUX_1
  * @param  None 
  * @retval None
  */
void vol_read_all(void)
{     
volt_setup_all_32_1(MUX_1);           // voltage setup condition for for mux-1
uint8_t j=0;
printmsg ("N_V@");
for(j=1;j<=32;j++)                    // Here total 17 channel will be test by adc through the MUX_1
 {
if(j==3 ||j==15 ||j==22) // this skip channel(8,15,18,22,25,28,31)not to be consider for pre voltage
{continue;}	 
 set_mux_ch(j);                      // Here Mux channel are select by this funtion from 1 to 17
 AdcVal=Get_ADC1_value(VOL_ADC_CH);  // To read the adc value from relevant channel of ADC module
volt=(float)AdcVal*3.3f;
volt/=4096;
volt*=2;	
sprintf((char *)response," %.2f,",volt);transimit_str_to(1,response,strlen((char *)response));             // to continue send out the value for the voltag.  
if(my_flag==DEBUG){sprintf((char *)response,"Channel[%d][MUX_1]-%s-|AdcVal-%d|%.2fvolt\n\r",j,test_name[j-1],AdcVal,volt); transimit_str_to(1,response,strlen((char *)response));}
volt=0;
 }
 mux_2_pre_vol_test();             // funtion for test the pre voltage signal connected to mux2
 mux_3_pre_vol_test();             // funtion for test the pre voltage signal connected to mux3
 mux_4_pre_vol_test();             // funtion for test the pre voltage signal connected to mux4
printmsg ("VOL READ DONE\r\n"); 
}
/** @fun    2.1
  * @brief  PRE voltage test through the diffrent input signal before the flash the board for MUX_2
  * @param  None 
  * @retval None
  */
void mux_2_pre_vol_test(void)
{
volt_setup_all_32_1(MUX_2);           //  condition for the voltage setup for 32 MUX_2
uint8_t j=0;
for(j=1;j<=16;j++)                    // Here total 4 channel will be test by adc through the MUX_1
 {
if(j==1 ||j==3||j==4||j==5) // this wiill we skiped channel from the mux_2
{continue;}	 
gpio_mux_16_1_sel(j);                      // Here Mux_16:1 channel are select by this funtion from 1 to 12 some channel are skip
AdcVal=Get_ADC1_value(VOL_ADC_CH);  // To read the adc value from relevant channel of ADC module
volt=(float)AdcVal*3.3f;
volt/=4096;
//volt*=2;	
//printmsg("%.2f,",volt);
sprintf((char *)response,"%.2f,",volt);transimit_str_to(1,response,strlen((char *)response)); transimit_str_to(1,response,strlen((char *)response)); }  
if(my_flag==DEBUG){sprintf((char *)response,"Channel[%d][MUX_2]-%s-|AdcVal-%d|%.2fvolt\n\r",j,test_name[j-1],AdcVal,volt);
//printmsg("s[%d]-%s-|AdcVal-%d|%.2fvolt\n\r",j,test_name[j-1],AdcVal,volt);
volt=0;
AdcVal=0x00;
 }
}
/** @fun    2.2
  * @brief  PRE voltage test through the diffrent input signal before the flash the board for MUX_3
  * @param  None 
  * @retval None
  */
void mux_3_pre_vol_test(void)
{
uint8_t j=0;
volt_setup_all_32_1(MUX_3); 	 
gpio_mux_16_1_sel(CH_5);                      // Here Mux_16:1 channel are select by this funtion for read only one channel that is cha_5 of mUX-3
AdcVal=Get_ADC1_value(VOL_ADC_CH);            // To read the adc value from relevant channel of ADC module
volt=(float)AdcVal*3.3f;
volt/=4096;
//volt*=2;	                       
sprintf((char *)response," %.2f,",volt); transimit_str_to(1,response,strlen((char *)response));        // Here raw data will be send to the PC application through the uart5
if(my_flag==DEBUG){sprintf((char *)response,"Channel[%d][MUX_3]-%s-|AdcVal-%d|%.2fvolt\n\r",j,test_name_mux_3[1-1],AdcVal,volt); transimit_str_to(1,response,strlen((char *)response)); }
volt=0;
AdcVal=0x00; 
}
/** @fun    2.2
  * @brief  PRE voltage test through the diffrent input signal before the flash the board for MUX_3
  * @param  None 
  * @retval None
  */
void mux_4_pre_vol_test(void)
{
volt_setup_all_32_1(MUX_4); 	 
gpio_mux_16_1_sel(CH_3);                      // Here Mux_16:1 channel are select by this funtion for read only one channel
AdcVal=Get_ADC1_value(VOL_ADC_CH);            // To read the adc value from relevant channel of ADC module
volt=(float)AdcVal*3.3f;
volt/=4096;
//volt*=2;	                      
sprintf((char *)response," %.2f,",volt); transimit_str_to(1,response,strlen((char *)response)); // Here raw data will be send to the PC application through the uart5
if(my_flag==DEBUG){sprintf((char *)response,"[TP34]SDM_PS_HOLD[channel_3-MUX_4]-|AdcVal-%d|%.2fvolt\n\r",AdcVal,volt); transimit_str_to(1,response,strlen((char *)response));}// for DEBUG Purpose
volt=0;
AdcVal=0x00; 
}
/** @fun    2.1
  * @brief  voltage test through the diffrent input signal as well as difrrent MUX After the flash the board
           (this funtion will be tested when we want to test all the post voltage )
  * @param  None 
  * @retval None
  */
void flash_vol_read_all(void)
{ 
	post_vol_read_mux_1();                                          //read post vol from MUX_1 for total 5 channel
	post_vol_read_mux_rest(MUX_2,CH_2,"VREG_L12A_1P8(TP87)MUX_2"); //read post vol from MUX_2 CH_2
	post_vol_read_mux_rest(MUX_3,CH_3,"CAM0_PWRTP(TP163)MUX_3");   //read post vol from MUX_3 CH_3
	post_vol_read_mux_rest(MUX_4,CH_4,"EEPROM_WP(TP166)MUX_4");    //read post vol from MUX_4 CH_4
	printmsg ("VOL READ DONE\r\n");                                // this is the signature of end of funtion
}
/** @fun    2.2
  * @brief  funtion defination voltage test from mux_1 for difrrent signal after falsh the board
  * @param  None 
  * @retval None
  */
void post_vol_read_mux_1(void)
{
uint8_t j=0;
uint32_t AdcVal=0x00;
float volt=0; 
printmsg ("N_A@\r\n");
for(j=1;j<=32;j++)          // only 4 channel we have to test on to MUX1 for post voltage and the channel are CH1,CH8,CH22,CH31
 { 	
if(j==2||j==3||j==4||j==5||j==6||j==7||j==9||j==10||j==11||j==12||j==13||j==14||j==15||j==16||j==17||j==18||j==19||j==20||j==21||j==23||\
	j==24||j==25||j==26||j==27||j==29||j==30||j==32)
{continue;}	
 set_mux_ch(j) ;                      // Here Mux channel are select by this funtion from 1 to 16
 AdcVal=Get_ADC1_value(VOL_ADC_CH);  // To read the adc value from relevant channel of ADC module
 volt=(float)AdcVal*3.3f;
 volt/=4096;
	//volt*=2;	
   //printmsg("%.2f,",volt);
sprintf((char *)response," %.2f,",volt); transimit_str_to(1,response,strlen((char *)response)); // Here raw data will be send to the PC application through the uart5
	if(my_flag==DEBUG){sprintf((char *)response,"s[%d]-%s-|AdcVal-%d|%.2fvolt\n\r",j,test_name[j-1],AdcVal,volt); transimit_str_to(1,response,strlen((char *)response)); }
	volt=0;
}
}
/** @fun    2.2
  * @brief  voltage test from the diffrent mux for difrrent signal after falsh the board
  * @param1  type of mux
  * @param2  channel number
  * @param2  Constant string  
  * @retval None
  */
void post_vol_read_mux_rest(uint8_t mux_num,uint8_t channel,const char *str)
{ 
	uint32_t AdcVal=0x00;
	float volt=0;
	volt_setup_all_32_1(mux_num);   			 
	gpio_mux_16_1_sel(channel);                      // Here Mux channel are select by this funtion from 1 to 8
	AdcVal=Get_ADC1_value(VOL_ADC_CH);  // To read the adc value from relevant channel of ADC module
	volt=(float)AdcVal*3.3f;
	volt/=4096;
	printmsg("%.2f,",volt);
	if(my_flag==DEBUG)printmsg("s[%d]-%s-|AdcVal-%d|%.2fvolt\n\r",channel,str,AdcVal,volt);	
	volt=0;
}	

/** @fun    
  * @brief  PWM Duty cycle Measurment for diffrent channel of the DUT End
  * @param  PWM number 
  * @retval channel number of mux 
  */
void pwm_duty_cycle_measurment(uint8_t pwm, uint8_t channel)
{
mux_switch_EN_DI(MUX_3); //enable the mux_3 at which the pwm signal are connected
TIMER_ENABLE;            //enable the timer mode to switch from adc to timer signal read of respected mux_3
switch(pwm)	
{
case 1:
gpio_mux_16_1_sel(channel);
TIMER4_START;
 if(status_flag)
 {
 status_flag=FALSE;
if(my_flag==DEBUG)printmsg("TP105-FAN_PWM[S8]_MUX_3\r\n");
 printmsg("pwm duty cycle-%d%\r\n",Duty_Cycle);
 }
 else
 printmsg("Pwm duty cycle did not measured\r\n");
break;
 case 2:
gpio_mux_16_1_sel(channel);
TIMER4_START;
 if(status_flag)
 {
 status_flag=FALSE;
	 if(my_flag==DEBUG)printmsg("TP209-IMU_FSYNC[S9]_MUX_3\r\n");
 printmsg("pwm duty cycle-%d%\r\n",Duty_Cycle);
 }
 else
 printmsg("Pwm duty cycle did not measured\r\n");
  
break;
case 3:
gpio_mux_16_1_sel(channel);
TIMER4_START;
 if(status_flag)
 {
 status_flag=FALSE;
  if(my_flag==DEBUG)printmsg("TP208-CAM2_FSYNC[S10]_MUX_3\r\n");
 printmsg("pwm duty cycle-%d%\r\n",Duty_Cycle);
 }
 else
 printmsg("Pwm duty cycle did not measured\r\n"); 
break;
case 4:
gpio_mux_16_1_sel(channel);
TIMER4_START;
 if(status_flag)
 {
 status_flag=FALSE;
 if(my_flag==DEBUG)printmsg("TP184-CAM0_FSIN_R[S11]_MUX_3\r\n");
 printmsg("pwm duty cycle-%d%\r\n",Duty_Cycle);
 }
 else
 printmsg("Pwm duty cycle did not measured\r\n");
  
break;
 case 5:
//gpio_mux_16_1_sel(channel);
 TIMER_DISABLE; // respected timer mux disable bcz there is no need of this pin at that moment
 TIMER2_START;  // respected timer like 2 on to measure the duty cycle at PA8 of MCU
 if(status_flag)// condtion check?
 {
 status_flag=FALSE;
 if(my_flag==DEBUG)printmsg("TP183-CAM0_FSIN_R PA8(MCU)\r\n");
 printmsg("pwm duty cycle-%d%\r\n",Duty_Cycle);
 }
 else
 printmsg("Pwm duty cycle did not measured\r\n");
  
break;
default :
break;	
}
}
/*======================================================================================*/
/*=======================================================================================*/
/*======================Debug Impedance/voltage test funtion===============================*/
	/**
* @brief  Impedance test Indivisual through the diffrent input signal for Debug purpose 
* @param1 Channel Number of the respected mux 
* @param2 Mux number for EN/DI the Respected Mux
* @param3 signal name of the respected Mux
* @retval None
*/
	void sep_imp_read(uint8_t channel,uint8_t mux_num,const char *str)
	{
	imp_setup_all(mux_num);
	uint32_t raw_value=0x00;
  float supply=3.3;
	float old=0.805;
	float i_new=0; 
	float i_resLow=0;
	float i_resUp=10;
	float res_diff=0;	
set_mux_ch(channel);
HAL_Delay(500);   //lets wait for some time to setup the power on the channel
raw_value=Get_ADC1_value(IMP_ADC_CH);
 i_new=(float)raw_value*supply;
 i_new/=4096;
// newVolt=0.6;
res_diff=old-i_new;
if(res_diff>0)
{
 i_resLow=i_new*i_resUp/res_diff;
sprintf((char *)response,"mux channel&NUM[%d-%d]|%s-|raw_value-%d |i_new-%.2f |res_diff-%.2f|i_resLow-%.2f KOHM\n\r",channel,mux_num,str,raw_value,i_new,res_diff,i_resLow);     //ob->imp_val
transimit_str_to(1,response,strlen((char *)response));
}
else
{
sprintf((char *)response,"mux channel&NUM[%d-%d]|%s-|raw_value-%d |i_new-%.2f |res_diff-%.2f|HIGH IMP-%d\n\r",channel,mux_num,str,raw_value,i_new,res_diff,IMP_LOW_SHORT);     //ob->imp_val
transimit_str_to(1,response,strlen((char *)response));
}	
}
/**
* @brief  voltage test through the diffrent input signal for Debug 
* @param1 Channel Number of the respected mux 
* @param2 Mux number for EN/DI the Respected Mux
* @param3 signal name of the respected Mux
* @retval None
*/
void sep_vol_read(uint8_t channel,uint8_t mux_num,const char *tp_name)
{
volt_setup_all_32_1(mux_num); 
uint32_t v_Adc=0x00;
float value=0;
float my_value=0; 
printmsg("\r\n");
set_mux_ch(channel);   // Here Mux channel are select by this funtion from 1 to 8
HAL_Delay(500);   //lets wait for some time to setup the power on the channel
v_Adc=Get_ADC1_value(VOL_ADC_CH);  // ADC_1 CH_6 at  PA_6
my_value=(float)v_Adc*3.3f;
my_value/=4096;	
	if(mux_num == 2 && channel == 3){my_value = 2*1.216216*my_value;};  //multiplication factor 
	if(mux_num == 2 && channel == 5){my_value = 2*1.216*my_value;};  //
	
  value=2*(my_value);
	
sprintf((char *)response,"mux channel&NUM[%d-%d]| %s|v_Adc-%d| my_val-%.2f volt|value-%.2f\r\n ",channel,mux_num,tp_name,v_Adc,my_value,value);
transimit_str_to(1,response,strlen((char *)response));		
}
/**
* @brief  Helper funtion for read the volt value of diffrent usb power of mux_32:1 
* @param  structure type pointer 
* @retval None
*/
float check_pwr_usb_plug_32_1(uint8_t channel)
{ 
	uint8_t my_value=0;
	float value=0;
	mux_switch_EN_DI(MUX_1); //enable the mux_1 of 32:1
  set_mux_ch(channel);
	my_value=Get_ADC1_value(VOL_ADC_CH);
	my_value=(float)my_value*3.3f;
	my_value/=4096;	
  value=2*(my_value);
	if(my_flag==DEBUG)printmsg("[MUX_32_1]before Fact-%.2f& After Fact-%.2f\r\n",my_value,value);
	return value;
}
/**
* @brief  Helper funtion for read the volt value of diffrent usb power of mux16:1 of MUX_2
* @param  channel number of the mux 
* @retval None
*/
float check_pwr_usb_plug_16_1(uint8_t channel)
{ 
	uint32_t my_value=0;
	float value=0;
	mux_switch_EN_DI(MUX_2);        //enable the mux_2 of 16:1
  gpio_mux_16_1_sel(channel);     //channel selected through the 16:1 
	my_value=Get_ADC1_value(VOL_ADC_CH);
	my_value=(float)my_value*3.3f;
	my_value/=4096;	
  value=2*(my_value);
	if(my_flag==DEBUG)printmsg("[MUX_16_1]before Fact-%.2f& After Fact-%.2f\r\n",my_value,value);
	return value;
}
/**
* @brief  voltage test of usb power before connect the plug in all conditions 
* @param  mode will decide the test of signal(channel/ALL) 
* @retval None
*/
void volt_check_usb_pwr_all(uint8_t mode)
{
	volt_setup_all_32_1(POWER_MUX); // Here we are initialize the some gpio that is require for these funtional power related test
	char *str[5]={"VCC_3P3_STANDBY","VBATT_3P7","VPH_PWR_3P7","VCC_6P0","VCC_6P0_FAN"};
	uint8_t i=0;
//float value=0;
	float usb_pwr=0;
	float usb_pwr_all[5]={0};
	switch(mode)
	{
		case 1:
		usb_pwr=	check_pwr_usb_plug_32_1(CH_15);
		if(my_flag==DEBUG)printmsg("MUX_1 CH_15|VCC_3P3_STANDBY(TN161)-%.2f\r\n",usb_pwr);
		
			break;
		case 2:
		usb_pwr=	check_pwr_usb_plug_32_1(CH_18);
		if(my_flag==DEBUG)printmsg("MUX_1 CH_18|VBATT_3P7(TN175)-%.2f\r\n",usb_pwr);
			break;
		case 3:
		usb_pwr=	check_pwr_usb_plug_32_1(CH_25);
		if(my_flag==DEBUG)printmsg("MUX_1 CH_25|VPH_PWR_3P7(TN213)-%.2f\r\n",usb_pwr);
			break;
		case 4:
		usb_pwr=	check_pwr_usb_plug_16_1(CH_3);
		if(my_flag==DEBUG)printmsg("MUX_2 CH_3|VCC_6P0(TN88)-%.2f\r\n",usb_pwr);
			break;
		case 5:
		usb_pwr=	check_pwr_usb_plug_16_1(CH_5);
		if(my_flag==DEBUG)printmsg("MUX_2 CH_5|VCC_6P0_FAN(TN218)-%.2f\r\n",usb_pwr);
			break;
		case 6:
		usb_pwr_all[0]=	check_pwr_usb_plug_32_1(CH_15);  //read_ip_status from MUX_1
		HAL_Delay(50);
		usb_pwr_all[1]=	check_pwr_usb_plug_32_1(CH_18);
    HAL_Delay(50);		
		usb_pwr_all[2]=	check_pwr_usb_plug_32_1(CH_25);
    HAL_Delay(50);		
		usb_pwr_all[3]=	check_pwr_usb_plug_16_1(CH_3);  
		HAL_Delay(50);
		usb_pwr_all[4]=	check_pwr_usb_plug_16_1(CH_5);
		HAL_Delay(50);
		printmsg("N_P@");
		for(i=0;i<=4;i++)
		{//printmsg("%s-%.2f\r\n",str,usb_pwr_all[i]);
		sprintf((char *)response,"%s-%.2f,",str[i],usb_pwr_all[i]); transimit_str_to(1,response,strlen((char *)response));
		}

		
		printmsg("VOL READ DONE\r\n");
			break;
		default:
			break;
		
	}

}

	   void gpio_mspint(void)
		 {
			    
					HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10, GPIO_PIN_SET);			 //PE10 TN125  OBD_LUMIA_GPS_PPS
			    HAL_Delay(50);
			    HAL_GPIO_WritePin(GPIOE, GPIO_PIN_10, GPIO_PIN_RESET);
			 
					HAL_GPIO_WritePin(GPIOG, GPIO_PIN_14, GPIO_PIN_SET);		  //PG14  TN12 MSP_CAN_INT_EN	 
			    HAL_Delay(50);
			    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_14, GPIO_PIN_RESET);
																
			    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_15, GPIO_PIN_RESET);                      //PG15  TN210  MSP_IGNITION_INT_EN
			    HAL_Delay(50);
			    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_15, GPIO_PIN_RESET);
			 
					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_RESET);												//PB5  TN33  MSP_TMP_ALERT
			    HAL_Delay(50);
			    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_RESET);
			 
					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET);												//PB6  TN6   IMU_INT
			    HAL_Delay(50);
			    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET);
		 
		 }

	
/*======================================================================================*/
/*=======================================================================================*/
/*======================End of Here===============================*/
