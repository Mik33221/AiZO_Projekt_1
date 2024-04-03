#pragma once
#include "TableManager.h"
#include "InsertSort.h"
#include "HeapSort.h"
#include "QuickSort.h"
#include "ShellSort.h"

#include <iostream>
#include <string>
#include <fstream>

#define M 7

template<typename T>
class Menu
{
	//work functions
	static void viewTab(T* tab, int n)
	{
		for (int i = 0; i < n; i++)
			std::cout << tab[i] << std::endl;

		std::cout << std::endl;
	}

	static std::string isSorted(T* tab, int n)
	{
		for (int i = 1; i < n; i++)
			if (tab[i] < tab[i - 1])
				return "Tablica nie posortowana\n";

		return "Tablica posortowana\n";
	}
	
	static void writeToFile(std::string filename, auto content) {

		std::ofstream outputFile(filename, std::ios::app);

		if (!outputFile.is_open()) {
			std::cerr << "Error opening file: " << filename << std::endl;
			return;

		}
		outputFile << " ";
		outputFile << content;

		outputFile.close();
	}
	

	static void cleanFile(std::string filename) {

		std::ofstream outputFile(filename);

		if (!outputFile.is_open()) {
			std::cerr << "Error opening file: " << filename << std::endl;
			return;

		}

		outputFile << "";

		outputFile.close();
	}

public:

	static void run()				//Displays menu
	{
		int menu;
		std::string input;

		std::cout << "1 - Testuj algorytmy\n"
			"2 - Rozpocznij workflow (spowoduje utworzenie plikow output.txt dla kazdej tablicy,\n    testy wszystkich algorytmow) aktualny runtime ~ 10 minut\n"
			"0 - Wyjdz\n";

		std::cin >> input;

		try {
			menu = std::stoi(input);
		}
		catch (const std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
			menu = 0;
		}

		switch (menu) {
		case 1:
			testAlgorithms();
			break;
		case 2:
			workflow();
			break;
		default:
			break;
		}
	}

private:

	static void workflow()			//Runs automatized algorythm flow
	{
		int N[M] = { 10000, 20000, 40000, 80000, 200000, 400000, 800000 };	// 10000, 20000, 40000, 80000, 200000, 400000, 800000 };

		TableManager<T> table(10);

		InsertSort<T> insertSort;
		HeapSort<T> heapSort;
		ShellSort<T> shellSort;
		QuickSort<T> quickSort;

		auto time = quickSort.sort(table.tabCopy, 10);

		for (int i = 0; i < M; i++)		//dla kazdej ilosci danych
		{
			table.newTab(N[i]);
			std::cout << N[i] << " LOOP\n";
			std::string filename;

			filename = "output" + std::to_string(N[i]) + ".txt";
			cleanFile(filename);

			for (int j = 0; j < 100; j++) //100 powtorzen
			{							//polimorficzne podejscie niestety nie jest kompatybilne z templatami
				table.newTab();
				if (N[i] < 80000) {
					time = insertSort.sort(table.tabCopy, N[i]);
					writeToFile(filename, time);
				}

				table.renewTab();
				time = heapSort.sort(table.tabCopy, N[i]);
				writeToFile(filename, time);

				table.renewTab();
				shellSort.setGap(ShellSort<T>::gapChoice::SHELL);
				time = shellSort.sort(table.tabCopy, N[i]);
				writeToFile(filename, time);

				table.renewTab();
				shellSort.setGap(ShellSort<T>::gapChoice::HIBBARD);
				time = shellSort.sort(table.tabCopy, N[i]);
				writeToFile(filename, time);

				table.renewTab();
				quickSort.setPivot(QuickSort<T>::pivotChoice::LEFT);
				time = quickSort.sort(table.tabCopy, N[i]);
				writeToFile(filename, time);

				table.renewTab();
				quickSort.setPivot(QuickSort<T>::pivotChoice::RIGHT);
				time = quickSort.sort(table.tabCopy, N[i]);
				writeToFile(filename, time);

				table.renewTab();
				quickSort.setPivot(QuickSort<T>::pivotChoice::MIDDLE);
				time = quickSort.sort(table.tabCopy, N[i]);
				writeToFile(filename, time);

				table.renewTab();
				quickSort.setPivot(QuickSort<T>::pivotChoice::RANDOM);
				time = quickSort.sort(table.tabCopy, N[i]);
				writeToFile(filename, time);
				writeToFile(filename, "\n");
			}
		}
		std::cout << "Workflow ended";
	}

