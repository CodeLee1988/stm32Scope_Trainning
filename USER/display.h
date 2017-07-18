#ifndef DISPLAY_H__
#define DISPLAY_H__

#include "lcd.h"
/*��ɫ����*/
#define BACKGROUNDCOLOR 0x0000
#define EDGELINECOLOR  0X01CF
#define WAVECOLOR YELLOW
#define FONTCOLOR 0x7C49  
#define APPARENTEDGELINECOLOR CYAN 

/*��ͼ��صĶ���*/
#define XBase_Pos 5  //ԭ��ˮƽ����
#define YBase_Pos  205 //ԭ����ֱ����
#define DivLength 25 //ÿ��div�ĳ���


#define HoriDiv 10 //ˮƽ10��div
#define VeriDiv 8  //��ֱ8��div
#define HoriEdge (XBase_Pos + HoriDiv * DivLength+2)
#define VeriEdge (YBase_Pos+2)
#define Hori_Length (HoriDiv * DivLength) //���᳤
#define Veri_Length (VeriDiv* DivLength)	//���᳤

/*������ʾ��صĶ���*/
#define Right_1st_x HoriEdge + 1
#define Right_1st_y 1

/*�̶���ʾ����*/
#define Character_Width 8
#define XScale_XPos	XBase_Pos						//ˮƽ�̶���ʾλ��
#define XScale_YPos VeriEdge + 2
#define YScale_XPos	(XScale_XPos + Character_Width*12)					//��ֱ�̶���ʾλ��
#define YScale_YPos XScale_YPos

/*ģʽ��ʾ����*/
#define Mode_XPos (YScale_XPos+Character_Width*12)
#define Mode_YPos (XScale_YPos)
enum RaisingOrFalling {Raising,Falling};
enum LeftOrRight {Left,Right};

typedef enum LeftOrRight LeftOrRightType;
typedef enum RaisingOrFalling RaisingOrFallingType;

extern u16 buffer[2048];

void display_Init(void);
void measureDisplay(float val);
void display_DrawAxis(void);
void display_ClearArea(void);
void display_DrawDotWithCoordinate(u8 coordinateX,u16 coordinateY); /*��������任���ٻ��*/
void display_DrawWave(u16 *a,u16 length);
void display_XScale(void);
void display_YScale(void);
void display_XScale_Cmd(RaisingOrFallingType m);
void display_XMove_Cmd(LeftOrRightType lr);
void display_Mode(void);
#endif
