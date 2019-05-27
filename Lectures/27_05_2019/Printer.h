#pragma once
#include <iostream>
#include "ElDevice.h"
class Printer : public Powerable {
	bool hasToner;
public:
	Printer() {
		this->hasToner = true;
	}
	void work() override {
		std::cout << "Printing..." << std::endl;
	}
	void printError() override {
		std::cout << "Error: Out of Toner" << std::endl;
	}
	void printInfo() override {
		std::cout << "A printer: " << std::endl;
		std::cout << "Toner: " << hasToner << std::endl;
	}
	Printer* clone() {
		std::cout << "Copy Printer" << std::endl;
		return new Printer(*this);
	}

};