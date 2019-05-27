#pragma once
#include <iostream>
#include <string>
#include "Alcohol.h"
using std::cout;
using std::endl;
class Rakiq : public Alcohol {
	std::string madeOf;
public:
	Rakiq() {
		this->madeOf = "Kvoto ostane";
	}
	std::string isMadeOf() const {
		return this->madeOf;
	}
};