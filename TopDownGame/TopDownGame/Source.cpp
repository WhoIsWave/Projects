#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include "Player.h"
#include "InputState.h"
#include "Crosshair.h"
#include "Bullet.h"
#include "Vector2.h"
#include <math.h>
#include <tgmath.h>
#include <vector>

using namespace std;

Player player = Player(50, 200, 50, 50, 4, 4);
Crosshair crosshair = Crosshair(25,25, 25, 25);
Bullet *bullet = nullptr;
vector<Bullet> &bullet;
InputState inputState;
Vector2 vector2;

bool handleInput();
void update();
void draw(SDL_Renderer*);
void close(SDL_Window* window, SDL_Renderer* renderer);
bool quit = false;

float angle;
float vx;
float vy;

const int bulletSpeed = 4;
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 450;



int main(int argc, char* args[])
{

	void draw(SDL_Renderer*);

	//Window Pointer
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	
	//Initialize Window
	SDL_Init(SDL_INIT_VIDEO);

	window = SDL_CreateWindow("Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	TTF_Init();


	while (!quit)
	{
		quit = handleInput();
		update();
		draw(renderer);
	}

	close(window, renderer);

	return 0;
}


void draw(SDL_Renderer* renderer)
{

	SDL_SetRenderDrawColor(renderer, 0x00, 0x50, 0x00, 0xFF);
	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	player.draw(renderer);

	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	crosshair.draw(renderer);

	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

	if (bullet != nullptr)
	{
		bullet->draw(renderer);
	}

	SDL_RenderPresent(renderer);


}

void close(SDL_Window* window, SDL_Renderer* renderer)
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	TTF_Quit();
}

void update()
{
	player.update(&inputState, SCREEN_HEIGHT, SCREEN_WIDTH);
	crosshair.update(SCREEN_HEIGHT, SCREEN_WIDTH);

	if (bullet != nullptr)
	{
		bullet->update(&inputState, SCREEN_HEIGHT, SCREEN_WIDTH);
	}



	if (inputState.playerClick) // when i click
	{
		// using "new" because bullet is a pointer
		bullet = new Bullet(player.x, player.y, 10, 10); //create a bullet, set its position to the player's 
		//bulletVector.push_back(bullet);
		//void fillVector(vector<Bullet>&myNewBullet);


		//calculate and set its speed
		vector2.x = crosshair.x - player.x;
		vector2.y = crosshair.y - player.y;

		angle = atan2(vector2.y, vector2.x);

		vx = cos(angle) * bulletSpeed; // calculate and set its speed
		vy = sin(angle) * bulletSpeed; // calculate and set its speed

		bullet->setBulletMove(vx, vy);

		cout << vx << endl;
		cout << vy << endl;

		inputState.playerClick = false;
	}
}

bool handleInput()
{
	SDL_Event e;
	//int mouseX, mouseY;
	while (SDL_PollEvent(&e) != 0)
	{
		if (e.type == SDL_KEYDOWN)
		{

			if (e.key.keysym.sym == SDLK_w)
			{
				inputState.playerUp = true;
			}
			else if (e.key.keysym.sym == SDLK_s)
			{
				inputState.playerDown = true;
			}
		}

		if (e.type == SDL_KEYUP)
		{
			if (e.key.keysym.sym == SDLK_w)
			{
				inputState.playerUp = false;
			}
			else if (e.key.keysym.sym == SDLK_s)
			{
				inputState.playerDown = false;
			}
		}

		if (e.type == SDL_KEYDOWN)
		{
			if (e.key.keysym.sym == SDLK_d)
			{
				inputState.playerRight = true;
			}
			else if (e.key.keysym.sym == SDLK_a)
			{
				inputState.playerLeft = true;
			}
		}

		if (e.type == SDL_KEYUP)
		{
			if (e.key.keysym.sym == SDLK_d)
			{
				inputState.playerRight = false;
			}
			else if (e.key.keysym.sym == SDLK_a)
			{
				inputState.playerLeft = false;
			}
		}

		if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT)
		{
			inputState.playerClick = true;
			
			//cout << vx << endl;
			//cout << vy << endl;R

			cout << angle << endl;
			
		}

		else if (e.type == SDL_QUIT)
		{
			return true;
		}

	}
	return false;
}
