//#include "key_scan.h"
//#include "key.h"
//#include "usart.h"	  



//extern int receive_data[10];


////1.ʶ�𳤰�����˼·������ʹ��ϵͳ��ʱ����ʱ��Ȼ����ϵͳÿ��һ��ʱ��ȥɨ�谴��I/O��״̬����ɨ�赽��������I/O��״̬�����趨����ʱ��ķ�ֵ�����ж���ΰ�������Ϊ��������������

////2.ʶ�𵥻�����˼·����ϵͳɨ�谴�����µ�I/O��ʱ��С�������趨�ĳ�����ֵ����ʱ�Ϳ��ܳ���������������1.�����ǵ��������2.������˫��������������˵���1��������������ʱ���ǿ��Լ�ⰴ�����º󣬰��������ʱ�䵽�´ΰ������µ�ʱ���������������µ����´ΰ������µ�ʱ�䳬��ĳ��ֵ���������ж���β���Ϊ��������������

////3.ʶ��˫������˼·�������˵�����1�������˵���2,��˫�������������Ǽ�ⰴ�����������һ��ʱ�䷧ֵ�ڣ��ּ�⵽����I/O���е�ƽ�仯���������ж���β���Ϊ��˫��������


//u16 keyup_flag = 1; u16 keydown_flag = 0;//���������־   �������±�־ 
//u16 keyup_cnt = 0; u16 keydown_cnt = 0;//������������ֵ   �������º����ֵ
//u16 key_short_flag = 0,key_double_flag = 0, key_long_flag = 0;//�̰��ͳ�����־
//u16 key_double_step1 = 0,key_double_step2 = 0;
//u8 led_state = 0;//LED�¼�
//u16 key_idle_flag = 0;//�ǿ���
//u16 key_long_short_flag = 0;
//u16 keyup_cnt2 = 0;


//u8 key1_press = 0;//PA11  CCW  key1
//u8 key2_press = 0;//PA12  CW   key2
//u8 key3_press = 0;//PB4  stop  key4
//u8 key4_press = 0;//PB5  start  key4
//u8 key5_press = 0;
//u8 key6_press = 0;//PB8  I_mA => 0  key6
//u8 key7_press = 0;//PB9  ADD  key7
//u8 key8_press = 0;//PA0  rotation_speed  key8
//u8 key9_press = 0;//PA1  current  key9
//u8 key10_press = 0;
//u8 key11_press = 0;
//u8 key12_press = 0;
//u8 key13_press = 0;
//u8 key14_press = 0;
//u8 key15_press = 0;
//u8 key16_press = 0;

//u16 key1up_flag = 1; u16 key1down_flag = 0;//���������־   �������±�־ 
//u16 key1up_cnt = 0; u16 key1down_cnt = 0;//������������ֵ   �������º����ֵ
//u16 key1_short_flag = 0;//�̰���־
//u16 key1_idle_flag = 0;//�ǿ���
//u16 key1up_cnt2 = 0;

//u16 key2up_flag = 1; u16 key2down_flag = 0;//���������־   �������±�־ 
//u16 key2up_cnt = 0; u16 key2down_cnt = 0;//������������ֵ   �������º����ֵ
//u16 key2_short_flag = 0;//�̰���־
//u16 key2_idle_flag = 0;//�ǿ���
//u16 key2up_cnt2 = 0;

//u16 key3up_flag = 1; u16 key3down_flag = 0;//���������־   �������±�־ 
//u16 key3up_cnt = 0; u16 key3down_cnt = 0;//������������ֵ   �������º����ֵ
//u16 key3_short_flag = 0;//�̰���־
//u16 key3_idle_flag = 0;//�ǿ���
//u16 key3up_cnt2 = 0;

//u16 key4up_flag = 1; u16 key4down_flag = 0;//���������־   �������±�־ 
//u16 key4up_cnt = 0; u16 key4down_cnt = 0;//������������ֵ   �������º����ֵ
//u16 key4_short_flag = 0;//�̰���־
//u16 key4_idle_flag = 0;//�ǿ���
//u16 key4up_cnt2 = 0;

