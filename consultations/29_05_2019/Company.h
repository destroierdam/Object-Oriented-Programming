#pragma once
#include "Employee.h"
class Company {
	Employee** employees;
	size_t size;
	size_t capacity;
	void copy(const Company& other) {
		this->size = other.size;
		this->capacity = other.capacity;
		this->employees = new Employee*[this->capacity];
		for (size_t i = 0; i < this->size; i++)
		{
			this->employees[i] = other.employees[i]->clone();
		}
	}
	void destroy() {
		for (size_t i = 0; i < this->size; i++)
		{
			delete this->employees[i];
		}
		delete[] this->employees;
	}
public:
	Company(){
		this->capacity = 8;
		this->employees = new Employee*[this->capacity];
		
		this->size = 0;
	}
	Company operator + (const Company& other) const {
		Company result;
		result.destroy();

		result.size = this->size + other.size;
		result.capacity = this->capacity + other.capacity;
		result.employees = new Employee*[result.capacity];

		for (size_t i = 0; i < this->size; i++)
		{
			result.employees[i] = this->employees[i]->clone();
		}
		for (size_t i = this->size, j = 0;
			 i < result.size, j < other.size;
			 i++, j++)
		{
			result.employees[i] = other.employees[j]->clone();
		}
		return result;
	}
	~Company() {
		this->destroy();
	}
};
