#include <iostream>
#include <string>
#include "roster.h"

using namespace std;

int main()
{
	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Jordan,Romney,jromne2@wgu.edu,28,12,16,21,SOFTWARE"
	};
	cout << "Course: C867 Scripting and Programming - Applications" << endl;
	cout << "Programming Language: C++" << endl;
	cout << "Student ID: 006310784" << endl;
	cout << "Name: Jordan Romney\n" << endl;

	Roster classRoster;

	for (int i = 0; i < 5; i++) {
		classRoster.parse(studentData[i]);
	};

	classRoster.printAll();

	classRoster.printInvalidEmails();
	
	string studentID = " ";
	for (int i = 0; i < 5; i++) {
		studentID = classRoster.classRosterArray[i]->GetStudentID();
		classRoster.printAverageDaysInCourse(studentID);
	}
	
	DegreeProgram software = DegreeProgram::SOFTWARE;
	classRoster.printByDegreeProgram(software);

	studentID = "A3";
	classRoster.remove(studentID);

	classRoster.printAll();

	classRoster.remove(studentID);

	return 0;
}
