#pragma once
#include "student.h"

class Roster {
	private:
		int numStudents = 0;
		Student student;
	public:
		~Roster();
		Student* classRosterArray[5];
		void parse(string row);
		void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
		void remove(string studentID);
		void printAll();
		void printAverageDaysInCourse(string studentID);
		void printInvalidEmails();
		void printByDegreeProgram(DegreeProgram d);
		
		
};