#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "lcd.h"
#include "display.h"
#include "adc.h"
#include "dma.h"
#include "Key.h"
#include "timer.h"
#include "control.h"
#include "dac.h"
u16 buffer[2048]; //������
u8 pause = 0;
extern uint32_t	TIM5CH1_CAPTURE_VAL;	//���벶��ֵ  
extern u8 count_Update;
extern u16 peakValue;
extern u16 valleyValue;

IsSuitable_Type isSuit;
int main(void)
 { 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//����ϵͳ�ж����ȼ�����2
	delay_init(168); 
	uart_init(9600);
	display_Init();
	DMA_ADCToMemory_Init((u32)buffer,2048);
	Adc_Init();
	Key_Init();
	Control_Init();

	TIM5_CH1_Cap_Init(0XFFFFFFFF,84-1); //��1Mhz��Ƶ�ʼ���
	
	
	
  while(1) 
	{
		ADC_DMACmd(ADC1,DISABLE);
		DMA_Cmd(DMA2_Stream0, DISABLE);
		if(count_Update)        //�ɹ�������һ�θߵ�ƽ
		{
			float temp = 16000 / (float)TIM5CH1_CAPTURE_VAL;
			display_Frequence(temp);
			count_Update = 0;		     //������һ�β���
		}
		if(!pause)
		{	
			
			display_DrawWave(buffer,2048);
			DMA_ClearFlag(DMA2_Stream0,DMA_FLAG_TEIF0);
			DMA_ClearFlag(DMA2_Stream0,DMA_FLAG_TCIF0);
			DMA_Cmd(DMA2_Stream0,ENABLE);
			ADC_ClearFlag(ADC1,ADC_FLAG_OVR);
			ADC_DMACmd(ADC1,ENABLE);
			ADC_SoftwareStartConv(ADC1);			
			delay_ms(1);
		}
		IsSuitable_Type isSuit = Control_NeedToAdjust(peakValue,valleyValue);
		if(isSuit!= OK)//
		{
			if(isSuit == Large)
				Control_DecInput();
			else if(isSuit == Small)
				Control_IncInput();
		}
	}
}
