#include "oled_iic.h"
#include "codetab.h"
#include "timer.h"


#include <stdio.h>


uint8_t Bef[3];//保存前一个数据的几个参数1.要写在第几页2.0x01要移动几位3.写什么数据
uint8_t Cur[3];//当前前一个数据1.要写在第几页2.0x01要移动几位3.写什么数据

void I2C_Configuration(void)
{
	I2C_InitTypeDef  I2C_InitStructure;
	GPIO_InitTypeDef  GPIO_InitStructure; 

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);

	/*STM32F103C8T6芯片的硬件I2C: PB6 -- SCL; PB7 -- SDA */
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_OD;//I2C必须开漏输出
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	I2C_DeInit(I2C1);//使用I2C1
	I2C_InitStructure.I2C_Mode = I2C_Mode_I2C;
	I2C_InitStructure.I2C_DutyCycle = I2C_DutyCycle_2;
	I2C_InitStructure.I2C_OwnAddress1 = 0x30;//主机的I2C地址,随便写的
	I2C_InitStructure.I2C_Ack = I2C_Ack_Enable;
	I2C_InitStructure.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
	I2C_InitStructure.I2C_ClockSpeed = 400000;//400K

	I2C_Cmd(I2C1, ENABLE);
	I2C_Init(I2C1, &I2C_InitStructure);
}

void I2C_WriteByte(uint8_t addr,uint8_t data)
{
//固件库
    while(I2C_GetFlagStatus(I2C1, I2C_FLAG_BUSY));
	
	I2C_GenerateSTART(I2C1, ENABLE);//开启I2C1
	while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT));/*EV5,主模式*/

	I2C_Send7bitAddress(I2C1, OLED_ADDRESS, I2C_Direction_Transmitter);//器件地址 -- 默认0x78
	while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED));

	I2C_SendData(I2C1, addr);//寄存器地址
	while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED));

	I2C_SendData(I2C1, data);//发送数据
	while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED));
	
	I2C_GenerateSTOP(I2C1, ENABLE);//关闭I2C1总线
	
	
////寄存器操作
//	while((I2C1->SR2 & 0x0002));//总线忙
//	I2C1->CR1 |= 1<<8;//开启I2C1起始条件已经发送
//	while(! (I2C1->SR1 & (1<<0)));//检查起始条件是否已经发送
//	I2C1->DR = OLED_ADDRESS;//OLED地址，头七位是地址，最低位决定传输方向  0：发送1：读取
//	while(! (I2C1->SR1 & (1<<1)));
//	I2C1->SR2;//软件读取SR1，SR2后将自动清除该位。手册上主发送的时候提到，只有发送地址和清除ADDR后才能发送字节。这个细节在寄存器描述的时候并没有提到，但是一定要有这句话，没有的话就不能正常通信.
//	I2C1->DR = addr;
//	while(! (I2C1->SR1 & (1<<2)));
//	I2C1->DR = data;
//	while(! (I2C1->SR1 & (1<<2)));
//	I2C1->CR1 |= 1<<9;//关闭I2C1总线


}

void WriteCmd(unsigned char I2C_Command)//写命令
{
	I2C_WriteByte(0x00, I2C_Command);
}

void WriteDat(unsigned char I2C_Data)//写数据
{
	I2C_WriteByte(0x40, I2C_Data);
}

