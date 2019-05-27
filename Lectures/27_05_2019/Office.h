#pragma once
#include "ElDevice.h"
class Office {
	Powerable** devices;
	size_t size;
	size_t capacity;
	void copy(const Office & other) {
		this->capacity = other.capacity;
		this->size = other.size;
		
		this->devices = new Powerable*[this->capacity];

		for (size_t i = 0; i < other.size; i++)
		{
			this->devices[i] = other.devices[i]->clone();
		}
	}
	void destroy() {
		for (size_t i = 0; i < this->size; i++)
		{
			delete this->devices[i];
		}
		delete[] this->devices;
	}
	void resize() {
		this->capacity *= 2;
		Powerable ** newDevices = new Powerable*[this->capacity];
		for (size_t i = 0; i < this->size; i++)
		{
			newDevices[i] = this->devices[i];
		}
		delete[] this->devices;
		this->devices = newDevices;
	}
public:
	Office() {
		this->capacity = 2;
		this->devices = new Powerable*[this->capacity];
		this->size = 0;
	}
	Office(const Office & other) {
		this->copy(other);
	}
	Office& operator = (const Office & other) {
		if (this != &other) {
			this->destroy();
			this->copy(other);
		}
		return *this;
	}
	void addDevice(Powerable* newDevice) {
		if (size == capacity) {
			resize();
		}
		this->devices[size] = newDevice;
		size++;
	}
	void removeDevice(size_t index) {
		//
	}
	~Office() {
		this->destroy();
	}
};