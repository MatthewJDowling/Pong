#include "sfwdraw.h"
#include "Player.h"
#include "deathBall.h"
#include "Ball.h"
using namespace sfw;


void main()
{
	Player paddle1 = makePlayer(20, 300, 100, 'W', 'S');
	Player paddle2 = makePlayer(780, 300, 100, 'O', 'L');
	balls ball1 = makeBall(390, 300, 6, 6, 10, RED);

	sfw::initContext(800, 600, "NSFW Draw");

	unsigned f = sfw::loadTextureMap("./res/tonc_font.png", 16, 6);
	unsigned d = sfw::loadTextureMap("./res/fontmap.png", 16, 16);
	unsigned r = sfw::loadTextureMap("./res/background.jpg");


	
	

	sfw::setBackgroundColor(BLACK);

	while (sfw::stepContext())
	{
		drawString(f, "Pong", 100, 600, 48, 48, 0, ' ');
		drawTexture(r, 0, 600, 800, 600, 0, false, 0, RED);
		
		updateBall(ball1);
		drawBall(ball1);

		updatePlayer(paddle2);
		drawPlayer(paddle2);
		
		updatePlayer(paddle1);
		drawPlayer(paddle1);
		

		
	

	}
}