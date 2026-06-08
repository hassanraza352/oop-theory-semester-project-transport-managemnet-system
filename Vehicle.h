#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
using namespace std;

class Vehicle
{
protected:
    int vehicleID;
    string vehicleNumber;
    int capacity;
    int occupiedSeats;

public:
    Vehicle();
    Vehicle(int id, string number, int cap);

    int getVehicleID();
    string getVehicleNumber();
    int getCapacity();
    int getOccupiedSeats();
    int getAvailableSeats();

    bool hasAvailableSeat();

    void reserveSeat();
    void releaseSeat();
    void setOccupiedSeats(int os);

    virtual void displayVehicle() = 0;

    virtual ~Vehicle();
};

#endif
