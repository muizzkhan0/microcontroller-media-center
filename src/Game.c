#include "GLCD.h"
#include "KBD.h"
#include <stdlib.h>
#include "Media_Center.h"

#define __FI    	1
#define DELAY_2N		18

int score = 0;
int playerx = 10;
int playery = 5;
char score_text[20];

int objx;
int objy;
int randy = 9;

int obj2x;
int obj2y;
int rand2y = 9;

int obj3x;
int obj3y;
int rand3y = 9;

int obj4x;
int obj4y;
int rand4y = 9;

void delay3 (int cnt) {
  cnt <<= DELAY_2N;
  while (cnt--);
}

void Game_Start(void){
	objy = rand() % (randy + 1);
	obj2y = rand() % (rand2y + 1);
	obj3y = rand() % (rand3y + 1);
	obj4y = rand() % (rand4y + 1);
	objx = 20;
	obj2x = 25;
	obj3x = 30;
	obj4x = 33;
	playerx = 10;
	playery = 5;
	score = 0;
	
	GLCD_Clear(White);
	GLCD_SetBackColor(Black);
	GLCD_SetTextColor(Black);
	GLCD_DisplayString(playery, playerx, __FI, "-");
	
	while(1){
		//getting player inputs and moving the player
		if((playerx == objx || playerx == objx+1) && (playery == objy || playery == objy+1) || 
			 (playerx == obj2x || playerx == obj2x+1) && (playery == obj2y || playery == obj2y+1) ||
			 (playerx == obj3x || playerx == obj3x+1) && (playery == obj3y || playery == obj3y+1) ||
			 (playerx == obj4x || playerx == obj4x+1) && (playery == obj4y || playery == obj4y+1)){ //collision detection
			break;
		}
		if(get_button() == KBD_UP){
			if(playery != 0){
				GLCD_SetBackColor(White);
				GLCD_SetTextColor(White);
				GLCD_DisplayString(playery, playerx, __FI, "-");
				playery--;
				GLCD_SetBackColor(Black);
				GLCD_SetTextColor(Black);
				GLCD_DisplayString(playery, playerx, __FI, "-");
			}
		}
		else if(get_button() == KBD_DOWN){
			if(playery != 9){
				GLCD_SetBackColor(White);
				GLCD_SetTextColor(White);
				GLCD_DisplayString(playery, playerx, __FI, "-");
				playery++;
				GLCD_SetBackColor(Black);
				GLCD_SetTextColor(Black);
				GLCD_DisplayString(playery, playerx, __FI, "-");
			}
		}
		else if(get_button() == KBD_LEFT){
			if(playerx != 0){
				GLCD_SetBackColor(White);
				GLCD_SetTextColor(White);
				GLCD_DisplayString(playery, playerx, __FI, "-");
				playerx--;
				GLCD_SetBackColor(Black);
				GLCD_SetTextColor(Black);
				GLCD_DisplayString(playery, playerx, __FI, "-");
			}
		}
		else if(get_button() == KBD_RIGHT){
			if(playerx != 19){
				GLCD_SetBackColor(White);
				GLCD_SetTextColor(White);
				GLCD_DisplayString(playery, playerx, __FI, "-");
				playerx++;
				GLCD_SetBackColor(Black);
				GLCD_SetTextColor(Black);
				GLCD_DisplayString(playery, playerx, __FI, "-");
			}
		}
		
		if(objx != -2){ //moving the obstacle from right to left, if its not already off screen
			GLCD_SetBackColor(White);
			GLCD_SetTextColor(White);
			GLCD_DisplayString(objy, objx, __FI, "--");
			GLCD_DisplayString(objy+1, objx, __FI, "--");
			objx--;
			GLCD_SetBackColor(Red);
			GLCD_SetTextColor(Red);
			GLCD_DisplayString(objy, objx, __FI, "--");
			GLCD_DisplayString(objy+1, objx, __FI, "--");
		}
		else{ //if its off screen then generate a new object at a random y
			objy = rand() % (randy + 1);
			objx = 20;
			score++;
		}
		if(score >= 2){
			if(obj2x != -2){ //moving the obstacle from right to left, if its not already off screen
				GLCD_SetBackColor(White);
				GLCD_SetTextColor(White);
				GLCD_DisplayString(obj2y, obj2x, __FI, "--");
				GLCD_DisplayString(obj2y+1, obj2x, __FI, "--");
				obj2x--;
				GLCD_SetBackColor(Red);
				GLCD_SetTextColor(Red);
				GLCD_DisplayString(obj2y, obj2x, __FI, "--");
				GLCD_DisplayString(obj2y+1, obj2x, __FI, "--");
			}
			else{ //if its off screen then generate a new object at a random y
				obj2y = rand() % (rand2y + 1);
				obj2x = 20;
				score++;
			}
		}
		
		if(score >= 6){
			if(obj3x != -2){ //moving the obstacle from right to left, if its not already off screen
				GLCD_SetBackColor(White);
				GLCD_SetTextColor(White);
				GLCD_DisplayString(obj3y, obj3x, __FI, "--");
				GLCD_DisplayString(obj3y+1, obj3x, __FI, "--");
				obj3x--;
				GLCD_SetBackColor(Red);
				GLCD_SetTextColor(Red);
				GLCD_DisplayString(obj3y, obj3x, __FI, "--");
				GLCD_DisplayString(obj3y+1, obj3x, __FI, "--");
			}
			else{ //if its off screen then generate a new object at a random y
				obj3y = rand() % (rand3y + 1);
				obj3x = 20;
				score++;
			}
		}
		
		if(score >= 12){
			if(obj4x != -2){ //moving the obstacle from right to left, if its not already off screen
				GLCD_SetBackColor(White);
				GLCD_SetTextColor(White);
				GLCD_DisplayString(obj4y, obj4x, __FI, "--");
				GLCD_DisplayString(obj4y+1, obj4x, __FI, "--");
				obj4x--;
				GLCD_SetBackColor(Red);
				GLCD_SetTextColor(Red);
				GLCD_DisplayString(obj4y, obj4x, __FI, "--");
				GLCD_DisplayString(obj4y+1, obj4x, __FI, "--");
			}
			else{ //if its off screen then generate a new object at a random y
				obj4y = rand() % (rand4y + 1);
				obj4x = 20;
				score++;
			}
		}
		if(score <= 18)
			delay3(10);
		else if(score <= 26)
			delay3(6);
		else if(score <= 34)
			delay3(3);
		else
			delay3(1);
	}
	
	GLCD_Clear(Black);
	GLCD_SetBackColor(Black);
	GLCD_SetTextColor(White);
	GLCD_DisplayString(0, 5, __FI, "Game Over");
	sprintf(score_text, "Final Score: %d", score);
	GLCD_DisplayString(4, 3, __FI, (unsigned char *)score_text);
	GLCD_DisplayString(8, 1, __FI, "SELECT to go home.");
	while(1){
		if(get_button() == KBD_SELECT){
			Media_Center();
			break;
		}
	}
}

void Game_Init(void){
	GLCD_Clear(White);
	GLCD_SetBackColor(White);
	GLCD_SetTextColor(Black);
	GLCD_DisplayString(1, 3, __FI, "SELECT to start");
	GLCD_DisplayString(3, 2, __FI, "Joystick to move");
	GLCD_DisplayString(5, 1, __FI, "Dodge Red Obstacles");
	GLCD_DisplayString(7, 2, __FI, "1 Dodge = 1 Score");
	GLCD_DisplayString(9, 5, __FI, "Go Back = L");
	
	while(1){
		if(get_button() == KBD_SELECT){
			Game_Start();
			break;
		}
		if(get_button() == KBD_LEFT){
			Media_Center();
			break;
		}
	}
}
