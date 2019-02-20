#include "pch.h"
#include<iostream>

// #pragma warning(disable:4996) // allows use of unsafe function strcpy()

using namespace std;

struct Computer
{
	int powerDraw;
	int length, width, height;

	Computer()
	{
		powerDraw = 500;
		length = width = height = 10;
	}
	Computer(int newPowerDraw, int newLength, int newHeight, int newWidth)
	{
		powerDraw = newPowerDraw;
		length = newLength;
		height = newHeight;
		width = newWidth;
	}
	Computer(int newPowerDraw)
	{
		powerDraw = newPowerDraw;
		length = width = height = 0;
	}
};


// Car task

const size_t NAME_SIZE = 128;
const size_t DESCRIPTION_SIZE = 512;

struct Car
{
	int kilometers;
	double avgFuelBurn;
	char name[NAME_SIZE], description[DESCRIPTION_SIZE];

	// Default constructor
	Car()
	{
		kilometers = 0;
		avgFuelBurn = 0;
		name[0] = '\0';
		description[0] = '\0';
	}
	// Constructor with parameters
	Car(int newKilometers,
		double newAvgFuelBurn,
		const char * newName,
		const char * newDescription)
	{
		kilometers = newKilometers;
		avgFuelBurn = newAvgFuelBurn;
		strcpy_s(name, strlen(newName)+1, newName);
		strcpy_s(description, strlen(newDescription)+1, newDescription);
	}
	// Copy constructor
	Car(const Car & other)
	{
		kilometers = other.kilometers;
		avgFuelBurn = other.avgFuelBurn;
		strcpy_s(name, strlen(other.name)+1, other.name);
		strcpy_s(description, strlen(other.description)+1, other.description);
	}

};

void readCars()
{
	size_t size;
	cin >> size;

	Car* carArray = new Car[size];

	for (size_t i = 0; i < size; i++)
	{
		cin >> carArray[i].kilometers;
		cin >> carArray[i].avgFuelBurn;

		cin.getline(carArray[i].name, NAME_SIZE);
		cin.getline(carArray[i].description, DESCRIPTION_SIZE);
	}
}

void teachers()
{
	size_t teachersSize;
	cin >> teachersSize;

	double** marks = new double*[teachersSize];

	for (size_t i = 0; i < teachersSize; i++)
	{
		size_t marksSize;
		cin >> marksSize;

		marks[i] = new double[marksSize];

		for (size_t j = 0; j < marksSize; j++)
		{
			cin >> marks[i][j];
		}
	}
}

struct DoubleArray
{
	size_t size;
	double * arr;
};

int main()
{
	DoubleArray arr1;
	arr1.arr = new double[128];
	for (size_t i = 0; i < 128; i++)
	{
		cin >> arr1.arr[i];
	}

	DoubleArray arr2(arr1);


	
	const Car myCar(500000,5.12,"Nissan","An average car");

	Car anotherCar(myCar);

	size_t size;
	cin >> size;

	Car* arr = new Car[size];
	for (size_t i = 0; i < size; i++)
	{
		cin >> arr[i].kilometers;
		cin >> arr[i].avgFuelBurn;
		cin.getline(arr[i].name,128);
		cin.getline(arr[i].description, 512);
	}

	

	return 0;
}