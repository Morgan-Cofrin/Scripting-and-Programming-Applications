#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <iostream>
#include "degree.h"
using namespace std;

class Student
{
public:
	const static int COURSE_DAYS_ARRAY_SIZE = 3;
	const static int NUM_STUDENTS = 5;

	//Constructors...
	Student();	//Empty
	Student(string ID, string firstName, string lastName, string rmail,
		string age, double days[], Degree degree); //Full constructor
	
	//Destructor...
	~Student();

	//Mutators...
	void setStudentID(string IDtoSet);
	void setStudentFirstName(string firstNametoSet);
	void setStudentLastName(string lastNametoSet);
	void setStudentEmail(string emailtoSet);
	void setStudentAge(string agetoSet);
	void setDaysinCourse(double days[]);
	virtual void setDegreeProgram(Degree degree) = 0;

	//Accessors...
	string getStudentID();
	string getStudentFirstName();
	string getStudentLastName();
	string getStudentEmail();
	string getStudentAge();
	double* getdaysinCourse();
	virtual Degree getDegreeProgram() = 0;

	virtual void print() = 0;

protected:
	string studentID;
	string studentFirstName;
	string studentLastName;
	string studentEmail;
	string studentAge;
	double* daysinCourse;
	Degree degreeProgram;
};

#endif // !STUDENT_H
