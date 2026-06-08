#include "Student.h"
#include <iostream>
#include "Utility.h"
using namespace std;

Student::Student() : User()
{
    registrationID = 0;
}

Student::Student(int id, string n, string e, string p, int regID)
    : User(id, n, e, p)
{
    registrationID = regID;
}

int Student::getRegistrationID()
{
    return registrationID;
}

void Student::applyTransport()
{
    setColor(10);
    cout << "\t\tTransport application submitted." << endl;
    setColor(15);
}

void Student::display()
{
    setColor(10);
    cout << "\t\tStudent ID: ";
    setColor(15);
    cout << userID << endl;

    setColor(10);
    cout << "\t\tName: ";
    setColor(15);
    cout << name << endl;

    setColor(10);
    cout << "\t\tEmail: ";
    setColor(15);
    cout << email << endl;

    setColor(10);
    cout << "\t\tRegistration ID: ";
    setColor(15);
    cout << registrationID << endl;
}