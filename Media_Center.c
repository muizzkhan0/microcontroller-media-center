#include <LPC17xx.H>
#include "string.h"
#include "GLCD.h"
#include "LED.h"
#include "KBD.h"
#include "Media_Center.h"
#include "Photo_Gallery.h"
#include "Game.h"
#include "usbdmain.h"
#include "usb.h"
#include "usbcfg.h"
#include "usbhw.h"
#include "usbcore.h"
#include "usbaudio.h"
#include "type.h"

#define __FI        1
#define DELAY_2N		18

int sel=1;
int music=0;
int k;

void delay (int cnt) {
  cnt <<= DELAY_2N;
  while (cnt--);
}

void MP3_Player2 (void){
		USB_Connect(TRUE);
    NVIC_EnableIRQ(TIMER0_IRQn);
    NVIC_EnableIRQ(USB_IRQn);
		
		while( 1 ){
			if (get_button() == KBD_LEFT){
				Media_Center();
			}
		}
}

int main (void) {                                           
	
	GLCD_Init();
	KBD_Init();
	
	Media_Center();
}

void Media_Center(){
int selection = 0;
	
	GLCD_Clear(White);              	 
  GLCD_SetBackColor(Blue);
  GLCD_SetTextColor(Yellow);
  GLCD_DisplayString(0, 0, __FI, "   COE718 Project   ");
	GLCD_SetTextColor(White);
  GLCD_DisplayString(1, 0, __FI, "  Use joystick to   ");
	GLCD_DisplayString(2, 0, __FI, "      navigate      ");
  GLCD_SetBackColor(White);
	GLCD_SetTextColor(Red);
	
	GLCD_DisplayString(4, 0, __FI, "Photo Gallery >");
	GLCD_DisplayString(5, 0, __FI, "MP3 Player >");
	GLCD_DisplayString(6, 0, __FI, "Game >");

	while(1){
		if(get_button() == KBD_DOWN){
			if(selection == 2){
				selection = 0;
			}
			else{
				selection++;
			}
			delay(10);
		}
		else if(get_button() == KBD_UP){
			if(selection == 0){
				selection = 2;
			}
			else{
				selection--;
			}
			delay(10);
		}
		else if(get_button() == KBD_SELECT){
			if(selection == 0){
				Photo_Gallery();
				break;
			}
			else if(selection == 1){
					GLCD_Clear(Black);              	 
					GLCD_SetBackColor(Blue);
					GLCD_SetTextColor(Yellow);
					GLCD_DisplayString(0, 0, __FI, "   COE718 Project   ");
					GLCD_SetTextColor(White);
					GLCD_DisplayString(1, 0, __FI, "     MP3 Player     "); 			
					GLCD_SetBackColor(Black);		
					GLCD_SetTextColor(White);		
					GLCD_DisplayString(4, 2, __FI, "  AUDIO");
					GLCD_DisplayString(5, 4, __FI, "STREAMING...");
					GLCD_DisplayString(8, 5, __FI, "Go Back = L");						
					if(music == 0){
						MP3_Player ();
					}  
					else if (music == 1) { 
						MP3_Player2 ();
					}		
			}
			else if(selection == 2){
				Game_Init();
				break;
			}
			delay(10);
		}
		
		if(selection == 0){
			GLCD_SetBackColor(Blue);
			GLCD_DisplayString(4, 0, __FI, "Photo Gallery >");
			GLCD_SetBackColor(White);
			GLCD_DisplayString(5, 0, __FI, "MP3 Player >");
			GLCD_DisplayString(6, 0, __FI, "Game >");
		}
		else if(selection == 1){
			GLCD_SetBackColor(Blue);
			GLCD_DisplayString(5, 0, __FI, "MP3 Player >");
			GLCD_SetBackColor(White);
			GLCD_DisplayString(4, 0, __FI, "Photo Gallery >");
			GLCD_DisplayString(6, 0, __FI, "Game >");
		}
		else if(selection == 2){
			GLCD_SetBackColor(Blue);
			GLCD_DisplayString(6, 0, __FI, "Game >");
			GLCD_SetBackColor(White);
			GLCD_DisplayString(5, 0, __FI, "MP3 Player >");
			GLCD_DisplayString(4, 0, __FI, "Photo Gallery >");
		}
	}
}	
