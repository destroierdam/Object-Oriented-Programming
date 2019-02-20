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
	Car traichosCar;

	// Unit tests for Default constructor
	assert(traichosCar.mileage == 0);
	assert(traichosCar.avgConsumption == 0);
	assert(traichosCar.name[0] == '\0');
	assert(traichosCar.description[0] == '\0');

	// Initialising using direct access
	traichosCar.mileage = 600000;
	traichosCar.avgConsumption = 8.4;
	strcpy_s(traichosCar.name, "Volkswagen Golf");
	strcpy_s(traichosCar.description, "No comment");

	Car dadsCar(200000, 7.3, "Ford Fiesta", "Small and great for Sofia");

	// Unit tests for Constructor with parameters
	assert(dadsCar.mileage == 200000);
	assert(dadsCar.avgConsumption == 7.3);
	assert(strcmp(dadsCar.name, "Ford Fiesta") == 0);
	assert(strcmp(dadsCar.description, "Small and great for Sofia") == 0);


	Car myCar(dadsCar);

	// Unit tests for Copy constructor
	assert(myCar.mileage == dadsCar.mileage);
	assert(myCar.avgConsumption == dadsCar.avgConsumption);
	assert(strcmp(myCar.name, dadsCar.name) == 0);
	assert(strcmp(myCar.description, dadsCar.description) == 0);

	return 0;
}
/*
Кола
Създайте структура, която описва кола с километраж,
среден разход, име на марката и описание на колата.

Направете инициализация с данни чрез директна промяна на член-данните и инициализация с конструктор.
*/