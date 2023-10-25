/*
 * main.c
 *
 *  Created on: Oct 17, 2023
 *      Author: Hazim Emad
 */
#include "../Library/STD_types.h"
#include "../Library/Bit_Math.h"
#include "../MCAL/DIO/Header/DIO_Interface.h"
#include "../HAL/LCD/Header/LCD_Interface.h"
#include "util/delay.h"

#define PLAYER_RUN_1	0
#define PLAYER_RUN_2	1
#define PLAYER_RUN_3	2
#define PLAYER_JUMP		3
#define GOALKEEPER		4
#define KEEPER_SLIDE	5
#define TROPHY			6
#define GOAL_SCORED		7

#define PLAYER_CELEBRATE  4
#define GOAL_POST		0b10111010
#define BALL_GROUND		0b00101110
#define BALL_AIR		0b10100101
#define FRAME_DELAY_MS  150


void LoadSpecialChars();
void PlayerTrains();
void Player1v1();
void PlayerCelebrates();
void PlayerCeremony();

void PlayerMove();
void DribbleEnemy();
void PlayerShoots();

u8 SpecialChars[8][8] = {
		{//Player run 1
				0b01111,
				0b01110,
				0b00101,
				0b01110,
				0b00100,
				0b01110,
				0b11010,
				0b10011
		},
		{//Player run 2
				0b01111,
				0b01110,
				0b00101,
				0b01110,
				0b00100,
				0b00111,
				0b01101,
				0b00001
		},
		{//Player run 3
				0b01111,
				0b01110,
				0b00101,
				0b01110,
				0b00100,
				0b01110,
				0b11010,
				0b00011
		},
		{//Player jump
				0b01111,
				0b01110,
				0b00101,
				0b01110,
				0b00100,
				0b01111,
				0b11000,
				0b00000
		},
		{//Goalkeeper
				0b11110,
				0b01110,
				0b10101,
				0b01110,
				0b00100,
				0b01110,
				0b01011,
				0b01001
		},
		{//Keeper slide
				0b00000,
				0b00000,
				0b01111,
				0b00111,
				0b01010,
				0b00111,
				0b01010,
				0b11110
		},
		{//Trophy
				0b11011,
				0b10001,
				0b11111,
				0b01110,
				0b11111,
				0b01110,
				0b00100,
				0b01110
		},
		{//Goal scored
				0b00000,
				0b11110,
				0b00010,
				0b01110,
				0b01110,
				0b00010,
				0b11110,
				0b00000
		}
};

u8 playerY = 10;

int main(){
	DIO_voidInit();
	LCD_voidInit();
	LoadSpecialChars();

	while(1){
		PlayerTrains();
		Player1v1();
		PlayerShoots();
		PlayerCelebrates();
		PlayerCeremony();
	}
	return 0;
}

void LoadSpecialChars(){
	u8 index = 0;
	for(index = 0; index < 8; index++){
		LCD_voidDisplaySpecialChar(SpecialChars[index], index, 0, 0);
	}
	LCD_voidSendCommand(LCD_ClearDisplay);
}

void PlayerTrains(){
	while(playerY < 20){
		LCD_voidGoToPosition(1,playerY);
		LCD_voidWriteChar(PLAYER_RUN_1);
		LCD_voidGoToPosition(3,4);
		LCD_voidWriteString((u8*) "Match Warm-up");
		_delay_ms(FRAME_DELAY_MS-50);
		LCD_voidSendCommand(LCD_ClearDisplay);
		LCD_voidGoToPosition(1,playerY);
		LCD_voidWriteChar(PLAYER_RUN_2);
		LCD_voidGoToPosition(3,4);
		LCD_voidWriteString((u8*) "Match Warm-up");
		_delay_ms(FRAME_DELAY_MS-50);
		LCD_voidSendCommand(LCD_ClearDisplay);
		LCD_voidGoToPosition(1,playerY);
		LCD_voidWriteChar(PLAYER_RUN_3);
		LCD_voidGoToPosition(3,4);
		LCD_voidWriteString((u8*) "Match Warm-up");
		_delay_ms(FRAME_DELAY_MS-50);
		LCD_voidSendCommand(LCD_ClearDisplay);
		playerY++;
	}
}

void Player1v1(){
	playerY = 10;
	while(playerY < 20){
		PlayerMove();
	}
	playerY = 6;
	while(playerY < 14){
		DribbleEnemy();
	}
}

