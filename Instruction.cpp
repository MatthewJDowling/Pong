#include "Instruction.h"
#include "sfwdraw.h"
#include <cstdio>

using namespace sfw;
void Instructions::init(int a_font)
{
	font = a_font; 
}

void Instructions::draw()
{
	char buffer[80];
	sprintf_s(buffer, "Player 1 Controls\n W to move up\n S to move down \n and E to Spike");
	sfw::drawString(font, buffer, 30, 550, 20, 20);
	sprintf_s(buffer, "Player 2 Controls\n I to move up\n K to move down \n and L to Spike");
	sfw::drawString(font, buffer, 455, 550, 20, 20);
	sprintf_s(buffer, "Protip: Dont try to hold \n down the spike key\n to spike");
	sfw::drawString(font, buffer, 150, 305, 20, 20);
	sprintf_s(buffer, "Press Tab to return to menu");
	sfw::drawString(font, buffer, 50, 25, 20, 20);
}

APP_State Instructions::next()
{
	if (getKey(KEY_TAB))
	{
		return ENTER_SPLASH;
	}
	else
	{
		return INSTRUCTION;
	}
}