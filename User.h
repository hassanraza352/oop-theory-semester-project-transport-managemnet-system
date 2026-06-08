#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
using namespace std;

class User
{
protected:
    int userID;
    string name;
    string email;
    string password;

public:
    User();
    User(int id, string n, string e, string p);

    int getUserID();
    string getName();
    string getEmail();
    string getPassword();

    void setName(string n);
    void setEmail(string e);
    void setPassword(string p);

    virtual void display() = 0;

    virtual ~User();
};

#endif