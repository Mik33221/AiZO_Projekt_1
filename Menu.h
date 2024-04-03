#pragma once
#include "TableManager.h"
#include "InsertSort.h"
#include "HeapSort.h"
#include "QuickSort.h"
#include "ShellSort.h"

#include <iostream>

#define N 50000
template<typename T>
class Menu
{
	//work functions
	void viewTab(T* tab)
	{
		for (int i = 0; i < N; i++)
			std::cout << tab[i] << std::endl;

		std::cout << std::endl;
	}

	std::string isSorted(T* tab)
	{
		for (int i = 1; i < N; i++)
			if (tab[i] < tab[i - 1])
				return "Table not sorted\n";

		return "Table sorted\n";
	}
public:

	static void run()				//Displays menu
	{
		test_algorithms();
	}

private:

	static void workflow()			//Runs automatized algorythm flow
	{
		TableManager<T> table(N);

		InsertSort<T> insertSort;
		HeapSort<T> heapSort;
		QuickSort<T> quickSort;
		ShellSort<T> shellSort;

		auto time = quickSort.sort(table.tabCopy, N);

		table.newTab();
		time = insertSort.sort(table.tabCopy, N);
		std::cout << isSorted(table.tabCopy);
		std::cout << "Insert sort time: " << time << "ms" << std::endl << std::endl;

		table.newTab();
		time = heapSort.sort(table.tabCopy, N);
		std::cout << isSorted(table.tabCopy);
		std::cout << "Heap sort time: " << time << "ms" << std::endl << std::endl;

		table.newTab();
		time = quickSort.sort(table.tabCopy, N);
		std::cout << isSorted(table.tabCopy);
		std::cout << "Quick sort time: " << time << "ms" << std::endl << std::endl;

		table.newTab();
		time = shellSort.sort(table.tabCopy, N);
		std::cout << isSorted(table.tabCopy);
		std::cout << "Shell sort time: " << time << "ms" << std::endl << std::endl;

		shellSort.setGap(ShellSort<T>::gapChoice::HIBBARD);
		table.newTab();
		time = shellSort.sort(table.tabCopy, N);
		std::cout << isSorted(table.tabCopy);
		std::cout << "Shell Hibbard sort time: " << time << "ms" << std::endl << std::endl;
	}

	static void test_algorithms()	//Displays algorythm testing menu
	{
		int menu;
		do {
			std::cout << "1 - Wczytaj tablice z pliku .txt\n"
				"2 - Wygeneruj losowa tablice\n"
				"3 - Wyswietl nieposortowana tablice\n"
				"4 - Sortuj tablice\n"
				"5 - Wyswietl posortowana tablice\n"
				"0 - Cofnij do wyboru typu\n";
			std::cin >> menu;
			
		} while (menu);
	}	
};