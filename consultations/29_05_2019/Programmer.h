#pragma once
#include <iostream>
#include "Employee.h"
using std::cout;
using std::endl;
class Programmer : public Employee {
	bool knowsCpp;
	bool knowsCs;
public:
	Programmer() : Employee() {
		cout << "Constructing Programmer" << endl;
		this->knowsCpp = false;
		this->knowsCs = false;
	}
	Programmer(bool _knowsCpp, bool _knowsCs) {
		this->knowsCpp = _knowsCpp;
		this->knowsCs = _knowsCs;
	}
	void work() {
		cout << "Programming" << endl;
	}
	Programmer* clone() const {
		return new Programmer(*this);
	}
	~Programmer() {
		std::cout << "Destructing programmer" << std::endl;
	}
};
