#include "oled_iic.h"
#include "codetab.h"
#include "timer.h"


#include <stdio.h>


uint8_t Bef[3];//����ǰһ�����ݵļ�������1.Ҫд�ڵڼ�ҳ2.0x01Ҫ�ƶ���λ3.дʲô����
uint8_t Cur[3];//��ǰǰһ������1.Ҫд�ڵڼ�ҳ2.0x01Ҫ�ƶ���λ3.дʲô����

void I2C_Configuration(void)
{
	I2C_InitTypeDef  I2C_InitStructure;
	GPIO_InitTypeDef  GPIO_InitStructure; 

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);

	/*STM32F103C8T6оƬ��Ӳ��I2C: PB6 -- SCL; PB7 -- SDA */
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_OD;//I2C���뿪©���
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	I2C_DeInit(I2C1);//ʹ��I2C1
	I2C_InitStructure.I2C_Mode = I2C_Mode_I2C;
	I2C_InitStructure.I2C_DutyCycle = I2C_DutyCycle_2;
	I2C_InitStructure.I2C_OwnAddress1 = 0x30;//������I2C��ַ,���д��
	I2C_InitStructure.I2C_Ack = I2C_Ack_Enable;
	I2C_InitStructure.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
	I2C_InitStructure.I2C_ClockSpeed = 400000;//400K

	I2C_Cmd(I2C1, ENABLE);
	I2C_Init(I2C1, &I2C_InitStructure);
}

void I2C_WriteByte(uint8_t addr,uint8_t data)
{
//�̼���
    while(I2C_GetFlagStatus(I2C1, I2C_FLAG_BUSY));
	
	I2C_GenerateSTART(I2C1, ENABLE);//����I2C1
	while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_MODE_SELECT));/*EV5,��ģʽ*/

	I2C_Send7bitAddress(I2C1, OLED_ADDRESS, I2C_Direction_Transmitter);//������ַ -- Ĭ��0x78
	while(!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED));

	I2C_SendData(I2C1, addr);//�Ĵ�����ַ
	while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED));

	I2C_SendData(I2C1, data);//��������
	while (!I2C_CheckEvent(I2C1, I2C_EVENT_MASTER_BYTE_TRANSMITTED));
	
	I2C_GenerateSTOP(I2C1, ENABLE);//�ر�I2C1����
	
	
////�Ĵ�������
//	while((I2C1->SR2 & 0x0002));//����æ
//	I2C1->CR1 |= 1<<8;//����I2C1��ʼ�����Ѿ�����
//	while(! (I2C1->SR1 & (1<<0)));//�����ʼ�����Ƿ��Ѿ�����
//	I2C1->DR = OLED_ADDRESS;//OLED��ַ��ͷ��λ�ǵ�ַ�����λ�������䷽��  0������1����ȡ
//	while(! (I2C1->SR1 & (1<<1)));
//	I2C1->SR2;//�����ȡSR1��SR2���Զ������λ���ֲ��������͵�ʱ���ᵽ��ֻ�з��͵�ַ�����ADDR����ܷ����ֽڡ����ϸ���ڼĴ���������ʱ��û���ᵽ������һ��Ҫ����仰��û�еĻ��Ͳ�������ͨ��.
//	I2C1->DR = addr;
//	while(! (I2C1->SR1 & (1<<2)));
//	I2C1->DR = data;
//	while(! (I2C1->SR1 & (1<<2)));
//	I2C1->CR1 |= 1<<9;//�ر�I2C1����


}

void WriteCmd(unsigned char I2C_Command)//д����
{
	I2C_WriteByte(0x00, I2C_Command);
}

void WriteDat(unsigned char I2C_Data)//д����
{
	I2C_WriteByte(0x40, I2C_Data);
}

