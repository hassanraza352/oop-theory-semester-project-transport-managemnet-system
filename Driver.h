#ifndef DRIVER_H
#define DRIVER_H

#include "User.h"

class Driver : public User
{
private:
    string licenseNo;

public:
    Driver();
    Driver(int id, string n, string e, string p, string l);

    string getLicenseNo();

    void display() override;
};

#endif
