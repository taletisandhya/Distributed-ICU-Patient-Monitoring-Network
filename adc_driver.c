#include<lpc21xx.h>
#include"header.h"


void adc_init(void)
{
PINSEL1|=0x15400000;      // configure adc pins p0.27,28,29 & 30
ADCR=0x00200400;         // select 10-bit adc , activate PDN mode , channel not selected , CLKDIV frequency 
}


#define DONE ((ADDR>>31)&1)
u32 adc_read(u8 ch_num)
{
unsigned int res=0;
ADCR|=(1<<ch_num);      // select channel from which data should be read 
ADCR|=(1<<24);         // to start the conversion from analog to digital
while(DONE==0);
ADCR^=(1<<24);
ADCR^=(1<<ch_num);
res=(ADDR>>6)&0x3ff;
return res;
}
