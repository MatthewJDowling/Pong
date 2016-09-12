#include "Ball.h"
#include "sfwdraw.h"
#include "Player.h"
#include <random>
#include <time.h>

using namespace sfw;

float randRange(int min, int max)
{
	srand(time(0));
	return rand() % (max - min) + min;
}

balls makeBall(float xPos, float yPos, float xVel, float yVel, float size, unsigned int color)
{


	
	balls ball;
	ball.xPos = xPos; 
	ball.yPos = yPos;
	ball.xVel = randRange(1, 7);
	ball.yVel = randRange(1, 7);
	ball.size = size;
	ball.color = color;

	return ball; 
}

void updateBall(balls &ball, Player &paddle1, Player &paddle2)
{
	ball.xPos += ball.xVel;
	ball.yPos += ball.yVel;
	
	if (ball.yPos >= 600 - ball.size)
	{
		
		ball.yVel *= -1;
	}

	if (ball.yPos < 0)
	{
		ball.yPos = 0;
		ball.yVel *= -1;
	}

	if (ball.xPos >= 800 - ball.size)
	{
		ball.xPos = 390;
		ball.yPos = 300;
	}
	if (ball.xPos <= 0 - ball.size)//spawn in the middle after scoring
	{
		ball.xPos = 390;
		ball.yPos = 300;
	}
	
	if (ball.xPos + ball.size > paddle2.x &&
		ball.yPos - ball.size < paddle2.y + paddle2.size &&
		ball.yPos + ball.size > paddle2.y)
	{
		ball.yVel *= 1;
		ball.xVel *= -1;
	}

	if (ball.xPos - ball.size < paddle1.x && 
		ball.yPos - ball.size < paddle1.y + paddle1.size && 
		ball.yPos + ball.size > paddle1.y)
	{
		ball.yVel *= 1;
		ball.xVel *= -1;
	}
	
}


void drawBall(const balls &ball)
{
	drawCircle(ball.xPos, ball.yPos, ball.size, 12, ball.color);
}