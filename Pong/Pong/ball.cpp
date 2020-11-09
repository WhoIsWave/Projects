#include <SDL.h>
#include "Ball.h"

Ball::Ball(int pX, int pY, int w, int h, int pSpeedX, int pSpeedY)
	: x(pX), y(pY), width(w), height(h), speedX(pSpeedX), speedY(pSpeedY)
{
}

void Ball::update(int screenWidth, int screenHeight)
{	
	x += speedX;
	y += speedY;

	if (y < 0)
	{
		speedY *= -1;
		y = 0;
	}

	if (y > screenHeight - 32)
	{
		speedY *= -1;
		y = screenHeight - 32;
	}

	if (x < 0)
	{
		speedX *= -1;
		x = 0;
	}
	
	if (x > screenWidth - 32)
	{
		speedX *= -1;
		x = screenWidth - 32;
	}
}

Ball::Ball()
	:x(0), y(0), width(32), height(32), speedX(6), speedY(6)
{}

Ball::~Ball()
{}

SDL_Rect Ball::toRect()
{
	SDL_Rect rect = { x, y, width, height };
	return rect;
}

void Ball::draw(SDL_Renderer* renderer)
{
	SDL_Rect rect = toRect();
	SDL_RenderFillRect(renderer, &rect);
}