//u16 key6up_flag = 1; u16 key6down_flag = 0;//���������־   �������±�־ 
//u16 key6up_cnt = 0; u16 key6down_cnt = 0;//������������ֵ   �������º����ֵ
//u16 key6_short_flag = 0;//�̰���־
//u16 key6_idle_flag = 0;//�ǿ���
//u16 key6up_cnt2 = 0;

//u16 key7up_flag = 1; u16 key7down_flag = 0;//���������־   �������±�־ 
//u16 key7up_cnt = 0; u16 key7down_cnt = 0;//������������ֵ   �������º����ֵ
//u16 key7_short_flag = 0;//�̰���־
//u16 key7_idle_flag = 0;//�ǿ���
//u16 key7up_cnt2 = 0;

//u16 key8up_flag = 1; u16 key8down_flag = 0;//���������־   �������±�־ 
//u16 key8up_cnt = 0; u16 key8down_cnt = 0;//������������ֵ   �������º����ֵ
//u16 key8_short_flag = 0;//�̰���־
//u16 key8_idle_flag = 0;//�ǿ���
//u16 key8up_cnt2 = 0;

//u16 key9up_flag = 1; u16 key9down_flag = 0;//���������־   �������±�־ 
//u16 key9up_cnt = 0; u16 key9down_cnt = 0;//������������ֵ   �������º����ֵ
//u16 key9_short_flag = 0;//�̰���־
//u16 key9_idle_flag = 0;//�ǿ���
//u16 key9up_cnt2 = 0;



//void key_init()
//{
//	//ʹ��ʱ��APB2��GPIOB GPIOA 
//	RCC->APB2ENR|=1<<3;//PB
//	RCC->APB2ENR|=1<<2;//PA
//	
//	//PA0 ����/��������
//	GPIOA->CRL &=0XFFFFFFF0; //�Ȱ���Ҫ���������߼���ƽ����������
//	GPIOA->CRL |=0X00000008;   	 
//    GPIOA->BSRR |= (1<<0);
//	
//	//PA1 ����/��������
//	GPIOA->CRL &=0XFFFFFF0F; //�Ȱ���Ҫ���������߼���ƽ����������
//	GPIOA->CRL |=0X00000080;   	 
//    GPIOA->BSRR |= (1<<1);
//	
//	
//	//PA11 ����/��������
//	GPIOA->CRH&=0XFFFF0FFF; 
//	GPIOA->CRH|=0X00008000;   	 
//    GPIOA->BSRR |= (1<<11);
//	
//	//PA12 ����/��������
//	GPIOA->CRH&=0XFFF0FFFF; 
//	GPIOA->CRH|=0X00080000;   	 
//    GPIOA->BSRR |= (1<<12);
//	
//	
//	
//	//PB4 ����/��������
//	GPIOB->CRL&=0XFFF0FFFF; //�Ȱ���Ҫ���������߼���ƽ����������
//	GPIOB->CRL|=0X00080000;   	 
//    GPIOB->BSRR |= (1<<4);
//	
//	//PB5 ����/��������
//	GPIOB->CRL&=0XFF0FFFFF; //�Ȱ���Ҫ���������߼���ƽ����������
//	GPIOB->CRL|=0X00800000;   	 
//    GPIOB->BSRR |= (1<<5);
//	
//	//PB8 ����/��������
//	GPIOB->CRH&=0XFFFFFFF0; //�Ȱ���Ҫ���������߼���ƽ����������
//	GPIOB->CRH|=0X00000008;   	 
//    GPIOB->BSRR |= (1<<8);
//	
//	//PB9 ����/��������
//	GPIOB->CRH&=0XFFFFFF0F; //�Ȱ���Ҫ���������߼���ƽ����������
//	GPIOB->CRH|=0X00000080;   	 
//    GPIOB->BSRR |= (1<<9);
//	
//	
//	
//	 
//}
//extern int key_3x3_flag;
//extern u8 KEY;
//void key_scan(void)
//{
//		KEY = KEY_4X4_Scan(0);
////		printf("%d\r\n",KEY);
//		switch(KEY)
//		{
//			case 1:key_3x3_flag=1;
//				key1_press=1;
//				break;
//			case 2:key_3x3_flag=1;
//				key2_press=1;
//				break;
//			case 3:key_3x3_flag=1;
//				key3_press=1;
//				break;
//			case 4:key_3x3_flag=1;
//				key4_press=1;
//				break;
//			case 5:key_3x3_flag=1;
//				key5_press=1;
//				break;
//			case 6:key_3x3_flag=1;
//				key6_press=1;
//				break;
//			case 7:key_3x3_flag=1;
//				key7_press=1;
//				break;
//			case 8:key_3x3_flag=1;
//				key8_press=1;
//				break;
//			case 9:key_3x3_flag=1;
//				key9_press=1;
//				break;
//			case 10:key_3x3_flag=1;
//				key10_press=1;
//				break;
//			case 11:key_3x3_flag=1;
//				key11_press=1;
//				break;
//			case 12:key_3x3_flag=1;
//				key12_press=1;
//				break;
//			case 13:key_3x3_flag=1;
//				key13_press=1;
//				break;
//			case 14:key_3x3_flag=1;
//				key14_press=1;
//				break;
//			case 15:key_3x3_flag=1;
//				key15_press=1;
//				break;
//			case 16:key_3x3_flag=1;
//				key16_press=1;
//				break;
//			
//			default:key_3x3_flag=0;
//				break;
//		}
//}

