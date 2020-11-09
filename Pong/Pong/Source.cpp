#include <SDL.h>
#include <SDL_ttf.h>
#include "Ball.h"
#include "Paddle.h"
#include "InputState.h"

Paddle leftPaddle = Paddle(0, 200, 32, 128, 4);
Ball ball = Ball{ 0,0,32,32,6,6 };
InputState inputState;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 450;
bool quit = false;


void load();
bool handleInput();
void update();
void draw(SDL_Renderer*);
void close(SDL_Window*, SDL_Renderer*);

int main(int argc, char* args[])
{
	void draw(SDL_Renderer*);

	//Window Pointer
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	//Initialize Window
	SDL_Init(SDL_INIT_VIDEO);

	//Create window
	window = SDL_CreateWindow("First Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	TTF_Init();

	//Load 
	load();

	while (!quit)
	{
		//inputs
		quit = handleInput();

		//update
		update();

		//draw
		draw(renderer);

	}

	//End 
	close(window, renderer);

	return 0;
}

void load()
{
	
}

bool handleInput()
{
	SDL_Event e;
	while (SDL_PollEvent(&e) != 0)
	{
		if (e.type == SDL_KEYDOWN)
		{
			if (e.key.keysym.sym == SDLK_w)
			{
				inputState.paddleUp = true;
			}
			else if (e.key.keysym.sym == SDLK_s)
			{
				inputState.paddleDown = true;
			}
		}

		if (e.type == SDL_KEYUP)
		{
			if (e.key.keysym.sym == SDLK_w)
			{
				inputState.paddleUp = false;
			}
			else if (e.key.keysym.sym == SDLK_s)
			{
				inputState.paddleDown = false;
			}
		}

		else if (e.type == SDL_QUIT)
		{
			return true;
		}
	}
	return false;
}

void update()
{
	ball.update(SCREEN_WIDTH, SCREEN_HEIGHT);
	leftPaddle.update(&inputState, SCREEN_HEIGHT);
}


void draw(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x50, 0xFF);
	SDL_RenderClear(renderer);
	
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	ball.draw(renderer);
	leftPaddle.draw(renderer);

	SDL_RenderPresent(renderer);
}

void close(SDL_Window* window, SDL_Renderer* renderer)
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	TTF_Quit();
}

bool AABBcollision(SDL_Rect* rectA, SDL_Rect* rectB)
{
	int xMinA = rectA->x;
	int xMaxA = rectA->x + rectA->w;
	int yMinA = rectA->y;
	int yMaxA = rectA->y + rectA->h;
	int xMinB = rectB->x;
	int xMaxB = rectB->y + rectB->h;
	int yMinB = rectB->y;
	int yMaxB = rectB->y + rectB->h;
	return !(xMinA > xMaxB || xMaxA < xMinA > yMaxB || yMaxA < yMinB);
}