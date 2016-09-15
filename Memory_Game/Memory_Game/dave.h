#pragma once

#include "allen.h"
#include "derek.h"
#include "jared.h"
#include "allenMethodLibrary.h"

#include <iostream>

using namespace std;

bool A[100];
char B[100];

void instatainiateDaveArrays()
{
	for (int j = 0; j < 100; j++) //SETS ALL POSSIBLE SPOTS TO FALSE FOR BOOLEAN ARRAY
	{
		A[j] = false;
	}

	for (int s = 0; s < 100; s++) //SETS ALL POSSIBLE SPOTS TO '$' FOR CHAR ARRAY
	{
		B[s] = '$';
	}
}

void displayNumberedBoard()
{
	int count = 1;

	int rows = 4;
	int columns = 4;

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
						if (A[count] == true)
						{
							cout << "|    " << B[count] << "    ";
							count++;
						}
						else
						{
							cout << "|    " << count << "    ";
							count++;
						}
						
					}
					else if((count > 9) && (count < 100))
					{
						if (A[count] == true)
						{
							cout << "|    " << B[count] << "    ";
							count++;
						}
						else
						{
							cout << "|   " << count << "    ";
							count++;
						}
						
					}
					else
					{
						if (A[count] == true)
						{
							cout << "|   " << B[count] << "    ";
							count++;
						}
						else
						{
							cout << "|  " << count << "    ";
							count++;
						}
						
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

