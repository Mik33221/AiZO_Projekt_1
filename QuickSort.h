#pragma once
#include "VirtualSort.h"

template<typename T>
class QuickSort : private VirtualSort<T>
{
public:

	enum pivotChoice { LEFT, RIGHT, MIDDLE, RANDOM };

	QuickSort(pivotChoice pivot = MIDDLE)
	{
		this->pivot = pivot;
		srand(time(NULL));
	}

	void setPivot(pivotChoice pivot) {
		this->pivot = pivot;
	}

	auto sort(T* table, int n)
	{
		tab = table;
		length = n;
		int p = 0;
		int r = length - 1;

		auto start_time = std::chrono::high_resolution_clock::now();

		quickSort(p, r);

		auto end_time = std::chrono::high_resolution_clock::now();
		auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();

		return time;
	}

private:

	T* tab = NULL;
	int length = 0;
	pivotChoice pivot;

	void quickSort(int p, int r) {
		if (p < r) {
			int partitionIndex = partition(p, r);
			quickSort(p, partitionIndex);			//recurrent quickSort call for left side
			quickSort(partitionIndex + 1, r);		//quickSort call for right side
		}
	}

	int partition(int p, int r)
	{
		T pivotValue = 0;
		int i, j, random;

		switch (pivot)	//switch choosing pivot
		{
		case LEFT:
			pivotValue = tab[p];
			break;

		case RIGHT:
			pivotValue = tab[r];
			std::swap(tab[r], tab[p]);	//enables us to use unmodified algorithm for rightmost sorting
			break;

		case MIDDLE:
			pivotValue = tab[(p + r) / 2];
			break;

		case RANDOM:
			random = p + rand() % (r - p + 1);
			pivotValue = tab[random];
			break;

		default:
			break;
		}
		i = p - 1;
		j = r + 1;

		while (true) {		//cormen guided implementation
			do {
				j--;
			} while (tab[j] > pivotValue);
			do {
				i++;
			} while (tab[i] < pivotValue);
			if (i < j)
				std::swap(tab[i], tab[j]);
			else
				return j;
		}
	}
};