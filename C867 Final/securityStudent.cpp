#include <iostream>
#include "student.h"
#include "degree.h"
#include "securityStudent.h"
using namespace std;

//SecurityStudent subclass constructor...
//Empty
SecurityStudent::SecurityStudent()
{
	setDegreeProgram(SECURITY);
}
//Full constructor
SecurityStudent::SecurityStudent(string ID, string firstName, string lastName, string email,
	int age, double* daysinCourse, Degree degree)
{
	setDegreeProgram(SECURITY);
}

//SecurityStudent subclass destructor...
SecurityStudent::~SecurityStudent()
{
	Student::~Student();
	delete this;
}

//Degree Mutator...
void SecurityStudent::setDegreeProgram(Degree degree)
{
	this->degreeProgram = SECURITY;
}

//Degree Accessor...
Degree SecurityStudent::getDegreeProgram()
{
	return SECURITY;
}

//Print function...
void SecurityStudent::print()
{
	this->Student::print();
	cout << "SECURITY" << endl;
}