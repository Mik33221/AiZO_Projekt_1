#pragma once

template <typename T>
class TableManager
{
public:
	static T* tab;

	static T* randomTab(int N);	//creates and fills N length tab with random numbers/chars


private:
	static T randomElement(); //generates random number/char

};
