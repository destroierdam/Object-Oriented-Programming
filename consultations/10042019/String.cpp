#include "pch.h"
#include <iostream>
#include <cstring>
using namespace std;

class String
{
private:
	// Pointer, that will hold the address of the dynamically allocated array
	char* str;

	// Holds the real size of the string 
	size_t size;

	// Holds the length of the array; must be >= size
	size_t CAPACITY;

	// Makes the array twice as big 
	void resize()
	{
		// Increase the capacity twice
		this->CAPACITY = CAPACITY * 2;

		// Remember where the old string is in memory
		char *tmp = str;

		// Allocate new place for string
		str = new char[CAPACITY];

		// Copy the contents of the old string in the new string
		strcpy_s(this->str, size + 1, tmp);


		// Alternatively, you can copy with a for-loop
		/*
		for (int i = 0; tmp[i] != '\0'; i++)
		{
			str[i] = tmp[i];
		}
		str[this->size] = '\0';
		*/

		// Delete the old array
		delete[] tmp;
	}

	// Delete the dynamically allocated memory
	void del()
	{
		delete[] str;
	}

	// Copy the contents of other into this
	void copy(const String& other) 
	{
		// We need to allocate memory for the string and + 1 for the '\0' character
		this->CAPACITY = strlen(other.str) + 1;

		// The size is the same
		this->size = other.size;

		// Allocate memory
		this->str = new char[CAPACITY];

		// Copy the contents into str from other.str and copy CAPACITY bytes
		strcpy_s(this->str, CAPACITY, other.str);
	}

public:
	// Default constructor (without arguments)
	// Called when constructed without arguments; Example: String s;
	String()
	{
		// Set the default capacity to be 8
		this->CAPACITY = 8;

		// Allocate array with length CAPACITY and type char 
		this->str = new char[CAPACITY];

		// The string is empty
		this->size = 0;
	}

	// Constructor with parameters
	String(const char* _str)
	{
		// We need to allocate strlen(_str) + 1 bytes for the string + '\0' character 
		this->CAPACITY = strlen(_str) + 1;

		// The size is the length of the string without the '\0' character
		this->size = CAPACITY - 1;

		// Allocate memory
		str = new char[CAPACITY];

		// Copy the contents from _str to this->str
		strcpy_s(this->str, CAPACITY, _str);
	}

	String(const String& other) // Copy constructor
	{
		copy(other);
	}

	String& operator=(const String& other) // Operator =
	{
		if (this != &other) // p4 = p4 ?? //(x = (y = (z = 69))) 
		{
			del();
			copy(other);
		}
		return *this;
	}

	~String() // Destructor
	{
		del();
	}
	void push(char a)
	{
		if (size == CAPACITY - 1)
		{
			resize();
		}
		this->str[size] = a;
		size++;
		this->str[size] = '\0';
	}
	friend std::ostream& operator<<(std::ostream& out, const String& data);
	String& operator+=(const String&);
	String operator+(const String&);
};

std::ostream& operator<<(std::ostream& out, const String& data)
{
	out << data.str;
	return out;
}


String& String::operator+=(const String& other)
{
	for (size_t i = 0; i < other.size; i++)
	{
		this->push(other.str[i]);
	}

	return *this;
}



String String::operator+(const String& other)
{
	String temp = *this;
	temp += other;

	return temp;
}


int main()
{
	std::cout << "Hello World!\n";

	String s1("abs");


}
