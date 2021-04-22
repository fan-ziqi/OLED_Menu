//#include "key_scan.h"
//#include "key.h"
//#include "usart.h"	  



//extern int receive_data[10];


////1.识别长按操作思路：我们使用系统定时器定时，然后让系统每过一段时间去扫描按键I/O口状态，当扫描到按键按下I/O口状态超过设定长按时间的阀值，就判定这次按键操作为“长按”操作；

////2.识别单击操作思路：当系统扫描按键按下的I/O口时间小于我们设定的长按阀值，这时就可能出现两种情况，情况1.可能是单击；情况2.可能是双击；首先我们来说情况1，单击操作，这时我们可以检测按键按下后，按键弹起的时间到下次按键按下的时间间隔，当按键按下弹起到下次按键按下的时间超过某个值，则我们判定这次操作为“单击”操作；

////3.识别双击操作思路：上面刚说的情况1，这次来说情况2,：双击操作，当我们检测按键按弹起后在一定时间阀值内，又检测到按键I/O口有电平变化，则我们判断这次操作为“双击”操作


//u16 keyup_flag = 1; u16 keydown_flag = 0;//按键弹起标志   按键按下标志 
//u16 keyup_cnt = 0; u16 keydown_cnt = 0;//按键弹起后计数值   按键按下后计数值
//u16 key_short_flag = 0,key_double_flag = 0, key_long_flag = 0;//短按和长按标志
//u16 key_double_step1 = 0,key_double_step2 = 0;
//u8 led_state = 0;//LED事件
//u16 key_idle_flag = 0;//非空闲
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

//u16 key1up_flag = 1; u16 key1down_flag = 0;//按键弹起标志   按键按下标志 
//u16 key1up_cnt = 0; u16 key1down_cnt = 0;//按键弹起后计数值   按键按下后计数值
//u16 key1_short_flag = 0;//短按标志
//u16 key1_idle_flag = 0;//非空闲
//u16 key1up_cnt2 = 0;

//u16 key2up_flag = 1; u16 key2down_flag = 0;//按键弹起标志   按键按下标志 
//u16 key2up_cnt = 0; u16 key2down_cnt = 0;//按键弹起后计数值   按键按下后计数值
//u16 key2_short_flag = 0;//短按标志
//u16 key2_idle_flag = 0;//非空闲
//u16 key2up_cnt2 = 0;

//u16 key3up_flag = 1; u16 key3down_flag = 0;//按键弹起标志   按键按下标志 
//u16 key3up_cnt = 0; u16 key3down_cnt = 0;//按键弹起后计数值   按键按下后计数值
//u16 key3_short_flag = 0;//短按标志
//u16 key3_idle_flag = 0;//非空闲
//u16 key3up_cnt2 = 0;

//u16 key4up_flag = 1; u16 key4down_flag = 0;//按键弹起标志   按键按下标志 
//u16 key4up_cnt = 0; u16 key4down_cnt = 0;//按键弹起后计数值   按键按下后计数值
//u16 key4_short_flag = 0;//短按标志
//u16 key4_idle_flag = 0;//非空闲
//u16 key4up_cnt2 = 0;

//u16 key6up_flag = 1; u16 key6down_flag = 0;//按键弹起标志   按键按下标志 
//u16 key6up_cnt = 0; u16 key6down_cnt = 0;//按键弹起后计数值   按键按下后计数值
//u16 key6_short_flag = 0;//短按标志
//u16 key6_idle_flag = 0;//非空闲
//u16 key6up_cnt2 = 0;

//u16 key7up_flag = 1; u16 key7down_flag = 0;//按键弹起标志   按键按下标志 
//u16 key7up_cnt = 0; u16 key7down_cnt = 0;//按键弹起后计数值   按键按下后计数值
//u16 key7_short_flag = 0;//短按标志
//u16 key7_idle_flag = 0;//非空闲
//u16 key7up_cnt2 = 0;

//u16 key8up_flag = 1; u16 key8down_flag = 0;//按键弹起标志   按键按下标志 
//u16 key8up_cnt = 0; u16 key8down_cnt = 0;//按键弹起后计数值   按键按下后计数值
//u16 key8_short_flag = 0;//短按标志
//u16 key8_idle_flag = 0;//非空闲
//u16 key8up_cnt2 = 0;

//u16 key9up_flag = 1; u16 key9down_flag = 0;//按键弹起标志   按键按下标志 
//u16 key9up_cnt = 0; u16 key9down_cnt = 0;//按键弹起后计数值   按键按下后计数值
//u16 key9_short_flag = 0;//短按标志
//u16 key9_idle_flag = 0;//非空闲
//u16 key9up_cnt2 = 0;