	static void testAlgorithms()	//Displays algorythm testing menu
	{
		TableManager<T> table(10);
		std::string fileName;
		int menu;
		std::string input;

		InsertSort<T> insertSort;
		HeapSort<T> heapSort;
		ShellSort<T> shellSort;
		QuickSort<T> quickSort;

		do {
			std::cout << "1 - Wczytaj tablice z pliku .txt\n"
				"2 - Wygeneruj losowa tablice\n"
				"3 - Wyswietl nieposortowana tablice\n"
				"4 - Sortuj tablice\n"
				"5 - Wyswietl/sprawdz posortowana tablice\n"
				"0 - Wyjdz\n";

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
				std::cout << "Podaj nazwe pliku .txt: ";
				std::cin >> fileName;
				fileName = fileName + ".txt";
				table.readTab(fileName);
				break;
			case 2:
				int l;
				std::cout << "\nPodaj wielkosc tablicy: ";
				std::cin >> input;
				try {
					l = std::stoi(input);
				}
				catch (const std::exception& e) {
					std::cerr << "Error: " << e.what() << std::endl;
					break;
				}
				table.newTab(l);
				break;
			case 3:
				viewTab(table.tab, table.getLength());
				break;
			case 4:
				table.renewTab();							//makes sure we are sorting unsorted array
				std::cout << "\n1 - InsertSort\n"
					"2 - HeapSort\n"
					"3 - ShellSort\n"
					"4 - ShellSort Hibbard\n"
					"5 - QuickSort pivot left\n"
					"6 - QuickSort pivot right\n"
					"7 - QuickSort pivot middle\n"
					"8 - QuickSort pivot random\n";

				std::cin >> input;
				try {
					menu = std::stoi(input);
				}
				catch (const std::exception& e) {
					std::cerr << "Error: " << e.what() << std::endl;
					std::cout << "Tablica nie posortowana, bledny wybor\n";
					return;
				}

				switch (menu)
				{
				case 1:
					insertSort.sort(table.tabCopy, table.getLength());
					break;

				case 2:
					heapSort.sort(table.tabCopy, table.getLength());
					break;

				case 3:
					shellSort.setGap(ShellSort<T>::gapChoice::SHELL);
					shellSort.sort(table.tabCopy, table.getLength());
					break;

				case 4:
					shellSort.setGap(ShellSort<T>::gapChoice::HIBBARD);
					shellSort.sort(table.tabCopy, table.getLength());
					break;

				case 5:
					quickSort.setPivot(QuickSort<T>::pivotChoice::LEFT);
					quickSort.sort(table.tabCopy, table.getLength());
					break;

				case 6:
					quickSort.setPivot(QuickSort<T>::pivotChoice::RIGHT);
					quickSort.sort(table.tabCopy, table.getLength());
					break;

				case 7:
					quickSort.setPivot(QuickSort<T>::pivotChoice::MIDDLE);
					quickSort.sort(table.tabCopy, table.getLength());
					break;

				case 8:
					quickSort.setPivot(QuickSort<T>::pivotChoice::RANDOM);
					quickSort.sort(table.tabCopy, table.getLength());
					break;

				default:
					std::cout << "Tablica nie posortowana, bledny wybor\n";
					break;
				}
				std::cout << "Tablica posortowana\n";
				break;
			case 5:
				if (table.getLength() < 20)
					viewTab(table.tabCopy, table.getLength());
				else
					std::cout << isSorted(table.tabCopy, table.getLength());
				break;

			default:
				break;
			}
		} while (menu);
	}
};