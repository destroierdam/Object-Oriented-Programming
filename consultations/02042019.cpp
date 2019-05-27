#include "stdafx.h"
#include <iostream>
#include <cstring>
using namespace std;
class Point
{
	int x; int y;
public:
	/*
	Point() { x = 0; y = 0; }
	Point(int _x, int _y) { x = _x; y = _y; }
	void changeX(int dx)
	{
		this->x += dx;
	}
	void changeY(int dy)
	{
		this->y += dy;
	}
	/*
	Point& operator+=(const Point & other)
	{

	}
	



	friend ostream& operator<<(ostream& out, const Point & obj);
	*/
};
//ostream& operator<<(ostream& out, const Point & obj)
//{
//	out << "X: " << obj.x << ", Y: " << obj.y;
//	return out;
//}
//class Circle
//{
//	Point center;
//	size_t radius;
//public:
//	Circle() { radius = 0; }
//	Circle(int x, int y, size_t r):center(x,y)
//	{
//		this->radius = r;
//	}
//	Circle(Point p, size_t r)
//	{
//		this->center = p;
//		this->radius = r;
//	}
//};


class String
{
public:
	char * str;
	size_t sz;
	String() { this->str = nullptr; sz = 0; cout << "Constructor called" << endl; }
	String(const char * _str)
	{
		this->sz = strlen(_str)+1;
		this->str = new char[sz];
		strcpy_s(this->str, sz, _str);
	}
	String(const String & other)
	{
		cout << "Copy constructor" << endl;
		this->str = new char[other.sz + 1];
		strcpy_s(this->str, other.sz + 1, other.str);
		this->sz = other.sz;
	}
	~String() { cout << "Destructor called" << endl; }
	void append(const String & other)
	{
		//
	}
	char get(size_t idx) const
	{
		return this->str[idx];
	}
	void set(size_t idx, char newChar)
	{
		this->str[idx] = newChar;
	}

	char& operator[](size_t idx)
	{
		return this->str[idx];
	}
	void read()
	{
		cin >> this->str;
	}
};

class Stack
{
	int * items;
	size_t capacity;
	void copy(const Stack & other)
	{
		this->items = new int[other.capacity];
		for (size_t i = 0; i < other.capacity; i++)
		{
			this->items[i] = other[i];
		}
		this->capacity = other.capacity;
	}
	void destroy()
	{
		delete[] this->items;
	}
public:
	Stack() { items = nullptr; capacity = 0; }
	Stack(const Stack & other)
	{
		this->copy(other);
	}
	Stack& operator=(const Stack & other)
	{
		if (this != &other)
		{
			this->destroy();
			this->copy(other);
		}
	}
	~Stack()
	{
		this->destroy();
	}
};
int main()
{
	Stack s;
	Stack s2(s);

	return 0;
}
