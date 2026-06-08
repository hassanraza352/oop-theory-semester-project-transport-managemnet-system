#ifndef STUDENT_H
#define STUDENT_H

#include "User.h"

class Student : public User
{
private:
    int registrationID;

public:
    Student();
    Student(int id, string n, string e, string p, int regID);

    int getRegistrationID();

    void applyTransport();

    void display() override;
};

#endif