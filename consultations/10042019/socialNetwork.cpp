// class Person.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <cstring>


class Person
{
private:
	char name[64];
	double height;
	int age;
	double weight;
	bool gender;
	char username[16];
	char password[32];

public:
	Person();
	Person(const char*, double, int, double, bool, const char*, const char*);
	bool operator==(const Person& other) const;
	bool operator!=(const Person& other) const;
	bool operator>(const Person& other) const;
	bool operator<(const Person& other) const;
	bool operator<=(const Person& other) const;

	void print() const;
};

void Person::print() const
{
	std::cout << this->name << " " << this->age << " " << this->gender << " " <<
		this->username << " " << this->password << std::endl;
}

bool Person::operator<=(const Person& other) const
{
	return !(*this > other);
}

bool Person::operator>(const Person& other) const // >, +,-, >= .. bind with left object
{
	if (this->age == other.age)
	{
		if (this->height == other.height)
		{
			return this->weight > other.weight;
		}
		return this->height > other.height;
	}
	return this->age > other.age;
}

bool Person::operator<(const Person& other) const
{
	return !(*this == other || *this > other); 
}

Person::Person()
{
	this->name[0] = '\0';
	this->height = 0;
	this->age = 0;
	this->weight = 0;
	this->gender = true;
	this->username[0] = '\0';
	this->password[0] = '\0';
}
Person::Person(const char* _name, double _height, int _age,
	double _weight, bool _gender, const char* _username, const char* _password)
{
	strcpy_s(this->name,strlen(_name) + 1, _name);
	this->height = _height;
	this->age = _age;
	this->weight = _weight;
	this->gender = _gender;
	strcpy_s(this->username, strlen(_username) + 1, _username);
	strcpy_s(this->password, strlen(_password) + 1, _password);
}
bool Person::operator==(const Person& other) const
{
	return this->height == other.height &&
		this->age == other.age &&
		this->weight == other.weight &&
		this->gender == other.gender &&
		strcmp(this->name, other.name) == 0 &&
		strcmp(this->username, other.username) == 0 &&
		strcmp(this->password, other.password) == 0;
}
bool Person::operator!=(const Person& other) const
{
	return !(*this == other);
}

class SocialNetwork
{
private:
	Person* users;
	size_t size;
	size_t capacity;

	void copy(const SocialNetwork& other);
	void erase();
	void resize();
	
	
public:
	SocialNetwork();
	SocialNetwork(const SocialNetwork& other);
	SocialNetwork& operator=(const SocialNetwork& other);
	~SocialNetwork();

	void push(const Person& newPerson);
	bool includes(const Person& newPerson);
	void removePerson(const Person& findPerson);
};

void SocialNetwork::removePerson(const Person& findPerson)
{
	for (size_t i = 0; i < size; i++)
	{
		if (findPerson == users[i])
		{
			users[i] = users[size];
			--size;
			return;
		}
	}
}
 
bool SocialNetwork::includes(const Person& newPerson) // Check if a person is in a database
{
	for (size_t i = 0; i < size; i++)
	{
		if (newPerson == users[i])
		{
			return true;
		}
	}
	return false;
}

void SocialNetwork::push(const Person& newPerson)
{
	if (size == capacity)
	{
		resize();
	}
	
	users[size] = newPerson;
	size++;
}

void SocialNetwork::resize() // Alternative to the one used with String
{
	this->capacity *= 2;
	
	Person* temp = new Person[capacity];

	for (size_t i = 0; i < this->size; i++)
	{
		temp[i] = this->users[i];
	}
	
	delete[] this->users;
	this->users = temp;
}

SocialNetwork& SocialNetwork::operator=(const SocialNetwork& other) // Operator =
{
	if (this != &other)
	{
		this->erase();
		this->copy(other);
	}
	return *this;
}

SocialNetwork::SocialNetwork(const SocialNetwork& other) // Copy constructor
{
	this->copy(other);
}

void SocialNetwork::copy(const SocialNetwork& other) // copy function
{
	this->size = other.size;
	this->capacity = other.capacity;

	this->users = new Person[capacity];

	for (size_t i = 0; i < size; i++)
	{
		this->users[i] = other.users[i];
	}
}

SocialNetwork::SocialNetwork() // Default Constructor
{
	this->users = nullptr;
	this->capacity = 8;
	this->size = 0;
}

SocialNetwork::~SocialNetwork()
{
	this->erase();
}

void SocialNetwork::erase()
{
	delete[] this->users;
	//this->users = nullptr;
}

int main()
{
	Person p1("Gosho", 171, 51, 50, 1, "userGosho", "pasGosho");
	Person p2("Traicho", 151, 41, 29, 0, "userTr", "pasTr");

	p1.print();

	p2.print();

	return 0;
}
