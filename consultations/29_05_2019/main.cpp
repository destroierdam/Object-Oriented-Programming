#include "pch.h"
#include <iostream>
#include "Employee.h"
#include "Programmer.h"
#include "Company.h"
using namespace std;
Company mergeCompanies(const Company & company1, const Company & company2) {
	return company1 + company2;
}
int main()
{
	Employee* emp = new Programmer();

	delete emp;
	return 0;
}
