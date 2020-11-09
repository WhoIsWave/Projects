#include <iostream>
#include <array>
#include <time.h>

using namespace std;

void DrawBoard();
void PlayerInput();
void CheckPossibilitesAI(char aiChoice);
void CheckPossibilites(char playerChoice);
void ChooseXO();
void AI_Input();
array<array<char, 3>, 3>* UpdateBoard(array<array<char, 3>, 3>* pBoardPos);
array<array<char, 3>, 3> board = { {{'0','1','2'},{'3', '4', '5'},{'6', '7', '8'}} };
array<array<char, 3>, 3>* pBoard;


bool gameOver = false;
bool gameStart = false;
int playerChoiceSlot;
int playerChoice;
char AI_Choice;

int main(int argc, char* args[])
{
	pBoard = &board;

	gameStart = true;
	if (gameStart == true)
	{
		DrawBoard();
		ChooseXO();
	}

	while (!gameOver)
	{
		DrawBoard();
		PlayerInput();
		AI_Input();
		UpdateBoard(pBoard);
		CheckPossibilites(playerChoice == 0 ? 'O':'X'); // if playerChoice == 0 set it to 'O' else set it to 'X'
		CheckPossibilitesAI(AI_Choice == 0 ? 'O' : 'X');
	}

	return 0;
}

void DrawBoard()
{
	cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << endl;
	cout << " ----+-----+-----" << endl;
	cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << endl;
	cout << " ----+-----+-----" << endl;
	cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << endl;
}


void PlayerInput()
{
	cout << "Now choose a slot on the board (0-8): " << endl;
	cin >> playerChoiceSlot;
}

void ChooseXO()
{
	cout << "Choose to be either O or X (0-1): " << endl;
	cin >> playerChoice;
	AI_Choice = playerChoice == 0 ? 'X' : 'O'; // if playerChoice == 0, set AI_choice to 'X' else set it to 'O'
}

void CheckPossibilites(char playerChoice)
{
	bool winner = false;

	bool rowOneAcross = board[0][0] == playerChoice && board[0][1] == playerChoice && board[0][2] == playerChoice;
	bool rowTwoAcross = board[1][0] == playerChoice && board[1][1] == playerChoice && board[1][2] == playerChoice;
	bool rowThreeAcross = board[2][0] == playerChoice && board[2][1] == playerChoice && board[2][2] == playerChoice;
	bool rowOneDown = board[0][0] == playerChoice && board[1][0] == playerChoice && board[2][0] == playerChoice;
	bool rowTwoDown = board[0][1] == playerChoice && board[1][1] == playerChoice && board[2][1] == playerChoice;
	bool rowThreeDown = board[0][2] == playerChoice && board[1][2] == playerChoice && board[2][2] == playerChoice;
	bool leftToRight = board[0][0] == playerChoice && board[1][1] == playerChoice && board[2][2] == playerChoice;
	bool rightToLeft = board[0][2] == playerChoice && board[1][1] == playerChoice && board[2][0] == playerChoice;
	

	if (rowOneAcross || rowTwoAcross || rowThreeAcross || rowOneDown || rowTwoDown || rowThreeDown || leftToRight || rightToLeft) // first row/second/third across
	{
		winner = true;
	}


	if (winner == true)
	{
		cout << "You beat a dumb AI, nice!" << endl;
		gameOver = true;
	}

}

