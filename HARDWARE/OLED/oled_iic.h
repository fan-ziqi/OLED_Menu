#ifndef __OLED_IIC_H
#define __OLED_IIC_H 
#include "sys.h"
#include "delay.h"
#include "menu.h"


#include "stm32f10x.h"

#define OLED_ADDRESS	0x78 //通过调整0R电阻,屏可以0x78和0x7A两个地址 -- 默认0x78

void I2C_Configuration(void);
void I2C_WriteByte(uint8_t addr,uint8_t data);
void WriteCmd(unsigned char I2C_Command);
void WriteDat(unsigned char I2C_Data);
void OLED_Init(void);
void OLED_SetPos(unsigned char x, unsigned char y);
void OLED_Fill(unsigned char fill_Data);
void OLED_CLS(void);
void OLED_ON(void);
void OLED_OFF(void);
void OLED_ShowStr(unsigned char x, unsigned char y, unsigned char ch[], unsigned char TextSize);
void OLED_ShowCN(unsigned char x, unsigned char y, unsigned char N);
void OLED_DrawBMP(unsigned char x0,unsigned char y0,unsigned char x1,unsigned char y1,unsigned char BMP[]);

void OLED_DrawWave(uint8_t x,uint8_t y);
void OLED_DrawPoint(uint8_t x,uint8_t y);
void Before_State_Update(uint8_t y);

void up_data(void);
void OLED_data_up(unsigned char fill_Data);

void up_time(void);
void OLED_time_up(unsigned char fill_Data);
void show_UI(void);

void show_chosen_current(void);
void show_chosen_rotation(void);
void show_chosen_all(void);

void show_menu(void);
void show_current_test(void);
void show_rotation_test(void);
void show_first_interface(void);
void show_all_test(void);
void show_bmp(u8 a);
void show_adc(void);



#endif
