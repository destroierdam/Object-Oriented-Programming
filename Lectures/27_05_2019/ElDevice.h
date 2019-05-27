#pragma once
#include <iostream>
class Powerable {
public:
	virtual Powerable* clone() = 0;
	virtual void printInfo() = 0;
	virtual void work() = 0;
	virtual void printError() = 0;
};