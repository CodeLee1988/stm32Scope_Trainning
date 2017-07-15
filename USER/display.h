#ifndef DISPLAY_H__
#define DISPLAY_H__

#include "lcd.h"
/*��ɫ����*/
#define BACKGROUNDCOLOR 0x0000
#define EDGELINECOLOR  0X01CF
#define WAVECOLOR 0xFFFF
#define FONTCOLOR 0x7C49  
#define APPARENTEDGELINECOLOR CYAN 

/*��ͼ��صĶ���*/
#define XBase 5  //ԭ��ˮƽ����
#define YBase  205 //ԭ����ֱ����
#define DivLength 25 //ÿ��div�ĳ���
#define HoriDiv 10 //ˮƽ10��div
#define VerDiv 8  //��ֱ8��div
#define HoriEdge (XBase + HoriDiv * DivLength+2)
#define VeriEdge YBase+2

/*������ʾ��صĶ���*/
#define Right_1st_x HoriEdge + 1
#define Right_1st_y 1
void display_Init(void);
void measureDisplay(float val);

#endif
