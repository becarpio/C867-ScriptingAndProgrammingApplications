#pragma once
#include <string>
#include <vector>
#include "degree.h"

class student
{
public:

	//Constructors
	student(); //Default
	student(std::string ID, std::string studentFirstName, std::string studentLastName, std::string studentEmail, int yearsOld, int courseDays[3], Degree programEnrolled); //Secondary

	//Accessor for each variable
	std::string GetStudentID();
	std::string GetFirstName();
	std::string GetLastName();
	std::string GetEmail();
	int GetAge();
	int* GetCourseNumberDays();
	Degree GetDegreeType();

	//Mutators for each variable
	void SetStudentID(std::string ID);
	void SetFirstName(std::string studentFirstName);
	void SetLastName(std::string studentLastName);
	void SetEmail(std::string studentEmail);
	void SetAge(int yearsOld);
	void SetCourseNumberDays(int courseDays[3]);
	void SetDegreeType(Degree programEnrolled);

	//Print functions
	virtual void printStudentData();

	//The Big Three
		//Destructor
		//Copy Constructor
		//Copy Assignment Operator

protected:
private:
	std::string studentID;
	std::string firstName;
	std::string lastName;
	std::string email;
	int age;
	int courseNumberDays[3];
	Degree degreeType;
};

