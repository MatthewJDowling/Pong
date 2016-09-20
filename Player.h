#pragma once 
//Sets up the Players structure and allows for 
//Player related functions to be called in the main. 
struct Player
{
	float x, y;
	float size;
	int score = 0;
	char upKey, downKey, spikeKey;

	enum KEYSTATE
	{
		UP,		// key is up
		PRESS,	// key has just been pressed
		DOWN,	// key is held down
		RELEASE	// keys has just been released
	};

	KEYSTATE spikeKeyState;
};


Player makePlayer(float x, float y, float size, char upKey, char downKey,char spikeKey,int score);
void updatePlayer(Player &paddle);
void drawPlayer(const Player &paddle);