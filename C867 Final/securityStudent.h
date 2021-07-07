#ifndef SECURITYSTUDENT_H
#define SECURITYSTUDENT_H
#include "degree.h"
#include "student.h"
using namespace std;

class SecurityStudent : public Student
{
public:

	//Constructors...
	//Empty
	SecurityStudent();

	//Full Constructor
	SecurityStudent(string ID, string firstName, string lastName, string email,
		int age, double* daysinCourse, Degree degree);

	//Destructor...
	~SecurityStudent();

	//Mutator...
	void setDegreeProgram(Degree degree);

	//Accessor...
	Degree getDegreeProgram();

	//Subclass print function...
	void print();

};

#endif // !SECURITYSTUDENT_H

