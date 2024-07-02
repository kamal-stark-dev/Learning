#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

// global variables
char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';

void resetBoard();
void printBoard();
int checkFreeSpaces();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char);

int main()
{
	char winner = ' ';

	resetBoard();
	while (winner == ' ' && checkFreeSpaces() != 0)
	{
		printBoard();

		playerMove();
		winner = checkWinner();
		if (winner != ' ' || checkFreeSpaces() == 0)
		{
			break;
		}

		computerMove();
		winner = checkWinner();
		if (winner != ' ' || checkFreeSpaces() == 0)
		{
			break;
		}
	}

	printBoard();
	printWinner(winner);
}

void resetBoard()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void printBoard()
{
	printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
	printf("\n---|---|---\n");
	printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
	printf("\n---|---|---\n");
	printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
	printf("\n");
}
int checkFreeSpaces()
{
	int freeSpaces = 9;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] != ' ')
			{
				freeSpaces--;
			}
		}
	}
	return freeSpaces;
}
void playerMove()
{
	int x, y;

	do
	{
		printf("Enter row (1-3): ");
		scanf("%d", &x);
		x--;

		printf("Enter column (1-3): ");
		scanf("%d", &y);
		y--;

		if (board[x][y] != ' ')
		{
			printf("Invalid Move\n");
		}
	} while (board[x][y] != ' ');
	board[x][y] = PLAYER;
}
void computerMove()
{
	// create a seed
	srand(time(0));
	int x, y;

	if (checkFreeSpaces() > 0)
	{
		do
		{
			x = rand() % 3;
			y = rand() % 3;
		} while (board[x][y] != ' ');
		board[x][y] = COMPUTER;
	}
	else
	{
		printWinner(' ');
	}
}
char checkWinner()
{
	// check rows
	for (int i = 0; i < 3; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
		{
			return board[i][0];
		}
	}

	// check columns
	for (int j = 0; j < 3; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j])
		{
			return board[0][j];
		}
	}

	// check diagonals
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
	{
		return board[1][1];
	}
	return ' '; // no winner for now
}
void printWinner(char winner)
{
	if (winner == PLAYER)
	{
		printf("You WIN!!");
	}
	else if (winner == COMPUTER)
	{
		printf("Computer WON :(");
	}
	else
	{
		printf("It's a TIE!!");
	}
}