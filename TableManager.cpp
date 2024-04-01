#include "TableManager.h"

template <typename T>
T* TableManager<T>::randomTab(int length)
{
	T* array = new T[length];
	for (int i = 0; i < length; ++i) {
		array[i] = randomElement<T>();
	}
	return array;
}

template <typename T>
T TableManager<T>::randomElement()
{
	T element = 0;

	return element;
}

template <>
char* TableManager<char>::randomElement()
{
	char element = 0;

	return element;
}