#pragma once
#include "VirtualSort.h"

template<typename T>
class QuickSort : private VirtualSort<T>
{
public:

	QuickSort(T* tab, int length)
	{
		this->tab = tab;
		this->length = length;
	}

	auto sort()
	{
		int i, j;
		T key;

		auto start_time = std::chrono::high_resolution_clock::now();

		

		auto end_time = std::chrono::high_resolution_clock::now();
		auto time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();

		return time;
	}

private:

	T* tab;
	int length;

};