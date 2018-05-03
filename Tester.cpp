#include <iostream>
#include <vector>
#include "Functions.h"

int main()
{

	int myInts[] = {3, 5, 7, 2, 1, 9, 4, 3, 7, 9};
	vector<int> testVec;

	testVec.assign(myInts, myInts + 10);

	for (vector<int>::iterator it1 = testVec.begin(); it1 != testVec.end(); ++it1)
	{
		cout << *it1 << " ";
	}
	cout << endl;

	quicksort<int>(testVec);

	for (vector<int>::iterator it2 = testVec.begin(); it2 != testVec.end(); ++it2)
	{
		cout << *it2 << " ";
	}
	cout << endl;
}