#include <iostream>
#include "roster.h"
#include "student.h"
#include "securityStudent.h"
#include "networkStudent.h"
#include "softwareStudent.h"

//Constructor...
//Empty
Roster::Roster()
{
	this->capacity = 0;
	this->lastIndex = -1;
	this->classRosterArray = nullptr;
}
//Full constructor
Roster::Roster(int capacity)
{
	this->capacity = capacity;
	this->lastIndex = -1;
	this->classRosterArray = new Student*[capacity];
}

//Destructor...
Roster::~Roster()
{
	for (int i = 0; i < lastIndex; i++)
	{
		delete this->classRosterArray[i];
	}
	delete this;
}

void Roster::parse(string dataRow)		//works, dont touch
{
		double daysArray[Student::COURSE_DAYS_ARRAY_SIZE];

		if (lastIndex < capacity)
		{
			//Make appropriate object
			lastIndex++;
			if (dataRow.back() == 'K')
			{
				this->classRosterArray[lastIndex] = new NetworkStudent();
				classRosterArray[lastIndex]->setDegreeProgram(NETWORK);
			}
			else if (dataRow.back() == 'Y')
			{
				this->classRosterArray[lastIndex] = new SecurityStudent();
				classRosterArray[lastIndex]->setDegreeProgram(SECURITY);
			}
			else if (dataRow.back() == 'E')
			{
				this->classRosterArray[lastIndex] = new SoftwareStudent();
				classRosterArray[lastIndex]->setDegreeProgram(SOFTWARE);
			}

			//Read ID
			int rhs = studentData[lastIndex].find(",");
			classRosterArray[lastIndex]->setStudentID(studentData[lastIndex].substr(0, rhs)); /////

			//Find and set first name
			int lhs = rhs + 1;
			rhs = studentData[lastIndex].find(",", lhs);
			classRosterArray[lastIndex]->setStudentFirstName(studentData[lastIndex].substr(lhs, rhs - lhs));

			//Read last name
			lhs = rhs + 1;
			rhs = studentData[lastIndex].find(",", lhs);
			classRosterArray[lastIndex]->setStudentLastName(studentData[lastIndex].substr(lhs, rhs - lhs));

			//Read email
			lhs = rhs + 1;
			rhs = studentData[lastIndex].find(",", lhs);
			classRosterArray[lastIndex]->setStudentEmail(studentData[lastIndex].substr(lhs, rhs - lhs));

			//Read age
			lhs = rhs + 1;
			rhs = studentData[lastIndex].find(",", lhs);
			classRosterArray[lastIndex]->setStudentAge(studentData[lastIndex].substr(lhs, rhs - lhs));

			//Read days in course
			lhs = rhs + 1;
			rhs = studentData[lastIndex].find(",", lhs);
			daysArray[0] = stod(studentData[lastIndex].substr(lhs, rhs - lhs));

			lhs = rhs + 1;
			rhs = studentData[lastIndex].find(",", lhs);
			daysArray[1] = stod(studentData[lastIndex].substr(lhs, rhs - lhs));

			lhs = rhs + 1;
			rhs = studentData[lastIndex].find(",", lhs);
			daysArray[2] = stod(studentData[lastIndex].substr(lhs, rhs - lhs));

			//set the days
			classRosterArray[lastIndex]->setDaysinCourse(daysArray);
		}
		else
		{
			cout << "Exceeded capacity, exiting";
			exit(-1);
		}
}

void Roster::printAll()		//works, dont touch
{
	cout << "Printing student data:" << endl;
	for (int i = 0; i <= this->lastIndex; i++)
	{
		(this->classRosterArray)[i]->print();
	}
	cout << endl;
}
bool Roster::remove(string studentID)		//works, dont touch
{
	bool found = false;
	for (int i = 0; i <= lastIndex; i++)
	{
		if (this->classRosterArray[i]->getStudentID() == studentID)
		{
			found = true;
			delete this->classRosterArray[i];
			this->classRosterArray[i] = this->classRosterArray[lastIndex];
			lastIndex--;
		}
	}
	return found;
}

void Roster::printAverageDaysInCourse(string studentID)
{
	bool found = false;
	for (int i = 0; i <= lastIndex; i++)
	{
		if (this->classRosterArray[i]->getStudentID() == studentID)
		{
			found = true;
			double* tempDays = classRosterArray[i]->getdaysinCourse();
			cout << "Average days per course for student " << studentID << " is "
				<< ((tempDays[0] + tempDays[1] + tempDays[2]) / 3) << " days." << endl;
		}
	}
	cout << endl;
}

void Roster::printInvalidEmails()		//works, dont touch
{
	cout << "Displaying invalid email addresses:\n";
	for (int i = 0; i <= lastIndex; i++)
	{
		string str1(this->classRosterArray[i]->getStudentEmail());
		char str2(' ');
		char str3('@');
		char str4('.');
		if (str1.find(str2) != string::npos)
		{
			cout << this->classRosterArray[i]->getStudentEmail();
			cout << endl;
		}
		if (str1.find(str3) == string::npos)
		{
			cout << this->classRosterArray[i]->getStudentEmail();
			cout << endl;
		}
		if (str1.find(str4) == string::npos)
		{
			cout << this->classRosterArray[i]->getStudentEmail();
			cout << endl;
		}
	}
	cout << endl;
}

void Roster::printByDegreeProgram(Degree degreeProgram)
{
	string tempDegree;
	if (degreeProgram == 0)
	{
		tempDegree = "Security";
	}
	if (degreeProgram == 1)
	{
		tempDegree = "Network";
	}
	if (degreeProgram == 2)
	{
		tempDegree = "Software";
	}
	cout << "Printing by degree: " << tempDegree << endl;
	for (int i = 0; i <= lastIndex; i++)
	{
		if (this->classRosterArray[i]->getDegreeProgram() == degreeProgram)
		{
			this->classRosterArray[i]->print();
		}
	}
	cout << endl;
}

int main()
{
	cout << "Course: Scripting and Programming Applications - C867" << endl;
	cout << "Language: C++" << endl;
	cout << "Student ID: #000862265" << endl;
	cout << "Name: Morgan Cofrin" << endl;
	cout << endl;

	//Make Roster...
	Roster* classRoster = new Roster(5);

	//Parse long strings...
	cout << "Parsing student data:" << endl;
	for (int i = 0; i < 5; i++)
	{
		classRoster->parse(studentData[i]);
	}
	cout << "Done" << endl << endl;

	//Print functionality...
	classRoster->printAll();

	//Print invalid emails...
	classRoster->printInvalidEmails();

	//Average of course days array...
	classRoster->printAverageDaysInCourse("A5");

	//Print by degree...
	classRoster->printByDegreeProgram(SOFTWARE);
	
	//Remove student from roster array...
	cout << "Removing student A3:" << endl;
	if (classRoster->remove("A3")) classRoster->printAll();
	else cout << "Student not found." << endl;

	//Error message if student not found in array...
	cout << "Removing student A3:" << endl;
	if (classRoster->remove("A3")) classRoster->printAll();
	else cout << "Student not found." << endl;
	//expected: the above line should print a message saying such a student with this ID was not found.

	return 0;
}