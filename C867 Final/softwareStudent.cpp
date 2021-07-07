#include <iostream>
#include "student.h"
#include "degree.h"
#include "softwareStudent.h"
using namespace std;

//SoftwareStudent subclass constructor...
//Empty
SoftwareStudent::SoftwareStudent()
{
	setDegreeProgram(SOFTWARE);
}
//Full constructor
SoftwareStudent::SoftwareStudent(string ID, string firstName, string lastName, string email,
	int age, double* daysinCourse, Degree degree)
{
	setDegreeProgram(SOFTWARE);
}

//SoftwareStudent subclass destructor...
SoftwareStudent::~SoftwareStudent()
{
	Student::~Student();
	delete this;
}

//Degree Mutator...
void SoftwareStudent::setDegreeProgram(Degree degree)
{
	this->degreeProgram = SOFTWARE;
}

//Degree Accessor...
Degree SoftwareStudent::getDegreeProgram()
{
	return SOFTWARE;
}

//Print function...
void SoftwareStudent::print()
{
	this->Student::print();
	cout << "SOFTWARE" << endl;
}