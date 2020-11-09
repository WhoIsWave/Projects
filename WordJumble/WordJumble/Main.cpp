#include <iostream>
#include <string>
#include <array>
#include <time.h>
#include <cstdlib>
#include <random>

using std::cout;
using std::cin;
using std::string;
using std::array;
using std::endl;


bool quit = false;


int main(int argc, char** argv)
{
	srand((unsigned int)time(0));
	int randomWord = (rand() % 5);

	array<array<char, 6>, 5> words{ {
		{'c','h','e','e','s','e'},
		{'c','h','e','s','s'},
		{'b','l','e','s','s'},
		{'m','e','s','s'},
		{'g','u','e','s','s'},
	} };

	int wordLength = words[randomWord].size();

	cout << randomWord << endl;

	for (int i = 0; i < wordLength; i++)
	{

		int index1 = rand() % wordLength;
		int index2 = rand() % wordLength;
		char tempLetter;

		tempLetter = words[randomWord][index1];
		words[randomWord][index1] = words[randomWord][index2];
		words[randomWord][index2] = tempLetter;

		if (words[randomWord][index1] == ' ' || words[randomWord][index2] == ' ')
		{
			words[randomWord][index1] = ' ';
		}

	}


	string jumbledWord(begin(words[randomWord]), end(words[randomWord]));
	cout << jumbledWord << endl;

	

}