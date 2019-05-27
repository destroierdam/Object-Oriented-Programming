#include "pch.h"
#include <iostream>
#include <vector>
#include "ElDevice.h"
#include "Printer.h"
#include "Scanner.h"
#include "MFU.h"
#include "Office.h"
#include <algorithm>
/*
struct Vector {
	double x;
	double y;
	Vector(double _x, double _y) {
		this->x = _x;
		this->y = _y;
	}
	bool operator < (const Vector & other)
	{
	}
};
bool compareVector(Vector lhs, Vector rhs) {
	return lhs.x < rhs.x ? true : false;
}
*/

void testElectricalOutlet(Powerable * powerTool) {
	std::cout << "Testing..." << std::endl;
}
int main()
{
	
	/*
	ElDevice * dev = new Printer();
	dev->work();
	dev->printError();
	*/

	Office office;

	Powerable * printer = new Printer();
	Powerable * scanner = new Scanner();
	Powerable * mfu = new MFU();

	office.addDevice(printer);
	office.addDevice(scanner);
	office.addDevice(mfu);

	Office newOffice(office);
	return 0;

	std::vector<Powerable*> devices;
	devices.push_back(new Printer());
	devices.push_back(new Scanner());
	devices.push_back(new Printer());
	devices.push_back(new MFU());

	for (size_t i = 0; i < devices.size(); i++)
	{
		devices[i]->work();
	}


	/*
	Drink * pitie = new Rakiq();
	pitie->drink();

	std::vector<Drink*> drinks;
	drinks.push_back(pitie);
	*/

	return 0;
}