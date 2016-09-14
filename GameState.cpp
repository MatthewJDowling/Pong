#include "Ball.h"
#include "Player.h"
#include "sfwdraw.h"
#include "utils.h"
#include "GameState.h"
using namespace sfw;


void GameState::init()
{	sfw::setBackgroundColor(BLACK);
	drawTexture(r, 0, 600, 800, 600, 0, false, 0, BLUE);
}

void GameState::update()
{
	updateBall(ball1, paddle1, paddle2);
	getP1Score(ball1, paddle1);
	getP2Score(ball1, paddle2);

	updatePlayer(paddle2);
	updatePlayer(paddle1);

}

void GameState::draw()
{
	
	drawString(f, paddle1.score, paddle2.score, 100, 600, 36, 36, ' ', GREEN);

	drawBall(ball1);

	drawPlayer(paddle2);

	drawPlayer(paddle1);

}