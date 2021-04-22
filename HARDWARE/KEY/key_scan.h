#ifndef __KEY_SCAN_H
#define __KEY_SCAN_H

#include "sys.h"
#include "timer.h"
#include "menu.h"

extern u16 key_short_flag;
extern u16 key_double_flag;
extern u16 key_double_step1 ,key_double_step2 ;
extern u16 key_long_flag;
extern u16 keyup_cnt;
extern u16 keyup_cnt2;
extern u16 keydown_cnt;
extern u16 keyup_flag; 
extern u16 keydown_flag;
extern u16 key_idle_flag;
extern u8 led_state;
extern volatile unsigned int keyon_time;

extern u16 key1_short_flag;
extern u16 key1up_cnt;
extern u16 key1up_cnt2;
extern u16 key1down_cnt;
extern u16 key1up_flag; 
extern u16 key1down_flag;
extern u16 key1_idle_flag;
extern volatile unsigned int key1on_time;

extern u16 key2_short_flag;
extern u16 key2up_cnt;
extern u16 key2up_cnt2;
extern u16 key2down_cnt;
extern u16 key2up_flag; 
extern u16 key2down_flag;
extern u16 key2_idle_flag;
extern volatile unsigned int key2on_time;

extern u16 key3_short_flag;
extern u16 key3up_cnt;
extern u16 key3up_cnt2;
extern u16 key3down_cnt;
extern u16 key3up_flag; 
extern u16 key3down_flag;
extern u16 key3_idle_flag;
extern volatile unsigned int key3on_time;

extern u16 key4_short_flag;
extern u16 key4up_cnt;
extern u16 key4up_cnt2;
extern u16 key4down_cnt;
extern u16 key4up_flag; 
extern u16 key4down_flag;
extern u16 key4_idle_flag;
extern volatile unsigned int key4on_time;

extern u16 key6_short_flag;
extern u16 key6up_cnt;
extern u16 key6up_cnt2;
extern u16 key6down_cnt;
extern u16 key6up_flag; 
extern u16 key6down_flag;
extern u16 key6_idle_flag;
extern volatile unsigned int key6on_time;

extern u16 key7_short_flag;
extern u16 key7up_cnt;
extern u16 key7up_cnt2;
extern u16 key7down_cnt;
extern u16 key7up_flag; 
extern u16 key7down_flag;
extern u16 key7_idle_flag;
extern volatile unsigned int key7on_time;

extern u16 key8_short_flag;
extern u16 key8up_cnt;
extern u16 key8up_cnt2;
extern u16 key8down_cnt;
extern u16 key8up_flag; 
extern u16 key8down_flag;
extern u16 key8_idle_flag;
extern volatile unsigned int key6on_time;

extern u16 key9_short_flag;
extern u16 key9up_cnt;
extern u16 key9up_cnt2;
extern u16 key9down_cnt;
extern u16 key9up_flag; 
extern u16 key9down_flag;
extern u16 key9_idle_flag;
extern volatile unsigned int key9on_time;


extern u8 key1_press ;//PA11  CCW  key1
extern u8 key2_press ;//PA12  CW   key2
extern u8 key3_press ;//PB4  stop  key3
extern u8 key4_press ;//PB5  start key4
extern u8 key5_press ;
extern u8 key6_press ;//PB8  zero  key6
extern u8 key7_press ;//PB9  add   key7
extern u8 key8_press ;//PB8  display_rotation key8
extern u8 key9_press ;//PB9  display_I_mA    key9
extern u8 key10_press ;
extern u8 key11_press ;
extern u8 key12_press ;
extern u8 key13_press ;
extern u8 key14_press ;
extern u8 key15_press ;
extern u8 key16_press ;


extern u8 keyfun(void);

extern void key_scan(void);
extern void key1_scan(void);//key3作为正转
extern void key2_scan(void);//key4作为反转
extern void key3_scan(void);//key3作为停止
extern void key4_scan(void);//key4作为开始
extern void key6_scan(void);//key6作为电流检测调零
extern void key7_scan(void);//key7作为 阀值加大
extern void key8_scan(void);//key8作为 数码管显示转速
extern void key9_scan(void);//key9作为 数码管显示计数



void deal_allkey_press(void);


#define KEY1 PAin(11)
#define KEY2 PAin(12)
#define KEY3 PBin(4)	
#define KEY4 PBin(5)

#define KEY6 PBin(8)
#define KEY7 PBin(9)
#define KEY8 PAin(0)
#define KEY9 PAin(1)

void key_init(void);

#endif



