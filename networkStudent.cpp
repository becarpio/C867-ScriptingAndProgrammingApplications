#include <iostream>
#include "NetworkStudent.h"


//Constructors
NetworkStudent::NetworkStudent() :Student() {
	degreeProgram = NETWORKING;
}NetworkStudent::NetworkStudent(std::string ID, std::string firstName, std::string lastName, std::string email, int age, int courseDays[], Degree degreeType)
	: Student(ID, firstName, lastName, email, age, courseDays) {
	this->degreeProgram = NETWORKING;
}

//Functions to override Student's virtual functions
Degree NetworkStudent::GetDegreeType() {
	return degreeProgram;
}

void NetworkStudent::PrintStudentData() {

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
NetworkStudent::~NetworkStudent() {
	//Call destructor from Student
	Student::~Student();
}
