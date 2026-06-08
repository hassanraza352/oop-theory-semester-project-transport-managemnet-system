#pragma once
#include <string>
using namespace std;

class Student;
class Route;

#include "Bill.h"

class TransportPass
{
private:
    int passID;
    Student* student;
    Route* route;

    float monthlyFee;
    float fine;
    float totalAmount;

    Bill<float> bill;
    string status;

public:
    TransportPass();
    TransportPass(int id, Student* s, Route* r);

    string getStatus();
    Student* getStudent();
    Route* getRoute();

    void setStatus(string s);

    void calculateBill();
    void displayPass();
    void generateInvoice();

    void applyLateFee(int daysLate);

    float getTotalBill();
    float getFineAmount();

    void setFine(float f);
};
