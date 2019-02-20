#include "pch.h"
#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;

const size_t NAME_SIZE = 128;
const size_t DESCRIPTION_SIZE = 1024;

struct Laptop
{
	size_t batteryCapacity;
	double screenSize;
	char name[NAME_SIZE], description[DESCRIPTION_SIZE];

	// Default constructor
	Laptop()
	{
		batteryCapacity = 0;
		screenSize = 0;
		name[0] = '\0';
		description[0] = '\0';
	}

	// Constructor with parameters
	Laptop(int newBatteryCapacity, double newScreenSize, const char * newName, const char * newDescription)
	{
		batteryCapacity = newBatteryCapacity;
		screenSize = newScreenSize;
		strcpy_s(name, newName);
		strcpy_s(description, newDescription);
	}
	// Copy constructor
	Laptop(const Laptop & other)
	{
		batteryCapacity = other.batteryCapacity;
		screenSize = other.screenSize;
		strcpy_s(name, other.name);
		strcpy_s(description, other.description);
	}
};

int main()
{
	Laptop traichosLaptop;

	// Unit tests for Default constructor
	assert(traichosLaptop.batteryCapacity == 0);
	assert(traichosLaptop.screenSize == 0);
	assert(traichosLaptop.name[0] == '\0');
	assert(traichosLaptop.description[0] == '\0');

	// Initialising using direct access
	traichosLaptop.batteryCapacity = 4500;
	traichosLaptop.screenSize = 17.3;
	strcpy_s(traichosLaptop.name, "Dell Inspiron");
	strcpy_s(traichosLaptop.description, "Long lasting");

	Laptop dadsLaptop(4500, 17.3, "Dell Inspiron", "Long lasting");

	// Unit tests for Constructor with parameters
	assert(dadsLaptop.batteryCapacity == 4500);
	assert(dadsLaptop.screenSize == 17.3);
	assert(strcmp(dadsLaptop.name, "Dell Inspiron") == 0);
	assert(strcmp(dadsLaptop.description, "Long lasting") == 0);


	Laptop myLaptop(dadsLaptop);

	// Unit tests for Copy constructor
	assert(myLaptop.batteryCapacity == dadsLaptop.batteryCapacity);
	assert(myLaptop.screenSize == dadsLaptop.screenSize);
	assert(strcmp(myLaptop.name, dadsLaptop.name) == 0);
	assert(strcmp(myLaptop.description, dadsLaptop.description) == 0);

	return 0;
}
/*
Лаптоп
Създайте структура, която описва лаптоп с капацитет на батерията, размер на екрана, име на марката и описание. 

Направете инициализация с данни чрез директна промяна на член-данните и инициализация с конструктор.
*/