void OLED_Init(void)
{
	I2C_Configuration();
	delay_ms(100); //�������ʱ����Ҫ

	WriteCmd(0xAE); //display off
	WriteCmd(0x20);	//Set Memory Addressing Mode	
	WriteCmd(0x10);	//00,Horizontal Addressing Mode;01,Vertical Addressing Mode;10,Page Addressing Mode (RESET);11,Invalid
	WriteCmd(0xb0);	//Set Page Start Address for Page Addressing Mode,0-7
	WriteCmd(0xc8);	//Set COM Output Scan Direction
	WriteCmd(0x00); //---set low column address
	WriteCmd(0x10); //---set high column address
	WriteCmd(0x40); //--set start line address
	WriteCmd(0x81); //--set contrast control register
	WriteCmd(0xff); //���ȵ��� 0x00~0xff
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
  * @brief  OLED_SetPos�����ù��
  * @param  x,�ڼ�ҳ
	*					y,�ڼ���
  * @retval ��
  */
void OLED_SetPos(unsigned char x, unsigned char y) //������ʼ������
{ 
	WriteCmd(0xb0+y);
	WriteCmd(((x&0xf0)>>4)|0x10);
	WriteCmd((x&0x0f)|0x01);
}

void OLED_Fill(unsigned char fill_Data)//ȫ�����
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


void OLED_CLS(void)//����
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

void up_data(void)//ˢ����ʾ
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

void up_time(void)//ˢ����ʾ
{
	OLED_time_up(0x00);
}


//--------------------------------------------------------------
// Prototype      : void OLED_ON(void)
// Calls          : 
// Parameters     : none
// Description    : ��OLED�������л���
//--------------------------------------------------------------
void OLED_ON(void)
{
	WriteCmd(0X8D);  //���õ�ɱ�
	WriteCmd(0X14);  //������ɱ�
	WriteCmd(0XAF);  //OLED����
}

//--------------------------------------------------------------
// Prototype      : void OLED_OFF(void)
// Calls          : 
// Parameters     : none
// Description    : ��OLED���� -- ����ģʽ��,OLED���Ĳ���10uA
//--------------------------------------------------------------
void OLED_OFF(void)
{
	WriteCmd(0X8D);  //���õ�ɱ�
	WriteCmd(0X10);  //�رյ�ɱ�
	WriteCmd(0XAE);  //OLED����
}

//--------------------------------------------------------------
// Prototype      : void OLED_ShowChar(unsigned char x, unsigned char y, unsigned char ch[], unsigned char TextSize)
// Calls          : 
// Parameters     : x,y -- ��ʼ������(x:0~127, y:0~7); ch[] -- Ҫ��ʾ���ַ���; TextSize -- �ַ���С(1:6*8 ; 2:8*16)
// Description    : ��ʾcodetab.h�е�ASCII�ַ�,��6*8��8*16��ѡ��
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
// Parameters     : x,y -- ��ʼ������(x:0~127, y:0~7); N:������codetab.h�е�����
// Description    : ��ʾcodetab.h�еĺ���,16*16����
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
// Parameters     : x0,y0 -- ��ʼ������(x0:0~127, y0:0~7); x1,y1 -- ���Խ���(������)������(x1:1~128,y1:1~8)
// Description    : ��ʾBMPλͼ
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





//��ʾ����
void show_UI(void)
{
	
	//������ʾ���н���
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
		INTERFACE_Statment();//״̬����ʾ�˵�
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
	OLED_ShowCN(32, 0, 5);			//��
	OLED_ShowCN(48, 0, 7);			//��
	OLED_ShowCN(64, 0, 9);			//��
	OLED_ShowCN(80, 0, 10);			//��
	
	
	OLED_ShowStr(16, 2, table1, 2);  //2.
	OLED_ShowCN(32, 2, 3);			//ת
	OLED_ShowCN(48, 2, 4);			//��
	OLED_ShowCN(64, 2, 9);			//��
	OLED_ShowCN(80, 2, 10);			//��
	
	
	OLED_ShowStr(16, 4, table2, 2);  //3.
	OLED_ShowCN(32, 4, 15);			//һ
	OLED_ShowCN(48, 4, 16);			//��
	OLED_ShowCN(64, 4, 9);			//��
	OLED_ShowCN(80, 4, 10);			//��
	
	
	OLED_ShowCN(0, 6, 11);			//ȷ
	OLED_ShowCN(16, 6, 12);			//��
	
	OLED_ShowCN(96, 6, 13);			//��
	OLED_ShowCN(112, 6, 14);		//��
}


void show_current_test(void)
{

	//��ʾ��ȡģ����趨�õĺ���
	unsigned char table0[20] = ":xx  ";
	unsigned char table1[20] = ":xx  ";
	unsigned char table5[20] = ":       ";
	
	
	sprintf((char *)table0,":%d mA", 123);
	sprintf((char *)table1,":%d mA", 456);
	

	OLED_ShowCN(32, 0, 5);			//��
	OLED_ShowCN(48, 0, 7);			//��
	OLED_ShowCN(64, 0, 9);			//��
	OLED_ShowCN(80, 0, 10);			//��
	
	
	OLED_ShowCN(0, 2, 0);		     //��
	OLED_ShowCN(16, 2, 2);			 //��
	OLED_ShowCN(32, 2, 5);		     //��
	OLED_ShowCN(48, 2, 7);			 //��
	
	
	OLED_ShowCN(0, 4, 1);		     //��
	OLED_ShowCN(16, 4, 2);			 //��
	OLED_ShowCN(32, 4, 5);		     //��
	OLED_ShowCN(48, 4, 7);			 //��
	
	
	OLED_ShowCN(0, 6, 9);			//��
	OLED_ShowCN(16, 6, 10);			//��
	
	
	OLED_ShowCN(96, 6, 13);			//��
	OLED_ShowCN(112, 6, 14);		//��
	
	if(time >= 500)
	{
		time = 0;
		//������
		OLED_ShowStr(64, 2, table5, 2); 
		OLED_ShowStr(64, 4, table5, 2);
		OLED_ShowStr(64, 2, table0, 2);  //��ʾ��Ӧ����ֵ
		OLED_ShowStr(64, 4, table1, 2);  //��ʾ��Ӧ����ֵ
	}
}

void show_rotation_test(void)
{
	//��ʾ��ȡģ����趨�õĺ���
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
	
	
	OLED_ShowCN(32, 0, 3);			//ת
	OLED_ShowCN(48, 0, 4);			//��
	OLED_ShowCN(64, 0, 9);			//��
	OLED_ShowCN(80, 0, 10);			//��
	
	
	OLED_ShowCN(0, 2, 0);		     //��
	OLED_ShowCN(16, 2, 2);			 //��
	OLED_ShowCN(32, 2, 3);		     //ת
	OLED_ShowCN(48, 2, 4);			 //��

	
	OLED_ShowCN(0, 4, 1);		     //��
	OLED_ShowCN(16, 4, 2);			 //��
	OLED_ShowCN(32, 4, 3);		     //ת
	OLED_ShowCN(48, 4, 4);			 //��
	
	
	OLED_ShowCN(0, 6, 9);			//��
	OLED_ShowCN(16, 6, 10);			//��
	
	
	OLED_ShowCN(96, 6, 13);			//��
	OLED_ShowCN(112, 6, 14);		//��
	
	if(time >= 500)
	{
		time = 0;
		//������
		OLED_ShowStr(64, 2, table5, 2); 
		OLED_ShowStr(64, 4, table5, 2);
		
		OLED_ShowStr(64, 2, table0, 2);  //��ʾ��Ӧ����ֵ
		OLED_ShowStr(64, 4, table1, 2);  //��ʾ��Ӧ����ֵ
	}
}

void show_all_test(void)
{


	//��ʾ��ȡģ����趨�õĺ���
	unsigned char table[20]  = ":xx  ";
	unsigned char table0[20] = ":xx  ";
	unsigned char table1[20] = ":xx  ";
	unsigned char table2[20] = ":xx  ";
	
	

	 
	

	
		
		OLED_ShowCN(0, 0, 3);//ת
		OLED_ShowCN(16, 0, 6);//��
//		OLED_ShowCN(97, 0, 3);//ת
//		OLED_ShowCN(113, 0, 8);//��
				
		OLED_ShowCN(0, 2, 0);		     //��
		OLED_ShowCN(16, 2, 2);			 //��
//		OLED_ShowCN(32, 4, 3);		     //ת
//		OLED_ShowCN(48, 4, 4);			 //��

		OLED_ShowCN(0, 4, 1);		     //��
		OLED_ShowCN(16, 4, 2);			 //��
//		OLED_ShowCN(32, 2, 3);		     //ת
//		OLED_ShowCN(48, 2, 4);			 //��
		
		OLED_ShowCN(0, 6, 5);           //��
		OLED_ShowCN(16, 6, 7);			 //��
		
		OLED_ShowCN(96, 6, 13);			//��
		OLED_ShowCN(112, 6, 14);		//��
		
		
	if(time >= 500)
	{
		time = 0;

		//������

		
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





