#pragma once

#include <iostream>
#include <vector>

using namespace std;

template<class T> void Quicksort(vector<T> vec, vector<T>::iterator begin, vector<T>::iterator end);
template<class T> void quicksort(vector<T> vec);
template<class T> void swap(T A, T B);

template<class T>
	void swap(T A, T B)
{
	T temp = A;
	A = B;
	B = temp;
}

template<class T>
	void Quicksort(vector<T> vec, vector<T>::iterator left, vector<T>::iterator right)
{
	if (vec.size() > 1)
	{
		T pivot = vec[vec.size() / 2];

		while (left <= right)
		{
			while (*left < pivot)
			{
				left++;
			}
			while (*right > pivot)
			{
				right--;
			}
			if (left <= right)
			{
				swap(*left, *right);

				left++;
				right--;
			}
		}

		Quicksort(vec.begin(), vec.begin() + right);
		Quicksort(vec.begin() + left, vec.end());
	}
}

template<class T>
	void quicksort(vector<T> vec)
{
		Quicksort(vec, vec.begin(), vec.end());
}