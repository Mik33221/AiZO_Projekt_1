#include <random>

template <typename T>
class TableManager
{
public:

	T* tab;

	TableManager<T>(int length)		//seeds random number generator and creates tab
	{
		std::random_device rd;
		mt_device.seed(rd());
		tab = randomTab(length);
	}

	~TableManager<T>()
	{
		delete[] tab;
	}

	void newTab(int length)			//replaces N length tab with new one
	{
		delete[] tab;
		tab = randomTab(length);
	}

private:

	std::mt19937 mt_device;
	std::uniform_int_distribution<> diceRoll;

	T* randomTab(int length)		//creates and fills N length tab with random numbers/chars
	{
		T* array = new T[length];
		for (int i = 0; i < length; ++i) {
			array[i] = randomElement<T>();
		}
		return array;
	}

	template <typename T>
	T randomElement()	//generates random number/char
	{
		T element = diceRoll(mt_device);

		return element;
	}

	template <>
	char randomElement<char>()
	{
		T element = diceRoll(mt_device)%25+65;

		return element;
	}
	
};