#include "sfwdraw.h"
#include "GameState.h"
#include "utils.h"
#include "Player.h"
#include "Ball.h"
#include "Splash.h"
#include "constdecl.h"
#include "Instruction.h"
using namespace sfw;


void main()
{
	
	initContext(800, 600, "NSFW Draw");
	unsigned font = sfw::loadTextureMap("./res/fontmap.png", 16, 16);
	unsigned f = sfw::loadTextureMap("./res/tonc_font.png", 16, 6);
	unsigned r = loadTextureMap("./res/background.jpg");
	GameState gs;
	Splash splash;
	Instructions control;
	splash.init(font);
	control.init(font);
	 // starting everything
	APP_State state = ENTER_SPLASH;
	while (stepContext())
	{
		sfw::drawTexture(r, 0, 600, 800, 600, 0, false, 0, 0x88888888);
		switch (state)
		{
		case ENTER_SPLASH:
			splash.init(font);
		case SPLASH:
			splash.draw();
			state = splash.next();
			break;
		case INSTRUCTION:
			control.draw();
			state = control.next();
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