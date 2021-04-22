#ifndef __MENU_H
#define __MENU_H


#include "sys.h"
#include "oled_iic.h"



typedef enum
{
//	MAIN_INTERFACE = 0,
	MENU_INTERFACE,
	CURRENT_TEST_INTERFACE,
	ROTATION_TEST_INTERFACE,
	ALL_TEST_INTERFACE,
	CURRENT_CHOSEN,
	ROTATION_CHOSEN,
	ALL_TEST_CHOSEN
}INTERFACE_OPTIONS;

extern INTERFACE_OPTIONS  interfece;




void INTERFACE_Statment(void);

void Menu_Key_Enter(void);
void Menu_Key_Return(void);
void Menu_Key_Up(void);
void Menu_Key_Down(void);




#endif

