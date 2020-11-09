#include <iostream>
#include <string>
#include "tamagochi.h"
#include <time.h>

using namespace std;

void Menu();
void playerChoiceManagement();
void questionLoop();
void randomEvents();

bool quitGame = false;
string playerChoice;

Tamagochi pet = Tamagochi(50, 50);

int main()
{
	Menu();

	while(!quitGame)
	{
		questionLoop();
		playerChoiceManagement();
		randomEvents();
	}

}

void Menu()
{
	cout << "Welcome to the scuffed version of Tamagochi!" << endl;
	cout << "You have three interactions with your Tamagochi" << endl;
	cout << "You can either play with it, talk to it, or feed it." << endl;
	cout << "Type play, talk, or feed: " << endl;
	cin >> playerChoice;
	playerChoiceManagement();
}

void questionLoop()
{
	cout << "Type play, talk or feed: " << endl;
	cin >> playerChoice;
}

void playerChoiceManagement()
{
	if (playerChoice == "play")
	{
		pet.play();
	}
	
	if (playerChoice == "talk")
	{
		pet.talk();
	}

	else 
	{
		pet.eat();
	}
}

void randomEvents()
{
	srand(time(NULL));
	int number = rand() % 10 + 1;
	if (number == 5)
	{
		cout << "------RAMDON EVENT-------" << endl;
		cout << "Your Tamagochi decided to take a walk around town..." << endl;
		cout << "He suddenly gets jumped by a bunch of Thug Tamagochi!" << endl;
		cout << "Poor Tamagochi... he will be remembered..." << endl;
	}
}