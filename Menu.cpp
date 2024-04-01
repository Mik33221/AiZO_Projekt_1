#include "Menu.h"
#include "TableManager.h"
#include "InsertSort.h"

#include <iostream>

#define N 5

using namespace std;

void Menu::run()
{
	workflow();
}

void Menu::workflow()
{
	TableManager<int> table(N);

	for (int i = 0; i < N; i++) {
		std::cout << table.tab[i] << std::endl;
	}

	std::cout << std::endl;

	for (int i = 0; i < N; i++) {
		std::cout << table.tabCopy[i] << std::endl;
	}

	std::cout << std::endl;

	InsertSort sort1;
	auto time = sort1.sort<int>(table.tabCopy, N);

	for (int i = 0; i < N; i++) {
		std::cout << table.tabCopy[i] << std::endl;
	}
	std::cout << "Time: " << time << "ms" << std::endl;
}

void Menu::test_algorithms() 
{
	cout << "No";
}