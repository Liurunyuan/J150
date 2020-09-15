#ifndef PF_ADC_HAL_H_
#define PF_ADC_HAL_H_

#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File
#include "prod.h"


#define Get_Adc_CHL0				((AdcRegs.ADCRESULT0) >> 4)
#define Get_Adc_CHL1			    ((AdcRegs.ADCRESULT1) >> 4)
#define Get_Adc_CHL2			    ((AdcRegs.ADCRESULT2) >> 4)
#define Get_Adc_CHL3		        ((AdcRegs.ADCRESULT3) >> 4)
#define Get_Adc_CHL4			    ((AdcRegs.ADCRESULT4) >> 4)
#define Get_Adc_CHL5			    ((AdcRegs.ADCRESULT5) >> 4)
#define Get_Adc_CHL6		        ((AdcRegs.ADCRESULT6) >> 4)
#define Get_Adc_CHL7			    ((AdcRegs.ADCRESULT7) >> 4)
#define Get_Adc_CHL8		        ((AdcRegs.ADCRESULT8) >> 4)
#define Get_Adc_CHL9		        ((AdcRegs.ADCRESULT9) >> 4)
#define Get_Adc_CHL10			    ((AdcRegs.ADCRESULT10) >> 4)
#define Get_Adc_CHL11			    ((AdcRegs.ADCRESULT11) >> 4)
#define Get_Adc_CHL12			    ((AdcRegs.ADCRESULT12) >> 4)
#define Get_Adc_CHL13			    ((AdcRegs.ADCRESULT13) >> 4)
#define Get_Adc_CHL14			    ((AdcRegs.ADCRESULT14) >> 4)
#define Get_Adc_CHL15			    ((AdcRegs.ADCRESULT15) >> 4)
#endif
