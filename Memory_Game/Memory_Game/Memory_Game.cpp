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

void printWelcomeMessage() //PRINTS WELCOME MESSAGE
{
	cout << "Welcome To MemoryGame v 1.0 . . .\n";
}

void displayNumberedBoard(int columns, int rows) //DISPLAYS THE BOARD WITH NUMBERS (UP TO 100)
{
	int count = 1;
	
	for (int i = 0; i < columns; i++)
	{
		cout << "|";

		for (int j = 0; j < rows; j++)
		{
			cout << "- - - - -|";
		}

		cout << "\n";

		for (int s = 0; s < 3; s++)
		{
			for (int r = 0; r < rows; r++)
			{
				if (s == 1)
				{
					if (count <= 9)
					{
						cout << "|    " << count << "    ";
						count++;
					}
					else if((count > 9) && (count < 100))
					{
						cout << "|   " << count << "    ";
						count++;
					}
					else
					{
						cout << "|  " << count << "    ";
						count++;
					}
					
				}
				else
				{
					cout << "|         ";
				}
				
			}
			
			cout << "|\n";	
		}	
	}
	
	for (int p = 0; p < rows; p++)
	{
		cout << "|- - - - -";
	}

	cout << "|";
	cout << "\n\n";
}

void memory()
{
	//VARIABLES TO BE USED
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

