#include <iostream>
#include "Student.h"

Student::Student(std::string studentID,
    std::string firstName,
    std::string lastName,
    std::string emailAddress,
    int age,
    int daysInCourse[],
    DegreeProgram degreeProgram)
    : studentID{ studentID },
    firstName{ firstName },
    lastName{ lastName },
    emailAddress{ emailAddress },
    age{ age },
    daysInCourse{ {*daysInCourse}, {*(daysInCourse + 1)}, {*(daysInCourse + 2)} },
    degreeProgram{ degreeProgram }
{
}

//=====GET METHODS=====

std::string Student::getStudentID()
{
    return this->studentID;
}

std::string Student::getFirstName()
{
    return this->firstName;
}

std::string Student::getLastName()
{
    return this->lastName;
}

std::string Student::getEmailAddress()
{
    return this->emailAddress;
}

int Student::getAge()
{
    return this->age;
}

int* Student::getDaysInCourse()
{
    return this->daysInCourse;
}

DegreeProgram Student::getDegreeProgram()
{
    return this->degreeProgram;
}

//=====SET METHODS=====

void Student::setStudentID(std::string studentID)
{
    this->studentID = studentID;
}

void Student::setFirstName(std::string firstName)
{
    this->firstName = firstName;
}

void Student::setLastName(std::string lastName)
{
    this->lastName = lastName;
}

void Student::setEmailAddress(std::string emailAddress)
{
    this->emailAddress = emailAddress;
}

void Student::setAge(int age)
{
    this->age = age;
}

void Student::setDaysInCourse(int daysInCourse[])
{
    for (size_t i{ 0 }; i < 3; i++)
    {
        *(this->daysInCourse + i) = *(daysInCourse + i);
    }
}

void Student::setDegreeProgram(DegreeProgram degreeProgram)
{
    this->degreeProgram = degreeProgram;
}

void Student::print()
{
    std::string program;
    switch (degreeProgram)
    {
    case SECURITY:
        program = "Security";
        break;
    case NETWORK:
        program = "Network";
        break;
    default:
        program = "Software";
        break;
    }
    std::cout << this->studentID << "      "
        << "First Name: " << this->firstName << "     "
        << "Last Name: " << this->lastName << "      "
        << "Age: " << this->age << "     "
        << "daysInCourse: {" << *(this->daysInCourse) << ", "
        << *(this->daysInCourse + 1) << ", "
        << *(this->daysInCourse + 2) << "} "
        << "Degree Program: " << program << std::endl;
}