#pragma once
#include <string>
#include <iostream>
#include <assert.h>
#include <algorithm>
#define size 5
using namespace std;

template<typename T,typename A>
	T Sum(const A& arr) {
	T sum = 0;
	for (auto& p : arr)
		if (p >= 0) {
			sum += p;
		}
	return sum;
}

template<typename T,typename A>
	T Min(const A& arr) {
	T min = arr[0];
	for (auto& p : arr)
		if (p < min) {
			min = p;
		}
	return min;
}

	template <typename A>
	void sort(A arr[])
	{
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = i + 1; j < size; j++)
			{
				if (arr[i] > arr[j])
					swap(arr[i], arr[j]);
			}
		}
	}