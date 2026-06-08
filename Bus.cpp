#include "Bus.h"
#include "Utility.h"
#include <iostream>

using namespace std;

Bus::Bus() : Vehicle()
{
}

Bus::Bus(int id, string number, int cap)
    : Vehicle(id, number, cap)
{
}

void Bus::displayVehicle()
{
    setColor(10);
    cout << "\t\tBus ID: ";
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