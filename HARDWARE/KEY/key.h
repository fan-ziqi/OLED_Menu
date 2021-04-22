#ifndef __KEY_H
#define __KEY_H	 
#include "stm32f10x.h"


#define Hang_00_L  GPIO_ResetBits(GPIOA, GPIO_Pin_0)//行00
#define Hang_00_H  GPIO_SetBits(GPIOA, GPIO_Pin_0)
 
#define Hang_01_L  GPIO_ResetBits(GPIOA, GPIO_Pin_1)//行01
#define Hang_01_H  GPIO_SetBits(GPIOA, GPIO_Pin_1)
 
#define Hang_02_L  GPIO_ResetBits(GPIOA, GPIO_Pin_2)//行02
#define Hang_02_H  GPIO_SetBits(GPIOA, GPIO_Pin_2)
 
#define Hang_03_L  GPIO_ResetBits(GPIOA, GPIO_Pin_3)//行03
#define Hang_03_H  GPIO_SetBits(GPIOA, GPIO_Pin_3)
 
#define Lie_00_V GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_4)//列00
#define Lie_01_V GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_5)//列01
#define Lie_02_V GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_6)//列02
#define Lie_03_V GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_7)//列03

#define  jpys   1   //宏定义，约定jpys==20，方便以后程序移植





extern u8 key1_press ;
extern u8 key2_press ;
extern u8 key3_press ;
extern u8 key4_press ;
extern u8 key5_press ;
extern u8 key6_press ;
extern u8 key7_press ;
extern u8 key8_press ;
extern u8 key9_press ;
extern u8 key10_press ;
extern u8 key11_press ;
extern u8 key12_press ;
extern u8 key13_press ;
extern u8 key14_press ;
extern u8 key15_press ;
extern u8 key16_press ;



void KEY_4X4_init(void);//IO初始化
u8 KEY_4X4_Scan(u8 mode);  	//按键扫描函数
void All_Key_Task(void);
void Key_Scan(void);

#endif


