#include <iostream>
#include "SecurityStudent.h"

//Constructors
SecurityStudent::SecurityStudent():Student() {
	this->degreeType = SECURITY;
}
SecurityStudent::SecurityStudent(
	std::string ID, std::string firstName, std::string lastName, 
	std::string email, int age, int courseDays[], Degree degreeType)
	:Student(ID, firstName, lastName, email, age, courseDays) {
		this->degreeType = SECURITY;
}

//Functions to override Student's virtual functions
Degree SecurityStudent::GetDegreeType() {
	return degreeType;
}

void SecurityStudent::PrintStudentData() {
	this->Student::PrintStudentData();
	std::cout << "\t Degree Program: ";
	if (GetDegreeType() == NETWORKING) {
		std::cout << degreeStrings[0] << std::endl;
	}
	else if (GetDegreeType() == SECURITY) {
		std::cout << degreeStrings[1] << std::endl;
	}
	else if (GetDegreeType() == SOFTWARE) {
		std::cout << degreeStrings[2] << std::endl;
	}
}

//Destructor
SecurityStudent::~SecurityStudent() {
	//Call destructor from Student
	Student::~Student();
}
