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
char* chars;

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

	if (board[newY][newX] == 'z')
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

			if (board[newY][newX] == 'z')
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

void generatePairs(int x, int y, int spotCount)
{
	int emptyX = 0;
	int emptyY = 0;
	int symbolNum = 0;
	char symbol = ' ';
	int* coordinates;

	//AS MANY SYMBOLS AS NEEDED * 2 FOR SPOT COUNT
	for (int i = 0; i < (x * y / 2); i++)
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

	writeLine(rows);
	writeLine(cols);

	for (int i = 0; i <= cols; i++)
	{
		for (int j = 0; j < rows; j++)
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
			board[j][i] = 'z';
		}
	}
}

int figureLength(int spots)
{
	if (spots % 10 == 0)
	{
		return 10;
	}
	else if (spots % 9 == 0)
	{
		return 9;
	}
	else if (spots % 8 == 0)
	{
		return 8;
	}
	else if (spots % 7 == 0)
	{
		return 7;
	}
	else if (spots % 6 == 0)
	{
		return 6;
	}
	else if (spots % 5 == 0)
	{
		return 5;
	}
	else if (spots % 4 == 0)
	{
		return 4;
	}
	else if (spots % 3 == 0)
	{
		return 3;
	}
	else
	{
		return 2;
	}
}

void convertToSingleArray(int leg, int wid)
{
	int counter = 0;
	char spot = ' ';

	for (int i = 0; i < leg; i++)
	{
		for (int j = 0; j < wid; j++)
		{
			spot = board[j][i];
			chars[counter] = spot;
			counter++;
		}
	}
}

void generateAmountOfPairs(int numOfPairs)
{
	chars = B;

	int length = 0;
	int width = 0;
	int count = 0;
	int spotCount = 0;

	spotCount = numOfPairs * 2;

	//FIGURE BEST AMOUNT BASED ON AMOUNT OF PAIRS
	length = figureLength(spotCount);
	width = spotCount / length;

	write("There are ");
	write(numOfPairs);
	writeLine(" pairs. Good luck!");

	initializeBoard(length, width);

	generatePairs(length, width, spotCount);

	convertToSingleArray(length, width);
}