//void key_init()
//{
//	//使能时钟APB2的GPIOB GPIOA 
//	RCC->APB2ENR|=1<<3;//PB
//	RCC->APB2ENR|=1<<2;//PA
//	
//	//PA0 上拉/下拉输入
//	GPIOA->CRL &=0XFFFFFFF0; //先把需要的用引脚逻辑电平清零再配置
//	GPIOA->CRL |=0X00000008;   	 
//    GPIOA->BSRR |= (1<<0);
//	
//	//PA1 上拉/下拉输入
//	GPIOA->CRL &=0XFFFFFF0F; //先把需要的用引脚逻辑电平清零再配置
//	GPIOA->CRL |=0X00000080;   	 
//    GPIOA->BSRR |= (1<<1);
//	
//	
//	//PA11 上拉/下拉输入
//	GPIOA->CRH&=0XFFFF0FFF; 
//	GPIOA->CRH|=0X00008000;   	 
//    GPIOA->BSRR |= (1<<11);
//	
//	//PA12 上拉/下拉输入
//	GPIOA->CRH&=0XFFF0FFFF; 
//	GPIOA->CRH|=0X00080000;   	 
//    GPIOA->BSRR |= (1<<12);
//	
//	
//	
//	//PB4 上拉/下拉输入
//	GPIOB->CRL&=0XFFF0FFFF; //先把需要的用引脚逻辑电平清零再配置
//	GPIOB->CRL|=0X00080000;   	 
//    GPIOB->BSRR |= (1<<4);
//	
//	//PB5 上拉/下拉输入
//	GPIOB->CRL&=0XFF0FFFFF; //先把需要的用引脚逻辑电平清零再配置
//	GPIOB->CRL|=0X00800000;   	 
//    GPIOB->BSRR |= (1<<5);
//	
//	//PB8 上拉/下拉输入
//	GPIOB->CRH&=0XFFFFFFF0; //先把需要的用引脚逻辑电平清零再配置
//	GPIOB->CRH|=0X00000008;   	 
//    GPIOB->BSRR |= (1<<8);
//	
//	//PB9 上拉/下拉输入
//	GPIOB->CRH&=0XFFFFFF0F; //先把需要的用引脚逻辑电平清零再配置
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
//	//当按键持续按下
//		 if(0 == ( GPIOA->IDR & (1<<11)))
//		{
//			  key1down_cnt++;
//			 if(key1down_cnt >= 10)//去抖时间
//			{
//				key1down_flag = 1;
//				key1up_flag = 0;//抬起清零
//				key1up_cnt = 0;
//				
//				if(key1_idle_flag)
//				{
//					key1_idle_flag = 0;
//				}
//			}
//		}
//		 //如果按键松开
//		else
//		{
//			if(key1_idle_flag)
//				return;
//			key1up_cnt ++;
//			
//			//负防抖  ***************************************
//			if(key1up_cnt >= 50)
//			{
//				key1up_flag = 1;
//				key1down_flag = 0;
//				key1down_cnt = 0;
//			}
//			
//			//按下时间大于100ms，判断为单击
//			if(key1down_cnt >= 50) 
//			{
//				key1_short_flag = 1;//****************  短按（单击）
//				key1down_flag = 0;
//				key1down_cnt = 0;
//			}
//			
//			else  //按下时间小于50ms，忽略
//			{
//				key1up_cnt = 0;//弹起计数清零
//				key1up_flag = 0;
//				key1down_cnt = 0;//清零按下抖动的次数
//				key1_short_flag = 0;
//				key1down_flag = 0;//按下标志清零
//				key1_idle_flag = 1;//如果抬起持续1s没动作，就判断为空闲状态
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
//	//当按键持续按下
//		 if(0 == ( GPIOA->IDR & (1<<12)))
//		{
//			  key2down_cnt++;
//			 if(key2down_cnt >= 10)//去抖时间
//			{
//				key2down_flag = 1;
//				key2up_flag = 0;//抬起清零
//				key2up_cnt = 0;
//				
//				if(key2_idle_flag)
//				{
//					key2_idle_flag = 0;
//				}
//			}
//		}
//		 //如果按键松开
//		else
//		{
//			if(key2_idle_flag)
//				return;
//			key2up_cnt ++;
//			
//			//负防抖  ***************************************
//			if(key2up_cnt >= 50)
//			{
//				key2up_flag = 1;
//				key2down_flag = 0;
//				key2down_cnt = 0;
//			}
//			
//			//按下时间大于100ms，判断为单击
//			if(key2down_cnt >= 50) 
//			{
//				key2_short_flag = 1;//****************  短按（单击）
//				key2down_flag = 0;
//				key2down_cnt = 0;
//			}
//			
//			else  //按下时间小于50ms，忽略
//			{
//				key2up_cnt = 0;//弹起计数清零
//				key2up_flag = 0;
//				key2down_cnt = 0;//清零按下抖动的次数
//				key2_short_flag = 0;
//				key2down_flag = 0;//按下标志清零
//				key2_idle_flag = 1;//如果抬起持续1s没动作，就判断为空闲状态
//			}		
//		}
//	if(key2_short_flag)
//	{
//		key2_short_flag = 0;
//		key2_press = 1;
//	}
//}

