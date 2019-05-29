#ifndef _MANAGER_H_
#define _MANAGER_H_
#include "Manager.h"
class Manager : public Employee {
	unsigned int peopleManaged;
public:
	Manager() {
		this->peopleManaged = 0;
	}
	Manager(unsigned int peopleManaged) {
		this->peopleManaged = peopleManaged;
	}
	Manager* clone() const {
		return new Manager(*this);
	}
};
#endif // _MANAGER_H_
