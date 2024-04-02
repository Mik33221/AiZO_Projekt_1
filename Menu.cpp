#include "Menu.h"
#include "TableManager.h"
#include "InsertSort.h"

#include <iostream>

#define N 5
#define TYPE int

using namespace std;

void Menu::run()
{
	workflow();
}

void Menu::workflow()
{
	TableManager<TYPE> table(N);
	
	for (int i = 0; i < N; i++) {
		std::cout << table.tab[i] << std::endl;
	}

	std::cout << std::endl;

	for (int i = 0; i < N; i++) {
		std::cout << table.tabCopy[i] << std::endl;
	}

	std::cout << std::endl;
	
	InsertSort sort1;	//drop polymorphism in this case
	auto time = sort1.sort<TYPE>(table.tabCopy, N);
	
	for (int i = 0; i < N; i++) {
		std::cout << table.tabCopy[i] << std::endl;
	}
	std::cout << "Time: " << time << "ms" << std::endl;
	
}

void Menu::test_algorithms() 
{
	cout << "No";
}