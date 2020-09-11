#pragma once
#include <string>
#include "student.h"

class SecurityStudent : public Student
{
public:

	//Constructors
	SecurityStudent();
	SecurityStudent(
		std::string ID, 
		std::string firstName, 
		std::string lastName, 
		std::string email, 
		int age, 
		int courseDays[], 
		Degree degreeType);

	//Functions to override Student's virtual functions
	Degree GetDegreeType();
	void PrintStudentData();

	//Destructor
	~SecurityStudent();
};
