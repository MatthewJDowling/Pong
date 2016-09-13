#pragma once 
//Sets up the Players structure and allows for 
//Player related functions to be called in the main. 
struct Player
{
	float x, y;
	float size;
	int score = 0;
	char upKey, downKey;
};


Player makePlayer(float x, float y, float size, char upKey, char downKey, int score);
void updatePlayer(Player &paddle);
void drawPlayer(const Player &paddle);