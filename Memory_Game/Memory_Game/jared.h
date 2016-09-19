#pragma once

#include "dave.h"
#include "allen.h"
#include "derek.h"

int getNumPairs()
{
	int pairs = 0;

	cout << "Please enter the ammount of pairs you would like: " << endl;
	cin >> pairs;
	while (pairs >= 51 || pairs <= 1)
	{
		cout << "Please put in a different number the one you entered was greater then 50 or less than 2" << endl;
		cout << "Please enter the ammount of pairs you would like: " << endl;
		cin >> pairs;
	}

	cout << "\n";

	return pairs;
}

void checkForMatch(char b[], bool a[], int guess1, int guess2)
{
	if (b[guess1] == b[guess2])
	{

	}
}

/*
A[guess1] = true;
		A[guess2] = true;
*/