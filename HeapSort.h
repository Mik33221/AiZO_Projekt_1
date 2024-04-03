#pragma once
#include "VirtualSort.h"

template<typename T>
class HeapSort : public VirtualSort<T>
{
public:

	auto sort(T* table, int n)
	{
		tab = table;
		length = n;
		int i;

		auto start_time = std::chrono::high_resolution_clock::now();

		for (i = length / 2 - 1; i >= 0; i--)   //make heap from an array
			heapify(length, i);

		for (i = length - 1; i > 0; i--) {
			std::swap(tab[0], tab[i]);          //swap first and last heap element

			heapify(i, 0);                      //fix rest of the heap
		}

		auto end_time = std::chrono::high_resolution_clock::now();
		auto time = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count();

		return time;
	}

private:

	T* tab;
	int length;

	void heapify(int length, int i)
	{
		int largest = i;
		int left = i * 2 + 1;   //left and right child have fixed positions
		int right = i * 2 + 2;

		if (left < length && tab[left] > tab[largest])      //check if left is bigger than its parent
			largest = left;
		if (right < length && tab[right] > tab[largest])    //check if right is bigger than its parent and left
			largest = right;

		if (largest != i)
		{
			std::swap(tab[i], tab[largest]);    //if parent isnt the largest, swap

			heapify(length, largest);           //recursively heapify remaining elements
		}
	}
};