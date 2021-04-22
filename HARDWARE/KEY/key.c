/************************************************************
  �����PA0123
  ������PA4567

  1  2  3  4  
  5  6  7  8  
  9  10 11 12  
  13 14 15 16  

  �ް������·���0
*************************************************************/

#include "key.h"
#include "delay.h"
#include "menu.h"

//extern int receive_data[10];

u8 key1_press = 0;
u8 key2_press = 0;
u8 key3_press = 0;
u8 key4_press = 0;
u8 key5_press = 0;
u8 key6_press = 0;
u8 key7_press = 0;
u8 key8_press = 0;
u8 key9_press = 0;
u8 key10_press = 0;
u8 key11_press = 0;
u8 key12_press = 0;
u8 key13_press = 0;
u8 key14_press = 0;
u8 key15_press = 0;
u8 key16_press = 0;



//����������ų�ʼ��         
void delayMs(u8 t)
{
	while(t--)
	{
		delay_ms(20);
	}
}
void KEY_4X4_init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//ʹ��PORTB,PORTD��PORTGʱ��
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3;                        //�У����
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;                       //�У�����
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;   //����ģʽ
	
	GPIO_Init(GPIOA,&GPIO_InitStructure);
}




//mode:0,��֧��������;1,֧��������;
u8 KEY_4X4_Scan(u8 mode)
{
	static u8 key1_up=1;//�������ɿ���־
	static u8 key2_up=1;//�������ɿ���־
	static u8 key3_up=1;//�������ɿ���־
	static u8 key4_up=1;//�������ɿ���־
	static u8 key5_up=1;//�������ɿ���־
	static u8 key6_up=1;//�������ɿ���־
	static u8 key7_up=1;//�������ɿ���־
	static u8 key8_up=1;//�������ɿ���־
	static u8 key9_up=1;//�������ɿ���־
	static u8 key10_up=1;//�������ɿ���־
	static u8 key11_up=1;//�������ɿ���־
	static u8 key12_up=1;//�������ɿ���־
	static u8 key13_up=1;//�������ɿ���־
	static u8 key14_up=1;//�������ɿ���־
	static u8 key15_up=1;//�������ɿ���־
	static u8 key16_up=1;//�������ɿ���־
	
	if(mode)
	{
			key1_up=1;
			key2_up=1;
			key3_up=1;
			key4_up=1;
			key5_up=1;
			key6_up=1;
			key7_up=1;
			key8_up=1;
			key9_up=1;
			key10_up=1;
			key11_up=1;
			key12_up=1;
			key13_up=1;
			key14_up=1;
			key15_up=1;
			key16_up=1;	
	}
	
    //��һ��
	Hang_00_L;//�ѵ�һ������͵�ƽ
	Hang_01_H;
	Hang_02_H;
	Hang_03_H;
		if(key2_up&&Lie_00_V==0)
		{    
		   delayMs(jpys); //��ʱ20�룬�������
			
		   key2_up=0;
		   if(Lie_00_V==0) //�����һ���ǵ͵�ƽ��˵���м������£����û��ֱ���˳�if���
		   {
			   return 1;
		   }
		}else if(Lie_00_V==1)key2_up=1;
	 
		if(key3_up&&Lie_01_V==0)//����ڶ����ǵ͵�ƽ��
		{    
		   delayMs(jpys);//��ʱ20�룬�������
		   key3_up=0;
		   if(Lie_01_V==0)//����ڶ����ǵ͵�ƽ��˵���м������£����û��ֱ���˳�if���
		   {
			  return 2; 
		   }
		}else if(Lie_01_V==1)key3_up=1;
	 
		if(key4_up&&Lie_02_V==0)
		{    
		   delayMs(jpys);
		   key4_up=0;
		   if(Lie_02_V==0)
		   {
			  return 3;
		   }
		}else if(Lie_02_V==1)key4_up=1;
	 
		if(key11_up&&Lie_03_V==0)//����������ǵ͵�ƽ
		{    
		   delayMs(jpys);
		   key11_up=0;
		   if(Lie_03_V==0)//����������ǵ͵�ƽ��˵���м������£����û��ֱ���˳�if���
		   {
			  return 4;
		   }
		}else if(Lie_03_V==1)key11_up=1;
 
	//�ڶ���
	Hang_00_H;
	Hang_01_L;//�ѵڶ�������
	Hang_02_H;
	Hang_03_H;
		if(key5_up&&Lie_00_V==0)//�����һ���ǵ͵�ƽ
		{    
		   delayMs(jpys);
		   key5_up=0;
		   if(Lie_00_V==0)//˵���м������£����û��ֱ���˳�if���
		   {
				return 5;
		   }
		}else if(Lie_00_V==1)key5_up=1;
		 
		if(key6_up&&Lie_01_V==0)
		{    
		   delayMs(jpys);
		   key6_up=0;
		   if(Lie_01_V==0)
		   {
		       return 6;
		   }
		}else if(Lie_01_V==1)key6_up=1;
		 
		if(key7_up&&Lie_02_V==0)
		{    
		   delayMs(jpys);
		   key7_up=0;
		   if(Lie_02_V==0)
		   {
			   return 7;
		   }
		}else if(Lie_02_V==1)key7_up=1;
		 
		if(key12_up&&Lie_03_V==0)
		{    
		   delayMs(jpys);
		   key12_up=0;
		   if(Lie_03_V==0)
		   {
		       return 8;  
		   }
		}else if(Lie_03_V==1)key12_up=1;
 
	//������
	Hang_00_H;
	Hang_01_H;
	Hang_02_L;//�ѵ������õ�
	Hang_03_H;
		if(key8_up&&Lie_00_V==0) //�����һ���ǵ͵�ƽ
		{    
		   delayMs(jpys);//��ʱ20��
		   key8_up=0;
		   if(Lie_00_V==0)//˵���м������£����û��ֱ���˳�if���
		   {
			   return 9;
		   }
		}else if(Lie_00_V==1)key8_up=1;
		 
		if(key9_up&&Lie_01_V==0)
		{    
		   delayMs(jpys);
		   key9_up=0;
		   if(Lie_01_V==0)
		   {
		       return 10;
		   }
		}else if(Lie_01_V==1)key9_up=1;
		 
		if(key10_up&&Lie_02_V==0)
		{    
		   delayMs(jpys);
		   key10_up=0;
		   if(Lie_02_V==0)
		   {
		       return 11;
		   }
		}else if(Lie_02_V==1)key10_up=1;
		 
		if(key13_up&&Lie_03_V==0)
		{    
		   delayMs(jpys);
		   key13_up=0;
		   if(Lie_03_V==0)
		   {
		       return 12; 
		   }
		}else if(Lie_03_V==1)key13_up=1;
 
	//������
	Hang_00_H;
	Hang_01_H;
	Hang_02_H;
	Hang_03_L;//�ѵ������õ�
		if(key15_up&&Lie_00_V==0)//�����һ���ǵ͵�ƽ
		{    
		   delayMs(jpys);
		   key15_up=0;
		   if(Lie_00_V==0)//˵���м������£����û��ֱ���˳�if���
		   {
		       return 13;
		   }
		}else if(Lie_00_V==1)key15_up=1;
		 
		if(key1_up&&Lie_01_V==0)
		{    
		   delayMs(jpys);
		   key1_up=0;
		   if(Lie_01_V==0)
		   {
		       return 14;
		   }
		}else if(Lie_01_V==1)key1_up=1;
		 
		if(key16_up&&Lie_02_V==0)//����������ǵ͵�ƽ
		{    
		   delayMs(jpys);
		   key16_up=0;
		   if(Lie_02_V==0)//˵���м������£����û��ֱ���˳�if���
		   {
		       return 15;
		   }
		}else if(Lie_02_V==1)key16_up=1;
		 
		if(key14_up&&Lie_03_V==0)
		{    
		   delayMs(jpys);
		   key14_up=0;
		   if(Lie_03_V==0)
		   {
		       return 16;
		   }
		}else if(Lie_03_V==1)key14_up=1;
		
		return 0;
}