void CheckPossibilitesAI(char aiChoice)
{
	bool ai_wins = false;

	bool rowOneAcross = board[0][0] == AI_Choice && board[0][1] == AI_Choice && board[0][2] == AI_Choice;
	bool rowTwoAcross = board[1][0] == AI_Choice && board[1][1] == AI_Choice && board[1][2] == AI_Choice;
	bool rowThreeAcross = board[2][0] == AI_Choice && board[2][1] == playerChoice && board[2][2] == AI_Choice;
	bool rowOneDown = board[0][0] == AI_Choice && board[1][0] == AI_Choice && board[2][0] == AI_Choice;
	bool rowTwoDown = board[0][1] == AI_Choice && board[1][1] == AI_Choice && board[2][1] == AI_Choice;
	bool rowThreeDown = board[0][2] == AI_Choice && board[1][2] == AI_Choice && board[2][2] == AI_Choice;
	bool leftToRight = board[0][0] == AI_Choice && board[1][1] == AI_Choice && board[2][2] == AI_Choice;
	bool rightToLeft = board[0][2] == AI_Choice && board[1][1] == AI_Choice && board[2][0] == AI_Choice;


	if (rowOneAcross || rowTwoAcross || rowThreeAcross || rowOneDown || rowTwoDown || rowThreeDown || leftToRight || rightToLeft) // first row/second/third across
	{
		ai_wins = true;
	}


	if (ai_wins == true)
	{
		cout << "The AI Won! Lol how did you lose to a dumb AI?" << endl;
		gameOver = true;
	}

}

void AI_Input()
{
	
	
}

array<array<char, 3>, 3>* UpdateBoard(array<array<char, 3>, 3>* pBoardPos)
{
	srand((unsigned int)time(0));
	bool playerX_took_a_spot = false;
	bool playerO_took_a_spot = false;
	bool AI_Chose_Spot = false;
	int AI_Choice_Slot = rand() % 8;
	int x1 = playerChoiceSlot / 3;
	int x2 = playerChoiceSlot % 3;

	int AI_x1 = AI_Choice_Slot / 3;
	int AI_x2 = AI_Choice_Slot % 3;

	if (playerChoice == 0 && (*pBoardPos)[x1][x2] != 'O'  && (*pBoardPos)[x1][x2] != 'X' && (*pBoardPos)[AI_x1][AI_x2] != 'X' && (*pBoardPos)[AI_x1][AI_x2] != 'O')
	{
		(*pBoardPos)[x1][x2] = 'O';
		playerO_took_a_spot = true;
	}

	else if (playerChoice == 1 && (*pBoardPos)[x1][x2] != 'X' && (*pBoardPos)[x1][x2] != 'O' && (*pBoardPos)[AI_x1][AI_x2] != 'X' && (*pBoardPos)[AI_x1][AI_x2] != 'O')
	{
		(*pBoardPos)[x1][x2] = 'X';
		playerX_took_a_spot = true;
	}

	if (AI_Choice == 'X' && playerO_took_a_spot == true)
	{
		AI_Chose_Spot = false;
		do
		{
			srand((unsigned int)time(0));
			AI_Choice_Slot = rand() % 8;

			if (AI_Choice_Slot != playerChoiceSlot && (*pBoardPos)[AI_x1][AI_x2] != 'O' && (*pBoardPos)[AI_x1][AI_x2] != 'X')
			{
				(*pBoardPos)[AI_x1][AI_x2] = 'X';
				AI_Chose_Spot = true;
				cout << "AI found spot" << endl;
			}
		} while (AI_Chose_Spot == false);

	}

	else if (AI_Choice == 'O' && playerX_took_a_spot == true)
	{
		AI_Chose_Spot = false;
		do
		{
			srand((unsigned int)time(0));
			AI_Choice_Slot = rand() % 8;

			if (AI_Choice_Slot != playerChoiceSlot && (*pBoardPos)[AI_x1][AI_x2] != 'O' && (*pBoardPos)[AI_x1][AI_x2] != 'X')
			{
				(*pBoardPos)[AI_x1][AI_x2] = 'O';
				AI_Chose_Spot = true;
				cout << "The AI picked a spot" << endl;
			}
		} while (AI_Chose_Spot == false);
	}

	else
	{
		playerO_took_a_spot = false;
		playerX_took_a_spot = false;
		cout << "This spot is already taken." << endl;
	}

	
	return pBoardPos;
}