void PlayerMove(){
	LCD_voidGoToPosition(1,playerY);
	LCD_voidWriteChar(PLAYER_RUN_1);
	LCD_voidWriteChar(BALL_GROUND);
	LCD_voidGoToPosition(3,0);
	LCD_voidWriteString((u8*) "Salah gets the ball!");
	_delay_ms(FRAME_DELAY_MS - 100);
	LCD_voidSendCommand(LCD_ClearDisplay);
	LCD_voidGoToPosition(1,playerY);
	LCD_voidWriteChar(PLAYER_RUN_2);
	LCD_voidWriteChar(BALL_AIR);
	LCD_voidGoToPosition(3,0);
	LCD_voidWriteString((u8*) "Salah gets the ball!");
	_delay_ms(FRAME_DELAY_MS - 100);
	LCD_voidSendCommand(LCD_ClearDisplay);
	LCD_voidGoToPosition(1,playerY);
	LCD_voidWriteChar(PLAYER_RUN_3);
	LCD_voidWriteChar(BALL_GROUND);
	LCD_voidGoToPosition(3,0);
	LCD_voidWriteString((u8*) "Salah gets the ball!");
	_delay_ms(FRAME_DELAY_MS - 100);
	LCD_voidSendCommand(LCD_ClearDisplay);
	playerY++;
}

void DribbleEnemy(){
	if(playerY < 9 || playerY == 12) {
		LCD_voidGoToPosition(1,playerY);
		LCD_voidWriteChar(PLAYER_RUN_1);
		LCD_voidWriteChar(BALL_GROUND);
		LCD_voidGoToPosition(1,10);
		LCD_voidWriteChar(GOALKEEPER);
		LCD_voidGoToPosition(1,15);
		LCD_voidWriteChar(GOAL_POST);
		if(playerY < 9)
		{
			LCD_voidGoToPosition(3,2);
			LCD_voidWriteString((u8*) "Salah vs Keeper!");
		}
		else{
			LCD_voidGoToPosition(3,5);
			LCD_voidWriteString((u8*) "Open goal");
		}
		_delay_ms(FRAME_DELAY_MS);
		LCD_voidSendCommand(LCD_ClearDisplay);
		LCD_voidGoToPosition(1,playerY);
		LCD_voidWriteChar(PLAYER_RUN_2);
		LCD_voidWriteChar(BALL_AIR);
		LCD_voidGoToPosition(1,10);
		LCD_voidWriteChar(GOALKEEPER);
		LCD_voidGoToPosition(1,15);
		LCD_voidWriteChar(GOAL_POST);
		if(playerY < 9)
		{
			LCD_voidGoToPosition(3,2);
			LCD_voidWriteString((u8*) "Salah vs Keeper!");
		}
		else{
			LCD_voidGoToPosition(3,5);
			LCD_voidWriteString((u8*) "Open goal");
		}
		_delay_ms(FRAME_DELAY_MS);
		LCD_voidSendCommand(LCD_ClearDisplay);
		LCD_voidGoToPosition(1,playerY);
		LCD_voidWriteChar(PLAYER_RUN_3);
		LCD_voidWriteChar(BALL_GROUND);
		LCD_voidGoToPosition(1,10);
		LCD_voidWriteChar(GOALKEEPER);
		LCD_voidGoToPosition(1,15);
		LCD_voidWriteChar(GOAL_POST);
		if(playerY < 9)
		{
			LCD_voidGoToPosition(3,2);
			LCD_voidWriteString((u8*) "Salah vs Keeper");
		}
		else{
			LCD_voidGoToPosition(3,5);
			LCD_voidWriteString((u8*) "Open goal");
		}
		_delay_ms(FRAME_DELAY_MS);
		LCD_voidSendCommand(LCD_ClearDisplay);
	}
	else if(playerY == 9){
		LCD_voidGoToPosition(1,playerY);
		LCD_voidWriteChar(PLAYER_RUN_3);
		LCD_voidWriteChar(BALL_AIR);
		LCD_voidGoToPosition(1,10);
		LCD_voidWriteChar(KEEPER_SLIDE);
		LCD_voidGoToPosition(1,15);
		LCD_voidWriteChar(GOAL_POST);
		LCD_voidGoToPosition(3,5);
		LCD_voidWriteString((u8*) "Keeper slides!");
		_delay_ms(FRAME_DELAY_MS);
		LCD_voidSendCommand(LCD_ClearDisplay);
	}
	else if(playerY < 12){
		LCD_voidGoToPosition(0,playerY);
		LCD_voidWriteChar(PLAYER_JUMP);
		LCD_voidWriteChar(BALL_AIR);
		LCD_voidGoToPosition(1,10);
		LCD_voidWriteChar(KEEPER_SLIDE);
		LCD_voidGoToPosition(1,15);
		LCD_voidWriteChar(GOAL_POST);
		LCD_voidGoToPosition(3,5);
		LCD_voidWriteString((u8*) "Salah jumps!");
		_delay_ms(FRAME_DELAY_MS+200);
		LCD_voidSendCommand(LCD_ClearDisplay);
	}
	else{
		LCD_voidGoToPosition(1,playerY);
		LCD_voidWriteChar(PLAYER_RUN_1);
		LCD_voidWriteChar(BALL_GROUND);
		LCD_voidGoToPosition(1,11);
		LCD_voidWriteChar(PLAYER_RUN_1);
		LCD_voidGoToPosition(1,15);
		LCD_voidWriteChar(GOAL_POST);
		LCD_voidGoToPosition(3,5);
		LCD_voidWriteString((u8*) "Salah shoots!");
		_delay_ms(FRAME_DELAY_MS);
		LCD_voidSendCommand(LCD_ClearDisplay);
		LCD_voidGoToPosition(1,playerY);
		LCD_voidWriteChar(PLAYER_RUN_2);
		LCD_voidWriteChar(BALL_AIR);
		LCD_voidGoToPosition(1,12);
		LCD_voidWriteChar(PLAYER_RUN_1);
		LCD_voidGoToPosition(1,15);
		LCD_voidWriteChar(GOAL_POST);
		LCD_voidGoToPosition(3,5);
		LCD_voidWriteString((u8*) "Salah shoots!");
		_delay_ms(FRAME_DELAY_MS);
		LCD_voidSendCommand(LCD_ClearDisplay);
		LCD_voidGoToPosition(1,playerY);
		LCD_voidWriteChar(PLAYER_RUN_3);
		LCD_voidGoToPosition(1,playerY+2);
		LCD_voidWriteChar(BALL_AIR);
		LCD_voidGoToPosition(1,12);
		LCD_voidWriteChar(PLAYER_RUN_1);
		LCD_voidGoToPosition(1,15);
		LCD_voidWriteChar(GOAL_POST);
		LCD_voidGoToPosition(3,5);
		LCD_voidWriteString((u8*) "Salah shoots!");
		_delay_ms(FRAME_DELAY_MS);
		LCD_voidSendCommand(LCD_ClearDisplay);
	}
	playerY++;
}

