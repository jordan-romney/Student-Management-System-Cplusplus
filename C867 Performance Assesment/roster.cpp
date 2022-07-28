#include <iostream>
#include <string>
#include "roster.h"

using namespace std;

void Roster::parse(string row) {
		size_t rhs = row.find(",");
		string studentID = row.substr(0, rhs);

		size_t lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string firstName = row.substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string lastName = row.substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string emailAddress = row.substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int age = stoi(row.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int daysInCourse1 = stoi(row.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int daysInCourse2 = stoi(row.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int daysInCourse3 = stoi(row.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string strDegreeProgram = row.substr(lhs, rhs - lhs);

		DegreeProgram degreeProgram = DegreeProgram::SOFTWARE;
		if (strDegreeProgram == "SECURITY") {
			degreeProgram = DegreeProgram::SECURITY;
		}
		else if (strDegreeProgram == "NETWORK") {
			degreeProgram = DegreeProgram::NETWORK;
		}
		else if (strDegreeProgram == "SOFTWARE") {
			degreeProgram = DegreeProgram::SOFTWARE;
		}
		add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	int numDaysToComplete[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	classRosterArray[numStudents++] = new Student(studentID, firstName, lastName, emailAddress, age, numDaysToComplete, degreeProgram);
}
void Roster::remove(string studentID) {
	cout << "Removing Student with ID: " << studentID << "\n" << endl;
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] == nullptr) {
			cout << "A Student with ID " << studentID << " was not found" << endl;
		}
		else if (studentID == classRosterArray[i]->GetStudentID()) {
			classRosterArray[i] = nullptr;
		}
	}
}
void Roster::printAll() {
	cout << "Displaying all enrolled students: \n" <<endl;
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != nullptr) {
			classRosterArray[i]->Print();
		}
	} 
	cout << "\n";
}
void Roster::printAverageDaysInCourse(string studentID) {
	double avg;
	for (int i = 0; i < 5; i++) {
		if (studentID == classRosterArray[i]->GetStudentID()) {
			avg = (classRosterArray[i]->GetNumDaysToComplete()[0] + classRosterArray[i]->GetNumDaysToComplete()[1] + classRosterArray[i]->GetNumDaysToComplete()[2]) / 3;
			cout << "Student ID: " << studentID << ", average days in course is : " << avg << endl;
		}
	}
}
void Roster::printInvalidEmails() {
	
	cout << "Displaying invalid emails:\n" <<endl;
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i]->GetEmailAddress().find(" ") != string::npos){
			cout << classRosterArray[i]->GetEmailAddress() << " - is invalid." << endl;
		}
		else if (classRosterArray[i]->GetEmailAddress().find("@") == string::npos) {
			cout << classRosterArray[i]->GetEmailAddress() << " - is invalid." << endl;
		}
		else if (classRosterArray[i]->GetEmailAddress().find(".") == string::npos) {
			cout << classRosterArray[i]->GetEmailAddress() << " - is invalid." << endl;
		}
	}
	cout << "\n";
}
void Roster::printByDegreeProgram(DegreeProgram d) {
	cout << "\nShowing students in degree program: " << student.GetDegreeProgramPrint() <<"\n" << endl;
	for (int i = 0; i < 5; i++) {
		if (d == classRosterArray[i]->GetDegreeProgram()) {
			classRosterArray[i]->Print();
		}
	}
	cout << "\n";
}

Roster::~Roster(){
	for (int i = 0; i < 4; i++)
	{
		delete classRosterArray[i];
	}
}

	

