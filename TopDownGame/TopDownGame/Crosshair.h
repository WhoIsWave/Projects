#pragma once
#include <SDL.h>
#include "InputState.h"


class Crosshair
{
public:
	Crosshair(int pX, int pY, int w, int h);
	SDL_Rect toRect();
	void draw(SDL_Renderer* renderer);
	void update( int screenHeight, int screenWidth);
	int x;
	int y;

private:
	int width;
	int height;
};