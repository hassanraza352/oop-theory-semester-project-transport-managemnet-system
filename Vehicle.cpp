#include "Vehicle.h"

Vehicle::Vehicle()
{
    vehicleID = 0;
    vehicleNumber = "";
    capacity = 0;
    occupiedSeats = 0;
}

Vehicle::Vehicle(int id, string number, int cap)
{
    vehicleID = id;
    vehicleNumber = number;
    capacity = cap;
    occupiedSeats = 0;
}

int Vehicle::getVehicleID()
{
    return vehicleID;
}

string Vehicle::getVehicleNumber()
{
    return vehicleNumber;
}

int Vehicle::getCapacity()
{
    return capacity;
}

int Vehicle::getOccupiedSeats()
{
    return occupiedSeats;
}

int Vehicle::getAvailableSeats()
{
    return capacity - occupiedSeats;
}

void Vehicle::setOccupiedSeats(int os)
{
    occupiedSeats = os;
}

bool Vehicle::hasAvailableSeat()
{
    return occupiedSeats < capacity;
}

void Vehicle::reserveSeat()
{
    occupiedSeats++;
}

void Vehicle::releaseSeat()
{
    if (occupiedSeats > 0)
    {
        occupiedSeats--;
    }
}

Vehicle::~Vehicle()
{
}