#include "timer.h"
#include "key.h"

uint16_t time = 0;
uint16_t time0 = 0;
uint16_t time1 = 0;
uint16_t time4 = 0;
uint16_t time5 = 0;
uint16_t time6 = 0;
uint16_t time7 = 0;
uint16_t time8 = 0;
uint16_t time9 = 0;
uint16_t time10 = 0;
uint16_t time11 = 0;
uint16_t time12 = 0;
uint16_t time13 = 0;
u8 flag_1ms;
//u8 flag_10ms;

//��ʱ��3�жϷ������	 
void TIM3_IRQHandler(void)
{ 		
	if(TIM3->SR&0X0001)//����ж�
	{	    
			
			time++;
			time0++;
			time1++;
			time4++;
			time5++;
			time6++;
			time7++;
			time8++;
			time9++;
			time10++;
			time11++;
			time12++;
			time13++;
			flag_1ms = 1;
//			flag_10ms = 1;//���Ҫ����ʱ������װ��ֵ��Ԥ��Ƶֵ�ж�
		
	}	
		
	TIM3->SR&=~(1<<0);//����жϱ�־λ 	    
}
//ͨ�ö�ʱ���жϳ�ʼ��
//����ʱ��ѡ��ΪAPB1��2������APB1Ϊ36M
//arr���Զ���װֵ��
//psc��ʱ��Ԥ��Ƶ��
//����ʹ�õ��Ƕ�ʱ��3!
void TIM3_init(u16 arr,u16 psc)
{
	*( volatile unsigned int *) 0x4002101C |= 1<<1;  
 	TIM3->ARR=arr;  	//�趨�������Զ���װֵ 
	TIM3->PSC=psc;  	//Ԥ��Ƶ������
	TIM3->DIER|=1<<0;   //��������ж�				
	TIM3->CR1|=0x01;    //ʹ�ܶ�ʱ��3
	MY_NVIC_Init(1,3,TIM3_IRQn,2);//��ռ1�������ȼ�3����2									 
}



void Mision_1ms(void)
{
	
	if(flag_1ms)
	{
		flag_1ms = 0;
		Key_Scan();

//		key1_scan();
//		key2_scan();
//		key3_scan();
//		key4_scan();
//		key6_scan();
//		key7_scan();
//		key8_scan();
//		key9_scan();

		static u8 cnt_10ms = 0 ;
		static u8 cnt_200ms = 0 ;
		static u16 cnt_500ms = 0;
		if(cnt_10ms ++ > 10)
		{
			cnt_10ms = 0 ;
			static u8 cnt_100ms = 0 ;
			if(cnt_100ms ++ > 10)
			{
				cnt_100ms = 0 ;
				static u8 cnt_1s = 0 ;
				if(cnt_1s ++ > 10)
				{
					cnt_1s = 0;
				}
			}
		}
		if(cnt_500ms++ >= 500)
		{
			cnt_500ms = 0;
		}
		if(cnt_200ms++ > 200)
		{
			cnt_200ms = 0;
		}
	}
}










