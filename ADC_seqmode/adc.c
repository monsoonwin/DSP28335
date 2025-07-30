/*
 * adc.c
 *
 *  Created on: 2018-1-29
 *      Author: Administrator
 */

#include "adc.h"




void ADC_Init(void)
{
	// Specific clock setting for this example:
	EALLOW;
	SysCtrlRegs.PCLKCR0.bit.ADCENCLK = 1;    // ADC
	EDIS;

	// Specific clock setting for this example:
	EALLOW;
	SysCtrlRegs.HISPCP.all = ADC_MODCLK;	// HSPCLK = SYSCLKOUT/(2*ADC_MODCLK)
	EDIS;

	InitAdc();  // For this example, init the ADC

	// Specific ADC setup for this example:
	AdcRegs.ADCTRL1.bit.ACQ_PS = ADC_SHCLK;
	AdcRegs.ADCTRL3.bit.ADCCLKPS = ADC_CKPS;
	AdcRegs.ADCTRL1.bit.SEQ_CASC = 0;        // 1  Cascaded mode
	AdcRegs.ADCTRL3.bit.SMODE_SEL = 0;        //顺序采样
	AdcRegs.ADCCHSELSEQ1.bit.CONV00 = 0x0;
	AdcRegs.ADCCHSELSEQ3.bit.CONV08 = 0x8;
	AdcRegs.ADCTRL1.bit.CONT_RUN = 1;       // Setup continuous run
    AdcRegs.ADCMAXCONV.all = 0x0000;

	// Start SEQ1
	//AdcRegs.ADCTRL2.all = 0x2000;
	AdcRegs.ADCTRL2.bit.SOC_SEQ1 = 1;
	AdcRegs.ADCTRL2.bit.SOC_SEQ2 = 1;

}


