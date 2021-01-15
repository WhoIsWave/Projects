#include "Player.h"

Player::Player(float pX, float pY, int w, int h, int pSpeedY, int pSpeedX)
	:x(pX), y(pY), width(w), height(h), speedY(pSpeedY), speedX(pSpeedX)
{

}

SDL_Rect Player::toRect()
{
	SDL_Rect rect = { x, y, width, height };
	return rect;
}

void Player::draw(SDL_Renderer* renderer)
{
	SDL_Rect rect = toRect();
	SDL_RenderFillRect(renderer, &rect);
}

void Player::update(InputState* inputState, int screenHeight, int screenWidth)
{
	if (inputState->playerUp)
	{
		y -= speedY;
		if (y < 0)
		{
			y = 0;
		}
	}

	if (inputState->playerDown)
	{
		y += speedY;
		if (y > screenHeight - height)
		{
			y = screenHeight - height;
		}
	}

	if (inputState->playerRight)
	{
		x += speedX;
		if (x < 0)
		{
			x = 0;
		}
	}

	if (inputState->playerLeft)
	{
		x -= speedX;
		if (x > screenWidth - width)
		{
			x = screenWidth - width;
		}
	}
}