#pragma once
#include <string>
using namespace std;

class Vehicle;
class Driver;

class Route
{
private:
    int routeID;
    string startPoint;
    string endPoint;
    float distance;

    int assignedVehicleID;
    Vehicle* assignedVehicle;

    int assignedDriverID;
    Driver* assignedDriver;

public:
    Route();
    Route(int id, string start, string end, float dist);

    int getRouteID();
    string getStartPoint();
    string getEndPoint();
    float getDistance();

    Vehicle* getAssignedVehicle();
    int getAssignedVehicleID();
    void setAssignedVehicleID(int id);

    Driver* getAssignedDriver();
    int getAssignedDriverID();

    void assignVehicle(Vehicle* v);
    void assignDriver(Driver* d);

    void displayRoute();
};
