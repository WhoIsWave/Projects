#pragma once
#include <iostream>
using namespace std;

class Tamagochi 
{

public:
	Tamagochi(int pHunger, int pBordem);
	Tamagochi();
	void eat();
	void talk();
	void play();
	void decreaseStats();
	bool death();

private:
	int hunger;
	int happiness;
};
