#pragma once
#include "Drink.h"
using std::cout;
using std::endl;
class NonAlcohol : public Drink {
	bool isCarbonated;
public:
	NonAlcohol(std::string label, double amount):Drink(label, amount) {
		cout << "Constructing nonAlcohol" << endl;
		isCarbonated = false;
	}
	void drink() override {
		cout << "Drink without mood" << endl;
	}

	void getMaker() const {
		cout << "Coca cola" << endl;
	}
};