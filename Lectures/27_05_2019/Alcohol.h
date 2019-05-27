#pragma once
#include "Drink.h"
using std::cout;
using std::endl;

class Alcohol : public Drink {
	double alcohol;
public:
	Alcohol() {
		this->alcohol = 50;
	}
	void drink() override {
		std::cout << "Drink with mood" << std::endl;
	}

	void getMaker() const {
		cout << "Vineks Preslav" << endl;
	}
};