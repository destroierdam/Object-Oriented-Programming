#include "pch.h"
#include <iostream>
#include <cassert>
using namespace std;

int main()
{
	size_t teachersSize;
	cin >> teachersSize;

	// In every row there will be an array - space, where the teachers will put their marks.

	// Make space for teachersSize teachers
	double** marks = new double*[teachersSize];

	for (size_t i = 0; i < teachersSize; i++)
	{
		size_t marksSize;
		cin >> marksSize;

		// Make space for the i'th teacher to put marksSize marks
		marks[i] = new double[marksSize];

		for (size_t j = 0; j < marksSize; j++)
		{
			cin >> marks[i][j];
		}
	}

	return 0;
}
/*
Учители
В една школа има определен брой учители. 
Всеки един от тях иска да нанесе определен брой оценки. 

Дайте на учителите места, където да си нанесат оценките.

*/