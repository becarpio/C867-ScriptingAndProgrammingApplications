#pragma once
#include <string>
#include "student.h"

class SoftwareStudent : public Student
{
public:
	Degree degreeProgram;

	//Constructors
	SoftwareStudent();
	SoftwareStudent(std::string ID, std::string firstName, std::string lastName, std::string email, int age, int courseDays[], Degree degreeType);

	//Functions to override Student's virtual functions
	Degree GetDegreeType();
	void PrintStudentData();

	//Destructor
	~SoftwareStudent();
};

