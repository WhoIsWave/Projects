#include "Crosshair.h"


Crosshair::Crosshair(int pX, int pY, int w, int h)
	:x(pX), y(pY), width(w), height(h)
{

}

SDL_Rect Crosshair::toRect()
{
	SDL_Rect rect = {x, y, width, height};
	return rect;
}

void Crosshair::draw(SDL_Renderer* renderer)
{
	SDL_Rect rect = toRect();
	SDL_RenderFillRect(renderer, &rect);
}

void Crosshair::update(int screenHeight, int screenWidth)
{

	int mouseX, mouseY;
	SDL_GetMouseState(&mouseX, &mouseY);

	x = mouseX;
	y = mouseY;
	/*if (inputState->playerClick)
	{
		x = mouseX;
		y = mouseY;
	}
	*/
}