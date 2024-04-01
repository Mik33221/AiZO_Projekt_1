#include "Menu.h"
#include "TableManager.h"
#include <iostream>

int main()
{

	TableManager<int> table(5);

	for (int i = 0; i < 5; i++) {
		std::cout << table.tab[i] << std::endl;
	}

	std::cout << std::endl;

}