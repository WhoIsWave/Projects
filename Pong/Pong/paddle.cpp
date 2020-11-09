#include "Paddle.h"

Paddle::Paddle(int pX, int pY, int w, int h, int pSpeedY)
	:x(pX), y(pY), width(w), height(h), speedY(pSpeedY)
{

}

SDL_Rect Paddle::toRect()
{
	SDL_Rect rect = { x, y, width, height };
	return rect;
}

void Paddle::draw(SDL_Renderer* renderer)
{
	SDL_Rect rect = toRect();
	SDL_RenderFillRect(renderer, &rect);
}

void Paddle::update(InputState* inputState, int screenHeight)
{
	if (inputState->paddleUp)
	{
		y -= speedY;
		if (y < 0)
		{
			y = 0;
		}
	}

	if (inputState->paddleDown)
	{
		y += speedY;
		if (y > screenHeight - height)
		{
			y = screenHeight - height;
		}
	}
}