extern int key_3x3_flag;
extern u8 KEY;
void Key_Scan(void)
{
		KEY = KEY_4X4_Scan(0);
//		printf("%d\r\n",KEY);
		switch(KEY)
		{
			case 1:key_3x3_flag=1;
				key1_press=1;
				break;
			case 2:key_3x3_flag=1;
				key2_press=1;
				break;
			case 3:key_3x3_flag=1;
				key3_press=1;
				break;
			case 4:key_3x3_flag=1;
				key4_press=1;
				break;
			case 5:key_3x3_flag=1;
				key5_press=1;
				break;
			case 6:key_3x3_flag=1;
				key6_press=1;
				break;
			case 7:key_3x3_flag=1;
				key7_press=1;
				break;
			case 8:key_3x3_flag=1;
				key8_press=1;
				break;
			case 9:key_3x3_flag=1;
				key9_press=1;
				break;
			case 10:key_3x3_flag=1;
				key10_press=1;
				break;
			case 11:key_3x3_flag=1;
				key11_press=1;
				break;
			case 12:key_3x3_flag=1;
				key12_press=1;
				break;
			case 13:key_3x3_flag=1;
				key13_press=1;
				break;
			case 14:key_3x3_flag=1;
				key14_press=1;
				break;
			case 15:key_3x3_flag=1;
				key15_press=1;
				break;
			case 16:key_3x3_flag=1;
				key16_press=1;
				break;
			
			default:key_3x3_flag=0;
				break;
		}
}


