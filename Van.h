#ifndef VAN_H
#define VAN_H

#include "Vehicle.h"

class Van : public Vehicle
{
public:
    Van();
    Van(int id, string number, int cap);

    void displayVehicle() override;
};

#endif
