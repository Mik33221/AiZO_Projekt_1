#include "Menu.h"
#include <iostream>

int main()
{
	int menu;
	do {
		std::cout << "Na jakim typie danych chcesz pracowac?\n"
			"1 - int\n"
			"2 - char\n"
			"3 - float\n"
			"4 - double\n"
			"0 - wyjdz\n";
		std::cin >> menu;
		switch (menu)
		{
		case 1:
			Menu<int>::run();
			break;
		case 2:
			Menu<char>::run();
			break;
		case 3:
			Menu<float>::run();
			break;
		case 4:
			Menu<double>::run();
			break;
		default:
			break;
		}
	} while (menu);
}