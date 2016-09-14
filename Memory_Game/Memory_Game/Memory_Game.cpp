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

void createBlankArray()
{

}

void createFullArray()
{

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

void printGoodbyeMessage()
{
	cout << "\nThank You For Playing Memory, Have A Great Day . . .\n\n";
}

void memory()
{
	//VARIABLES TO BE USED
	int numPairsFound = 0;
	int boardLength = 0; //x
	int boardWidth = 0; //y
	int playAgain = 0;
	
	bool keepPlaying = true; //IF USER WANTS TO PLAY AGAIN
	bool boardComplete = false; //IF USER HAS GUESSED ALL THE SPOTS CORRECTLY
	
	
	printWelcomeMessage();
	printDirections();

	while((keepPlaying == true) && (boardComplete == false)) //LOOPS AS LONG AS USER WANTS TO PLAY OR BOARD IS COMPLETE
	{
		// GETUSERINPUT
		getBoardLength(boardLength);
		getBoardWidth(boardWidth);
		//GENERATE PAIRS
		generateAmountOfPairs(boardLength, boardWidth);
		
		//DO THE STORING
		
		//PRINTING
		
		//GET USER SPOT GUESSES
		
		//CHECK BOARD	
		
		//numPairsFound++;
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		// < - - - DECIDES WHETHER PLAYER WANTS TO RESTART GAME - - - > //
		cout << "Would You Like To Play Again? Enter 1 for Yes. Otherwise, Enter 2 For No . . .";
		cin >> playAgain; //GETS INPUT AS TO WHETHER USER WANTS TO PLAY AGAIN OR NOT
		while ((playAgain != 1) && (playAgain != 2)) //ERROR CHECKING FOR USER INPUT
		{
			cout << "Try again";
			cin >> let;
		}
	}

	printGoodbyeMessage(); //ENDS GAME
	
}

int main()
{
	memory();
    return 0;
}

