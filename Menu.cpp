#include "Menu.h"
#include "TableManager.h"
#include "InsertSort.h"
#include "HeapSort.h"
#include "QuickSort.h"

#include <iostream>

#define N 100000
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
	workflow();
}

void Menu::workflow()
{
	TableManager<TYPE> table(N);

	InsertSort<TYPE> insertSort(table.tabCopy, N);
	HeapSort<TYPE> heapSort(table.tabCopy, N);

	table.renewTab();
	auto time = heapSort.sort();
	std::cout << isSorted(table.tabCopy);
	std::cout << "Time: " << time << "ms" << std::endl << std::endl;

	table.renewTab();
	time = insertSort.sort();
	std::cout << isSorted(table.tabCopy);
	std::cout << "Time: " << time << "ms" << std::endl << std::endl;

}

void Menu::test_algorithms() 
{
	cout << "No";
}