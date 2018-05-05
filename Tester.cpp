#include <iostream>
#include <ctime>		//only used as seed for rand()
#include <vector>
#include "Functions.h"
#include "winTimer.h"

int main()
{
	///////////////////////////////////////////////////////////////////////////////////////////////
	// Quicksort with a vector of ints
	///////////////////////////////////////////////////////////////////////////////////////////////

	cout << "\n\n--------------------Quicksort with a vector of ints--------------------\n";
	cout << "\nWhen the vector is of 100 random ints between 0 and 99:\n";

	vector<int> testVec(100);
	for (vector<int>::iterator it1 = testVec.begin(); it1 != testVec.end(); ++it1)
	{
		*it1 = rand() % 100;
	}

	Timer timer1;

	timer1.start();
	testVec = quicksort<int>(testVec);
	timer1.stop();

	cout << "\n" << timer1() << " seconds.\n";

	cout << "\nif the size is quadrupled:\n";
	testVec = vector<int>(400);
	for (vector<int>::iterator it400 = testVec.begin(); it400 != testVec.end(); ++it400)
	{
		*it400 = rand() % 100;
	}

	timer1.clear();
	timer1.start();
	testVec = quicksort<int>(testVec);
	timer1.stop();

	cout << "\n" << timer1() << " seconds.\n";


	cout << "\nIf the vector is sorted in reverse order from 25 to 0:\n";
	testVec = { 25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1 };

	timer1.clear();
	timer1.start();
	testVec = quicksort(testVec);
	timer1.stop();

	cout << "\n" << timer1() << " seconds.\n";

	cout << "\nIf the vector is of size 100 and all the same value:\n";
	testVec = vector<int>(100, 1);

	timer1.clear();
	timer1.start();
	testVec = quicksort(testVec);
	timer1.stop();

	cout << "\n" << timer1() << " seconds.\n";



	///////////////////////////////////////////////////////////////////////////////////////////////
	// Quicksort with a string as a vector of chars
	///////////////////////////////////////////////////////////////////////////////////////////////

	cout << "\n\n--------------------Quicksort with a string as a vector of chars--------------------\n";
	std::string sentence = "the quick brown fox jumps over the lazy dog";
	vector<char> test2(sentence.begin(), sentence.end());

	cout << "\nthe string is:\n";
	for (vector<char>::iterator it1 = test2.begin(); it1 != test2.end(); ++it1)
	{
		cout << *it1;
	}
	cout << '.' <<  endl;

	Timer timer2;

	timer2.start();
	test2 = quicksort<char>(test2);
	timer2.stop();

	cout << "\nWhen the string is sorted into a vector using quicksort it becomes:\n" << '{';
	for (vector<char>::iterator it2 = test2.begin(); it2 != test2.end(); ++it2)
	{
		cout << *it2;
	}
	cout << '}' << endl;

	cout << "\nThis operation took " << timer2() << " seconds.\n";



	////////////////////////////////////////////////////////////////////////////////////////////////
	// Binary Search thrugh a vector of ints
	////////////////////////////////////////////////////////////////////////////////////////////////

	cout << "\n\n--------------------Binary Search with a vector of ints--------------------\n";
	cout << "\nFor a reversely ordered list from 0 to 99 and looking for the value 73:\n";

	int inc = 0;
	vector<int> test3(100);
	for (vector<int>::iterator it6 = test3.begin(); it6 != test3.end(); ++it6)
	{
		*it6 = inc;
		inc++;
	}

	Timer timer3;
	int value = 73;
	int loc;
	
	timer3.start();
	loc = binarySearch(test3, value);
	timer3.stop();

	cout << "\nThis operation took " << timer3() << " seconds.\n";

	cout << "\nIf the length of the vector is quadrupled:\n";
	inc = 0;
	test3 = vector<int>(400);
	for (vector<int>::iterator it6 = test3.begin(); it6 != test3.end(); ++it6)
	{
		*it6 = inc;
		inc++;
	}

	timer3.clear();
	timer3.start();
	loc = binarySearch<int>(test3, value);
	timer3.stop();

	cout << "\nThis operation took " << timer3() << " seconds.\n";

	cout << "\nIf the value is not in the vector:\n";
	test3 = vector<int>(100, 1);

	timer3.clear();
	timer3.start();
	loc = binarySearch<int>(test3, value);
	timer3.stop();

	cout << "\nThis operation took " << timer3() << " seconds.\n";

	//////////////////////////////////////////////////////////////////////////////////////////
	// Binary search through a vector of chars
	//////////////////////////////////////////////////////////////////////////////////////////

	cout << "\n\n--------------------Binary Search with a vector of chars--------------------\n";
	cout << "\nIf the vector is the alphabet and the value is 'v':\n";

	vector<char> test4({ 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' });
	char c = 'v';

	Timer timer4;

	timer4.start();
	loc = binarySearch<char>(test4, c);
	timer4.stop();

	cout << "\nThis operation took " << timer4() << " seconds.\n";

	/////////////////////////////////////////////////////////////////////////////////////////
	// Merge Sort a vector of doubles
	/////////////////////////////////////////////////////////////////////////////////////////

	cout << "\n\n--------------------Merge Sort with a vector of doubles--------------------\n";
	cout << "\nIf the vector consists of 100 random doubles from 0 to 100:\n";

	vector<double> test5(100);
	for (vector<double>::iterator it7 = test5.begin(); it7 != test5.end(); ++it7)
	{
		*it7 = ((double)rand() / RAND_MAX) * 100;
	}
	/*
	cout << "\nBefore MergeSort:\n" << '{';
	for (vector<double>::iterator it9 = test5.begin(); it9 != test5.end(); ++it9)
	{
		cout << *it9 << ',';
	}
	cout << '}' << endl;
	*/
	Timer timer5;

	timer5.start();
	test5 = MergeSort<double>(test5);
	timer5.stop();
	/*
	cout << "\nAfter MergeSort:\n" << '{';
	for (vector<double>::iterator it8 = test5.begin(); it8 != test5.end(); ++it8)
	{
		cout << *it8 << ',';
	}
	cout << '}' << endl;
	*/
	cout << "\nThis operation took " << timer5() << " seconds.\n";

	cout << "\nIf the values in the vector are all the same:\n";

	for (vector<double>::iterator it11 = test5.begin(); it11 != test5.end(); ++it11)
	{
		*it11 = 0.0;
	}

	timer5.clear();
	timer5.start();
	test5 = MergeSort<double>(test5);
	timer5.stop();

	cout << "\nThis operation took " << timer5() << " seconds.\n";

	cout << "\nIf the values in the vector are reverse sorted:\n";

	double dec = 100.0;
	for (vector<double>::iterator it12 = test5.begin(); it12 != test5.end(); ++it12)
	{
		*it12 = dec;
		dec--;
	}

	timer5.clear();
	timer5.start();
	test5 = MergeSort<double>(test5);
	timer5.stop();

	cout << "\nThis operation took " << timer5() << " seconds.\n";

	/////////////////////////////////////////////////////////////////////////////////////
	// Text/Int to Int Hash Function
	/////////////////////////////////////////////////////////////////////////////////////



	system("pause");
}