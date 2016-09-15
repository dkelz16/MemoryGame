#pragma once

#include "dave.h"
#include "jared.h"
#include "derek.h"
#include "allenMethodLibrary.h"

#include <string>
#include <iostream>
#include <vector>
#include <array>

using namespace std;

char board[100][100];
char symbols[50];

void printDirections()
{
	writeLine("Hello and welcome to the game of Memory!");
	writeLine("The object of the game is to match pairs of cards face down.");
	writeLine("Or in this case, symbols, that hide to act like cards.\n");
	writeLine("To begin, first enter the x and y values of the first and second cards.");
}

int* findEmptySpot(int x, int y)
{
	int newX = 0;
	int newY = 0;
	int coords[2] = { 0, 0 };
	int maxSpots = 0;
	bool isEmpty = false;

	maxSpots = x * y;
	maxSpots /= 2;

	//GET RANDOM SPOT
	newX = getRandomNumber(x);
	newY = getRandomNumber(y);

	//CHECK IF SPOT NOT EMPTY

	if (board[newY][newX] == ' ')
	{
		isEmpty = true;
		coords[0] = newX;
		coords[1] = newY;
	}
	else
	{
		while (!isEmpty)
		{
			newX = getRandomNumber(x);
			newY = getRandomNumber(y);

			if (board[newY][newX] == ' ')
			{
				coords[0] = newX;
				coords[1] = newY;
				isEmpty = true;
			}
		}
	}

	//IF EMPTY RETURN COORDS

	return coords;
}

void generatePairs(int x, int y)
{
	int emptyX = 0;
	int emptyY = 0;
	int symbolNum = 0;
	char symbol = ' ';
	int* coordinates;

	int totalSpots = x * y;

	//AS MANY SYMBOLS AS NEEDED * 2 FOR SPOT COUNT
	for (int i = 0; i < (totalSpots / 2); i++)
	{
		//SAME SYMB TWICE
		for (int j = 0; j < 2; j++)
		{
			symbolNum = i + 33;
			symbol = (char)symbolNum;

			coordinates = findEmptySpot(x, y);
			emptyX = coordinates[0];
			emptyY = coordinates[1];

			board[emptyY][emptyX] = symbol;
		}
	}
}

void printBoard(int rows, int cols)
{
	for (int i = 0; i <= rows; i++)
	{
		for (int j = 0; j <= cols; j++)
		{
			write(board[i][j]);
			write(" ");
		}
		writeLine(" ");
	}
}

void initializeBoard(int min, int max)
{
	for (int i = 0; i < min; i++)
	{
		for (int j = 0; j < max; j++)
		{
			board[j][i] = ' ';
		}
	}
}

void generateAmountOfPairs(int length, int width)
{
	int numOfPairs = 0;
	int count = 0;
	numOfPairs = length * width;
	numOfPairs /= 2;

	write("There are ");
	write(numOfPairs);
	writeLine(" pairs. Good luck!");

	initializeBoard(length, width);

	generatePairs(length, width);

	printBoard(length, width);
}

