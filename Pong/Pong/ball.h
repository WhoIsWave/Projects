#pragma once
#include <SDL_rect.h>

class Ball
{
public:
	Ball(int px, int pY, int w, int h,int pSpeedX, int pSpeedY);
	Ball();
	~Ball();

	void update(int screenWidth,int screenHeight);
	
	SDL_Rect toRect();

	void draw(SDL_Renderer* renderer);

private:
	int x;
	int y;
	int width;
	int height;
	int speedX;
	int speedY;
};

