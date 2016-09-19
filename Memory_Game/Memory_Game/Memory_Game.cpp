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

//ADDED TO DAVE.h

void printGoodbyeMessage()
{
	cout << "\nThank You For Playing Memory, Have A Great Day . . .\n\n";
}

void memory()
{
	//VARIABLES TO BE USED
	int cookies = 0;
	int numPairsFound = 0;
	int numPairs = 0;
	int userSpotA = 0;
	int userSpotB = 0;
	int playAgain = 0;
	int rows;
	int numMatches = 0;
	int maxMatches = 0;
	int columns;
	int* boardSize;
	bool startingNewGame = true;

	bool keepPlaying = true; //IF USER WANTS TO PLAY AGAIN
	bool boardComplete = false; //IF USER HAS GUESSED ALL THE SPOTS CORRECTLY

	instatainiateDaveArrays();

	printWelcomeMessage();
	printDirections();

	while (keepPlaying == true) //LOOPS AS LONG AS USER WANTS TO PLAY OR BOARD IS COMPLETE
	{
		if (startingNewGame == true) //HAPPENS ONLY IF A NEW GAME STARTS
		{
			//reset everything
			for (int k = 0; k < 100; k++)
			{
				A[k] = false;
			}

			numMatches = 0;
			numPairs = 0;

			// GETUSERINPUT
			//TODO: JARED, CHANGE THIS TO YOUR METHOD NAME 
			numPairs = getNumPairs();

			//GENERATE PAIRS
			boardSize = generateAmountOfPairs(numPairs);
			rows = boardSize[0];
			columns = boardSize[1];

			maxMatches = rows * columns;
			maxMatches /= 2;

			//PRINTS NUMBERED BOARD
			displayNumberedBoard(rows, columns);

			startingNewGame = false; //GAME STARTED
		}
		else //GAME IS RUNNING 
		{
			//GET USER SPOT GUESSES
			userSpotA = getCoordinate(); //IDEA...
			userSpotB = getCoordinate(); //IDEA...

			if ((userSpotA == -1) || (userSpotB == -1))
			{
				return;
			}

			//IF USER SPOT GUESSES ARE A MATCH, INCREMENT A COUNTER ... 

			while ((userSpotA == userSpotB) || (A[userSpotA] == true) || (A[userSpotB] == true))
			{
				if (userSpotA == userSpotB)
				{
					writeLine("\nYou cannot enter the same number.\n");
					userSpotA = getCoordinate();
					userSpotB = getCoordinate();
				}
				else
				{
					writeLine("\nYou cannot select one that has been matched.\n");
					userSpotA = getCoordinate();
					userSpotB = getCoordinate();
				}

				if ((userSpotA == -1) || (userSpotB == -1))
				{
					return;
				}
			}

			if (B[userSpotA] == B[userSpotB])
			{
				A[userSpotA] = true;
				A[userSpotB] = true;

				writeLine("\nYou got a match!\n");
				numMatches++;

				displayNumberedBoard(rows, columns);
			}
			else
			{
				A[userSpotA] = true;
				A[userSpotB] = true;

				writeLine("\nIt was not a match.\n");

				displayNumberedBoard(rows, columns);

				A[userSpotA] = false;
				A[userSpotB] = false;
			}

			//CHECK BOARD

			if (numMatches == numPairs)
			{
				writeLine("\n\nYou completed memory, you earned yourself a cookie!\n");
				cookies++;
				write("Current cookie count: ");
				writeLine(cookies);
				write("\n");

				// < - - - DECIDES WHETHER PLAYER WANTS TO RESTART GAME - - - > //
				cout << "Would You Like To Play Again? Enter 1 for Yes. Otherwise, Enter 2 For No . . .\n";
				cin >> playAgain; //GETS INPUT AS TO WHETHER USER WANTS TO PLAY AGAIN OR NOT
				while ((playAgain != 1) && (playAgain != 2)) //ERROR CHECKING FOR USER INPUT
				{
					cout << "Try again";
					cin >> playAgain;
				}

				if (playAgain == 1)
				{
					cout << "\nStarting New Game . . .\n\n";
					startingNewGame = true;
				}
				else
				{
					keepPlaying = false;
					printGoodbyeMessage(); //ENDS GAME
				}
			}
		}
	}

	
}

int main()
{
	memory();
	return 0;
}