//void key3_scan(void)//key3作为 stop
//{
//	//当按键持续按下
//		 if(0 == ( GPIOB->IDR & (1<<4)))
//		{
//			  key3down_cnt++;
//			 if(key3down_cnt >= 10)//去抖时间
//			{
//				key3down_flag = 1;
//				key3up_flag = 0;//抬起清零
//				key3up_cnt = 0;
//				
//				if(key3_idle_flag)
//				{
//					key3_idle_flag = 0;
//				}
//			}
//		}
//		 //如果按键松开
//		else
//		{
//			if(key3_idle_flag)
//				return;
//			key3up_cnt ++;
//			
//			//负防抖  ***************************************
//			if(key3up_cnt >= 50)
//			{
//				key3up_flag = 1;
//				key3down_flag = 0;
//				key3down_cnt = 0;
//			}
//			
//			//按下时间大于100ms，判断为单击
//			if(key3down_cnt >= 50) 
//			{
//				key3_short_flag = 1;//****************  短按（单击）
//				key3down_flag = 0;
//				key3down_cnt = 0;
//			}
//			
//			else  //按下时间小于50ms，忽略
//			{
//				key3up_cnt = 0;//弹起计数清零
//				key3up_flag = 0;
//				key3down_cnt = 0;//清零按下抖动的次数
//				key3_short_flag = 0;
//				key3down_flag = 0;//按下标志清零
//				key3_idle_flag = 1;//如果抬起持续1s没动作，就判断为空闲状态
//			}		
//		}
//	if(key3_short_flag)
//	{
//		key3_short_flag = 0;
//		key3_press = 1;
////		LED1 = 1;
//	}
//}


//void key4_scan(void)//key4作为 start
//{
//	//当按键持续按下
//		 if(0 == ( GPIOB->IDR & (1<<5)))
//		{
//			 key4down_cnt++;
//			 if(key4down_cnt >= 10)//去抖时间
//			{
//				key4down_flag = 1;
//				key4_idle_flag = 0;//非空闲
//				key4up_flag = 0;//抬起清零
//				key4up_cnt = 0;
//			}
//		}
//		//如果按键松开
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
//			//按下时间大于100ms弹起，判断为单击
//			if(key4down_cnt >= 50)
//			{
//				key4_short_flag = 1;//****************  短按（单击）
//				key4down_cnt = 0;	
//				key4down_flag = 0;
//			}
//			else
//			{
//				key4up_cnt = 0;//弹起计数清零
//				key4up_flag = 0;
//				key4_idle_flag = 1;//如果抬起持续1s没动作，就判断为空闲状态
//				key4down_cnt = 0;//清零按下抖动的次数
//				key4_short_flag = 0;
//				key4down_flag = 0;//按下标志清零
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


//void key6_scan(void)//key6作为 电流调零
//{
//	//当按键持续按下
//		 if(0 == ( GPIOB->IDR & (1<<8)))
//		{
//			 key6down_cnt++;
//			 if(key6down_cnt >= 10)//去抖时间
//			{
//				key6down_flag = 1;
//				key6_idle_flag = 0;//非空闲
//				key6up_flag = 0;//抬起清零
//				key6up_cnt = 0;
//			}
//		}
//		//如果按键松开
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
//			//按下时间大于100ms弹起，判断为单击
//			if(key6down_cnt >= 50)
//			{
//				key6_short_flag = 1;//****************  短按（单击）
//				key6down_cnt = 0;	
//				key6down_flag = 0;
//			}
//			else
//			{
//				key6up_cnt = 0;//弹起计数清零
//				key6up_flag = 0;
//				key6_idle_flag = 1;//如果抬起持续1s没动作，就判断为空闲状态
//				key6down_cnt = 0;//清零按下抖动的次数
//				key6_short_flag = 0;
//				key6down_flag = 0;//按下标志清零
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


