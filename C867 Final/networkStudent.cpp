#include <iostream>
#include "student.h"
#include "degree.h"
#include "networkStudent.h"
using namespace std;

//NetworkStudent subclass constructor...
//Empty
NetworkStudent::NetworkStudent()
{
	setDegreeProgram(NETWORK);
}
//Full constructor
NetworkStudent::NetworkStudent(string ID, string firstName, string lastName, string email,
	int age, double* daysinCourse, Degree degree)
{
	setDegreeProgram(NETWORK);
}

//NetworkStudent subclass destructor...
NetworkStudent::~NetworkStudent()
{
	Student::~Student();
	delete this;
}

//Degree Mutator...
void NetworkStudent::setDegreeProgram(Degree degree)
{
	this->degreeProgram = NETWORK;
}

//Degree Accessor...
Degree NetworkStudent::getDegreeProgram()
{
	return NETWORK;
}

//Print function...
void NetworkStudent::print()
{
	this->Student::print();
	cout << "NETWORK" << endl;
}