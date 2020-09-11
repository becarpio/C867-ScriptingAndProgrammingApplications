#include "student.h"
#include <iostream>
#include <iomanip>

//Default Constructor
Student::Student() {
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->email = "";
	this->age = 0;
	for (int i = 0; i < courseArraySize; i++) {
		this->courseNumberDays[i] = 0;
	}
}

//Secondary Constructor
Student::Student(std::string ID, std::string firstName, std::string lastName, std::string email, int age, int courseDays[]) {
	this->studentID = ID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	for (int i = 0; i < courseArraySize; i++) {
		this->courseNumberDays[i] = courseDays[i];
	}
}

// Destructor
Student::~Student() {
	//Empty because there is nothing that Student declares that would need to be deleted	
}

//Returns Student ID
std::string Student::GetStudentID() {
	return studentID;
}

//Returns Student's First Name
std::string Student::GetFirstName() {
	return firstName;
}

//Returns Student's Last Name
std::string Student::GetLastName() {
	return lastName;
}

//Returns Student's Email Address
std::string Student::GetEmail() {
	return email;
}

//Returns Student's Age
int Student::GetAge() {
	return age;
}

//Returns Course Number Day for indicated index
int* Student::GetCourseNumberDays() {
	return courseNumberDays;
}

//Sets Student ID
void Student::SetStudentID(std::string ID) {
	this->studentID = ID;
	
	return;
}

//Sets Student First Name
void Student::SetFirstName(std::string firstName) {
	this->firstName = firstName;
	
	return;
}

//Sets Student Last Name
void Student::SetLastName(std::string lastName) {
	this->lastName = lastName;
	
	return;
}

//Sets Student Email
void Student::SetEmail(std::string email) {
	this->email = email;
	
	return;
}

//Sets Student Age
void Student::SetAge(int age) {
	this->age = age;
	
	return;
}

//Sets Course Array Days
void Student::SetCourseNumberDays(int courseNumberDays[]) {
	for (int i = 0; i < courseArraySize; i++) {
		this->courseNumberDays[i] = courseNumberDays[i];
	}
	
	return;
}

//Prints all of Single Student's data
void Student::PrintStudentData() {
	std::cout << "Student ID: " << GetStudentID();
	std::cout << "\t First Name: " << GetFirstName();
	std::cout << "\t Last Name: " << GetLastName();
	std::cout << "\t Age: " << GetAge();
	std::cout << "\t Days in Course: ";
	for (int i = 0; i < courseArraySize; i++) {
		std::cout << GetCourseNumberDays()[i] << " ";
	}

	return;
}