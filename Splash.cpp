#include "Splash.h"
#include "sfwdraw.h"
#include <cstdio>
#include "sfwdraw.h"

using namespace sfw;
void Splash::init(int a_font)
{
	font = a_font;
}

void Splash::draw()
{
	char buffer[64];
	sprintf_s(buffer, "Press ENTER to play.");
	sfw::drawString(font, buffer, 100, 100, 20, 20);
	
}

APP_State Splash::next()
{
	if (getKey(KEY_ENTER))
	{
		return GAME;
	}
	else
	{
		return SPLASH;
	}
}