#ifndef NETWORKSTUDENT_H
#define NETWORKSTUDENT_H
#include "degree.h"
#include "student.h"
using namespace std;

class NetworkStudent : public Student
{
public:

	//Constructors...
	//Empty
	NetworkStudent();

	//Full Constructor
	NetworkStudent(string ID, string firstName, string lastName, string email,
		int age, double* daysinCourse, Degree degree);

	//Destructor...
	~NetworkStudent();

	//Mutator...
	void setDegreeProgram(Degree degree);

	//Accessor...
	Degree getDegreeProgram();

	//Subclass print function...
	void print();

};

#endif // !NETWORKSTUDENT_H

