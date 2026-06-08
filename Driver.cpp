#include "Driver.h"
#include <iostream>
#include "Utility.h"
using namespace std;

Driver::Driver() : User()
{
    licenseNo = "";
}

Driver::Driver(int id, string n, string e, string p, string l)
    : User(id, n, e, p)
{
    licenseNo = l;
}

string Driver::getLicenseNo()
{
    return licenseNo;
}

void Driver::display()
{
    setColor(10);
    cout << "\t\tDriver ID: ";
    setColor(15);
    cout << userID << endl;

    setColor(10);
    cout << "\t\tName: ";
    setColor(15);
    cout << name << endl;

    setColor(10);
    cout << "\t\tLicense No: ";
    setColor(15);
    cout << licenseNo << endl;
}