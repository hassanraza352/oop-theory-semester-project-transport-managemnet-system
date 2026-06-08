#include "User.h"
#include "Utility.h"
User::User()
{
    userID = 0;
    name = "";
    email = "";
    password = "";
}

User::User(int id, string n, string e, string p)
{
    userID = id;
    name = n;
    email = e;
    password = p;
}

int User::getUserID()
{
    return userID;
}

string User::getName()
{
    return name;
}

string User::getEmail()
{
    return email;
}

string User::getPassword()
{
    return password;
}

void User::setName(string n)
{
    name = n;
}

void User::setEmail(string e)
{
    email = e;
}

void User::setPassword(string p)
{
    password = p;
}

User::~User()
{
}