#pragma once

#include <vector>
#include "LinkedList.h"

using namespace std;

template<class T>
vector<T> Quicksort(vector<T> vec, int start, int stop)
{
	if ((stop - start) >= 1)
	{
		int left = start;
		int right = stop;
		T pivot = vec[left + (((right + 1) - left) / 2)];

		while (left <= right)
		{
			while (vec[left] < pivot && left <= stop)
			{
				left = left + 1;
			}

			while (vec[right] > pivot && right >= start)
			{
				right = right - 1;
			}

			if (left <= right)
			{
				T temp = vec[right];
				vec[right] = vec[left];
				vec[left] = temp;

				left = left + 1;
				right = right - 1;
			}
		}
		
		vec = Quicksort(vec, start, right);

		vec = Quicksort(vec, left, stop);
	}

	return vec;
}

template<class T>
vector<T> quicksort(vector<T> vec)
{
		return Quicksort<T>(vec, 0, vec.size() - 1);
}

template<class T>
T BinarySearch(typename vector<T> vec, typename T value, int low, int high)
{
	if (high < low)
	{
		return NULL;
	}

	int mid = low + ((high - low) / 2);

	if (vec[mid] > value)
	{
		return BinarySearch(vec, value, low, mid - 1);
	}

	else if (vec[mid] < value)
	{
		return BinarySearch(vec, value, mid + 1, high);
	}

	else
	{
		return mid;
	}
}

template<class T>
T binarySearch(typename vector<T> vec, typename T value)
{
	return BinarySearch(vec, value, 0, vec.size() - 1);
}

template<class T>
vector<T> MergeSort(typename vector<T> vec)
{
	vector<T> left, right, result;
	if ((vec.size()) <= 1)
	{
		return vec;
	}
	else
	{
		int middle = (vec.size()) / 2;

		for (int i = 0; i <= middle - 1; i++)
		{
			left.push_back(vec[i]);
		}

		for (int j = middle; j <= vec.size() - 1; j++)
		{
			right.push_back(vec[j]);
		}

		left = MergeSort<T>(left);
		right = MergeSort<T>(right);

		if (left[left.size() - 1] <= right[0])
		{
			left.insert(left.end(), right.begin(), right.end());
			return left;
		}

		result = merge<T>(left, right);
		return result;
	}
}

template<class T>
vector<T> merge(vector<T> left, vector<T> right)
{
	vector<T> result;
	int leftInd = 0;
	int rightInd = 0;

	while ((left.size()) > leftInd && (right.size()) > rightInd)
	{
		if (left[leftInd] <= right[rightInd])
		{
			result.push_back(left[leftInd]);
			leftInd++;
		}
		else
		{
			result.push_back(right[rightInd]);
			rightInd++;
		}
	}
	if (leftInd < left.size())
	{
		result.insert(result.end(), left.begin() + leftInd, left.end());
	}
	if (rightInd < right.size())
	{
		result.insert(result.end(), right.begin() + rightInd, right.end());
	}
	
	return result;
}

template<class T>
int Hash(typename T info)
{
	List bigList;


}