//void key1_scan(void)//CCW
//{
//	//��������������
//		 if(0 == ( GPIOA->IDR & (1<<11)))
//		{
//			  key1down_cnt++;
//			 if(key1down_cnt >= 10)//ȥ��ʱ��
//			{
//				key1down_flag = 1;
//				key1up_flag = 0;//̧������
//				key1up_cnt = 0;
//				
//				if(key1_idle_flag)
//				{
//					key1_idle_flag = 0;
//				}
//			}
//		}
//		 //��������ɿ�
//		else
//		{
//			if(key1_idle_flag)
//				return;
//			key1up_cnt ++;
//			
//			//������  ***************************************
//			if(key1up_cnt >= 50)
//			{
//				key1up_flag = 1;
//				key1down_flag = 0;
//				key1down_cnt = 0;
//			}
//			
//			//����ʱ�����100ms���ж�Ϊ����
//			if(key1down_cnt >= 50) 
//			{
//				key1_short_flag = 1;//****************  �̰���������
//				key1down_flag = 0;
//				key1down_cnt = 0;
//			}
//			
//			else  //����ʱ��С��50ms������
//			{
//				key1up_cnt = 0;//�����������
//				key1up_flag = 0;
//				key1down_cnt = 0;//���㰴�¶����Ĵ���
//				key1_short_flag = 0;
//				key1down_flag = 0;//���±�־����
//				key1_idle_flag = 1;//���̧�����1sû���������ж�Ϊ����״̬
//			}		
//		}
//	if(key1_short_flag)
//	{
//		key1_short_flag = 0;
//		key1_press = 1;
//	}
//}


//void key2_scan(void)//CW
//{
//	//��������������
//		 if(0 == ( GPIOA->IDR & (1<<12)))
//		{
//			  key2down_cnt++;
//			 if(key2down_cnt >= 10)//ȥ��ʱ��
//			{
//				key2down_flag = 1;
//				key2up_flag = 0;//̧������
//				key2up_cnt = 0;
//				
//				if(key2_idle_flag)
//				{
//					key2_idle_flag = 0;
//				}
//			}
//		}
//		 //��������ɿ�
//		else
//		{
//			if(key2_idle_flag)
//				return;
//			key2up_cnt ++;
//			
//			//������  ***************************************
//			if(key2up_cnt >= 50)
//			{
//				key2up_flag = 1;
//				key2down_flag = 0;
//				key2down_cnt = 0;
//			}
//			
//			//����ʱ�����100ms���ж�Ϊ����
//			if(key2down_cnt >= 50) 
//			{
//				key2_short_flag = 1;//****************  �̰���������
//				key2down_flag = 0;
//				key2down_cnt = 0;
//			}
//			
//			else  //����ʱ��С��50ms������
//			{
//				key2up_cnt = 0;//�����������
//				key2up_flag = 0;
//				key2down_cnt = 0;//���㰴�¶����Ĵ���
//				key2_short_flag = 0;
//				key2down_flag = 0;//���±�־����
//				key2_idle_flag = 1;//���̧�����1sû���������ж�Ϊ����״̬
//			}		
//		}
//	if(key2_short_flag)
//	{
//		key2_short_flag = 0;
//		key2_press = 1;
//	}
//}

