#include "Menu.h"
#include "TableManager.h"
#include "TableManager.cpp"
#include <iostream>

int main()
{
	TableManager<int> LinkingTable;
	std::cout << LinkingTable.randomTab(5);

}