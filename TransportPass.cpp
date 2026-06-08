#include "TransportPass.h"
#include "Student.h"
#include "Route.h"
#include <iostream>
#include "Utility.h"

using namespace std;


TransportPass::TransportPass()
{
    passID = 0;
    student = nullptr;
    route = nullptr;

    monthlyFee = 0;
    fine = 0;
    totalAmount = 0;

    status = "";
}

TransportPass::TransportPass(int id, Student* s, Route* r)
{
    passID = id;
    student = s;
    route = r;

    bill = Bill<float>(5000, 0);
    status = "PENDING";
}

// ================= Getters =================

string TransportPass::getStatus() { return status; }
Student* TransportPass::getStudent() { return student; }
Route* TransportPass::getRoute() { return route; }

// ================= Setters =================

void TransportPass::setStatus(string s)
{
    status = s;
}

// ================= Bill Logic =================

void TransportPass::calculateBill()
{
    totalAmount = monthlyFee + fine;
}

float TransportPass::getTotalBill()
{
    return bill.getTotalAmount();
}

float TransportPass::getFineAmount()
{
    return bill.getFine();
}

void TransportPass::applyLateFee(int daysLate)
{
    bill.applyLateFine(daysLate);
}

void TransportPass::setFine(float f)
{
    bill.setFine(f);
}

// ================= Display =================

void TransportPass::displayPass()
{
    setColor(8);
    cout << "\n\t\t===== TRANSPORT PASS =====" << endl;

    setColor(10); cout << "\t\tPass ID: ";
    setColor(15); cout << passID << endl;

    setColor(10); cout << "\t\tStatus: ";

    if (status == "APPROVED") setColor(10);
    else if (status == "REJECTED") setColor(12);
    else setColor(14);

    cout << status << endl;

    setColor(8);
    cout << "\n\t\t--- Student Info ---" << endl;
    student->display();

    setColor(8);
    cout << "\n\t\t--- Route Info ---" << endl;
    route->displayRoute();
}

// ================= Invoice =================

void TransportPass::generateInvoice()
{
    setColor(10);
    cout << "\n\t\tStudent: ";
    setColor(15);
    cout << student->getName() << endl;

    bill.generateInvoice();
}