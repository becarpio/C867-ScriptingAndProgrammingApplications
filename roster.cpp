#include "roster.h"
#include <iostream>
#include <string>

//Constructor
Roster::Roster() {
	this->lastIndex = -1;
	this->classRosterArray = new Student *[5];
}

//Destructor for Roster
Roster::~Roster() {
	for (int i = 0; i <= lastIndex; i++) {
		//Delete each Student
		delete this->classRosterArray[i];
	}
	//Delete the whole Roster
	delete classRosterArray; 
}

Student* Roster::GetStudentAt(int index) {
	return classRosterArray[index];
}

void Roster::Parse(std::string studentDataString) {
	std::string ID;
	std::string firstName;
	std::string lastName;
	std::string email;
	std::string nonEnumDegree;
	std::string updatedStudentData;
	int age;
	int course1Days;
	int course2Days;
	int course3Days;
	Degree degreeType;

	//Parse each row individually and add to the roster
		//Begin with ID
	int rhs = studentDataString.find(',');
	ID = studentDataString.substr(0, rhs);

	//Read firstName
	int lhs = rhs + 1;
	rhs = studentDataString.find(',', lhs);
	firstName = studentDataString.substr(lhs, rhs - lhs);

	//Read lastName
	lhs = rhs + 1;
	rhs = studentDataString.find(',', lhs);
	lastName = studentDataString.substr(lhs, rhs - lhs);

	//Read email
	lhs = rhs + 1;
	rhs = studentDataString.find(',', lhs);
	email = studentDataString.substr(lhs, rhs - lhs);

	//Read age
	lhs = rhs + 1;
	rhs = studentDataString.find(',', lhs);
	age = stoi(studentDataString.substr(lhs, rhs - lhs));

	//Read each courseNumberDays
	lhs = rhs + 1;
	rhs = studentDataString.find(',', lhs);
	course1Days = stoi(studentDataString.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentDataString.find(',', lhs);
	course2Days = stoi(studentDataString.substr(lhs, rhs - lhs));


	lhs = rhs + 1;
	rhs = studentDataString.find(',', lhs);
	course3Days = stoi(studentDataString.substr(lhs, rhs - lhs));

	//Read nonEnumDegree
	lhs = rhs + 1;
	rhs = studentDataString.find(',', lhs);
	nonEnumDegree = studentDataString.substr(lhs, rhs - lhs);

	//Convert string nonEnumDegree to enumerated value
	if (nonEnumDegree == "NETWORK") {
		degreeType = NETWORKING;
	}
	else if (nonEnumDegree == "SECURITY") {
		degreeType = SECURITY;
	}
	else if (nonEnumDegree == "SOFTWARE") {
		degreeType = SOFTWARE;
	}

	lastIndex += 1;
	//Add new student to class roster using the appropriate subclass based on degree type
	Add(ID, firstName, lastName, email, age, course1Days, course2Days, course3Days, degreeType);
}

// Sets the instance variables for Student and updates the roster
void Roster::Add(std::string ID, std::string firstName, std::string lastName, std::string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeType) {
	
	int courseDays[3];
	courseDays[0] = daysInCourse1;
	courseDays[1] = daysInCourse2;
	courseDays[2] = daysInCourse3;
	
	if (degreeType == NETWORKING) {
		classRosterArray[lastIndex] = new NetworkStudent(ID, firstName, lastName, email, age, courseDays, degreeType);
	}
	else if (degreeType == SOFTWARE) {
		classRosterArray[lastIndex] = new SoftwareStudent(ID, firstName, lastName, email, age, courseDays, degreeType);
	}
	else if (degreeType == SECURITY) {
		classRosterArray[lastIndex] = new SecurityStudent(ID, firstName, lastName, email, age, courseDays, degreeType);
	}
	return;
}

// Remove a student from the roster by studentID. If the student ID does not exist, the function prints an error message
// to that effect
void Roster::Remove(std::string studentID) {
	bool studentIDFound = false;
	// Find the studentID based on the string
	// Delete the student information
	for (int i = 0; i <= lastIndex; i++) {
		if (this->classRosterArray[i]->GetStudentID() == studentID) {
			studentIDFound = true;
			delete this->classRosterArray[i];

			//Move last book into this position to leave no gaps in the array
			this->classRosterArray[i] = this->classRosterArray[lastIndex];
			lastIndex--; 
		}
	}

	if (studentIDFound == false) {
		// If the ID doesn't exist print an error message
		std::cout << "Error: Student with this ID was not found" << std::endl;
	}
	else {
		std::cout << "Student " << studentID << " removed." << std::endl;
	}

	return;
}

// Prints a complete tab-separated list of student data using accessor functions. 
// Function loops through all students in classRosterArray and calls the Student::print() function for each student.
void Roster::PrintAll() {
	for (int i = 0; i <= lastIndex; i++) {
		this->classRosterArray[i]->PrintStudentData();
	}
	return;
}

// Prints a student's average number of days in the three courses.
// The student is identified by the studentID parameter.
void Roster::PrintDaysInCourse(std::string studentID) {
	int totalDaysInCourse = 0;
	for (int i = 0; i <= lastIndex; i++) {
		// Checks to see if array member studentID matches
		// Assumes that each studentID is unique
		if (this->classRosterArray[i]->GetStudentID() == studentID) {
			// If so, Averages the course days and prints the average;
			for (int j = 0; j < 3; j++) {
				totalDaysInCourse += classRosterArray[i]->GetCourseNumberDays()[j];
			}
			break;
		}
	}
	std::cout << studentID << "'s average days per course: " << totalDaysInCourse / 3 << std::endl;
	return;
}

// Verifies student email addresses and displays all invalid email addresses to the user
// Valid emails include and '@' symbol AND '.'
// Valid emails do NOT include a ' '
void Roster::PrintInvalidEmails(){
	std::cout << std::endl;
	std::cout << "INVALID EMAIL ADDRESSES " << std::endl;
	for (int i = 0; i <= lastIndex; i++) {
		// Verify that each email address has '@' and '.'
		// Verify that each email address does NOT have ' '
		// If invalid, print out email address ONLY
		if (this->classRosterArray[i]->GetEmail().find('@') == std::string::npos ||
			this->classRosterArray[i]->GetEmail().find('.') == std::string::npos ||
			this->classRosterArray[i]->GetEmail().find(' ') != std::string::npos) {
			std::cout << classRosterArray[i]->GetEmail() << std::endl;
		}
	}
	return;
}

// Prints out student information for a degree program specified by an enumerated type
void Roster::PrintByDegreeProgram(int degreeType) {
	std::cout << std::endl <<  "Printing " << degreeStrings[degreeType] << " Student Information" << std::endl;

	for (int i = 0; i <= lastIndex; i++) {
		if (this->classRosterArray[i]->GetDegreeType() == (Degree)degreeType) {
			this->classRosterArray[i]->PrintStudentData();
		}
	}

	return;
}


void main() {

	static const std::string studentData[5] = {
			"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
			"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
			"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
			"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
			"A5,Jane,Smith,JSmith@school.edu,29,20,50,42,SOFTWARE" };

	std::string updatedStudentData;
	std::string currentID;

	// Prints Course Info, Name, etc. to the screen.
	std::cout << "Course Title: C867 - Scripting and Programming - Applications" << std::endl;
	std::cout << "Language Used: C++" << std::endl;
	std::cout << "Student ID: 000469842" << std::endl;
	std::cout << "Student Name: Bethany Carpio" << std::endl;

	// Create an instance of Roster called classRoster
	Roster* classRoster = new Roster;


	// Add each student to class Roster using the const string studentData
	// and the Add function of Roster


	for (int i = 0; i < 5; i++) {
		classRoster->Parse(studentData[i]);
	}


	// Print the whole Roster
	std::cout << std::endl;
	std::cout << "STUDENT ROSTER" << std::endl;
	classRoster->PrintAll();

	// Print the invalid emails
	classRoster->PrintInvalidEmails();

	// Loop through each member of classRoster and print
	// the Average days in course using student ID
	std::cout << std::endl;
	std::cout << "AVERAGE DAYS PER COURSE BY STUDENT" << std::endl;
	for (int i = 0; i <= sizeof(classRoster); i++) {
		currentID = classRoster->GetStudentAt(i)->GetStudentID();
		classRoster->PrintDaysInCourse(currentID);
	}


	// Print by degree program
	std::cout << std::endl;
	std::cout << "STUDENTS BY DEGREE PROGRAM" << std::endl;
	for (int i = 0; i < 3; i++) {
		classRoster->PrintByDegreeProgram(i);
	}

	// Remove student A3
	std::cout << std::endl;
	std::cout << "REMOVING STUDENT INFORMATION" << std::endl;
	classRoster->Remove("A3");

	// Remove again to show that the error message works
	classRoster->Remove("A3");

	// Call the destructor to release the Roster memory
	classRoster->~Roster();

	return;
}
