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
	AdcRegs.ADCTRL1.bit.SEQ_CASC = 1;        // 级联
	AdcRegs.ADCTRL3.bit.SMODE_SEL = 0;        //顺序采样
	
	AdcRegs. ADCCHSELSEQ1.bit. CONV00 = 0x0;
	AdcRegs. ADCCHSELSEQ1.bit. CONV01 = 0x1;
	AdcRegs. ADCCHSELSEQ1.bit. CONV02 = 0x2;
	AdcRegs. ADCCHSELSEQ1.bit. CONV03 = 0x3;
	AdcRegs. ADCCHSELSEQ2.bit. CONV04 = 0x4;
	AdcRegs. ADCCHSELSEQ2.bit. CONV05 = 0x5;
	AdcRegs. ADCCHSELSEQ2.bit. CONV06 = 0x6;
	AdcRegs. ADCCHSELSEQ2.bit. CONV07 = 0x7;
	AdcRegs. ADCCHSELSEQ3.bit. CONV08 = 0x8;
	AdcRegs. ADCCHSELSEQ3.bit. CONV09 = 0x9;
	AdcRegs. ADCCHSELSEQ3.bit. CONV10 = 0xA;
	AdcRegs. ADCCHSELSEQ3.bit. CONV11 = 0xB;
	AdcRegs. ADCCHSELSEQ4.bit. CONV12 = 0xC;
	AdcRegs. ADCCHSELSEQ4.bit. CONV13 = 0xD;
	AdcRegs. ADCCHSELSEQ4.bit. CONV14 = 0xE;
	AdcRegs. ADCCHSELSEQ4.bit. CONV15 = 0xF;

	AdcRegs.ADCTRL1.bit.CONT_RUN = 1;       // Setup continuous run
	AdcRegs.ADCTRL1.bit.SEQ_OVRD = 1;
    //AdcRegs.ADCMAXCONV.all = 0x0000;
	AdcRegs.ADCMAXCONV.bit.MAX_CONV1 = 0xF;

	// Start SEQ1
	AdcRegs.ADCTRL2.bit.SOC_SEQ1 = 1;


}

/*Uint16 Read_ADCValue(void)
{
	while (AdcRegs.ADCST.bit.INT_SEQ1== 0);
	AdcRegs.ADCST.bit.INT_SEQ1_CLR = 1;
	return AdcRegs.ADCRESULT0>>4;
}*/

