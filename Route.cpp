#include "Route.h"
#include "Vehicle.h"
#include "Driver.h"
#include "Utility.h"
#include <iostream>

using namespace std;

// Constructor
Route::Route()
{
    routeID = 0;
    startPoint = "";
    endPoint = "";
    distance = 0.0;

    assignedVehicle = nullptr;
    assignedVehicleID = -1;

    assignedDriver = nullptr;
    assignedDriverID = -1;
}

Route::Route(int id, string start, string end, float dist)
{
    routeID = id;
    startPoint = start;
    endPoint = end;
    distance = dist;

    assignedVehicle = nullptr;
    assignedVehicleID = -1;

    assignedDriver = nullptr;
    assignedDriverID = -1;
}

// Getters
int Route::getRouteID() { return routeID; }
string Route::getStartPoint() { return startPoint; }
string Route::getEndPoint() { return endPoint; }
float Route::getDistance() { return distance; }

Vehicle* Route::getAssignedVehicle() { return assignedVehicle; }
int Route::getAssignedVehicleID() { return assignedVehicleID; }

Driver* Route::getAssignedDriver() { return assignedDriver; }
int Route::getAssignedDriverID() { return assignedDriverID; }

// Setters / Assignments
void Route::setAssignedVehicleID(int id)
{
    assignedVehicleID = id;
}

void Route::assignVehicle(Vehicle* v)
{
    assignedVehicle = v;
}

void Route::assignDriver(Driver* d)
{
    assignedDriver = d;

    if (d != nullptr)
        assignedDriverID = d->getUserID();
}

// Display
void Route::displayRoute()
{
    setColor(10); cout << "\t\tRoute ID: ";
    setColor(15); cout << routeID << endl;

    setColor(10); cout << "\t\tStart: ";
    setColor(15); cout << startPoint << endl;

    setColor(10); cout << "\t\tEnd: ";
    setColor(15); cout << endPoint << endl;

    setColor(10); cout << "\t\tDistance: ";
    setColor(15); cout << distance << endl;

    if (assignedVehicle != nullptr)
    {
        setColor(8);
        cout << "\n\t\t--- Assigned Vehicle ---" << endl;
        setColor(15);
        assignedVehicle->displayVehicle();
    }
    else
    {
        setColor(12);
        cout << "\t\tNo Vehicle assigned yet." << endl;
        setColor(15);
    }

    if (assignedDriver != nullptr)
    {
        setColor(8);
        cout << "\n\t\t--- Assigned Driver ---" << endl;
        setColor(15);
        assignedDriver->display();
    }
}