#pragma once
#include "degree.h"
#include "student.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"


class Roster
{
public:
	//Constructor
	Roster(); 

	//Destructor for Roster
	~Roster();

	//Accessor
	Student* GetStudentAt(int index);

	//Mutators
	// Sets the instance variables for Student and updates the roster
	void Parse(std::string studentDataString);
	void Add(std::string studentID, std::string firstName, std::string lastName,
		std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeType);

	// Remove a student from the roster by studentID. If the student ID does not exist, the function prints an error message
	// to that effect
	void Remove(std::string studentID);


	//Print Functions

	// Prints a complete tab-separated list of student data using accessor functions. 
	// Function loops through all students in classRosterArray and calls the Student::print() function for each student.
	void PrintAll();

	// Prints a student's average number of days in the three courses.
	// The student is identified by the studentID parameter.
	void PrintDaysInCourse(std::string studentID);

	// Verifies student email addresses and displays all invalid email addresses to the user
	// Valid emails include and '@' symbol AND '.'
	// Valid emails do NOT include a ' '
	void PrintInvalidEmails();

	// Prints out student information for a degree program specified by an enumerated type
	void PrintByDegreeProgram(int degreeType);




private:
	int lastIndex; //Records how many entries are currently in the roster
	Student** classRosterArray; // Array of pointers to hold the data provided in the studentData table


};

