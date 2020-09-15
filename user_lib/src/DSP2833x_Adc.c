// TI File $Revision: /main/5 $
// Checkin $Date: October 23, 2007   13:34:09 $
//###########################################################################
//
// FILE:	DSP2833x_Adc.c
//
// TITLE:	DSP2833x ADC Initialization & Support Functions.
//
//###########################################################################
// $TI Release: DSP2833x/DSP2823x Header Files V1.20 $
// $Release Date: August 1, 2008 $
//###########################################################################

#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File

#define ADC_usDELAY  5000L

//---------------------------------------------------------------------------
// InitAdc:
//---------------------------------------------------------------------------
// This function initializes ADC to a known state.
//
void InitAdc(void)
{
    extern void DSP28x_usDelay(Uint32 Count);
    // *IMPORTANT*
	// The ADC_cal function, which  copies the ADC calibration values from TI reserved
	// OTP into the ADCREFSEL and ADCOFFTRIM registers, occurs automatically in the
	// Boot ROM. If the boot ROM code is bypassed during the debug process, the
	// following function MUST be called for the ADC to function according
	// to specification. The clocks to the ADC MUST be enabled before calling this
	// function.
	// See the device data manual and/or the ADC Reference
	// Manual for more information.
	EALLOW;
	SysCtrlRegs.PCLKCR0.bit.ADCENCLK = 1;
	ADC_cal();
	EDIS;
    // To powerup the ADC the ADCENCLK bit should be set first to enable
    // clocks, followed by powering up the bandgap, reference circuitry, and ADC core.
    // Before the first conversion is performed a 5ms delay must be observed
	// after power up to give all analog circuits time to power up and settle

    // Please note that for the delay function below to operate correctly the
	// CPU_RATE define statement in the DSP2833x_Examples.h file must
	// contain the correct CPU clock period in nanoseconds.

    //AdcRegs.ADCTRL3.all = 0x00E0;  // Power up bandgap/reference/ADC circuits
	AdcRegs.ADCTRL3.bit.ADCBGRFDN = 3;
  	AdcRegs.ADCTRL3.bit.ADCPWDN = 1;
    DELAY_US(ADC_usDELAY);
    // DELAY_US(20); // Delay at least 20us before converting ADC channels 	//  ����20us��ʱ
  	// DELAY_US(5000);
    // DELAY_US(ADC_usDELAY);         // Delay before converting ADC channels
}

void ADC_Config(void)
{
	AdcRegs.ADCTRL2.bit.SOC_SEQ1 = 0;
	AdcRegs.ADCTRL3.bit.ADCCLKPS = 0x0005;
	AdcRegs.ADCTRL1.bit.ACQ_PS = 0x0002;
	AdcRegs.ADCTRL3.bit.SMODE_SEL = 1;
	AdcRegs.ADCTRL1.bit.SEQ_CASC = 1;
	AdcRegs.ADCTRL1.bit.CONT_RUN = 0;
	AdcRegs.ADCMAXCONV.all = 0x0007;
    AdcRegs.ADCCHSELSEQ1.bit.CONV00 = 0x0;
    AdcRegs.ADCCHSELSEQ1.bit.CONV01 = 0x1;
    AdcRegs.ADCCHSELSEQ1.bit.CONV02 = 0x2;
    AdcRegs.ADCCHSELSEQ1.bit.CONV03 = 0x3;
    AdcRegs.ADCCHSELSEQ2.bit.CONV04 = 0x4;
    AdcRegs.ADCCHSELSEQ2.bit.CONV05 = 0x5;
    AdcRegs.ADCCHSELSEQ2.bit.CONV06 = 0x6;
    AdcRegs.ADCCHSELSEQ2.bit.CONV07 = 0x7;
	AdcRegs.ADCTRL1.bit.SEQ_OVRD = 0;
	AdcRegs.ADCTRL2.bit.SOC_SEQ1 = 1;
    AdcRegs.ADCTRL2.bit.EPWM_SOCA_SEQ1 = 1;
    AdcRegs.ADCTRL2.bit.RST_SEQ1 = 0x1;
}
/*
 * Initialize ADC, including GPIO and configuration
 */
void Init_ADC(void)
{
	InitAdc();
	ADC_Config();
}
//===========================================================================
// End of file.
//===========================================================================
