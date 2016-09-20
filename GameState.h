#pragma once
#include "Ball.h"
#include "Player.h"
#include "sfwdraw.h"
#include "utils.h"
#include "constdecl.h"

using namespace sfw;

class GameState 
{
	unsigned f;
	unsigned d;
	unsigned r;
	Player paddle1;
	Player paddle2;
	balls ball1;

public:
	void init();
	void update();
	void draw();
	APP_State next();
};