#pragma once
#include <SDL.h>
#include "InputState.h"


class Bullet
{
public:
	Bullet(float pX, float pY, int w, int h);
	SDL_Rect toRect();
	void draw(SDL_Renderer* renderer);
	void update(InputState* inputState, int screenHeight, int screenWidth);
	void setPosition(float xPos, float yPos);
	void setBulletMove(float pVx, float pVy);
	float x;
	float y;
	float vx;
	float vy;
	float speed;

private:
	int width;
	int height;
};