void PlayerShoots(){
	LCD_voidGoToPosition(1,13);
	LCD_voidWriteChar(PLAYER_RUN_3);
	LCD_voidGoToPosition(1,12);
	LCD_voidWriteChar(PLAYER_RUN_1);
	LCD_voidGoToPosition(1,15);
	LCD_voidWriteChar(GOAL_SCORED);
	DIO_voidSetPinValue(DIO_PortC, DIO_PIN6, High);
	LCD_voidGoToPosition(3,5);
	LCD_voidWriteString((u8*) "Salah scores!");
	_delay_ms(FRAME_DELAY_MS + 300);
	DIO_voidSetPinValue(DIO_PortC, DIO_PIN6, Low);
}

void PlayerCelebrates(){
	LCD_voidGoToPosition(1,13);
	LCD_voidWriteChar(PLAYER_RUN_1);
	LCD_voidGoToPosition(1,12);
	LCD_voidWriteChar(KEEPER_SLIDE);
	LCD_voidGoToPosition(1,15);
	LCD_voidWriteChar(GOAL_SCORED);
	LCD_voidGoToPosition(3,2);
	LCD_voidWriteString((u8*) "Crowd goes wild!");
	_delay_ms(FRAME_DELAY_MS + 500);
	LCD_voidSendCommand(LCD_ClearDisplay);
	LCD_voidGoToPosition(2,13);
	LCD_voidWriteChar(PLAYER_JUMP);
	LCD_voidGoToPosition(1,12);
	LCD_voidWriteChar(KEEPER_SLIDE);
	LCD_voidGoToPosition(1,15);
	LCD_voidWriteChar(GOAL_SCORED);
	LCD_voidGoToPosition(3,4);
	LCD_voidWriteString((u8*) "SIUUUUUUUUUU!");
	_delay_ms(FRAME_DELAY_MS + 500);
	LCD_voidSendCommand(LCD_ClearDisplay);
	LCD_voidGoToPosition(2,13);
	LCD_voidWriteChar(PLAYER_CELEBRATE);
	LCD_voidGoToPosition(1,12);
	LCD_voidWriteChar(KEEPER_SLIDE);
	LCD_voidGoToPosition(1,15);
	LCD_voidWriteChar(GOAL_SCORED);
	LCD_voidGoToPosition(3,4);
	LCD_voidWriteString((u8*) "SIUUUUUUUUUU!");
	_delay_ms(FRAME_DELAY_MS + 500);
	LCD_voidSendCommand(LCD_ClearDisplay);
}

void PlayerCeremony(){
	LCD_voidGoToPosition(1,9);
	LCD_voidWriteChar(PLAYER_CELEBRATE);
	LCD_voidGoToPosition(1,10);
	LCD_voidWriteChar(TROPHY);
	LCD_voidGoToPosition(3,2);
	LCD_voidWriteString((u8*) "Man of the match");
	_delay_ms(FRAME_DELAY_MS + 1000);
	LCD_voidSendCommand(LCD_ClearDisplay);
}

