#include "Van.h"
#include "Utility.h"
#include <iostream>

using namespace std;

Van::Van() : Vehicle()
{
}

Van::Van(int id, string number, int cap)
    : Vehicle(id, number, cap)
{
}

void Van::displayVehicle()
{
    setColor(10);
    cout << "\t\tVan ID: ";
    setColor(15);
    cout << vehicleID << endl;

    setColor(10);
    cout << "\t\tVehicle Number: ";
    setColor(15);
    cout << vehicleNumber << endl;

    setColor(10);
    cout << "\t\tCapacity: ";
    setColor(15);
    cout << capacity << endl;
}