#pragma once
#include "VirtualSort.h"

template<typename T>
class ShellSort : public VirtualSort<T>
{
public:

	enum gapChoice { SHELL, HIBBARD };

	ShellSort(gapChoice chosenGap = SHELL)
	{
		this->chosenGap = chosenGap;
	}

	void setGap(gapChoice chosenGap) {
		this->chosenGap = chosenGap;
	}

	auto sort(T* table, int n)
	{
		tab = table;
		length = n;
		auto start_time = std::chrono::high_resolution_clock::now();
		int gap;
		
		switch (chosenGap) {
		case HIBBARD:
			start_time = std::chrono::high_resolution_clock::now();
			gap = 1;
			while (gap < length / 2)					//gaps created using Hibbard sequence 2 ^ k - 1
				gap = gap * 2 + 1;						//to begin we find biggest element of sequence
			while (gap > 0) {
				gappedInsertionSort(gap);
				gap = (gap - 1) / 2;					//after sorting find next sequence element
			}
			break;

		case SHELL:
		default:
			start_time = std::chrono::high_resolution_clock::now();
			for (gap = length / 2; gap > 0; gap /= 2) {	//gaps created using Shell sequence floor(N / 2 ^ k)
				gappedInsertionSort(gap);
			}
		}
		

		auto end_time = std::chrono::high_resolution_clock::now();
		auto time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();

		return time;
	}

private:

	T* tab = NULL;
	int i = 0, j = 0, length = 0;
	T key = 0;
	gapChoice chosenGap;

	void gappedInsertionSort(int gap) {
		for (i = gap; i < length; ++i) {		//for every i element starting at gap
			key = tab[i];
			j = i;

			while (j >= gap && tab[j - gap] > key) {
				tab[j] = tab[j - gap];
				j -= gap;
			}
			tab[j] = key;
		}
	}
};