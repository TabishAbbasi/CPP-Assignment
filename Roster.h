#ifndef _ROSTER_H_
#define _ROSTER_H_
#include "Student.h"

class Roster
{
private:
    Student* classRosterArray[5];

public:
    Roster();
    void add(std::string studentID,
        std::string firstName,
        std::string lastName,
        std::string emailAddress,
        int age,
        int daysInCourse1,
        int daysInCourse2,
        int daysInCourse3,
        DegreeProgram degreeProgram);
    void remove(std::string studentID);
    void printAll();
    void printAverageDaysInCourse(std::string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
    Student** getClassRosterArray();
};

#endif