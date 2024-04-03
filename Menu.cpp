/*
#include "Menu.h"
#include "TableManager.h"
#include "InsertSort.h"
#include "HeapSort.h"
#include "QuickSort.h"
#include "ShellSort.h"

#include <iostream>

#define N 50000
#define TYPE int

using namespace std;

//work functions
template<typename T>
void viewTab(T* tab)
{
	for (int i = 0; i < N; i++)
		std::cout << tab[i] << std::endl;

	std::cout << std::endl;
}

template<typename T>
string isSorted(T* tab)
{
	for (int i = 1; i < N; i++)
		if (tab[i] < tab[i - 1])
			return "Table not sorted\n";

	return "Table sorted\n";
}

//menu

void Menu::run()
{
	test_algorithms();
}

void Menu::workflow()
{
	TableManager<TYPE> table(N);

	InsertSort<TYPE> insertSort;
	HeapSort<TYPE> heapSort;
	QuickSort<TYPE> quickSort;
	ShellSort<TYPE> shellSort;

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

	shellSort.setGap(ShellSort<TYPE>::gapChoice::HIBBARD);
	table.newTab();
	time = shellSort.sort(table.tabCopy, N);
	std::cout << isSorted(table.tabCopy);
	std::cout << "Shell Hibbard sort time: " << time << "ms" << std::endl << std::endl;
}

void Menu::test_algorithms()
{
	int menu;
	do {
		cout << "1 - Wczytaj tablice z pliku .txt\n"
			"2 - Wygeneruj losowa tablice\n"
			"3 - Wyswietl nieposortowana tablice\n"
			"4 - Sortuj tablice\n"
			"5 - Wyswietl posortowana tablice\n"
			"0 - Wyjdz\n";
		cin >> menu;
		switch (menu) {

		}
	} while (menu);
}*/