//void key3_scan(void)//key3��Ϊ stop
//{
//	//��������������
//		 if(0 == ( GPIOB->IDR & (1<<4)))
//		{
//			  key3down_cnt++;
//			 if(key3down_cnt >= 10)//ȥ��ʱ��
//			{
//				key3down_flag = 1;
//				key3up_flag = 0;//̧������
//				key3up_cnt = 0;
//				
//				if(key3_idle_flag)
//				{
//					key3_idle_flag = 0;
//				}
//			}
//		}
//		 //��������ɿ�
//		else
//		{
//			if(key3_idle_flag)
//				return;
//			key3up_cnt ++;
//			
//			//������  ***************************************
//			if(key3up_cnt >= 50)
//			{
//				key3up_flag = 1;
//				key3down_flag = 0;
//				key3down_cnt = 0;
//			}
//			
//			//����ʱ�����100ms���ж�Ϊ����
//			if(key3down_cnt >= 50) 
//			{
//				key3_short_flag = 1;//****************  �̰���������
//				key3down_flag = 0;
//				key3down_cnt = 0;
//			}
//			
//			else  //����ʱ��С��50ms������
//			{
//				key3up_cnt = 0;//�����������
//				key3up_flag = 0;
//				key3down_cnt = 0;//���㰴�¶����Ĵ���
//				key3_short_flag = 0;
//				key3down_flag = 0;//���±�־����
//				key3_idle_flag = 1;//���̧�����1sû���������ж�Ϊ����״̬
//			}		
//		}
//	if(key3_short_flag)
//	{
//		key3_short_flag = 0;
//		key3_press = 1;
////		LED1 = 1;
//	}
//}


//void key4_scan(void)//key4��Ϊ start
//{
//	//��������������
//		 if(0 == ( GPIOB->IDR & (1<<5)))
//		{
//			 key4down_cnt++;
//			 if(key4down_cnt >= 10)//ȥ��ʱ��
//			{
//				key4down_flag = 1;
//				key4_idle_flag = 0;//�ǿ���
//				key4up_flag = 0;//̧������
//				key4up_cnt = 0;
//			}
//		}
//		//��������ɿ�
//		else
//		{
//			if(key4_idle_flag)
//				return;
//			key4up_cnt ++;
//			
//			if(key4up_cnt >= 50)
//			{
//				key4up_flag = 1;
//				key4down_flag = 0;
//				key4down_cnt = 0;
//			}
//			
//			//����ʱ�����100ms�����ж�Ϊ����
//			if(key4down_cnt >= 50)
//			{
//				key4_short_flag = 1;//****************  �̰���������
//				key4down_cnt = 0;	
//				key4down_flag = 0;
//			}
//			else
//			{
//				key4up_cnt = 0;//�����������
//				key4up_flag = 0;
//				key4_idle_flag = 1;//���̧�����1sû���������ж�Ϊ����״̬
//				key4down_cnt = 0;//���㰴�¶����Ĵ���
//				key4_short_flag = 0;
//				key4down_flag = 0;//���±�־����
//			}
//						
//		}
//		
//	if(key4_short_flag)
//	{
//		key4_short_flag = 0;
//		key4_press = 1;
//	}
//}


