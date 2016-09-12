// Memory_Game.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "allenMethodLibrary.h" //My useful library

//OUR METHOD HEADERS
#include "allen.h"
#include "dave.h"
#include "derek.h"
#include "jared.h"

#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

//2D ARRAYS HERE

void printWelcomeMessage()
{
	cout << "Welcome To MemoryGame v 1.0 . . .\n";
}

void memory()
{
	//VARIBALES TO BE USED
	int numPairsFound = 0;
	int boardLength = 0; //x
	int boardWidth = 0; //y

	printWelcomeMessage();
	printDirections();

	//LOOP THIS BITCH??

	// GETUSERINPUT
	
	//GENERATE PAIRS
	generateAmountOfPairs(boardLength, boardWidth);

	//DO THE STORING

	//PRINTING

	//GET USER SPOT GUESSES

	//CHECK BOARD

	//numPairsFound++;

	//PRINT GOODBYE
}

int main()
{
	memory();
    return 0;
}

