#pragma once

#include "dave.h"
#include "allen.h"
#include "derek.h"

int getNumPairs()
{
	int pairs = 0;

	cout << "please enter the ammount of pairs you would like: " << endl;
	cin >> pairs;
	while (pairs >= 51 || pairs <= 1)
	{
		cout << "please put in a different number the one you entered was greater then 50 or less than 2" << endl;
		cout << "please enter the ammount of pairs you would like: " << endl;
		cin >> pairs;
	}
	cout << pairs << endl;
	return pairs;
}