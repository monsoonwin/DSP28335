/*
 * main.c
 *
 *  Created on: 2018-3-21
 *      Author: Administrator
 */


#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File

#include "leds.h"
#include "time.h"
#include "smg.h"
#include "adc.h"


#define BUFF_SIZE   2

float SampleTable[BUFF_SIZE];

/*******************************************************************************
* 函 数 名         : main
* 函数功能		   : 主函数
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void main()
{
    int i;
    //int arr_index;
    //float adc_vol;

	InitSysCtrl();

	InitPieCtrl();
	IER = 0x0000;
	IFR = 0x0000;
	InitPieVectTable();

	LED_Init();
	TIM0_Init(150,200000);//200ms
	//SMG_Init();
	for(i=0;i<BUFF_SIZE;i++)
	{
	    SampleTable[i]=0;
	}
	ADC_Init();
	AdcRegs.ADCTRL2.bit。SOC_SEQ1 = 1;

	while(1)
	{
	    while (AdcRegs.ADCST.bit。INT_SEQ1== 0){}
	        AdcRegs.ADCST.bit。INT_SEQ1_CLR = 1;
		//adc_vol=(float)Read_ADCValue()*3.0/4096;
		SampleTable[0] = ((AdcRegs.ADCRESULT0)>>4)*3.0/4095.0;
		AdcRegs.ADCTRL2.bit。SOC_SEQ2 = 1;
		while (AdcRegs.ADCST.bit。INT_SEQ2== 0){}
		AdcRegs.ADCST.bit。INT_SEQ2_CLR = 1;
		SampleTable[1] = ((AdcRegs.ADCRESULT8)>>4)*3.0/4095.0;

		AdcRegs.ADCTRL2.bit。SOC_SEQ1 = 1;


		//SMG_DisplayFloat(adc_vol,2);
//		SMG_DisplayInt(Read_ADCValue());

	}
}