//void key6_scan(void)//key6��Ϊ ��������
//{
//	//��������������
//		 if(0 == ( GPIOB->IDR & (1<<8)))
//		{
//			 key6down_cnt++;
//			 if(key6down_cnt >= 10)//ȥ��ʱ��
//			{
//				key6down_flag = 1;
//				key6_idle_flag = 0;//�ǿ���
//				key6up_flag = 0;//̧������
//				key6up_cnt = 0;
//			}
//		}
//		//��������ɿ�
//		else
//		{
//			if(key6_idle_flag)
//				return;
//			key6up_cnt ++;
//			
//			if(key6up_cnt >= 50)
//			{
//				key6up_flag = 1;
//				key6down_flag = 0;
//				key6down_cnt = 0;
//			}
//			
//			//����ʱ�����100ms�����ж�Ϊ����
//			if(key6down_cnt >= 50)
//			{
//				key6_short_flag = 1;//****************  �̰���������
//				key6down_cnt = 0;	
//				key6down_flag = 0;
//			}
//			else
//			{
//				key6up_cnt = 0;//�����������
//				key6up_flag = 0;
//				key6_idle_flag = 1;//���̧�����1sû���������ж�Ϊ����״̬
//				key6down_cnt = 0;//���㰴�¶����Ĵ���
//				key6_short_flag = 0;
//				key6down_flag = 0;//���±�־����
//			}
//						
//		}
//		
//	if(key6_short_flag)
//	{
//		key6_short_flag = 0;
//		key6_press = 1;
//	}
//}


//void key7_scan(void)//key7��Ϊ ADD
//{
//	//��������������
//		 if(0 == ( GPIOB->IDR & (1<<9)))
//		{
//			  key7down_cnt++;
//			 if(key7down_cnt >= 10)//ȥ��ʱ��
//			{
//				key7down_flag = 1;
//				key7up_flag = 0;//̧������
//				key7up_cnt = 0;
//				
//				if(key7_idle_flag)
//				{
//					key7_idle_flag = 0;
//				}
//			}
//		}
//		 //��������ɿ�
//		else
//		{
//			if(key7_idle_flag)
//				return;
//			key7up_cnt ++;
//			
//			//������  ***************************************
//			if(key7up_cnt >= 50)
//			{
//				key7up_flag = 1;
//				key7down_flag = 0;
//				key7down_cnt = 0;
//			}
//			
//			//����ʱ�����100ms���ж�Ϊ����
//			if(key7down_cnt >= 50) 
//			{
//				key7_short_flag = 1;//****************  �̰���������
//				key7down_flag = 0;
//				key7down_cnt = 0;
//			}
//			
//			else  //����ʱ��С��50ms������
//			{
//				key7up_cnt = 0;//�����������
//				key7up_flag = 0;
//				key7down_cnt = 0;//���㰴�¶����Ĵ���
//				key7_short_flag = 0;
//				key7down_flag = 0;//���±�־����
//				key7_idle_flag = 1;//���̧�����1sû���������ж�Ϊ����״̬
//			}		
//		}
//	if(key7_short_flag)
//	{
//		key7_short_flag = 0;
//		key7_press = 1;
//	}
//}

//void key8_scan(void)//key8��Ϊ ת��
//{
//	//��������������
//		 if(0 == ( GPIOA->IDR & (1<<0)))
//		{
//			  key8down_cnt++;
//			 if(key8down_cnt >= 10)//ȥ��ʱ��
//			{
//				key8down_flag = 1;
//				key8up_flag = 0;//̧������
//				key8up_cnt = 0;
//				
//				if(key8_idle_flag)
//				{
//					key8_idle_flag = 0;
//				}
//			}
//		}
//		 //��������ɿ�
//		else
//		{
//			if(key8_idle_flag)
//				return;
//			key8up_cnt ++;
//			
//			//������  ***************************************
//			if(key8up_cnt >= 50)
//			{
//				key8up_flag = 1;
//				key8down_flag = 0;
//				key8down_cnt = 0;
//			}
//			
//			
//			//����ʱ�����50ms���ж�Ϊ����
//			if(key8down_cnt >= 50) 
//			{
//				key8_short_flag = 1;//****************  �̰���������
//				key8down_flag = 0;
//				key8down_cnt = 0;
//			}
//			else  //����ʱ��С��50ms������
//			{
//				key8up_cnt = 0;//�����������
//				key8up_flag = 0;
//				key8down_cnt = 0;//���㰴�¶����Ĵ���
//				key8_short_flag = 0;
//				key8down_flag = 0;//���±�־����
//				key8_idle_flag = 1;//���̧�����1sû���������ж�Ϊ����״̬
//			}		
//		}
//	if(key8_short_flag)
//	{
//		key8_short_flag = 0;
//		key8_press = 1;
//	}
//}


