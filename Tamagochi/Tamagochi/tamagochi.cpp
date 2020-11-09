#include <iostream>
#include "tamagochi.h"

using namespace std;

Tamagochi::Tamagochi(int pHunger, int pHappiness)
	:hunger(pHunger),happiness(pHappiness)
{
}

Tamagochi::Tamagochi()
{
	//hunger;
	//bordem;
}

void Tamagochi::talk()
{
	if (hunger < 50)
	{
		cout << "Im hungry..." << endl;
	}

	else
	{
		cout << "Im feeling pretty good! What do you want to do?" << endl;
	}
	
	if (happiness < 50)
	{
		cout << "Im pretty bored..." << endl;
	}

	else 
	{
		cout << "Im not really bored, but I still want to play! What do you want to do?" << endl;
	}
	
}

void Tamagochi::play()
{
	if (happiness < 100)
	{
		happiness += 10;
		cout << "hehehehehe, says the little tamagochi, he likes playing!" << endl;
		cout << "Your Tamagochi's happiness is now at " << happiness << "%" << endl;
	}
	
	else 
	{
		cout << "Are you crazy master? Im off an adrenaline high right now, too much playing!" << endl;
	}

}

void Tamagochi::eat()
{
	if (hunger < 100)
	{
		hunger += 10;
		cout << "You feed your Tamagochi" << endl;
		cout << "Pretty anti-climatic right?" << endl;
		cout << "Your Tamagochi's hunger is now at " << hunger << " %" << endl;
	}

	else
	{
		cout << "Are you crazy master, stop shoving stuff in my mouth!" << endl;
		cout << "Your Tamagochi's hunger is at " << hunger << "%" << endl;
	}
}