#include "Admin.h"
#include <iostream>
#include "Utility.h"
using namespace std;

Admin::Admin() : User()
{
}

Admin::Admin(int id, string n, string e, string p)
    : User(id, n, e, p)
{
}

void Admin::addVehicle()
{
    setColor(10);
    cout << "\t\tVehicle Added Successfully!" << endl;
    setColor(15);
}

void Admin::removeVehicle()
{
    setColor(10);
    cout << "\t\tVehicle Removed Successfully!" << endl;
    setColor(15);
}

void Admin::display()
{
    setColor(10);
    cout << "\t\tAdmin ID: ";
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
    cout << "\t\tPassword: ";
    setColor(15);
    cout << password << endl;
}