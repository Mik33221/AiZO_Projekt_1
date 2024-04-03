#pragma once
#include "VirtualSort.h"

template<typename T>
class InsertSort : public VirtualSort<T>
{
public:

	auto sort(T* table, int n)
	{
		tab = table;
		length = n;
		int i, j;
		T key;

		auto start_time = std::chrono::high_resolution_clock::now();

		for (i = 1; i < length; ++i) {		//for every i element
			key = tab[i];
			j = i - 1;
			while (j >= 0 && tab[j] > key) {	//while elements to the left are < i
				tab[j + 1] = tab[j];			//shift all elements < i
				j--;
			}
			tab[j + 1] = key;					//insert i at last shifted element
		}

		auto end_time = std::chrono::high_resolution_clock::now();
		auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();

		return time;
	}

private:

	T* tab;
	int length;
};