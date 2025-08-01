#include <LPC17xx.H>
#include "string.h"
#include "GLCD.h"
#include "LED.h"
#include "KBD.h"
#include "Media_Center.h"
#include "Photo_Gallery.h"
#include "Photo_Viewer.h"

#define __FI        1

extern unsigned char MARIO[];
extern unsigned char MAPLE_LEAFS[];
extern unsigned char RAPTORS[];
extern unsigned char BLUE_JAYS[];

int Photo_Viewer(int j){
	
	GLCD_Clear(Navy);
	GLCD_ClearLn(8,1);
	GLCD_ClearLn(9,1);
	
	while (1) { 
		
			if (j == 1){
					GLCD_SetBackColor(Navy);
					GLCD_SetTextColor(White);					
					GLCD_DisplayString(0, 7, __FI,(unsigned char*)"MARIO");	 	
					GLCD_Bitmap (80, 30, 160, 160, MARIO);		
					GLCD_DisplayString(9, 5, __FI,(unsigned char*)"Go Back = L");
			}
			else if (j == 2){					
					GLCD_SetBackColor(Navy);
					GLCD_SetTextColor(White);					
					GLCD_DisplayString(0, 2, __FI,(unsigned char*)"MAPLE LEAFS LOGO");	  	
					GLCD_Bitmap (80, 30, 160, 160, MAPLE_LEAFS);
					GLCD_DisplayString(9, 5, __FI,(unsigned char*)"Go Back = L");				
			}
			else if (j == 3){		
					GLCD_SetBackColor(Navy);	
					GLCD_SetTextColor(White);					
					GLCD_DisplayString(0, 4, __FI,(unsigned char*)"RAPTORS LOGO");	  	
					GLCD_Bitmap (80, 30, 160, 160, RAPTORS);		
					GLCD_DisplayString(9, 5, __FI,(unsigned char*)"Go Back = L");	
					
			}
			else if (j == 4){	
					GLCD_SetBackColor(Navy);	
					GLCD_SetTextColor(White);					
					GLCD_DisplayString(0, 3, __FI,(unsigned char*)"BLUE JAYS LOGO");	  	
					GLCD_Bitmap (80, 30, 160, 160, BLUE_JAYS);					
					GLCD_DisplayString(9, 5, __FI,(unsigned char*)"Go Back = L");				
			}
				
			
			if (get_button() ==  KBD_LEFT){
					Photo_Gallery();
					break;			
			}
	} 		
	return(0);
}	