//void key7_scan(void)//key7作为 ADD
//{
//	//当按键持续按下
//		 if(0 == ( GPIOB->IDR & (1<<9)))
//		{
//			  key7down_cnt++;
//			 if(key7down_cnt >= 10)//去抖时间
//			{
//				key7down_flag = 1;
//				key7up_flag = 0;//抬起清零
//				key7up_cnt = 0;
//				
//				if(key7_idle_flag)
//				{
//					key7_idle_flag = 0;
//				}
//			}
//		}
//		 //如果按键松开
//		else
//		{
//			if(key7_idle_flag)
//				return;
//			key7up_cnt ++;
//			
//			//负防抖  ***************************************
//			if(key7up_cnt >= 50)
//			{
//				key7up_flag = 1;
//				key7down_flag = 0;
//				key7down_cnt = 0;
//			}
//			
//			//按下时间大于100ms，判断为单击
//			if(key7down_cnt >= 50) 
//			{
//				key7_short_flag = 1;//****************  短按（单击）
//				key7down_flag = 0;
//				key7down_cnt = 0;
//			}
//			
//			else  //按下时间小于50ms，忽略
//			{
//				key7up_cnt = 0;//弹起计数清零
//				key7up_flag = 0;
//				key7down_cnt = 0;//清零按下抖动的次数
//				key7_short_flag = 0;
//				key7down_flag = 0;//按下标志清零
//				key7_idle_flag = 1;//如果抬起持续1s没动作，就判断为空闲状态
//			}		
//		}
//	if(key7_short_flag)
//	{
//		key7_short_flag = 0;
//		key7_press = 1;
//	}
//}

//void key8_scan(void)//key8作为 转速
//{
//	//当按键持续按下
//		 if(0 == ( GPIOA->IDR & (1<<0)))
//		{
//			  key8down_cnt++;
//			 if(key8down_cnt >= 10)//去抖时间
//			{
//				key8down_flag = 1;
//				key8up_flag = 0;//抬起清零
//				key8up_cnt = 0;
//				
//				if(key8_idle_flag)
//				{
//					key8_idle_flag = 0;
//				}
//			}
//		}
//		 //如果按键松开
//		else
//		{
//			if(key8_idle_flag)
//				return;
//			key8up_cnt ++;
//			
//			//负防抖  ***************************************
//			if(key8up_cnt >= 50)
//			{
//				key8up_flag = 1;
//				key8down_flag = 0;
//				key8down_cnt = 0;
//			}
//			
//			
//			//按下时间大于50ms，判断为单击
//			if(key8down_cnt >= 50) 
//			{
//				key8_short_flag = 1;//****************  短按（单击）
//				key8down_flag = 0;
//				key8down_cnt = 0;
//			}
//			else  //按下时间小于50ms，忽略
//			{
//				key8up_cnt = 0;//弹起计数清零
//				key8up_flag = 0;
//				key8down_cnt = 0;//清零按下抖动的次数
//				key8_short_flag = 0;
//				key8down_flag = 0;//按下标志清零
//				key8_idle_flag = 1;//如果抬起持续1s没动作，就判断为空闲状态
//			}		
//		}
//	if(key8_short_flag)
//	{
//		key8_short_flag = 0;
//		key8_press = 1;
//	}
//}


//void key9_scan(void)//key9作为 电流
//{
//	//当按键持续按下
//		if(0 == ( GPIOA->IDR & (1<<1)))
//		{
//			  key9down_cnt++;
//			 if(key9down_cnt >= 10)//去抖时间
//			{
//				key9down_flag = 1;
//				key9up_flag = 0;//抬起清零
//				key9up_cnt = 0;
//				
//				if(key9_idle_flag)
//				{
//					key9_idle_flag = 0;
//				}
//			}
//		}
//		 //如果按键松开
//		else
//		{
//			if(key9_idle_flag)
//				return;
//			key9up_cnt ++;
//			
//			//负防抖  ***************************************
//			if(key9up_cnt >= 50)
//			{
//				key9up_flag = 1;
//				key9down_flag = 0;
//				key9down_cnt = 0;
//			}
//			
//			//按下时间大于100ms，判断为单击
//			if(key9down_cnt >= 50) 
//			{
//				key9_short_flag = 1;//****************  短按（单击）
//				key9down_flag = 0;
//				key9down_cnt = 0;
//			}
//			
//			else  //按下时间小于50ms，忽略
//			{
//				key9up_cnt = 0;//弹起计数清零
//				key9up_flag = 0;
//				key9down_cnt = 0;//清零按下抖动的次数
//				key9_short_flag = 0;
//				key9down_flag = 0;//按下标志清零
//				key9_idle_flag = 1;//如果抬起持续1s没动作，就判断为空闲状态
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

