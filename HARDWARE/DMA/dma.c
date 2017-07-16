#include "dma.h"

void DMA_ADCToMemory_Init(u32 memoryAddr,int length)
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA2,ENABLE);//DMA2ʱ��ʹ�� 
	/*ADC1 ������DMA2 ͨ��0 ������0*/
	DMA_DeInit(DMA2_Stream0);
	DMA_Cmd(DMA2_Stream0, DISABLE);
	 DMA_InitTypeDef DMA_InitStruct = 
		{
			.DMA_BufferSize = length,//������250��λ
			.DMA_Channel = DMA_Channel_0,
			.DMA_DIR = DMA_DIR_PeripheralToMemory,//DMA���䷽�����赽�ڴ�
			.DMA_Mode = DMA_Mode_Circular,//ѭ����
			.DMA_Priority = DMA_Priority_High,
			/*�洢������*/
			.DMA_Memory0BaseAddr = memoryAddr,//�׵�ַ��buffer��
			.DMA_MemoryBurst = DMA_MemoryBurst_INC4,
			.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord,
			.DMA_MemoryInc = DMA_MemoryInc_Enable,
			
			/*��������*/
			.DMA_PeripheralBaseAddr = ADC1_DR_Address,//ADC1 �����ݼĴ���
			.DMA_PeripheralBurst = DMA_PeripheralBurst_INC4,
			.DMA_PeripheralInc = DMA_PeripheralInc_Disable,//���������ģʽ
			.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord,//�������ݳ���:16λ
			/*FIFO����*/
			.DMA_FIFOMode = DMA_FIFOMode_Enable,
		  .DMA_FIFOThreshold = DMA_FIFOThreshold_Full		
		};
		
		DMA_Init(DMA2_Stream0, &DMA_InitStruct);//��ʼ��DMA������
//		DMA_FlowControllerConfig(DMA2_Stream0,DMA_FlowCtrl_Peripheral);

		DMA_Cmd(DMA2_Stream0, ENABLE);
}
