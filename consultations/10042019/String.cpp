#include "pch.h"
#include <iostream>
#include <cstring>

class String
{
private:
	char* str;
	size_t size;
	size_t CAPACITY;

	void resize()
	{
		this->CAPACITY = CAPACITY * 2;
		char *tmp = str;
		str = new char[CAPACITY];
		strcpy_s(this->str, size + 1, tmp);

		/*
		for (int i = 0; tmp[i] != '\0'; i++)
		{
			str[i] = tmp[i];
		}
		str[this->size] = '\0';
		*/
		
		
		delete[] tmp;
	}

	void del() // Delete dynamically allocated memory
	{
		delete[] str;
	}

	void copy(const String& other) // Copy function
	{
		this->CAPACITY = strlen(other.str) + 1;
		this->size = other.size;
		str = new char[CAPACITY];

		strcpy_s(str, CAPACITY, other.str);
	}

public:
	String() // Default construnctor
	{
		CAPACITY = 8;
		this->str = new char[CAPACITY];
		this->size = 0;
	}

	String(const char* _str) // Parametric constructor
	{
		this->CAPACITY = strlen(_str) + 1;
		this->size = CAPACITY - 1;
		str = new char[CAPACITY];
		
		strcpy_s(str, CAPACITY, _str);
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
	friend std::ostream& operator<<(std::ostream out, const String& data);
	String& operator+=(const String&);
	String operator+(const String&);
};

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

std::ostream& operator<<(std::ostream& out, const String& data)
{
	out << data.str;
}

int main()
{
    std::cout << "Hello World!\n";

	String s1("abs");

	std::cout << s1;
}
