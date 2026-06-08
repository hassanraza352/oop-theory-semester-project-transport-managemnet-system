#pragma once
#include <iostream>
#include "Utility.h"
using namespace std;

template <typename T>
class Bill
{
private:
    T monthlyFee;
    T fine;
    T totalAmount;

public:
    Bill();
    Bill(T fee, T f);

    void calculateBill();
    void displayBill();
    void generateInvoice();

    Bill<T> operator+(T extraFine);

    void applyLateFine(int daysLate);

    T getTotalAmount();
    T getFine();

    void setFine(T f);
};

// ================= IMPLEMENTATION =================

template <typename T>
Bill<T>::Bill()
{
    monthlyFee = 0;
    fine = 0;
    totalAmount = 0;
}

template <typename T>
Bill<T>::Bill(T fee, T f)
{
    monthlyFee = fee;
    fine = f;
    totalAmount = 0;
}

template <typename T>
void Bill<T>::setFine(T f)
{
    fine = f;
}

template <typename T>
void Bill<T>::calculateBill()
{
    totalAmount = monthlyFee + fine;
}

template <typename T>
void Bill<T>::displayBill()
{
    calculateBill();

    setColor(8);
    cout << "\t\t=================== Bill Calculated =====================" << endl;

    setColor(10); cout << "\t\tMonthly Fee: ";
    setColor(15); cout << monthlyFee << endl;

    setColor(10); cout << "\t\tFine: ";
    setColor(15); cout << fine << endl;

    setColor(14); cout << "\t\tTotal Amount: ";
    setColor(15); cout << totalAmount << endl;

    setColor(15);
}

template <typename T>
void Bill<T>::applyLateFine(int daysLate)
{
    if (daysLate > 0)
        fine = daysLate * 50;
}

template <typename T>
T Bill<T>::getFine()
{
    return fine;
}

template <typename T>
T Bill<T>::getTotalAmount()
{
    calculateBill();
    return totalAmount;
}

template <typename T>
void Bill<T>::generateInvoice()
{
    calculateBill();

    setColor(8);
    cout << "\n\t\t========== TRANSPORT INVOICE ==========" << endl;

    setColor(10); cout << "\t\tMonthly Fee: ";
    setColor(15); cout << monthlyFee << endl;

    setColor(10); cout << "\t\tLate Fine: ";
    setColor(15); cout << fine << endl;

    setColor(14); cout << "\t\tTotal Amount: ";
    setColor(15); cout << totalAmount << endl;

    setColor(8);
    cout << "\t\t=======================================" << endl;

    setColor(15);
}

template <typename T>
Bill<T> Bill<T>::operator+(T extraFine)
{
    Bill<T> temp;

    temp.monthlyFee = monthlyFee;
    temp.fine = fine + extraFine;
    temp.totalAmount = temp.monthlyFee + temp.fine;

    return temp;
}
