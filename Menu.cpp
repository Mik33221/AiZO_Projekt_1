#include "Menu.h"
#include "TableManager.h"
#include "InsertSort.h"

#include <iostream>

#define N 5
#define TYPE int

using namespace std;

//work functions
template<typename T>
void viewTab(T* tab) {
	for (int i = 0; i < N; i++) {
		std::cout << tab[i] << std::endl;
	}

	std::cout << std::endl;
}

template<typename T>
string isSorted(T* tab) {
	for (int i = 1; i < N; i++) {
		if (tab[i] < tab[i - 1]) return "Table not sorted\n\n";
	}
	return "Table sorted\n\n";
}

//menu
void Menu::run()
{
	workflow();
}

void Menu::workflow()
{
	TableManager<TYPE> table(N);

	//viewTab<>(table.tab);

	//viewTab(table.tabCopy);
	
	InsertSort sort1;	//drop polymorphism in this case
	auto time = sort1.sort<TYPE>(table.tabCopy, N);
	
	//viewTab(table.tabCopy);
	std::cout << isSorted(table.tabCopy);

	std::cout << "Time: " << time << "ms" << std::endl;

}

void Menu::test_algorithms() 
{
	cout << "No";
}