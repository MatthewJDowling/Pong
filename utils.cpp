#include "utils.h"
#include <cstdio>
#include "Player.h"
#include "Ball.h"
#include "Score.h"

void drawString(unsigned handle, int score1, int score2, float x, float y,
								float width, float height, char offset, unsigned int tint)
{
	char buffer[64];
	
	sprintf_s(buffer, "Score: %d to %d", score2,score1);

	sfw::drawString(handle, buffer,x,y,width,height, 0, offset, tint);
	//void drawString(unsigned handle, const char *text, float x, float y, float width = 1, float height = 1, float angle = 0, char offset = '\0', unsigned int tint = WHITE, const float transform[16] = identity);
	
}
