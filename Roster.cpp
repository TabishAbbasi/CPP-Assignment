#include <iostream>
#include "Roster.h"

Roster::Roster() : classRosterArray{ {nullptr} }
{
}

void Roster::add(std::string studentID,
    std::string firstName,
    std::string lastName,
    std::string emailAddress,
    int age,
    int daysInCourse1,
    int daysInCourse2,
    int daysInCourse3,
    DegreeProgram degreeProgram)
{
    int daysInCourse[3]{ daysInCourse1, daysInCourse2, daysInCourse3 };
    Student* newStudent = new Student(studentID,
        firstName,
        lastName,
        emailAddress,
        age,
        daysInCourse,
        degreeProgram);
    bool studentNotAdded = true;
    for (size_t i{ 0 }; i < 5 && studentNotAdded; ++i)
    {
        if (*(this->classRosterArray + i) == nullptr)
        {
            *(this->classRosterArray + i) = newStudent;
            studentNotAdded = false;
        }
    }
}

void Roster::remove(std::string studentID)
{
    bool studentInRoster = true;
    for (size_t i{ 0 }; i < 5 && studentInRoster; ++i)
    {
        if (*(this->classRosterArray + i) != nullptr &&
            (*(this->classRosterArray + i))->getStudentID() == studentID)
        {
            delete* (this->classRosterArray + i);
            *(this->classRosterArray + i) = nullptr;
            studentInRoster = false;
        }
    }

    if (studentInRoster)
    {
        std::cout << "Error: Student not found\n" << std::endl;
    }
}
void Roster::printAll()
{
    for (size_t i{ 0 }; i < 5; ++i)
    {
        if (*(this->classRosterArray + i) != nullptr)
        {
            (*(this->classRosterArray + i))->print();
        }
    }
    std::cout << std::endl;
}

void Roster::printAverageDaysInCourse(std::string studentID)
{
    bool searching = true;
    for (size_t i{ 0 }; i < 5 && searching; ++i)
    {
        if (*(this->classRosterArray + i) != nullptr &&
            (*(this->classRosterArray + i))->getStudentID() == studentID)
        {
            double value{ 0 };
            for (size_t j{ 0 }; j < 3; ++j)
            {
                value += *((*(this->classRosterArray + i))->getDaysInCourse() + j);
            }
            value = value / 3;
            std::cout << "Average days in course: " << value << std::endl;
            searching = false;
        }
    }
    std::cout << std::endl;
}

void Roster::printInvalidEmails()
{
    std::string currentEmail{ "" };
    for (size_t i{ 0 }; i < 5; ++i)
    {
        if (*(this->classRosterArray + i) != nullptr)
        {
            currentEmail = (*(this->classRosterArray + i))->getEmailAddress();
            //Process email to see if it's valid
            if (currentEmail.find("@") == std::string::npos)
            {
                std::cout << "Invalid Email Address: " << currentEmail << std::endl;
            }
            else if (currentEmail.find(".") == std::string::npos)
            {
                std::cout << "Invalid Email Address: " << currentEmail << std::endl;
            }
            else if (currentEmail.find(" ") != std::string::npos)
            {
                std::cout << "Invalid Email Address: " << currentEmail << std::endl;
            }
        }
    }
    std::cout << std::endl;
}

void Roster::printByDegreeProgram(DegreeProgram degreePogram)
{
    for (size_t i{ 0 }; i < 5; ++i)
    {
        if (*(this->classRosterArray + i) != nullptr &&
            (*(this->classRosterArray + i))->getDegreeProgram() == degreePogram)
        {
            (*(this->classRosterArray + i))->print();
        }
    }
    std::cout << std::endl;
}

Student** Roster::getClassRosterArray()
{
    return this->classRosterArray;
}