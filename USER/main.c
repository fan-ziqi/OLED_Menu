#include "stm32f10x.h"
#include "delay.h"
#include "usart.h"
#include "sys.h"
#include "timer.h"
#include "key.h"
#include "string.h"
#include "oled_iic.h"
#include "menu.h"
#include <stdio.h>


extern int receive_data[10];
extern __IO u16 ADC_ConvertedValue[3];


int key_3x3_flag=0;
u8 KEY=0;


int main (void)
{

	//4X4�������
	
	KEY_4X4_init();
	
	//����
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(115200);	 //���ڳ�ʼ��Ϊ115200
	delay_init();
	
	OLED_Init();
	
	TIM3_init(1000-1,72-1);
	OLED_CLS();//����
	
	//��ʾ����ͼƬ
	show_bmp(1);
	for(int i=0;i<=5;i++)
	{
		delay_ms(500);
	}
	OLED_CLS();//����
	
	
	while(1)
	{	
		
		if(key_3x3_flag==1)
		{
			printf("%d\r\n",KEY);
			key_3x3_flag=0;
		}
		
		Get_Serial_Data();
		All_Key_Task();//������ְ����¼�
		Mision_1ms();//1msɨ������
		show_UI();//OLED��ʾ
	}
}







