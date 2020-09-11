#include <iostream>
#include "softwareStudent.h"

//Constructors
SoftwareStudent::SoftwareStudent() :Student() {
	degreeProgram = SOFTWARE;;
}
SoftwareStudent::SoftwareStudent(std::string ID, std::string firstName, std::string lastName, std::string email, int age, int courseDays[], Degree degreeType)
	: Student(ID, firstName, lastName, email, age, courseDays) {
	this->degreeProgram = SOFTWARE;
}

//Functions to override Student's virtual functions
Degree SoftwareStudent::GetDegreeType() {
	return degreeProgram;
}

void SoftwareStudent::PrintStudentData() {
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
SoftwareStudent::~SoftwareStudent() {
	//Call destructor from Student
	Student::~Student();
}
