#include <iostream>
#include "Roster.h"

void populateRoster(Roster* classRoster, const std::string studentData[]);

int main()
{
    std::cout << "C867: Scripting and Programming - Applications"
        << "\nProgramming Language: C++"
        << "\nStudenID: #010100279"
        << "\nStudent Name: Tabish Abbasi\n"
        << std::endl;

    const std::string studentData[] = { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
                                       "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
                                       "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
                                       "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
                                       "A5,Tabish,Abbasi,tabishabbasi3@gmail.com,27,20,30,40,SOFTWARE" };

    Roster* classRoster = new Roster();
    populateRoster(classRoster, studentData);

    classRoster->printAll();
    classRoster->printInvalidEmails();
    for (size_t i{ 0 }; i < 5; ++i)
    {
        classRoster->printAverageDaysInCourse((*(classRoster->getClassRosterArray() + i))->getStudentID());
    }

    classRoster->printByDegreeProgram(SOFTWARE);
    classRoster->remove("A3");
    classRoster->printAll();
    classRoster->remove("A3");
    delete classRoster;

    return 0;
}
/**
* Modified version of Amy Antonucci's String Parse function from course tip #9, WGU, C867.
*/
void populateRoster(Roster* classRoster, const std::string studentData[])
{
    for (size_t i{ 0 }; i < 5; ++i)
    {
        std::string data = *(studentData + i);
        size_t rhs = data.find(",");
        std::string studentID = data.substr(0, rhs);

        size_t lhs = rhs + 1;
        rhs = data.find(",", lhs);
        std::string firstName = data.substr(lhs, rhs - lhs);

        lhs = rhs + 1;
        rhs = data.find(",", lhs);
        std::string lastName = data.substr(lhs, rhs - lhs);

        lhs = rhs + 1;
        rhs = data.find(",", lhs);
        std::string emailAddress = data.substr(lhs, rhs - lhs);

        lhs = rhs + 1;
        rhs = data.find(",", lhs);
        int age = stoi(data.substr(lhs, rhs - lhs));

        lhs = rhs + 1;
        rhs = data.find(",", lhs);
        int daysInCourse1 = stoi(data.substr(lhs, rhs - lhs));

        lhs = rhs + 1;
        rhs = data.find(",", lhs);
        int daysInCourse2 = stoi(data.substr(lhs, rhs - lhs));

        lhs = rhs + 1;
        rhs = data.find(",", lhs);
        int daysInCourse3 = stoi(data.substr(lhs, rhs - lhs));

        lhs = rhs + 1;
        rhs = data.find(",", lhs);
        std::string strDegreeProgram = data.substr(lhs, rhs - lhs);

        DegreeProgram degreeProgram = SECURITY;
        if (strDegreeProgram == "NETWORK")
        {
            degreeProgram = NETWORK;
        }
        else if (strDegreeProgram == "SOFTWARE")
        {
            degreeProgram = SOFTWARE;
        }

        classRoster->add(studentID,
            firstName,
            lastName,
            emailAddress,
            age,
            daysInCourse1,
            daysInCourse2,
            daysInCourse3,
            degreeProgram);
    }
}