#include "Player.h"
#include "sfwdraw.h"
using namespace sfw;
Player makePlayer(float x, float y, float size, char upKey, char downKey, int score)
{
	Player paddle; //making the attributes of the paddle
	paddle.x = x;
	paddle.y = y;
	paddle.size = size;
	paddle.upKey = upKey;
	paddle.downKey = downKey;
	paddle.score = score;

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
}

void drawPlayer(const Player &paddle)//constructing the paddle
{
	drawLine(paddle.x, paddle.y, paddle.x, paddle.y + paddle.size, WHITE);
}