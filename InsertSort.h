#pragma once
#include "VirtualSort.h"
#include <chrono>

class InsertSort: public VirtualSort
{
public:

	template <typename T>
	auto sort(T* tab, int length)
	{
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
		auto time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
		
		return time;
	}


};