#include "Player.h"
#include "sfwdraw.h"
#include <cstdio>

using namespace sfw;
Player makePlayer(float x, float y, float size, char upKey, char downKey,char spikeKey,int score)
{
	Player paddle; //making the attributes of the paddle
	paddle.x = x;
	paddle.y = y;
	paddle.size = size;
	paddle.upKey = upKey;
	paddle.downKey = downKey;
	paddle.score = score;
	paddle.spikeKey = spikeKey;
	paddle.spikeKeyState = Player::KEYSTATE::UP;
	return paddle;
}

void updatePlayer(Player &paddle)
{
	if (getKey(paddle.downKey))// preventing the paddle from going to far down
	{
		if (paddle.y > 0) 
		{
			paddle.y -= 5;
		}
		else 
		{
			paddle.y -= 0;
		}
	}

	if (getKey(paddle.upKey))//preventing the paddle from going to far up
	{
		if (paddle.y < 500)
		{
			paddle.y += 5;
		}
		else
		{
			paddle.y += 0;
		}
	}


	if((paddle.spikeKeyState == Player::KEYSTATE::UP || paddle.spikeKeyState == Player::KEYSTATE::RELEASE) &&
		sfw::getKey(paddle.spikeKey))
	{
		paddle.spikeKeyState = Player::KEYSTATE::PRESS;
	}
	else if ((paddle.spikeKeyState == Player::KEYSTATE::DOWN||
		paddle.spikeKeyState == Player::KEYSTATE::PRESS) &&
		!sfw::getKey(paddle.spikeKey))
	{
		paddle.spikeKeyState = Player::KEYSTATE::RELEASE;
	}
	else if (paddle.spikeKeyState == Player::KEYSTATE::PRESS)
	{
		paddle.spikeKeyState = Player::KEYSTATE::DOWN;
	}
	else if (paddle.spikeKeyState == Player::KEYSTATE::RELEASE)
	{
		paddle.spikeKeyState = Player::KEYSTATE::UP;
	}
}

void drawPlayer(const Player &paddle)//constructing the paddle
{
	drawLine(paddle.x, paddle.y, paddle.x, paddle.y + paddle.size, WHITE);
}