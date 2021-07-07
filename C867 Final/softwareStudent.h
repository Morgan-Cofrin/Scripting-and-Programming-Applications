#ifndef SOFTWARESTUDENT_H
#define SOFTWARESTUDENT_H
#include "degree.h"
#include "student.h"
using namespace std;

class SoftwareStudent : public Student
{
public:

	//Constructors...
	//Empty
	SoftwareStudent();

	//Full Constructor
	SoftwareStudent(string ID, string firstName, string lastName, string email,
		int age, double* daysinCourse, Degree degree);

	//Destructor...
	~SoftwareStudent();

	//Mutator...
	void setDegreeProgram(Degree degree);

	//Accessor...
	Degree getDegreeProgram();

	//Subclass print function...
	void print();

};

#endif // !SOFTWARESTUDENT_H

