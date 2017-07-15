#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "lcd.h"
#include "display.h"
#include "adc.h"
int main(void)
{ 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//����ϵͳ�ж����ȼ�����2
	delay_init(168); 
	uart_init(9600);
	display_Init();
	Adc_Init();
	u16 adcx;
  while(1) 
	{	
	 	adcx=Get_Adc_Average(ADC_Channel_5,20);//��ȡͨ��5��ת��ֵ��20��ȡƽ��
		float temp=(float)adcx*(3.3/4096);
		measureDisplay(temp);
		delay_ms(250);
	}
}
