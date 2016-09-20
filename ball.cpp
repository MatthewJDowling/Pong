#include "Ball.h"
#include "sfwdraw.h"
#include "Player.h"
#include <random>
#include <time.h>

using namespace sfw;




float randRange(int min, int max)//a function so i can get truly random numbers
{
	srand(time(0));
	return rand() % (max - min) + min;
}

balls makeBall(float xPos, float yPos, float xVel, float yVel, float size, unsigned int color)
{


	
	balls ball;
	ball.xPos = xPos; 
	ball.yPos = yPos;
	ball.xVel = randRange(7, 10);
	ball.yVel = randRange(7, 10);
	ball.size = size;
	ball.color = color;
	
	return ball; 

	
}

int getP1Score(balls &ball, Player &paddle1)
{

	if (ball.xPos >= 800 - ball.size)
	{
		
		paddle1.score++;
		return paddle1.score;
	}
}

int getP2Score(balls &ball, Player &paddle2)
{
	if (ball.xPos < 0 - ball.size)
	{

		paddle2.score++;
		return paddle2.score;
	}
}

float dist(float x1, float y1, float x2, float y2)
{
	float term1 = (x1 - x2) * (x1 - x2);
	float term2 = (y1 - y2) * (y1 - y2);

	return sqrt(term1 + term2);
}

void updateBall(balls &ball, Player &paddle1, Player &paddle2)
{
	ball.xPos += ball.xVel;
	ball.yPos += ball.yVel;
	
	if (ball.yPos >= 600 - ball.size)//boundry setting
	{
		
		ball.yVel *= -1;
	}

	if (ball.yPos < 0)
	{
		ball.yPos = 0;
		ball.yVel *= -1;
	}

	if (ball.xPos >= 800 - ball.size)//reseting the ball, changing the score and speed
	{
		ball.xPos = 390;
		ball.yPos = 300;
		ball.xVel = randRange(7, 10);
		ball.yVel = randRange(7, 10);
		paddle2.score++;
		ball.color = WHITE;
	}
	if (ball.xPos <= 0 - ball.size)//reseting the ball, changing the score and speed
	{
		ball.xPos = 390;
		ball.yPos = 300;
		ball.xVel = randRange(7, 10);
		ball.yVel = randRange(7, 10);
		paddle1.score++;
		ball.color = WHITE;
	}
	
	if (ball.xPos + ball.size > paddle2.x &&//collision/detction
		ball.yPos - ball.size < paddle2.y + paddle2.size &&
		ball.yPos + ball.size > paddle2.y)
	{
		ball.yVel *= 1;
		ball.xVel *= -1;
		ball.color = WHITE;
	}

	if (ball.xPos - ball.size < paddle1.x && //collision/dectection
		ball.yPos - ball.size < paddle1.y + paddle1.size && 
		ball.yPos + ball.size > paddle1.y)
	{
		ball.yVel *= 1;
		ball.xVel *= -1;
		ball.color = WHITE;
	}

	// calculate distance between paddle midpoint and left of ball
	float distance = dist((ball.xPos - ball.size), ball.yPos, paddle1.x, paddle1.y + paddle1.size / 2);
	// check if distance is within threshold for spiking
	if (distance <= 30.0f && paddle1.spikeKeyState == Player::KEYSTATE::PRESS)
	{
		printf("something family friendly\n");
		ball.xVel += 20;
		ball.yVel = 0;
		ball.color = RED; 
	}

	// PAD MID and RIGHT OF BALL
	float distance1 = dist((ball.xPos + ball.size),
							ball.yPos,
							paddle2.x,
							paddle2.y + paddle2.size / 2);

	//printf("%f\n", distance1);

	if (distance1 <= 30.0f && paddle2.spikeKeyState == Player::KEYSTATE::PRESS)
	{
		printf("something family friendly2\n");
		ball.xVel += 20;
		ball.yVel = 0;
		ball.color = RED;
	}
	// UP		// not pressed at all
	// PRESS	// first frame pressed
	// HOLD		// continous pressing
	// RELEASE  // first frame up

}


void drawBall(const balls &ball)//making the ball appear
{
	drawCircle(ball.xPos, ball.yPos, ball.size, 12, ball.color);
}