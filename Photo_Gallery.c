#include <LPC17xx.H>
#include "string.h"
#include "GLCD.h"
#include "LED.h"
#include "KBD.h"
#include "Media_Center.h"
#include "Photo_Gallery.h"
#include "Photo_Viewer.h"

#define __FI        1
#define DELAY_2N		18
int selection2;

void delay2 (int cnt) {
  cnt <<= DELAY_2N;
  while (cnt--);
}

void Photo_Gallery(){
	GLCD_Clear(Navy);              	 
  GLCD_SetBackColor(Blue);
  GLCD_SetTextColor(Yellow);
  GLCD_DisplayString(0, 0, __FI, "   Photo Gallery    ");
	GLCD_SetTextColor(White);
  GLCD_DisplayString(1, 0, __FI, "  Use joystick to   ");
	GLCD_DisplayString(2, 0, __FI, "      navigate      ");
	GLCD_SetBackColor(Navy);
	GLCD_SetTextColor(White);
	GLCD_DisplayString(9, 5, __FI, "Go Back = L");
  
	while (1) {               
		
		if(get_button() == KBD_DOWN){
			if(selection2 == 3){
				selection2 = 0;
			}
			else{
				selection2++;
			}
			delay2(10);
		}
		else if(get_button() == KBD_UP){
			if(selection2 == 0){
				selection2 = 3;
			}
			else{
				selection2--;
			}
			delay2(10);
		}
		else if(get_button() == KBD_SELECT){
			if(selection2 == 0){
				Photo_Viewer(1);
				break;
			}
			else if(selection2 == 1){
				Photo_Viewer(2);
				break;
			}
			else if(selection2 == 2){
				Photo_Viewer(3);
				break;
			}
			else if(selection2 == 3){
				Photo_Viewer(4);
				break;
			}
			delay2(5);
		}
		else if (get_button() ==  KBD_LEFT){
			Media_Center();		
			break;
		}
		
		if(selection2 == 0){
			GLCD_SetBackColor(Blue);
			GLCD_DisplayString(4, 5, __FI, "Photo 1 >");
			GLCD_SetBackColor(Navy);
			GLCD_DisplayString(5, 5, __FI, "Photo 2 >");
			GLCD_DisplayString(6, 5, __FI, "Photo 3 >");
			GLCD_DisplayString(7, 5, __FI, "Photo 4 >");
		}
		else if(selection2 == 1){
			GLCD_SetBackColor(Blue);
			GLCD_DisplayString(5, 5, __FI, "Photo 2 >");
			GLCD_SetBackColor(Navy);
			GLCD_DisplayString(4, 5, __FI, "Photo 1 >");
			GLCD_DisplayString(6, 5, __FI, "Photo 3 >");
			GLCD_DisplayString(7, 5, __FI, "Photo 4 >");
		}
		else if(selection2 == 2){
			GLCD_SetBackColor(Blue);
			GLCD_DisplayString(6, 5, __FI, "Photo 3 >");
			GLCD_SetBackColor(Navy);
			GLCD_DisplayString(4, 5, __FI, "Photo 1 >");
			GLCD_DisplayString(5, 5, __FI, "Photo 2 >");
			GLCD_DisplayString(7, 5, __FI, "Photo 4 >");;
		}
		else if(selection2 == 3){
			GLCD_SetBackColor(Blue);
			GLCD_DisplayString(7, 5, __FI, "Photo 4 >");
			GLCD_SetBackColor(Navy);
			GLCD_DisplayString(4, 5, __FI, "Photo 1 >");
			GLCD_DisplayString(5, 5, __FI, "Photo 2 >");
			GLCD_DisplayString(6, 5, __FI, "Photo 3 >");
		}
	} 
}	
