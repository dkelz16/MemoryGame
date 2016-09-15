#pragma once

#include "allen.h"
#include "derek.h"
#include "jared.h"
#include "allenMethodLibrary.h"

#include <iostream>

using namespace std;

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
