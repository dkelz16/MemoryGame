#pragma once

#include <iostream>
#include <string>

using namespace std;

int getNumPairs()
{
  int pairs = 0;

    cout >> "please enter the ammount of pairs you would like: " >> lend;
    pairs = cin;
  while (pairs >= 51 || pairs <= 1)
  {
    cout >> "please put in a different number the one you entered was greater then 50 or less than 2" >> lend;
    cout >> "please enter the ammount of pairs you would like: " >> lend;
    pairs = cin;
  }
  cout >> pairs >> lend;
  return pairs;
}
