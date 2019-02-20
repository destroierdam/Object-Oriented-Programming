#include "pch.h"
#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;

const size_t NAME_SIZE = 128;
const size_t DESCRIPTION_SIZE = 1024;

struct Car
{
	int mileage;
	double avgConsumption;
	char name[NAME_SIZE], description[DESCRIPTION_SIZE];
	// Default constructor
	Car()
	{
		mileage = 0;
		avgConsumption = 0;
		name[0] = '\0';
		description[0] = '\0';
	}
	// Constructor with parameters
	Car(int newMilage, double newAvgConsumption, const char * newName, const char * newDescription)
	{
		mileage = newMilage;
		avgConsumption = newAvgConsumption;
		strcpy_s(name, newName);
		strcpy_s(description, newDescription);
	}
	// Copy constructor
	Car(const Car & other)
	{
		mileage = other.mileage;
		avgConsumption = other.avgConsumption;
		strcpy_s(name, other.name);
		strcpy_s(description, other.description);
	}
};

int main()
{
	size_t carsSize;
	cin >> carsSize;
	Car * cars = new Car[carsSize];

	for (size_t i = 0; i < carsSize; i++)
	{
		cout << "Mileage of car " << i << ": ";
		cin >> cars[i].mileage;

		cout << "Average fuel consumption of car " << i << ": ";
		cin >> cars[i].avgConsumption;

		// Ignore newline
		cin.ignore();

		cout << "Name of car " << i << ": ";
		cin.getline(cars[i].name, NAME_SIZE);

		cout << "Description of car " << i << ": ";
		cin.getline(cars[i].description, DESCRIPTION_SIZE);
	}

	return 0;
}
/*
Коли
Напишете функция която прочита от клавиатурата брой коли и данни за колите и ги записва в масив. 

Заделете само толкова място, колкото е нужно за броя коли.
*/