void OLED_Init(void)
{
	I2C_Configuration();
	delay_ms(100); //这里的延时很重要

	WriteCmd(0xAE); //display off
	WriteCmd(0x20);	//Set Memory Addressing Mode	
	WriteCmd(0x10);	//00,Horizontal Addressing Mode;01,Vertical Addressing Mode;10,Page Addressing Mode (RESET);11,Invalid
	WriteCmd(0xb0);	//Set Page Start Address for Page Addressing Mode,0-7
	WriteCmd(0xc8);	//Set COM Output Scan Direction
	WriteCmd(0x00); //---set low column address
	WriteCmd(0x10); //---set high column address
	WriteCmd(0x40); //--set start line address
	WriteCmd(0x81); //--set contrast control register
	WriteCmd(0xff); //亮度调节 0x00~0xff
	WriteCmd(0xa1); //--set segment re-map 0 to 127
	WriteCmd(0xa6); //--set normal display
	WriteCmd(0xa8); //--set multiplex ratio(1 to 64)
	WriteCmd(0x3F); //
	WriteCmd(0xa4); //0xa4,Output follows RAM content;0xa5,Output ignores RAM content
	WriteCmd(0xd3); //-set display offset
	WriteCmd(0x00); //-not offset
	WriteCmd(0xd5); //--set display clock divide ratio/oscillator frequency
	WriteCmd(0xf0); //--set divide ratio
	WriteCmd(0xd9); //--set pre-charge period
	WriteCmd(0x22); //
	WriteCmd(0xda); //--set com pins hardware configuration
	WriteCmd(0x12);
	WriteCmd(0xdb); //--set vcomh
	WriteCmd(0x20); //0x20,0.77xVcc
	WriteCmd(0x8d); //--set DC-DC enable
	WriteCmd(0x14); //
	WriteCmd(0xaf); //--turn on oled panel

}
 /**
  * @brief  OLED_SetPos，设置光标
  * @param  x,第几页
	*					y,第几列
  * @retval 无
  */
void OLED_SetPos(unsigned char x, unsigned char y) //设置起始点坐标
{ 
	WriteCmd(0xb0+y);
	WriteCmd(((x&0xf0)>>4)|0x10);
	WriteCmd((x&0x0f)|0x01);
}

void OLED_Fill(unsigned char fill_Data)//全屏填充
{
	unsigned char m,n;
	for(m=0;m<8;m++)
	{
		WriteCmd(0xb0+m);		//page0-page1
		WriteCmd(0x00);		//low column start address
		WriteCmd(0x10);		//high column start address
		for(n=0;n<128;n++)
		{
			WriteDat(fill_Data);
		}
	}
}


void OLED_CLS(void)//清屏
{
	OLED_Fill(0x00);
}

void OLED_data_up(unsigned char fill_Data)
{
	unsigned char m,n;
	for(m=0;m<2;m++)
	{
		WriteCmd(0xb2+m);		//page0-page1
		WriteCmd(0x00);		//low column start address
		WriteCmd(0x10);		//high column start address
		for(n=0;n<128;n++)
		{
			WriteDat(fill_Data);
		}
	}
}

void up_data(void)//刷新显示
{
	OLED_data_up(0x00);
}

void OLED_time_up(unsigned char fill_Data)
{
	unsigned char m,n;
	for(m=0;m<2;m++)
	{
		WriteCmd(0xb4+m);		//page0-page1
		WriteCmd(0x00);		//low column start address
		WriteCmd(0x10);		//high column start address
		for(n=0;n<128;n++)
			{
				WriteDat(fill_Data);
			}
	}
}

void up_time(void)//刷新显示
{
	OLED_time_up(0x00);
}


//--------------------------------------------------------------
// Prototype      : void OLED_ON(void)
// Calls          : 
// Parameters     : none
// Description    : 将OLED从休眠中唤醒
//--------------------------------------------------------------
void OLED_ON(void)
{
	WriteCmd(0X8D);  //设置电荷泵
	WriteCmd(0X14);  //开启电荷泵
	WriteCmd(0XAF);  //OLED唤醒
}

//--------------------------------------------------------------
// Prototype      : void OLED_OFF(void)
// Calls          : 
// Parameters     : none
// Description    : 让OLED休眠 -- 休眠模式下,OLED功耗不到10uA
//--------------------------------------------------------------
void OLED_OFF(void)
{
	WriteCmd(0X8D);  //设置电荷泵
	WriteCmd(0X10);  //关闭电荷泵
	WriteCmd(0XAE);  //OLED休眠
}