//void key9_scan(void)//key9��Ϊ ����
//{
//	//��������������
//		if(0 == ( GPIOA->IDR & (1<<1)))
//		{
//			  key9down_cnt++;
//			 if(key9down_cnt >= 10)//ȥ��ʱ��
//			{
//				key9down_flag = 1;
//				key9up_flag = 0;//̧������
//				key9up_cnt = 0;
//				
//				if(key9_idle_flag)
//				{
//					key9_idle_flag = 0;
//				}
//			}
//		}
//		 //��������ɿ�
//		else
//		{
//			if(key9_idle_flag)
//				return;
//			key9up_cnt ++;
//			
//			//������  ***************************************
//			if(key9up_cnt >= 50)
//			{
//				key9up_flag = 1;
//				key9down_flag = 0;
//				key9down_cnt = 0;
//			}
//			
//			//����ʱ�����100ms���ж�Ϊ����
//			if(key9down_cnt >= 50) 
//			{
//				key9_short_flag = 1;//****************  �̰���������
//				key9down_flag = 0;
//				key9down_cnt = 0;
//			}
//			
//			else  //����ʱ��С��50ms������
//			{
//				key9up_cnt = 0;//�����������
//				key9up_flag = 0;
//				key9down_cnt = 0;//���㰴�¶����Ĵ���
//				key9_short_flag = 0;
//				key9down_flag = 0;//���±�־����
//				key9_idle_flag = 1;//���̧�����1sû���������ж�Ϊ����״̬
//			}		
//		}
//	if(key9_short_flag)
//	{
//		key9_short_flag = 0;
//		key9_press = 1;
//	}
//}

//void deal_key1_press(void)
//{
//	if(key1_press)
//		{
//			key1_press = 0;
//			Menu_Key_Enter();
//		}
//}

//void deal_key2_press(void)
//{
//	if(key2_press)
//		{
//			key2_press = 0;
//			Menu_Key_Up();
//		}
//}

//void deal_key3_press(void)
//{
//	if(key3_press)
//		{
//			key3_press = 0;
//			Menu_Key_Return();
//		}
//}


//void deal_key4_press(void)
//{
//	if(key4_press)
//		{
//			key4_press = 0;

//		}
//}

//void deal_key5_press(void)
//{
//	if(key5_press)
//		{
//			key5_press = 0;

//		}
//}


//void deal_key6_press(void)
//{
//	if(key6_press==1)
//		{
//			key6_press = 0;
//			
//			Menu_Key_Down();
//		}
//}


//void deal_key7_press(void)
//{
//	if(key7_press==1)
//		{
//			key7_press = 0;
//			
//		}
//}



//void deal_key8_press(void)
//{
//	if(key8_press==1)
//		{
//			key8_press = 0;

//		}
//}


//void deal_key9_press(void)
//{
//	if(key9_press==1)
//		{
//			key9_press = 0;
//			
//		}
//}

//void deal_key10_press(void)
//{
//	if(key10_press)
//		{
//			key10_press = 0;
//			
//		}
//}

//void deal_key11_press(void)
//{
//	if(key11_press)
//		{
//			key11_press = 0;
//			
//		}
//}

//void deal_key12_press(void)
//{
//	if(key12_press)
//		{
//			key12_press = 0;
//			
//		}
//}

//void deal_key13_press(void)
//{
//	if(key13_press)
//		{
//			key13_press = 0;

//		}
//}


//void deal_key14_press(void)
//{
//	if(key14_press)
//		{
//			key14_press = 0;

//		}
//}

//void deal_key15_press(void)
//{
//	if(key15_press)
//		{
//			key15_press = 0;

//		}
//}


//void deal_key16_press(void)
//{
//	if(key16_press==1)
//		{
//			key16_press = 0;
//			
//		}
//}









//void deal_allkey_press(void)
//{
//	deal_key1_press();
//	deal_key2_press();
//	deal_key3_press();
//	deal_key4_press();
//	deal_key5_press();
//	deal_key6_press();
//	deal_key7_press();
//	deal_key8_press();
//	deal_key9_press();
//	deal_key10_press();
//	deal_key11_press();
//	deal_key12_press();
//	deal_key13_press();
//	deal_key14_press();
//	deal_key15_press();
//	deal_key16_press();
//}

