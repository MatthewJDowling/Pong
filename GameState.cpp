#include "Ball.h"
#include "Player.h"
#include "sfwdraw.h"
#include "utils.h"
#include "GameState.h"
#include "Splash.h"
using namespace sfw;


void GameState::init()
{
	f = loadTextureMap("./res/tonc_font.png", 16, 6);
	d = loadTextureMap("./res/fontmap.png", 16, 16);
	r = loadTextureMap("./res/background.jpg");
	paddle1 = makePlayer(20, 300, 100, 'W', 'S','E',0);
	paddle2 = makePlayer(780, 300, 100, 'I', 'K','L',0);
	ball1 = makeBall(390, 300, 6, 6, 10, GREEN);
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
	sfw::setBackgroundColor(BLACK);
	drawTexture(r, 0, 600, 800, 600, 0, false, 0, BLUE);
	bool scoreStreak1;
	bool scoreStreak2;

	/*if (scoreStreak1 = true)
	{
		sfw::drawString(f, "SCORE SPREE", 75, 150, 24,24, 0, ' ', GREEN);
	}*/
	if (scoreStreak2 = true)

	if (paddle1.score >= 10 || paddle2.score >= 10)
	{
		sfw::drawString(f, " GG Well Played! ", 75, 300, 36, 36, 0, ' ', GREEN);
		sfw::drawString(f, " Press Enter To Restart", 65, 265, 36, 36, 0, ' ', GREEN);
	}
	else
	{

		drawString(f, paddle1.score, paddle2.score, 100, 600, 36, 36, ' ', GREEN);

		drawBall(ball1);

		drawPlayer(paddle2);

		drawPlayer(paddle1);
	}
}

APP_State GameState::next()
{
	if (paddle1.score >= 10 || paddle2.score >= 10)
	{
		if (sfw::getKey(KEY_ENTER))
		{
			return APP_State::ENTER_GAME;
		}
	}
	
	return APP_State::GAME;
}