//--------------------------------------------------------------
// Prototype      : void OLED_ShowChar(unsigned char x, unsigned char y, unsigned char ch[], unsigned char TextSize)
// Calls          : 
// Parameters     : x,y -- 起始点坐标(x:0~127, y:0~7); ch[] -- 要显示的字符串; TextSize -- 字符大小(1:6*8 ; 2:8*16)
// Description    : 显示codetab.h中的ASCII字符,有6*8和8*16可选择
//--------------------------------------------------------------
void OLED_ShowStr(unsigned char x, unsigned char y, unsigned char ch[], unsigned char TextSize)
{
	unsigned char c = 0,i = 0,j = 0;
	switch(TextSize)
	{
		case 1:
		{
			while(ch[j] != '\0')
			{
				c = ch[j] - 32;
				if(x > 126)
				{
					x = 0;
					y++;
				}
				OLED_SetPos(x,y);
				for(i=0;i<6;i++)
					WriteDat(F6x8[c][i]);
				x += 6;
				j++;
			}
		}break;
		case 2:
		{
			while(ch[j] != '\0')
			{
				c = ch[j] - 32;
				if(x > 120)
				{
					x = 0;
					y++;
				}
				OLED_SetPos(x,y);
				for(i=0;i<8;i++)
					WriteDat(F8X16[c*16+i]);
				OLED_SetPos(x,y+1);
				for(i=0;i<8;i++)
					WriteDat(F8X16[c*16+i+8]);
				x += 8;
				j++;
			}
		}break;
	}
}

//--------------------------------------------------------------
// Prototype      : void OLED_ShowCN(unsigned char x, unsigned char y, unsigned char N)
// Calls          : 
// Parameters     : x,y -- 起始点坐标(x:0~127, y:0~7); N:汉字在codetab.h中的索引
// Description    : 显示codetab.h中的汉字,16*16点阵
//--------------------------------------------------------------
void OLED_ShowCN(unsigned char x, unsigned char y, unsigned char N)
{
	unsigned char wm=0;
	unsigned int  adder=32*N;
	OLED_SetPos(x , y);
	for(wm = 0;wm < 16;wm++)
	{
		WriteDat(F16x16[adder]);
		adder += 1;
	}
	OLED_SetPos(x,y + 1);
	for(wm = 0;wm < 16;wm++)
	{
		WriteDat(F16x16[adder]);
		adder += 1;
	}
}

//--------------------------------------------------------------
// Prototype      : void OLED_DrawBMP(unsigned char x0,unsigned char y0,unsigned char x1,unsigned char y1,unsigned char BMP[]);
// Calls          : 
// Parameters     : x0,y0 -- 起始点坐标(x0:0~127, y0:0~7); x1,y1 -- 起点对角线(结束点)的坐标(x1:1~128,y1:1~8)
// Description    : 显示BMP位图
//--------------------------------------------------------------
void OLED_DrawBMP(unsigned char x0,unsigned char y0,unsigned char x1,unsigned char y1,unsigned char BMP[])
{
	unsigned int j=0;
	unsigned char x,y;

  if(y1%8==0)
		y = y1/8;
  else
		y = y1/8 + 1;
	for(y=y0;y<y1;y++)
	{
		OLED_SetPos(x0,y);
    for(x=x0;x<x1;x++)
		{
			WriteDat(BMP[j++]);
		}
	}
}





//显示界面
void show_UI(void)
{
	
	//滚动显示所有界面
//	show_first_interface();
//	delay_ms(500);
//	show_menu();
//	delay_ms(500);
//	show_chosen_current();
//	delay_ms(500);
//	show_current_test();
//	delay_ms(500);
//	show_chosen_rotation();
//	delay_ms(500);
//	show_rotation_test();
//	delay_ms(500);
//	show_chosen_all();
//	delay_ms(500);
//	show_all_test();
//	delay_ms(500);

	if(time13 >= 500)
	{
		time13 = 0;
		INTERFACE_Statment();//状态机显示菜单
	}
	
}


