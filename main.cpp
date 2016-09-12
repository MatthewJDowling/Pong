#include "sfwdraw.h"

#include "utils.h"

#include "Player.h"
#include "Ball.h"

using namespace sfw;


void main()
{
	Player paddle1 = makePlayer(20, 300, 100, 'W', 'S');
	Player paddle2 = makePlayer(780, 300, 100, 'O', 'L');
	balls ball1 = makeBall(390, 300, 6, 6, 10, GREEN);

	initContext(800, 600, "NSFW Draw");

	unsigned f = loadTextureMap("./res/tonc_font.png", 16, 6);
	unsigned d = loadTextureMap("./res/fontmap.png", 16, 16);
	unsigned r = loadTextureMap("./res/background.jpg");

	int score1 = 0;
	int score2 = 0;
	
	

	sfw::setBackgroundColor(BLACK);

	while (stepContext())
	{
		
		drawTexture(r, 0, 600, 800, 600, 0, false, 0, BLUE);
		drawString(f, "Score: %d to %d",score1,score2,320, 500, 36, 36, 0, ' ', BLUE);
		
		
		updateBall(ball1,paddle1,paddle2);
		drawBall(ball1);

		updatePlayer(paddle2);
		drawPlayer(paddle2);
		
		updatePlayer(paddle1);
		drawPlayer(paddle1);
		

		
	

	}
}