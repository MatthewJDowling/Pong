#include "sfwdraw.h"

#include "utils.h"

#include "Player.h"
#include "Ball.h"

using namespace sfw;


void main()
{
	Player paddle1 = makePlayer(20, 300, 100, 'W', 'S',/*paddle1.score=*/0);
	Player paddle2 = makePlayer(780, 300, 100, 'O', 'L',/*paddle2.score=*/0);
	balls ball1 = makeBall(390, 300, 6, 6, 10, GREEN);

	initContext(800, 600, "NSFW Draw");

	unsigned f = loadTextureMap("./res/tonc_font.png", 16, 6);
	unsigned d = loadTextureMap("./res/fontmap.png", 16, 16);
	unsigned r = loadTextureMap("./res/background.jpg");

	
	
	

	sfw::setBackgroundColor(BLACK);

	while (stepContext())
	{
		
		drawTexture(r, 0, 600, 800, 600, 0, false, 0, BLUE);
		drawString(f,paddle1.score,paddle2.score,100, 600, 36, 36, ' ', BLUE);
		
		
		updateBall(ball1,paddle1,paddle2);
		drawBall(ball1);
		getP1Score(ball1,paddle1);
		getP2Score(ball1,paddle2);
		
		
		updatePlayer(paddle2);
		drawPlayer(paddle2);
		
		updatePlayer(paddle1);
		drawPlayer(paddle1);
		

		
	

	}
}