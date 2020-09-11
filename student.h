#pragma once
#include <string>
#include "degree.h"

class Student
{
public:
	//Variable for number of courses
	static const int courseArraySize = 3;

	//Constructors
	Student(); //Default
	//Full Constructor. Does not include bookType because subclasses will address
	Student(
		std::string ID, 
		std::string firstName, 
		std::string lastName,
		std::string email, 
		int age, 
		int courseDays[]);

	//Destructor
	~Student();

	// Accessor for each variable
	// Returns the data assigned to the variable
	std::string GetStudentID();
	std::string GetFirstName();
	std::string GetLastName();
	std::string GetEmail();
	int GetAge();
	int* GetCourseNumberDays();
	

	// Populated by the subclasses (NetworkStudent, SecurityStudent, and SoftwareStudent)
	virtual Degree GetDegreeType() = 0;

	// Mutators for each variable
	// Sets the value for each variable, except degreeType which is populated in the subclasse
	void SetStudentID(std::string ID);
	void SetFirstName(std::string firstName);
	void SetLastName(std::string lastName);
	void SetEmail(std::string email);
	void SetAge(int age);
	void SetCourseNumberDays(int courseNumberDays[]);

	// Print functions
	// Prints all of the data related to a specific student
	virtual void PrintStudentData() = 0;

protected:
	std::string studentID;
	std::string firstName;
	std::string lastName;
	std::string email;
	int age;
	int courseNumberDays[courseArraySize];
	Degree degreeType;

};

