#pragma once
#include <SDL.h>
#include "InputState.h"

class Player
{
public:
	Player(float pX, float pY, int w, int h, int pSpeedY, int pSpeedX);
	SDL_Rect toRect();
	void draw(SDL_Renderer* renderer);
	void update(InputState* inputState, int screenHeight, int screenWidth);
	float x;
	float y;

private: 
	//int x;
	//int y;
	int width;
	int height;
	int speedY;
	int speedX;
};