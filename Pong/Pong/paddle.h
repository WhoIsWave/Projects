#pragma once
#include <SDL.h>
#include "InputState.h"

class Paddle
{
public:
	Paddle(int px, int pY, int w, int h, int pSpeedY);
	SDL_Rect toRect();
	void draw(SDL_Renderer* renderer);
	void update(InputState* inputState, int screenHeight);

private:
	int x;
	int y;
	int width;
	int height;
	int speedY;

};