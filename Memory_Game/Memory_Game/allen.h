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


void printDirections()
{
	writeLine("Hello and welcome to the game of Memory!");
	writeLine("The object of the game is to match pairs of cards face down.");
	writeLine("Or in this case, symbols, that hide to act like cards.\n");
	writeLine("To begin, first enter the x and y values of the first and second cards.");
}

void createBoard(int amountPairs)
{

}

void generateAmountOfPairs(int length, int width)
{
	int numOfPairs = 0;
	int count = 0;
	numOfPairs = length * width;
	numOfPairs /= 2;

	write("Amount of pairs: ");
	writeLine(numOfPairs);

	 //94 max

	createBoard(numOfPairs);


}

