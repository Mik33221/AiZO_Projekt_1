#pragma once
#include <random>

template <typename T>
class TableManager
{
public:

	T* tab;						//current table
	T* tabCopy;					//copy used for sorting

	TableManager<T>(int length)	//seeds random number generator and creates tab
	{
		std::random_device rd;
		mt_device.seed(rd());
		tab = randomTab(length);
		tabCopy = copyTab(tab, length);
	}

	~TableManager<T>()
	{
		delete[] tab;
		delete[] tabCopy;
	}

	void newTab(int length)		//replaces N length tab with new one
	{
		delete[] tab;
		delete[] tabCopy;
		tab = randomTab(length);
		tabCopy = copyTab(tab, length);
	}

private:

	std::mt19937 mt_device;
	std::uniform_int_distribution<> diceRoll;

	T* copyTab(T* tab, int length) //creates new tab and copies content of tab to it
	{
		T* array = new T[length];
		for (int i = 0; i < length; ++i) {
			array[i] = tab[i];
		}
		return array;
	}

	T* randomTab(int length)	//creates and fills N length tab with random numbers/chars
	{
		T* array = new T[length];
		for (int i = 0; i < length; ++i) {
			array[i] = randomElement<T>();
		}
		return array;
	}

	template <typename T>
	T randomElement()			//generates random number/char
	{
		T element = diceRoll(mt_device);

		return element;
	}

	template <>
	char randomElement<char>()	//specified char range for user visibility
	{
		T element = diceRoll(mt_device)%25+65;

		return element;
	}
	
};