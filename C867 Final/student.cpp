#include <iostream>
#include <string>
#include <iomanip>
#include "student.h"

using namespace std;

//Constructors...
//Empty
Student::Student()
{
	this->studentID = "NoID";
	this->studentFirstName = "NoFirstName";
	this->studentLastName = "NoLastName";
	this->studentEmail = "NoEmail";
	this->studentAge = "NoAge";
	this->daysinCourse = new double[COURSE_DAYS_ARRAY_SIZE];
	for (int i = 0; i < COURSE_DAYS_ARRAY_SIZE; i++) this->daysinCourse[i] = -1;
}

//Full constructor
Student::Student(string ID, string firstName, string lastName, string email,
	string age, double days[], Degree degree)
{
	this->studentID = ID;
	this->studentFirstName = firstName;
	this->studentLastName = lastName;
	this->studentEmail = email;
	this->studentAge = age;
	this->daysinCourse = new double[COURSE_DAYS_ARRAY_SIZE];
	for (int i = 0; i < NUM_STUDENTS; i++) this->daysinCourse[i] = days[i];
}

//Destructor...
Student::~Student()
{
	if (daysinCourse != nullptr)
	{
		delete[] daysinCourse;
		daysinCourse = nullptr;
	}
}

//Mutator Functions...
void Student::setStudentID(string IDtoSet)
{
	this->studentID = IDtoSet;
}
void Student::setStudentFirstName(string firstNametoSet)
{
	this->studentFirstName = firstNametoSet;
}
void Student::setStudentLastName(string lastNametoSet)
{
	this->studentLastName = lastNametoSet;
}
void Student::setStudentEmail(string emailtoSet)
{
	this->studentEmail = emailtoSet;
}
void Student::setStudentAge(string agetoSet)
{
	this->studentAge = agetoSet;
}
void Student::setDaysinCourse(double days[])
{
	if (this->daysinCourse != nullptr)
	{
		delete[] this->daysinCourse;
		this->daysinCourse = nullptr;
	}

	this->daysinCourse = new double[COURSE_DAYS_ARRAY_SIZE];
	for (int i = 0; i < COURSE_DAYS_ARRAY_SIZE; i++)
	{
		this->daysinCourse[i] = days[i];
	}
}

//Accessor Functions...
string Student::getStudentID()
{
	return studentID;
}
string Student::getStudentFirstName()
{
	return studentFirstName;
}
string Student::getStudentLastName()
{
	return studentLastName;
}
string Student::getStudentEmail()
{
	return studentEmail;
}
string Student::getStudentAge()
{
	return studentAge;
}
double * Student::getdaysinCourse()
{
	return daysinCourse;
}

void Student::print()
{
	cout << studentID << "   ";
	cout << studentFirstName << "   ";;
	cout << studentLastName << "   ";;
	cout << studentEmail << "   ";;
	cout << studentAge << "   ";;
	cout << daysinCourse[0] << ", ";;
	cout << daysinCourse[1] << ", ";;
	cout << daysinCourse[2] << "   ";;
}