void Key1_Task(void)
{
	if(key1_press)
		{
			key1_press = 0;
			Menu_Key_Enter();
		}
}

void Key2_Task(void)
{
	if(key2_press)
		{
			key2_press = 0;
			Menu_Key_Up();
		}
}

void Key3_Task(void)
{
	if(key3_press)
		{
			key3_press = 0;
			Menu_Key_Return();
		}
}


void Key4_Task(void)
{
	if(key4_press)
		{
			key4_press = 0;

		}
}

void Key5_Task(void)
{
	if(key5_press)
		{
			key5_press = 0;

		}
}


void Key6_Task(void)
{
	if(key6_press==1)
		{
			key6_press = 0;
			
			Menu_Key_Down();
		}
}


void Key7_Task(void)
{
	if(key7_press==1)
		{
			key7_press = 0;
			
		}
}



void Key8_Task(void)
{
	if(key8_press==1)
		{
			key8_press = 0;

		}
}


void Key9_Task(void)
{
	if(key9_press==1)
		{
			key9_press = 0;
			
		}
}

void Key10_Task(void)
{
	if(key10_press)
		{
			key10_press = 0;
			
		}
}

void Key11_Task(void)
{
	if(key11_press)
		{
			key11_press = 0;
			
		}
}

void Key12_Task(void)
{
	if(key12_press)
		{
			key12_press = 0;
			
		}
}

void Key13_Task(void)
{
	if(key13_press)
		{
			key13_press = 0;

		}
}


void Key14_Task(void)
{
	if(key14_press)
		{
			key14_press = 0;

		}
}

void Key15_Task(void)
{
	if(key15_press)
		{
			key15_press = 0;

		}
}


void Key16_Task(void)
{
	if(key16_press==1)
		{
			key16_press = 0;

		}
}


void All_Key_Task(void)
{
	Key1_Task();
	Key2_Task();
	Key3_Task();
	Key4_Task();
	Key5_Task();
	Key6_Task();
	Key7_Task();
	Key8_Task();
	Key9_Task();
	Key10_Task();
	Key11_Task();
	Key12_Task();
	Key13_Task();
	Key14_Task();
	Key15_Task();
	Key16_Task();
}

