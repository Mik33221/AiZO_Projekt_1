#pragma once
#include <random>
#include <fstream>
#include <string>
#include <iostream>

template <typename T>	//length and type of tab must be initialized with constructor
class TableManager
{
public:

	T* tab;						//current table
	T* tabCopy;					//copy used for sorting

	TableManager<T>(int tableLength)	//seeds random number generator, creates tab and copy for sorting
	{
		std::random_device rd;
		mt_device.seed(rd());
		length = tableLength;
		tab = randomTab();
		tabCopy = copyTab(tab);
	}

	~TableManager<T>()
	{
		delete[] tab;
		delete[] tabCopy;
	}

	void newTab()		//replaces tab with new random one
	{
		delete[] tab;
		delete[] tabCopy;
		tab = randomTab();
		tabCopy = copyTab(tab);
	}

	void newTab(int len)		//replaces tab with new random one with desired length
	{
		delete[] tab;
		delete[] tabCopy;
		this->length = len;
		tab = randomTab();
		tabCopy = copyTab(tab);
	}

	void renewTab()		//provides new tab for sorting, wihout randomizing
	{
		delete[] tabCopy;
		tabCopy = copyTab(tab);
	}

	void readTab(std::string fileName)
	{
		delete[] tab;
		delete[] tabCopy;

		int l = 0;
		T element;

		std::ifstream file(fileName);
		if (!file.is_open()) {
			std::cerr << "Error opening file: " << fileName << std::endl;
			return;
		}

		file >> l;	//pierwsza linijka oznacza dlugosc tablicy
		this->length = l;

		T* array = new T[length];

		int i = 0;
		while (file >> element) {
			array[i] = element;
			i++;
		}

		file.close();

		tab = array;
		tabCopy = copyTab(tab);
	}

	int getLength()
	{
		return length;
	}

private:

	int length;
	std::mt19937 mt_device;
	std::uniform_int_distribution<> diceRoll;

	T* copyTab(T* tab) //creates new tab and copies content of arg to it
	{
		T* array = new T[length];
		for (int i = 0; i < length; ++i) {
			array[i] = tab[i];
		}
		return array;
	}

	T* randomTab()	//creates and fills N length tab with random numbers/chars
	{
		T* array = new T[length];
		for (int i = 0; i < length; ++i) {
			array[i] = randomElement<T>();
		}
		return array;
	}

	template <typename T>
	T randomElement()			//generates random int/float/double
	{
		T element = diceRoll(mt_device);

		return element;
	}

	template <>
	char randomElement<char>()	//specified char range for user visibility
	{
		T element = diceRoll(mt_device) % 25 + 65;

		return element;
	}
};