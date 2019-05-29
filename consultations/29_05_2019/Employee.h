#pragma once
#include<iostream>
class Employee {
	int stazh;
	char* name;
	void copy(const Employee& other) {
		size_t nameSize = strlen(name) + 1;
		this->name = new char[nameSize];
		strcpy_s(this->name,strlen(other.name)+1, other.name);

		this->stazh = other.stazh;
	}
	void destroy() {
		delete[] this->name;
	}
public:
	Employee() : Employee("default", 0) {
		std::cout << "Constructing Employee" << std::endl;
	}
	Employee(const char* name, int stazh)
	{
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
		this->stazh = stazh;
	}
	Employee(const Employee& other) {
		this->copy(other);
	}
	Employee& operator=(const Employee& other)
	{
		if (this != &other)
		{
			this->destroy();
			this->copy(other);
		}
		return *this;
	}
	virtual ~Employee() {
		std::cout << "Destructing Employee" << std::endl;
		this->destroy();
	};
	
	virtual void work()
	{
		std::cout << "Working" << std::endl;
	}
	
	virtual Employee* clone() const {
		return new Employee(*this);
	}

};
