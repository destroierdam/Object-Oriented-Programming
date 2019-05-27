#pragma once
#include <iostream>
#include "ElDevice.h"
class Scanner : public Powerable {
	bool hasNetwork;
public:
	Scanner() {
		this->hasNetwork = false;
	}
	void work() override {
		std::cout << "Scaning..." << std::endl;
	}
	void printError() override {
		std::cout << "Error: Cannot scan" << std::endl;
	}
	void printInfo() override {
		std::cout << "A Scanner: " << std::endl;
		std::cout <<"Network: "<< hasNetwork << std::endl;
	}
	Scanner* clone() {
		std::cout << "Copy Scanner" << std::endl;
		return new Scanner(*this);
	}
};