#include <iostream>
#include <string>
#include "student.h"

using namespace std;

Student::Student() {
	this-> studentID = "";
	this-> firstName = "";
	this-> lastName = "";
	this-> emailAddress = "";
	this-> age = 0;
	for (int i = 0; i < 3; i++) {
		this -> numDaysToComplete[i] = 0;
	};
	this-> degreeProgram = DegreeProgram::SOFTWARE; 
}
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int numDaysToComplete[3], DegreeProgram degreeProgram) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < 3; i++) {
		this->numDaysToComplete[i] = numDaysToComplete[i];
	};
	this->degreeProgram = degreeProgram;
}
Student::~Student() {};

void Student::SetStudentID(string ID) {
	studentID = ID;
}
void Student::SetFirstName(string f) {
	firstName = f;
}
void Student::SetLastName(string l) {
	lastName = l;
}
void Student::SetEmailAddress(string e) {
	emailAddress = e;
}
void Student::SetAge(int a) {
	age = a;
}
void Student::SetNumDaysToComplete(int numDays[]) {
	for (int i = 0; i < 3; i++) {
		numDaysToComplete[i] = numDays[i];
	}
}
void Student::SetDegreeProgram(DegreeProgram d) {
	degreeProgram = d;
}

string Student::GetStudentID() {
	return studentID;
}
string Student::GetFirstName() {
	return firstName;
}
string Student::GetLastName() {
	return lastName;
}
string Student::GetEmailAddress() {
	return emailAddress;
}
int Student::GetAge() {
	return age;
}
int *Student::GetNumDaysToComplete() {
	return numDaysToComplete;
}
void Student::GetNumDaysToCompletePrint() {
	cout << "{";
	for (int i = 0; i < 3; i++) {
		if (i == 0) {
			cout << GetNumDaysToComplete()[i];
		}
		else {
			cout << "," << GetNumDaysToComplete()[i];
		}
	}
	cout << "}";
}
DegreeProgram Student::GetDegreeProgram() {
	return degreeProgram;
}
string Student::GetDegreeProgramPrint() {
	string degreeString;
	if (GetDegreeProgram() == DegreeProgram::NETWORK) {
		degreeString = "NETWORK";
	}
	else if (GetDegreeProgram() == DegreeProgram::SECURITY) {
		degreeString = "SECURITY";
	}
	else if (GetDegreeProgram() == DegreeProgram::SOFTWARE) {
		degreeString = "SOFTWARE";
	};
	return degreeString;
}

void Student::Print() {
	
	cout << GetStudentID() << "\t" << GetFirstName() << "\t" << GetLastName() << "\t" << GetEmailAddress() << "\t" << GetAge() << "\t"; GetNumDaysToCompletePrint(); cout << "\t" << GetDegreeProgramPrint() << endl;
}
