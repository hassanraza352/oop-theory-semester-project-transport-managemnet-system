#pragma once
#include <iostream>
#include <string>
using namespace std;

void setColor(int color);
void clearScreen();
void printHeading();
void printSubHeading(string title);

int getValidInt(string prompt);
float getValidFloat(string prompt);
