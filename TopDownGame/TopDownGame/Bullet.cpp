#include "Bullet.h"
#include "Player.h"
#include "iostream"
#include <vector>

using namespace std;

float angle1;
float bulletSpeed = 2.0;



Bullet::Bullet(float pX, float pY, int w, int h)
	:x(pX), y(pY), width(w), height(h)
{

}

SDL_Rect Bullet::toRect()
{
	SDL_Rect rect = { x, y, width, height };
	return rect;
}

void Bullet::draw(SDL_Renderer* renderer)
{
	SDL_Rect rect = toRect();
	SDL_RenderFillRect(renderer, &rect);
}

void Bullet::update(InputState* inputState, int screenHeight, int screenWidth)
{
	//int mouseX, mouseY;
	//SDL_GetMouseState(&mouseX, &mouseY);
	
	x += vx;
	y += vy;
	
}

void Bullet::setPosition(float xPos, float yPos) //setter function
{
	x = xPos;
	y = yPos;
}

void Bullet::setBulletMove(float pVx, float pVy)
{
	vx = pVx;
	vy = pVy;
}
