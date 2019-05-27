#pragma once
#include <iostream>
#include <string>
#include "Scanner.h"
#include "Printer.h"

class MFU : public Powerable {
	std::string maker;
public:
	MFU() {
		this->maker = "Default maker";
	}
	void printInfo() override {
		std::cout << "A MFU: " << std::endl;
		//Printer::printInfo();
		//Scanner::printInfo();
	}
	void work() override {
		std::cout << "Doing many things" << std::endl;
	}
	void printError() override {
		std::cout << "Not working" << std::endl;
	}
	MFU* clone() {
		std::cout << "Copy MFU" << std::endl;
		return new MFU(*this);
	}
};