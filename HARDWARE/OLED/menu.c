#include "menu.h"


//用状态机做菜单显示
INTERFACE_OPTIONS  interfece;


void INTERFACE_Statment(void)
{

	switch(interfece)
	{
//		case MAIN_INTERFACE:
//			show_first_interface();
//			break;
		
		case MENU_INTERFACE:
			show_menu(); 
			break;
		
		case CURRENT_CHOSEN:
			show_chosen_current();
			show_menu();
			break;
		
		case ROTATION_CHOSEN:
			show_chosen_rotation(); 
			show_menu();
			break;
		
		case ALL_TEST_CHOSEN:
			show_chosen_all();
			show_menu();
			break;
		
		case CURRENT_TEST_INTERFACE:
			show_current_test();
			break;
		
		case ROTATION_TEST_INTERFACE:
			show_rotation_test();
			break;
		
		case ALL_TEST_INTERFACE:
			show_all_test();
			break;
		
		default:
			break;
	}
}



void Menu_Key_Enter(void)
{
	OLED_CLS();//清屏
//	if(interfece == MAIN_INTERFACE)
//	{
//		interfece = MENU_INTERFACE;
//	}
	if(interfece == MENU_INTERFACE)
	{
		interfece = CURRENT_CHOSEN;
	}
	else if(interfece == CURRENT_CHOSEN)
	{
		interfece = CURRENT_TEST_INTERFACE;
	}
	else if(interfece == ROTATION_CHOSEN)
	{
		interfece = ROTATION_TEST_INTERFACE;
	}
	else if(interfece == ALL_TEST_CHOSEN)
	{
		interfece = ALL_TEST_INTERFACE;
	}
}

void Menu_Key_Return(void)
{
	OLED_CLS();//清屏
	if(interfece == MENU_INTERFACE)
	{
		interfece = MENU_INTERFACE;
	}
	else if(interfece == CURRENT_CHOSEN)	
	{
		interfece = MENU_INTERFACE;
	}
	else if(interfece == ROTATION_CHOSEN)	
	{
		interfece = MENU_INTERFACE;
	}
	else if(interfece == ALL_TEST_CHOSEN)	
	{
		interfece = MENU_INTERFACE;
	}
	else if(interfece == CURRENT_TEST_INTERFACE)	
	{
		interfece = CURRENT_CHOSEN;
	}
	else if(interfece == ROTATION_TEST_INTERFACE)	
	{
		interfece = ROTATION_CHOSEN;
	}
	else if(interfece == ALL_TEST_INTERFACE)	
	{
		interfece = ALL_TEST_CHOSEN;
	}
}

void Menu_Key_Up(void)
{
//	OLED_CLS();//清屏
	if(interfece == CURRENT_CHOSEN)
	{
		interfece = ALL_TEST_CHOSEN;
	}
	else if(interfece == ALL_TEST_CHOSEN)
	{
		interfece = ROTATION_CHOSEN;
	}
	else if(interfece == ROTATION_CHOSEN)
	{
		interfece = CURRENT_CHOSEN;
	}
}

void Menu_Key_Down(void)
{
//	OLED_CLS();//清屏
	if(interfece == CURRENT_CHOSEN)
	{
		interfece = ROTATION_CHOSEN;
	}
	else if(interfece == ROTATION_CHOSEN)
	{
		interfece = ALL_TEST_CHOSEN;
	}
	else if(interfece == ALL_TEST_CHOSEN)
	{
		interfece = CURRENT_CHOSEN;
	}
}

//用变量直接做菜单



















