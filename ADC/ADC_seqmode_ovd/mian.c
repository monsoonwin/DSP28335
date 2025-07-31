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


#define BUFF_SIZE   16

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
    int arr_index;
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
	    SampleTable[i] = 0.0f;
	}
	ADC_Init();
	//AdcRegs.ADCTRL2.bit.SOC_SEQ1 = 1;

	while(1)
	{
	    arr_index=0;
	    //AdcRegs.ADCTRL2.bit.SOC_SEQ1 = 1;
	    for(i=0;i<(BUF_SIZE/16);i++)
	    {
	    while (AdcRegs.ADCST.bit.INT_SEQ1== 0){}
	        AdcRegs.ADCST.bit.INT_SEQ1_CLR = 1;
		SampleTable[arr_index++] = ((AdcRegs.ADCRESULT0)>>4)*3.0/4095.0;
		SampleTable[arr_index++] = ((AdcRegs.ADCRESULT1)>>4)*3.0/4095.0;
		SampleTable[arr_index++] = ((AdcRegs.ADCRESULT2)>>4)*3.0/4095.0;
		SampleTable[arr_index++] = ((AdcRegs.ADCRESULT3)>>4)*3.0/4095.0;
		SampleTable[arr_index++] = ((AdcRegs.ADCRESULT4)>>4)*3.0/4095.0;
        SampleTable[arr_index++] = ((AdcRegs.ADCRESULT5)>>4)*3.0/4095.0;
        SampleTable[arr_index++] = ((AdcRegs.ADCRESULT6)>>4)*3.0/4095.0;
        SampleTable[arr_index++] = ((AdcRegs.ADCRESULT7)>>4)*3.0/4095.0;

        SampleTable[arr_index++] = ((AdcRegs.ADCRESULT8)>>4)*3.0/4095.0;
        SampleTable[arr_index++] = ((AdcRegs.ADCRESULT9)>>4)*3.0/4095.0;
        SampleTable[arr_index++] = ((AdcRegs.ADCRESULT10)>>4)*3.0/4095.0;
        SampleTable[arr_index++] = ((AdcRegs.ADCRESULT11)>>4)*3.0/4095.0;
        SampleTable[arr_index++] = ((AdcRegs.ADCRESULT12)>>4)*3.0/4095.0;
        SampleTable[arr_index++] = ((AdcRegs.ADCRESULT13)>>4)*3.0/4095.0;
        SampleTable[arr_index++] = ((AdcRegs.ADCRESULT14)>>4)*3.0/4095.0;
        SampleTable[arr_index++] = ((AdcRegs.ADCRESULT15)>>4)*3.0/4095.0;

	    }


	}
}

