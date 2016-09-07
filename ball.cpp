#include "Ball.h"
#include "sfwdraw.h"
#include "Player.h"
#include <random>
#include <time.h>
using namespace sfw;

balls makeBall(float xPos, float yPos, float xVel, float yVel, float size, unsigned int color)
{


	srand(time(NULL));
	balls ball;
	ball.xPos = xPos; 
	ball.yPos = yPos;
	ball.xVel = rand() % 10 + 1;
	ball.yVel = rand() % 10 + 1;
	ball.size = size;
	ball.color = color;

	return ball; 
}

void updateBall(balls &ball, Player &paddle1, Player &paddle2)
{
	ball.xPos += ball.xVel;
	ball.yPos += ball.yVel;

	if (ball.yPos > 600 - ball.size)
	{
		
		ball.yVel *= -1;
	}

	if (ball.yPos < 0)
	{
		ball.yPos = 0;
		ball.yVel *= -1;
	}

	if (ball.xPos > 800 - ball.size)
	{
		ball.xPos = 390;
		ball.yPos = 300;
	}
	if (ball.xPos < 0 - ball.size)
	{
		ball.xPos = 390;
		ball.yPos = 300;
	}
	
	if (ball.yPos > paddle2.y && ball.xPos = paddle2.x)
	{
		ball.yVel *= -1;
	}
	
}


void drawBall(const balls &ball)
{
	drawCircle(ball.xPos, ball.yPos, ball.size, 12, ball.color);
}