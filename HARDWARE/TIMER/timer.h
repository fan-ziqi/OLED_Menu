#ifndef __TIMER_H
#define __TIMER_H	

#include "sys.h"
#include "delay.h"

#define LED0_PWM_VAL TIM1->CCR1

#define M  100
#define K  20

#define A1 PAin(15)
#define B1 PBin(3)
#define A2 PAin(8)
#define B2 PAin(9)






extern uint16_t time;
extern uint16_t time0;
extern uint16_t time1;
extern uint16_t time4;
extern uint16_t time5;
extern uint16_t time6;
extern uint16_t time7;
extern uint16_t time8;
extern uint16_t time9;
extern uint16_t time10;
extern uint16_t time11;
extern uint16_t time12;
extern uint16_t time13;




void TIM3_init(u16 arr,u16 psc);

void MY_NVIC_Init(u8 NVIC_PreemptionPriority,u8 NVIC_SubPriority,u8 NVIC_Channel,u8 NVIC_Group);

void Smooth(int data[]);


void Mision_1ms(void);


extern u8 flag_1ms;
//extern u8 flag_10ms;
	



#endif

