#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "lcd.h"
#define XBase 5  //ԭ��ˮƽ����
#define YBase  205 //ԭ����ֱ����
#define DivLength 25 //ÿ��div�ĳ���
#define HoriDiv 10 //ˮƽ10��div
#define VerDiv 8  //��ֱ8��div
#define HoriEdge (XBase + HoriDiv * DivLength+2)
#define VeriEdge YBase+2
int main(void)
{ 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//����ϵͳ�ж����ȼ�����2
	delay_init(168); 
	uart_init(9600);
 	LCD_Init();           //��ʼ��LCD FSMC�ӿ�
	
	LCD_Clear(BACKGROUNDCOLOR);
	/*���Ʊ߿���*/
	POINT_COLOR = LIGHTBLUE;
	LCD_DrawRectangle(0,0,HoriEdge,VeriEdge);
	LCD_DrawRectangle(HoriEdge,0,320,240);
	LCD_DrawRectangle(0,0,320,240);
	/*����div����*/
	POINT_COLOR = EDGELINECOLOR;
	for(int i = 0;i<=VerDiv;i++)
		LCD_DrawDottedLine(XBase,YBase-i*DivLength,XBase + HoriDiv * DivLength, YBase-i*DivLength);
	for(int i = 0;i<=HoriDiv;i++)
		LCD_DrawDottedLine(XBase+i*DivLength,YBase,XBase+i*DivLength, YBase- VerDiv * DivLength);
	/*����������*/
	POINT_COLOR = APPARENTEDGELINECOLOR;
	LCD_DrawLine(XBase,YBase - 4 * DivLength,XBase + HoriDiv * DivLength,YBase - 4 * DivLength);
	LCD_DrawLine(XBase + 5*DivLength ,YBase,XBase + 5*DivLength,YBase - VerDiv * DivLength);
  while(1) 
	{	
	 	
	}
}
