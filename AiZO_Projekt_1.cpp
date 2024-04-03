#include "Menu.h"
#include <iostream>
#include <sstream>

int main()
{
	int menu;
	std::string input;

	std::cout << "Na jakim typie danych chcesz pracowac?\n"
		"1 - int\n"
		"2 - char\n"
		"3 - float\n"
		"4 - double\n"
		"0 - wyjdz\n";

	std::cin >> input;

	try {
		menu = std::stoi(input);
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		menu = 10;
	}

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
}