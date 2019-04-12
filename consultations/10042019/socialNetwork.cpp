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
	// Default constructor
	Person();
	Person(const char*, double, int, double, bool, const char*, const char*);
	// Overloading relational operators; const => doesn't change the caller's data
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
	// If the ages are equal, 
	if (this->age == other.age)
	{
		// If the height is equal,
		if (this->height == other.height)
		{
			// Compare by weight
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
	// Set default values for Person's data
	this->name[0] = '\0';
	this->height = 0;
	this->age = 0;
	this->weight = 0;
	this->gender = true;
	this->username[0] = '\0';
	this->password[0] = '\0';
}
// Constructor with parameters; gives Person info about him
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
	// Array of Person's; dynamically allocated
	Person* users;
	// Stores the actual number of people in the social network
	size_t size;
	// Stores the number of people that we have allocated; the real size of the array "users"
	size_t capacity;

	// Copies the values of other into this; allocates necessarry memory
	void copy(const SocialNetwork& other);
	// Deletes the dynamically allocated array
	void erase();
	// Increases the size of array "users" dynamically
	void resize();
	
	
public:
	// Goliama chetvorka
	// Default constructor
	SocialNetwork();
	// Copy constructor
	SocialNetwork(const SocialNetwork& other);
	// Operator =
	SocialNetwork& operator=(const SocialNetwork& other);
	// Destructor
	~SocialNetwork();

	// Adds a person to the social network
	void push(const Person& newPerson);
	// Checks whether a person is already in the network
	bool includes(const Person& newPerson);
	void removePerson(const Person& findPerson);
};

void SocialNetwork::removePerson(const Person& findPerson)
{
	// Go through all Persons in users
	for (size_t i = 0; i < size; i++)
	{
		// If you find the person you are looking for
		if (findPerson == users[i])
		{
			// Overwrite it with the last person
			users[i] = users[size];
			// Decrease the size of the array
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
