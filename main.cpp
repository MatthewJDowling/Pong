#include "sfwdraw.h"
#include "GameState.h"
#include "utils.h"
#include "Player.h"
#include "Ball.h"
#include "Splash.h"
#include "constdecl.h"
using namespace sfw;


void main()
{
	
	initContext(800, 600, "NSFW Draw");
	unsigned font = sfw::loadTextureMap("./res/fontmap.png", 16, 16);
	

	GameState gs;
	Splash splash;

	splash.init(font);
	 // starting everything
	APP_State state = ENTER_SPLASH;
	while (stepContext())
	{
		switch (state)
		{
		case ENTER_SPLASH:
			splash.init(font);
		case SPLASH:
			splash.draw();
			state = splash.next();
			break;
		case ENTER_GAME:
			gs.init();

		case GAME:
			gs.update();
			gs.draw();
			state = gs.next();
			break;
		}
		
		
	}
}