#pragma once
#include <string>
using std::cout;
using std::endl;
class Drink {
	std::string label;
	double amount;
public:
	Drink() {
		cout << "Constructing drink" << endl;
		this->label = "Default";
		this->amount = 1.0;
	}
	Drink(std::string _label, double _amount) {
		this->label = _label;
		this->amount = _amount;
	}
	virtual void drink() {
		std::cout << "Drinking something" << std::endl;
	}
	virtual void getMaker() const = 0;
};