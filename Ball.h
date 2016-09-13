#pragma once
#include "Player.h"
// Sets up the balls structure and allows for ball 
//related functions to be called in the main 
struct balls
{
	float xPos, yPos;
	float xVel, yVel;
	float size;
	unsigned int color;
	int score; 
};

balls makeBall(float xPos, float yPos, float xVel, float yVel, float size, unsigned int color);
void drawBall(const balls &ball);
void updateBall(balls &ball, Player &paddle1, Player &paddle2);
int getP1Score(balls &ball, Player &paddle1);
int getP2Score(balls &ball, Player &paddle2);