void show_chosen_current(void)
{
	unsigned char table[20]  = ">>";
	unsigned char table1[10]  = "  ";

	OLED_ShowStr(0, 0, table, 2);    //>>
	OLED_ShowStr(0, 2, table1, 2);    //
	OLED_ShowStr(0, 4, table1, 2);    //
}


void show_chosen_rotation(void)
{

	unsigned char table[20]  = ">>";
	unsigned char table1[10]  = "  ";
	
	OLED_ShowStr(0, 0, table1, 2);    //>>
	OLED_ShowStr(0, 2, table, 2);    //>>
	OLED_ShowStr(0, 4, table1, 2);    //>>
	
}


void show_chosen_all(void)
{

	unsigned char table[20]  = ">>";
	unsigned char table1[10]  = "  ";

	
	OLED_ShowStr(0, 0, table1, 2);    //>>
	OLED_ShowStr(0, 2, table1, 2);    //>>
	OLED_ShowStr(0, 4, table, 2);    //>>
		
}


void show_menu(void)
{

	unsigned char table0[20] = "1.";
	unsigned char table1[20] = "2.";
	unsigned char table2[20] = "3.";
		
	OLED_ShowStr(16, 0, table0, 2);  //1.
	OLED_ShowCN(32, 0, 5);			//电
	OLED_ShowCN(48, 0, 7);			//流
	OLED_ShowCN(64, 0, 9);			//检
	OLED_ShowCN(80, 0, 10);			//测
	
	
	OLED_ShowStr(16, 2, table1, 2);  //2.
	OLED_ShowCN(32, 2, 3);			//转
	OLED_ShowCN(48, 2, 4);			//速
	OLED_ShowCN(64, 2, 9);			//检
	OLED_ShowCN(80, 2, 10);			//测
	
	
	OLED_ShowStr(16, 4, table2, 2);  //3.
	OLED_ShowCN(32, 4, 15);			//一
	OLED_ShowCN(48, 4, 16);			//键
	OLED_ShowCN(64, 4, 9);			//检
	OLED_ShowCN(80, 4, 10);			//测
	
	
	OLED_ShowCN(0, 6, 11);			//确
	OLED_ShowCN(16, 6, 12);			//认
	
	OLED_ShowCN(96, 6, 13);			//返
	OLED_ShowCN(112, 6, 14);		//回
}


void show_current_test(void)
{

	//显示经取模软件设定好的汉字
	unsigned char table0[20] = ":xx  ";
	unsigned char table1[20] = ":xx  ";
	unsigned char table5[20] = ":       ";
	
	
	sprintf((char *)table0,":%d mA", 123);
	sprintf((char *)table1,":%d mA", 456);
	

	OLED_ShowCN(32, 0, 5);			//电
	OLED_ShowCN(48, 0, 7);			//流
	OLED_ShowCN(64, 0, 9);			//检
	OLED_ShowCN(80, 0, 10);			//测
	
	
	OLED_ShowCN(0, 2, 0);		     //左
	OLED_ShowCN(16, 2, 2);			 //侧
	OLED_ShowCN(32, 2, 5);		     //电
	OLED_ShowCN(48, 2, 7);			 //流
	
	
	OLED_ShowCN(0, 4, 1);		     //右
	OLED_ShowCN(16, 4, 2);			 //侧
	OLED_ShowCN(32, 4, 5);		     //电
	OLED_ShowCN(48, 4, 7);			 //流
	
	
	OLED_ShowCN(0, 6, 9);			//检
	OLED_ShowCN(16, 6, 10);			//测
	
	
	OLED_ShowCN(96, 6, 13);			//返
	OLED_ShowCN(112, 6, 14);		//回
	
	if(time >= 500)
	{
		time = 0;
		//清数据
		OLED_ShowStr(64, 2, table5, 2); 
		OLED_ShowStr(64, 4, table5, 2);
		OLED_ShowStr(64, 2, table0, 2);  //显示对应的数值
		OLED_ShowStr(64, 4, table1, 2);  //显示对应的数值
	}
}

