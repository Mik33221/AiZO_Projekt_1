#pragma once
#include "VirtualSort.h"
#include <chrono>

class InsertSort: public VirtualSort
{
public:

	template <typename T>
	auto sort(T* tab, int length)
	{
		auto start_time = std::chrono::high_resolution_clock::now();

		for (int i = 0; i < length; i++) {
			tab[i] = i;
		}

		auto end_time = std::chrono::high_resolution_clock::now();
		auto time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();
		
		return time;
	}

};