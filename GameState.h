#pragma once
#include "Ball.h"
#include "Player.h"
#include "sfwdraw.h"
#include "utils.h"
using namespace sfw;
class GameState 
{
	unsigned f = loadTextureMap("./res/tonc_font.png", 16, 6);
	unsigned d = loadTextureMap("./res/fontmap.png", 16, 16);
	unsigned r = loadTextureMap("./res/background.jpg");
	Player paddle1 = makePlayer(20, 300, 100, 'W', 'S', 0);
	Player paddle2 = makePlayer(780, 300, 100, 'I', 'K', 0);
	balls ball1 = makeBall(390, 300, 6, 6, 10, GREEN);


	unsigned font;

public:
	void init();
	void update();
	void draw();

	
};