void show_rotation_test(void)
{
	//显示经取模软件设定好的汉字
	unsigned char table0[20] = ":xx  ";
	unsigned char table1[20] = ":xx  ";
	unsigned char table5[20] = ":       ";
	
//	if((rotation_left_value >= 999)||(rotation_right_value >= 999))
//	{
//		rotation_left_value = 0;
//		rotation_right_value = 0;
//	}
	
//	sprintf((char *)table0,":%d rpm", (int)rotation_left_value);
//	sprintf((char *)table1,":%d rpm", (int)rotation_right_value);
	
	
	OLED_ShowCN(32, 0, 3);			//转
	OLED_ShowCN(48, 0, 4);			//速
	OLED_ShowCN(64, 0, 9);			//检
	OLED_ShowCN(80, 0, 10);			//测
	
	
	OLED_ShowCN(0, 2, 0);		     //左
	OLED_ShowCN(16, 2, 2);			 //侧
	OLED_ShowCN(32, 2, 3);		     //转
	OLED_ShowCN(48, 2, 4);			 //速

	
	OLED_ShowCN(0, 4, 1);		     //右
	OLED_ShowCN(16, 4, 2);			 //侧
	OLED_ShowCN(32, 4, 3);		     //转
	OLED_ShowCN(48, 4, 4);			 //速
	
	
	OLED_ShowCN(0, 6, 9);			//检
	OLED_ShowCN(16, 6, 10);			//测
	
	
	OLED_ShowCN(96, 6, 13);			//返
	OLED_ShowCN(112, 6, 14);		//回
	
	if(time >= 500)
	{
		time = 0;
		//清数据
		OLED_ShowStr(64, 2, table5, 2); 
		OLED_ShowStr(64, 4, table5, 2);
		
		OLED_ShowStr(64, 2, table0, 2);  //显示对应的数值
		OLED_ShowStr(64, 4, table1, 2);  //显示对应的数值
	}
}

void show_all_test(void)
{


	//显示经取模软件设定好的汉字
	unsigned char table[20]  = ":xx  ";
	unsigned char table0[20] = ":xx  ";
	unsigned char table1[20] = ":xx  ";
	unsigned char table2[20] = ":xx  ";
	
	

	 
	

	
		
		OLED_ShowCN(0, 0, 3);//转
		OLED_ShowCN(16, 0, 6);//差
//		OLED_ShowCN(97, 0, 3);//转
//		OLED_ShowCN(113, 0, 8);//向
				
		OLED_ShowCN(0, 2, 0);		     //左
		OLED_ShowCN(16, 2, 2);			 //侧
//		OLED_ShowCN(32, 4, 3);		     //转
//		OLED_ShowCN(48, 4, 4);			 //速

		OLED_ShowCN(0, 4, 1);		     //右
		OLED_ShowCN(16, 4, 2);			 //侧
//		OLED_ShowCN(32, 2, 3);		     //转
//		OLED_ShowCN(48, 2, 4);			 //速
		
		OLED_ShowCN(0, 6, 5);           //电
		OLED_ShowCN(16, 6, 7);			 //流
		
		OLED_ShowCN(96, 6, 13);			//返
		OLED_ShowCN(112, 6, 14);		//回
		
		
	if(time >= 500)
	{
		time = 0;

		//清数据

		
		OLED_ShowStr(32,0,table,2);//
		OLED_ShowStr(32, 2, table2, 2);//
		OLED_ShowStr(32, 4, table0, 2);// 
		OLED_ShowStr(32, 6, table1, 2);//

	}
}

void show_first_interface(void)
{
	show_bmp(1);
}

void show_bmp(u8 a)
{
	switch(a)
	{
		case 1:
				OLED_DrawBMP(0,0,128,8,BMP1);
			break;
			
//		case 2:
//				OLED_DrawBMP(0,0,128,8,BMP2);
//			break;
			
			
		default:
			break;
			
	}
	
}





