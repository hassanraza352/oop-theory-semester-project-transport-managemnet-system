#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"

class Admin : public User
{
public:
    Admin();
    Admin(int id, string n, string e, string p);

    void addVehicle();
    void removeVehicle();

    void display() override;
};

#endif
