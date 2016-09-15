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
	int numPairsFound = 0;
	int boardLength = 0; //x
	int boardWidth = 0; //y
	int numPairs = 0;
	int userSpotA = 0;
	int userSpotB = 0;
	int playAgain = 0;
	int rows;
	int columns;
	bool startingNewGame = true;

	bool keepPlaying = true; //IF USER WANTS TO PLAY AGAIN
	bool boardComplete = false; //IF USER HAS GUESSED ALL THE SPOTS CORRECTLY

	instatainiateDaveArrays();

	printWelcomeMessage();
	//printDirections();

	while ((keepPlaying == true) && (boardComplete == false)) //LOOPS AS LONG AS USER WANTS TO PLAY OR BOARD IS COMPLETE
	{
		if (startingNewGame == true) //HAPPENS ONLY IF A NEW GAME STARTS
		{
			// GETUSERINPUT
			//TODO: JARED, CHANGE THIS TO YOUR METHOD NAME 
			numPairs = getNumPairs();
			rows = numPairs / 2;
			columns = numPairs / 2;
			//GENERATE PAIRS
			generateAmountOfPairs(numPairs,2);

			//PRINTS NUMBERED BOARD
			displayNumberedBoard(A, B, rows, columns);

			startingNewGame = false; //GAME STARTED
		}
		else //GAME IS RUNNING 
		{
			//GET USER SPOT GUESSES
			//userSpotA = getInt(); //IDEA...
			//userSpotB = getInt(); //IDEA...

			//GET COORDS FOR BOTH

			//IF USER SPOT GUESSES ARE A MATCH, INCREMENT A COUNTER ... 


			//CHECK BOARD	

			//numPairsFound++;	
		}


		// < - - - DECIDES WHETHER PLAYER WANTS TO RESTART GAME - - - > //
		cout << "Would You Like To Play Again? Enter 1 for Yes. Otherwise, Enter 2 For No . . .";
		cin >> playAgain; //GETS INPUT AS TO WHETHER USER WANTS TO PLAY AGAIN OR NOT
		while ((playAgain != 1) && (playAgain != 2)) //ERROR CHECKING FOR USER INPUT
		{
			cout << "Try again";
			cin >> playAgain;
		}

		if (playAgain == 1)
		{
			cout << "\nStarting New Game . . .\n";
			startingNewGame = true;
		}
		else
		{
			keepPlaying = false;
			printGoodbyeMessage(); //ENDS GAME
		}
	}
}

int main()
{
	memory();
	return 0;
}
