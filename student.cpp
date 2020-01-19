#include "student.h"
#include "degree.h"


//Default Constructor
student::student() {
	studentID = "none";
	firstName = "none";
	lastName = "none";
	email = "none";
	age = 0;
	courseNumberDays[0] = 0;
	courseNumberDays[1] = 0;
	courseNumberDays[2] = 0;
	degreeType = Degree::SOFTWARE;

}

//Secondary Constructor
student::student(std::string ID, std::string studentFirstName, std::string studentLastName, std::string studentEmail, int yearsOld, int courseDays[3], Degree programEnrolled) {
	studentID = ID;
	firstName = studentFirstName;
	lastName = studentLastName;
	email = studentEmail;
	age = yearsOld;
	courseNumberDays[0] = courseDays[0];
	courseNumberDays[1] = courseDays[1];
	courseNumberDays[2] = courseDays[2];
	degreeType = programEnrolled;
}

std::string student::GetStudentID() {
	return studentID;
}

std::string student::GetFirstName() {
	return firstName;
}

std::string student::GetLastName() {
	return lastName;
}

std::string student::GetEmail() {
	return email;
}

int student::GetAge() {
	return age;
}

int* student::GetCourseNumberDays() {
	return courseNumberDays;
}
Degree student::GetDegreeType() {
	return degreeType;
}

void student::SetStudentID(std::string ID) {
	studentID = ID;
	return;
}
void student::SetFirstName(std::string studentFirstName) {
	firstName = studentFirstName;
	return;
}
void student::SetLastName(std::string studentLastName) {
	lastName = studentLastName;
	return;
}
void student::SetEmail(std::string studentEmail) {
	email = studentEmail;
	return;
}
void student::SetAge(int yearsOld) {
	age = yearsOld;
	return;
}
void student::SetCourseNumberDays(int courseDays[3]) {
	courseNumberDays[0] = courseDays[0];
	courseNumberDays[1] = courseDays[1];
	courseNumberDays[2] = courseDays[2];
	return;
}
void student::SetDegreeType(Degree programEnrolled) {
	degreeType = programEnrolled;
	return;
}

//FIXME: Make this into the format from the directions

void student::printStudentData() {
	
	return;
}