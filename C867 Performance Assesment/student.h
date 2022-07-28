#pragma once
#include "degree.h"
using namespace std;

class Student {
	private:
		string studentID;
		string firstName;
		string lastName;
		string emailAddress;
		int age;
		int numDaysToComplete[3]; 
		DegreeProgram degreeProgram;
	public:
		Student();
		Student(string studentID, string firstName, string lastName, string emailAddress, int age, int numDaysToComplete[3], DegreeProgram degreeProgram);
		~Student();
		
		
		void SetStudentID(string ID);
		void SetFirstName(string f);
		void SetLastName(string l);
		void SetEmailAddress(string e);
		void SetAge(int a);
		void SetNumDaysToComplete(int numDays[]);
		void SetDegreeProgram(DegreeProgram d);
	
		
		string GetStudentID();
		string GetFirstName();
		string GetLastName();
		string GetEmailAddress();
		int GetAge();
		int *GetNumDaysToComplete();
		void GetNumDaysToCompletePrint();
		DegreeProgram GetDegreeProgram();
		string GetDegreeProgramPrint();
		void Print();
		
};
