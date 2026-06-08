#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <cstdlib>
#include <iomanip> 
using namespace std;
void setColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void clearScreen()
{
    system("cls");
}

void printHeading()
{
    cout << "\n\n";
    // Silver/Platinum Gradient for Professional Look
    setColor(15);
    cout << "\t     _______ _____            _   _  _____ _____   ____  _____ _______ \n";
    cout << "\t    |__   __|  __ \\     /\\   | \\\\ | |/ ____|  __ \\ / __ \\|  __ \\__   __|\n";
    setColor(7);
    cout << "\t       | |  | |__) |   /  \\  |  \\| | (___ | |__) | |  | | |__) | | |   \n";
    cout << "\t       | |  |  _  /   / /\\ \\ | . ` |\\___ \\|  ___/| |  | |  _  /  | |   \n";
    setColor(8);
    cout << "\t       | |  | | \\ \\  / ____ \\| |\\  |____) | |    | |__| | | \\ \\  | |   \n";
    cout << "\t       |_|  |_|  \\_\\/_/    \\_\\_| \\_|_____/|_|     \\____/|_|  \\_\\ |_|   \n\n";

    setColor(8);
    cout << "\t\t\t+---------------------------------------+\n";
    cout << "\t\t\t|    ";
    setColor(14); cout << "MANAGEMENT SYSTEM OF UNIVERSITY"; setColor(8);
    cout << "    |\n";
    cout << "\t\t\t+---------------------------------------+\n\n";
    setColor(15);
}

void printSubHeading(string title)
{
    setColor(8);
    cout << "\n\t\t\t~=~=~=~ ";
    setColor(11); // Cyan for Subheading text
    cout << title;
    setColor(8);
    cout << " ~=~=~=~\n\n";
    setColor(15);
}

int getValidInt(string prompt)
{
    string input;
    while (true)
    {
        setColor(14); // Yellow for Prompt
        cout << prompt;
        setColor(15); // White for user input
        cin >> input;

        if (input == "r" || input == "R")
        {
            cin.ignore(10000, '\n');
            return -1;
        }

        bool valid = true;
        for (int i = 0; i < input.length(); i++)
        {
            if (input[i] < '0' || input[i] > '9')
            {
                valid = false;
                break;
            }
        }

        if (valid && input.length() > 0)
        {
            cin.ignore(10000, '\n');
            return stoi(input);
        }
        else
        {
            setColor(12);
            cout << "\t\tInvalid Input! Please enter valid numbers only. (or press 'R' to go back)\n";
        }
    }
}

float getValidFloat(string prompt)
{
    string input;
    while (true)
    {
        setColor(14); // Yellow for Prompt
        cout << prompt;
        setColor(15); // White for user input
        cin >> input;

        if (input == "r" || input == "R")
        {
            cin.ignore(10000, '\n');
            return -1.0;
        }

        bool valid = true;
        int dotCount = 0;
        for (int i = 0; i < input.length(); i++)
        {
            if (input[i] == '.')
            {
                dotCount++;
                if (dotCount > 1) valid = false;
            }
            else if (input[i] < '0' || input[i] > '9')
            {
                valid = false;
                break;
            }
        }

        if (valid && input.length() > 0)
        {
            cin.ignore(10000, '\n');
            return stof(input);
        }
        else
        {
            setColor(12);
            cout << "\t\tInvalid Input! Please enter valid numeric values. (or press 'R' to go back)\n";
        }
    }
}

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

int User::getUserID() { return userID; }
string User::getName() { return name; }
string User::getEmail() { return email; }
string User::getPassword() { return password; }
void User::setName(string n) { name = n; }
void User::setEmail(string e) { email = e; }
void User::setPassword(string p) { password = p; }
User::~User() {}

class Student : public User
{
private:
    int registrationID;
public:
    Student();
    Student(int id, string n, string e, string p, int regID);
    int getRegistrationID();
    void applyTransport();
    void display();
};

Student::Student() : User() { registrationID = 0; }

Student::Student(int id, string n, string e, string p, int regID) : User(id, n, e, p)
{
    registrationID = regID;
}

int Student::getRegistrationID() { return registrationID; }

void Student::applyTransport()
{
    setColor(10);
    cout << "\t\tTransport application submitted." << endl;
    setColor(15);
}

void Student::display()
{
    setColor(10); cout << "\t\tStudent ID: "; setColor(15); cout << userID << endl;
    setColor(10); cout << "\t\tName: "; setColor(15); cout << name << endl;
    setColor(10); cout << "\t\tEmail: "; setColor(15); cout << email << endl;
    setColor(10); cout << "\t\tRegistration ID: "; setColor(15); cout << registrationID << endl;
}

class Admin : public User
{
public:
    Admin();
    Admin(int id, string n, string e, string p);
    void addVehicle();
    void removeVehicle();
    void display();
};

Admin::Admin() : User() {}
Admin::Admin(int id, string n, string e, string p) : User(id, n, e, p) {}

void Admin::addVehicle()
{
    setColor(10);
    cout << "\t\tVehicle Added Successfully!" << endl;
    setColor(15);
}

void Admin::removeVehicle()
{
    setColor(10);
    cout << "\t\tVehicle Removed Successfully!" << endl;
    setColor(15);
}

void Admin::display()
{
    setColor(10); cout << "\t\tAdmin ID: "; setColor(15); cout << userID << endl;
    setColor(10); cout << "\t\tName: "; setColor(15); cout << name << endl;
    setColor(10); cout << "\t\tEmail: "; setColor(15); cout << email << endl;
    setColor(10); cout << "\t\tPassword: "; setColor(15); cout << password << endl;
}

class Driver : public User
{
private:
    string licenseNo;
public:
    Driver();
    Driver(int id, string n, string e, string p, string l);
    string getLicenseNo();
    void display();
};

Driver::Driver() : User() { licenseNo = ""; }
Driver::Driver(int id, string n, string e, string p, string l) : User(id, n, e, p) { licenseNo = l; }

string Driver::getLicenseNo() { return licenseNo; }

void Driver::display()
{
    setColor(10); cout << "\t\tDriver ID: "; setColor(15); cout << userID << endl;
    setColor(10); cout << "\t\tName: "; setColor(15); cout << name << endl;
    setColor(10); cout << "\t\tLicense No: "; setColor(15); cout << licenseNo << endl;
}

class Vehicle
{
protected:
    int vehicleID;
    string vehicleNumber;
    int capacity;
    int occupiedSeats;
public:
    Vehicle();
    Vehicle(int id, string number, int cap);
    int getVehicleID();
    string getVehicleNumber();
    int getCapacity();
    bool hasAvailableSeat();
    void reserveSeat();
    virtual void displayVehicle() = 0;
    int getOccupiedSeats();
    int getAvailableSeats();
    virtual ~Vehicle();
    void setOccupiedSeats(int os);
    void releaseSeat();
};

Vehicle::Vehicle()
{
    vehicleID = 0;
    vehicleNumber = "";
    capacity = 0;
    occupiedSeats = 0;
}

int Vehicle::getVehicleID() { return vehicleID; }
void Vehicle::setOccupiedSeats(int os) { occupiedSeats = os; }
string Vehicle::getVehicleNumber() { return vehicleNumber; }
int Vehicle::getCapacity() { return capacity; }
int Vehicle::getAvailableSeats() { return capacity - occupiedSeats; }

Vehicle::Vehicle(int id, string number, int cap)
{
    vehicleID = id;
    vehicleNumber = number;
    capacity = cap;
    occupiedSeats = 0;
}

int Vehicle::getOccupiedSeats() { return occupiedSeats; }
Vehicle::~Vehicle() {}

bool Vehicle::hasAvailableSeat()
{
    return (occupiedSeats < capacity);
}

void Vehicle::reserveSeat() { occupiedSeats++; }

void Vehicle::releaseSeat()
{
    if (occupiedSeats > 0) occupiedSeats--;
}

class Bus : public Vehicle
{
public:
    Bus();
    Bus(int id, string number, int cap);
    void displayVehicle();
};

Bus::Bus() : Vehicle() {}
Bus::Bus(int id, string number, int cap) : Vehicle(id, number, cap) {}

void Bus::displayVehicle()
{
    setColor(10); cout << "\t\tBus ID: "; setColor(15); cout << vehicleID << endl;
    setColor(10); cout << "\t\tVehicle Number: "; setColor(15); cout << vehicleNumber << endl;
    setColor(10); cout << "\t\tCapacity: "; setColor(15); cout << capacity << endl;
}

class Van : public Vehicle
{
public:
    Van();
    Van(int id, string number, int cap);
    void displayVehicle();
};

Van::Van() : Vehicle() {}
Van::Van(int id, string number, int cap) : Vehicle(id, number, cap) {}

void Van::displayVehicle()
{
    setColor(10); cout << "\t\tVan ID: "; setColor(15); cout << vehicleID << endl;
    setColor(10); cout << "\t\tVehicle Number: "; setColor(15); cout << vehicleNumber << endl;
    setColor(10); cout << "\t\tCapacity: "; setColor(15); cout << capacity << endl;
}

class Route
{
private:
    int routeID;
    string startPoint;
    string endPoint;
    float distance;
    int assignedVehicleID;
    Vehicle* assignedVehicle;
    Driver* assignedDriver;
    int assignedDriverID;
public:
    Vehicle* getAssignedVehicle();
    int getRouteID();
    string getStartPoint();
    string getEndPoint();
    float getDistance();
    Route();
    Route(int id, string start, string end, float dist);
    void assignVehicle(Vehicle* v);
    void displayRoute();
    int getAssignedVehicleID();
    void setAssignedVehicleID(int id);
    void assignDriver(Driver* d);
    Driver* getAssignedDriver();
    int getAssignedDriverID();

};

Route::Route()
{
    routeID = 0;
    startPoint = "";
    endPoint = "";
    distance = 0.0;
    assignedVehicle = nullptr;
    assignedVehicleID = -1;
    assignedDriver = nullptr;
    assignedDriverID = -1;
}

Route::Route(int id, string start, string end, float dist)
{
    routeID = id;
    startPoint = start;
    endPoint = end;
    distance = dist;
    assignedVehicle = nullptr;
    assignedVehicleID = -1;
}

int Route::getRouteID() { return routeID; }
string Route::getStartPoint() { return startPoint; }
string Route::getEndPoint() { return endPoint; }
float Route::getDistance() { return distance; }
void Route::assignVehicle(Vehicle* v) { assignedVehicle = v; }
void Route::setAssignedVehicleID(int id) { assignedVehicleID = id; }

void Route::displayRoute()
{
    setColor(10); cout << "\t\tRoute ID: "; setColor(15); cout << routeID << endl;
    setColor(10); cout << "\t\tStart: "; setColor(15); cout << startPoint << endl;
    setColor(10); cout << "\t\tEnd: "; setColor(15); cout << endPoint << endl;
    setColor(10); cout << "\t\tDistance: "; setColor(15); cout << distance << endl;

    if (assignedVehicle != nullptr)
    {
        setColor(8);
        cout << "\n\t\t--- Assigned Vehicle ---" << endl;
        setColor(15);
        assignedVehicle->displayVehicle();
    }
    else
    {
        setColor(12);
        cout << "\t\tNo Vehicle assigned yet." << endl;
        setColor(15);
    }
    if (assignedDriver != nullptr)
    {
        setColor(8);
        cout << "\n\t\t--- Assigned Driver ---" << endl;
        setColor(15);
        assignedDriver->display();
    }
}

Vehicle* Route::getAssignedVehicle() { return assignedVehicle; }
int Route::getAssignedVehicleID() { return assignedVehicleID; }
Driver* Route::getAssignedDriver() { return assignedDriver; }
int Route::getAssignedDriverID()
{
    return assignedDriverID;
}
void Route::assignDriver(Driver* d)
{
    assignedDriver = d;
    if (d != nullptr)
        assignedDriverID = d->getUserID();
}

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

template <typename T>
Bill<T>::Bill() { monthlyFee = 0; fine = 0; totalAmount = 0; }

template <typename T>
void Bill<T>::setFine(T f) { fine = f; }

template <typename T>
Bill<T>::Bill(T fee, T f) { monthlyFee = fee; fine = f; totalAmount = 0; }

template <typename T>
void Bill<T>::calculateBill() { totalAmount = monthlyFee + fine; }

template <typename T>
void Bill<T>::displayBill()
{
    calculateBill();
    setColor(8);
    cout << "\t\t=================== Bill Calculated =====================" << endl;
    setColor(10); cout << "\t\tMonthly Fee: "; setColor(15); cout << monthlyFee << endl;
    setColor(10); cout << "\t\tFine: "; setColor(15); cout << fine << endl;
    setColor(14); cout << "\t\tTotal Amount: "; setColor(15); cout << totalAmount << endl;
    setColor(15);
}

template <typename T>
void Bill<T>::applyLateFine(int daysLate)
{
    if (daysLate > 0) fine = daysLate * 50;
}

template <typename T>
T Bill<T>::getFine() { return fine; }

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
    setColor(10); cout << "\t\tMonthly Fee: "; setColor(15); cout << monthlyFee << endl;
    setColor(10); cout << "\t\tLate Fine: "; setColor(15); cout << fine << endl;
    setColor(14); cout << "\t\tTotal Amount: "; setColor(15); cout << totalAmount << endl;
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
    string getStatus();
    Student* getStudent();
    Route* getRoute();
    TransportPass();
    TransportPass(int id, Student* s, Route* r);
    void setStatus(string s);
    void calculateBill();
    void displayPass();
    void generateInvoice();
    void applyLateFee(int daysLate);
    float getTotalBill();
    float getFineAmount();
    void setFine(float f);
};

TransportPass::TransportPass()
{
    passID = 0; student = nullptr; route = nullptr;
    monthlyFee = 0; fine = 0; totalAmount = 0; status = "";
}

TransportPass::TransportPass(int id, Student* s, Route* r)
{
    passID = id; student = s; route = r;
    bill = Bill<float>(5000, 0); status = "PENDING";
}

void TransportPass::calculateBill() { totalAmount = monthlyFee + fine; }

void TransportPass::displayPass()
{
    setColor(8);
    cout << "\n\t\t===== TRANSPORT PASS =====" << endl;
    setColor(10); cout << "\t\tPass ID: "; setColor(15); cout << passID << endl;
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

float TransportPass::getTotalBill() { return bill.getTotalAmount(); }
float TransportPass::getFineAmount() { return bill.getFine(); }
Student* TransportPass::getStudent() { return student; }
string TransportPass::getStatus() { return status; }
void TransportPass::setStatus(string s) { status = s; }
Route* TransportPass::getRoute() { return route; }

void TransportPass::generateInvoice()
{
    setColor(10); cout << "\n\t\tStudent: "; setColor(15); cout << student->getName() << endl;
    bill.generateInvoice();
}

void TransportPass::applyLateFee(int daysLate) { bill.applyLateFine(daysLate); }
void TransportPass::setFine(float f) { bill.setFine(f); }

class Report
{
public:
    void generateRevenueReport();
    void generateRouteUsageReport();
};

void Report::generateRevenueReport()
{
    setColor(10);
    cout << "\n\t\t===== Revenue Report =====" << endl;
    cout << "\t\tRevenue Report Generated Successfully." << endl;
    setColor(15);
}

void Report::generateRouteUsageReport()
{
    setColor(10);
    cout << "\n\t\t===== Route Usage Report =====" << endl;
    cout << "\t\tRoute Usage Report Generated Successfully." << endl;
    setColor(15);
}

class TransportManager
{
private:
    Student* students[100];
    Vehicle* vehicles[100];
    Route* routes[100];
    TransportPass* passes[100];
    Driver* drivers[100];
    int driverCount;
    int studentCount;
    int vehicleCount;
    int routeCount;
    int passCount;

public:
    Student* loginStudent();
    TransportManager();
    ~TransportManager();

    void addStudent(Student* s);
    void addVehicle(Vehicle* v);
    void addRoute(Route* r);
    void addPass(TransportPass* p);
    void viewStudents();
    void viewVehicles();
    void viewRoutes();
    void viewPasses();
    void registerStudent();
    void createVehicle();
    void createRoute();
    void applyForTransport(Student* s);
    void cancelRegistration(int studentID);
    void assignVehicleToRoute();
    bool isAlreadyRegistered(int studentID);
    void removeDriver();
    void removeRoute();
    bool studentIDExists(int id);
    bool vehicleIDExists(int id);
    bool routeIDExists(int id);
    bool driverIDExists(int id);
    void addDriver(Driver* d);

    void saveVehicles();
    void loadVehicles();
    void saveStudents();
    void loadStudents();
    void saveRoutes();
    void loadRoutes();
    void savePasses();
    void loadPasses();
    void saveDrivers();
    void loadDrivers();

    float getTotalRevenue();
    void routeUsageReport();
    void viewMyRegistration(int studentID);
    void approvePass();
    void editVehicle();
    void removeVehicle();
    void viewVehicleSeatStatus();
    void generateStudentInvoice(int studentID);
    void applyLateFineToStudent();

    void createDriver();
    void viewDrivers();
    void assignDriverToRoute();

};

TransportManager::TransportManager()
{
    studentCount = 0; vehicleCount = 0; routeCount = 0; passCount = 0;
    driverCount = 0;
}

TransportManager::~TransportManager()
{
    for (int i = 0; i < studentCount; i++) { delete students[i]; }
    for (int i = 0; i < vehicleCount; i++) { delete vehicles[i]; }
    for (int i = 0; i < routeCount; i++) { delete routes[i]; }
    for (int i = 0; i < passCount; i++) { delete passes[i]; }
    for (int i = 0; i < driverCount; i++) { delete drivers[i]; }
}

// ==========================================
// MISSING IMPLEMENTATIONS ADDED PROPERLY
// ==========================================
bool TransportManager::studentIDExists(int id)
{
    for (int i = 0; i < studentCount; i++)
    {
        if (students[i]->getUserID() == id)
            return true;
    }
    return false;
}

bool TransportManager::vehicleIDExists(int id)
{
    for (int i = 0; i < vehicleCount; i++)
    {
        if (vehicles[i]->getVehicleID() == id)
            return true;
    }
    return false;
}

bool TransportManager::routeIDExists(int id)
{
    for (int i = 0; i < routeCount; i++)
    {
        if (routes[i]->getRouteID() == id)
            return true;
    }
    return false;
}

bool TransportManager::driverIDExists(int id)
{
    for (int i = 0; i < driverCount; i++)
    {
        if (drivers[i]->getUserID() == id)
            return true;
    }
    return false;
}

void TransportManager::addDriver(Driver* d)
{
    if (driverCount >= 100)
    {
        setColor(12);
        cout << "\t\tDriver limit reached!" << endl;
        setColor(15);
        return;
    }
    drivers[driverCount] = d;
    driverCount++;
}
// ==========================================

void TransportManager::addStudent(Student* s)
{
    if (studentCount >= 100)
    {
        setColor(12);
        cout << "\t\tStudent limit reached!" << endl;
        setColor(15);
        return;
    }
    students[studentCount] = s;
    studentCount++;
}

void TransportManager::addVehicle(Vehicle* v)
{
    if (vehicleCount >= 100)
    {
        setColor(12);
        cout << "\t\tVehicle limit reached!" << endl;
        setColor(15);
        return;
    }
    vehicles[vehicleCount] = v;
    vehicleCount++;
}

void TransportManager::addRoute(Route* r)
{
    routes[routeCount] = r;
    routeCount++;
}

void TransportManager::addPass(TransportPass* p)
{
    passes[passCount] = p;
    passCount++;
}

void TransportManager::viewStudents()
{
    clearScreen();
    printHeading();
    printSubHeading("REGISTERED STUDENTS");

    if (studentCount == 0)
    {
        setColor(14);
        cout << "\t\tNo students registered yet.\n\n";
        setColor(15);
        return;
    }

    for (int i = 0; i < studentCount; i++)
    {
        students[i]->display();
        cout << endl;
    }
}

void TransportManager::viewVehicles()
{
    clearScreen();
    printHeading();
    printSubHeading("ALL VEHICLES");

    if (vehicleCount == 0)
    {
        setColor(14);
        cout << "\t\tNo vehicles available yet.\n\n";
        setColor(15);
        return;
    }

    for (int i = 0; i < vehicleCount; i++)
    {
        vehicles[i]->displayVehicle();
        cout << endl;
    }
}

void TransportManager::viewRoutes()
{
    clearScreen();
    printHeading();
    printSubHeading("ALL ROUTES");

    if (routeCount == 0)
    {
        setColor(14);
        cout << "\t\tNo routes available yet.\n\n";
        setColor(15);
        return;
    }

    for (int i = 0; i < routeCount; i++)
    {
        routes[i]->displayRoute();
        cout << endl;
    }
}

void TransportManager::viewPasses()
{
    if (passCount == 0)
    {
        setColor(14);
        cout << "\t\tNo transport passes issued yet.\n\n";
        setColor(15);
        return;
    }

    for (int i = 0; i < passCount; i++)
    {
        passes[i]->displayPass();
        cout << endl;
    }
}

bool TransportManager::isAlreadyRegistered(int studentID)
{
    for (int i = 0; i < passCount; i++)
    {
        if (passes[i]->getStudent()->getUserID() == studentID) return true;
    }
    return false;
}

void TransportManager::registerStudent()
{
    clearScreen();
    printHeading();
    printSubHeading("STUDENT REGISTRATION");

    int id = getValidInt("\t\tEnter Student ID: ");
    if (id == -1) return;
    if (studentIDExists(id))
    {
        setColor(12);
        cout << "\n\t\tStudent ID already exists!" << endl;
        cout << "\t\tPlease enter a unique ID." << endl;
        setColor(15);
        return;
    }

    string name;
    setColor(14); cout << "\t\tEnter Name (or 'R' to return): "; setColor(15);
    getline(cin, name);
    if (name == "R" || name == "r") return;

    string email;
    setColor(14); cout << "\t\tEnter Email (or 'R' to return): "; setColor(15);
    getline(cin, email);
    if (email == "R" || email == "r") return;

    string password;
    setColor(14); cout << "\t\tEnter Password (or 'R' to return): "; setColor(15);
    getline(cin, password);
    if (password == "R" || password == "r") return;

    int regID = getValidInt("\t\tEnter Registration ID: ");
    if (regID == -1) return;

    Student* s = new Student(id, name, email, password, regID);
    addStudent(s);

    setColor(10);
    cout << "\n\t\tStudent Registered Successfully!" << endl;
    setColor(15);
}

Student* TransportManager::loginStudent()
{
    clearScreen();
    printHeading();
    printSubHeading("STUDENT LOGIN");

    if (studentCount == 0)
    {
        setColor(14);
        cout << "\t\tNo students registered yet! Please register first.\n\n";
        setColor(15);
        return nullptr;
    }

    int id = getValidInt("\t\tEnter ID: ");
    if (id == -1) return nullptr;

    string password;
    setColor(14); cout << "\t\tEnter Password (or 'R' to return): "; setColor(15);
    cin >> password;
    if (password == "r" || password == "R") return nullptr;

    for (int i = 0; i < studentCount; i++)
    {
        if (students[i]->getUserID() == id && students[i]->getPassword() == password)
        {
            return students[i];
        }
    }
    return nullptr;
}

void TransportManager::createVehicle()
{
    clearScreen();
    printHeading();
    printSubHeading("ADD VEHICLE");

    int choice;
    while (true)
    {
        setColor(8); cout << "\t\t1. "; setColor(15); cout << "Bus\n";
        setColor(8); cout << "\t\t2. "; setColor(15); cout << "Van\n";
        choice = getValidInt("\n\t\tChoice: ");
        if (choice == -1) return;
        if (choice == 1 || choice == 2) break;

        setColor(12);
        cout << "\n\t\tInvalid choice!\n\n";
        setColor(15);
    }

    int id = getValidInt("\n\t\tVehicle ID: ");
    if (id == -1) return;
    if (vehicleIDExists(id))
    {
        setColor(12);
        cout << "\n\t\tVehicle ID already exists!" << endl;
        setColor(15);
        return;
    }
    string number;
    setColor(14); cout << "\t\tVehicle Number (or 'R' to return): "; setColor(15);
    cin >> number;
    if (number == "r" || number == "R") return;

    int capacity = getValidInt("\t\tCapacity: ");
    if (capacity == -1) return;

    if (choice == 1) addVehicle(new Bus(id, number, capacity));
    else if (choice == 2) addVehicle(new Van(id, number, capacity));

    setColor(10); cout << "\n\t\tVehicle Added Successfully!\n"; setColor(15);
}

void TransportManager::createRoute()
{
    clearScreen();
    printHeading();
    printSubHeading("ADD ROUTE");

    int id = getValidInt("\t\tRoute ID: ");
    if (id == -1) return;
    if (routeIDExists(id))
    {
        setColor(12);
        cout << "\n\t\tRoute ID already exists!" << endl;
        setColor(15);
        return;
    }
    string start;
    setColor(14); cout << "\t\tStart Point (or 'R' to return): "; setColor(15);
    getline(cin, start);
    if (start == "r" || start == "R") return;

    string end;
    setColor(14); cout << "\t\tEnd Point (or 'R' to return): "; setColor(15);
    getline(cin, end);
    if (end == "r" || end == "R") return;

    float distance = getValidFloat("\t\tDistance: ");
    if (distance == -1) return;

    addRoute(new Route(id, start, end, distance));

    setColor(10); cout << "\n\t\tRoute Added Successfully!\n"; setColor(15);
}
void TransportManager::removeDriver()
{
    clearScreen();
    printHeading();
    printSubHeading("REMOVE DRIVER");

    if (driverCount == 0)
    {
        cout << "\t\tNo Drivers Available!\n";
        return;
    }

    for (int i = 0; i < driverCount; i++)
    {
        cout << "\nIndex: " << i + 1 << endl;
        drivers[i]->display();
    }

    int index = getValidInt("\n\t\tEnter Driver Index: ");
    if (index == -1) return;

    index--;

    if (index < 0 || index >= driverCount)
    {
        cout << "\t\tInvalid Index!\n";
        return;
    }

    // Check if assigned to any route
    for (int i = 0; i < routeCount; i++)
    {
        if (routes[i]->getAssignedDriver() == drivers[index])
        {
            cout << "\n\t\tDriver is assigned to a route!" << endl;
            cout << "\t\tRemove driver from route first." << endl;
            return;
        }
    }

    delete drivers[index];

    for (int i = index; i < driverCount - 1; i++)
    {
        drivers[i] = drivers[i + 1];
    }

    drivers[driverCount - 1] = nullptr;
    driverCount--;

    cout << "\n\t\tDriver Removed Successfully!" << endl;
}
void TransportManager::applyForTransport(Student* s)
{
    clearScreen();
    printHeading();
    printSubHeading("APPLY FOR TRANSPORT");

    if (routeCount == 0)
    {
        setColor(14); cout << "\t\tNo Routes Available!" << endl; setColor(15);
        return;
    }

    if (isAlreadyRegistered(s->getUserID()))
    {
        setColor(12); cout << "\t\tYou are already registered for transport!" << endl; setColor(15);
        return;
    }

    setColor(8); cout << "\n\t\tAvailable Routes:" << endl; setColor(15);

    for (int i = 0; i < routeCount; i++)
    {
        setColor(8); cout << "\n\t\tRoute Index: "; setColor(15); cout << i + 1 << endl;
        routes[i]->displayRoute();
    }

    int routeIndex = getValidInt("\n\t\tSelect Route Index: ");
    if (routeIndex == -1) return;
    routeIndex--;

    if (routeIndex < 0 || routeIndex >= routeCount)
    {
        setColor(12); cout << "\t\tInvalid Route Selected!" << endl; setColor(15);
        return;
    }

    Vehicle* v = routes[routeIndex]->getAssignedVehicle();
    if (v == nullptr)
    {
        setColor(12); cout << "\t\tNo Vehicle Assigned To This Route!" << endl; setColor(15);
        return;
    }

    if (!v->hasAvailableSeat())
    {
        setColor(12); cout << "\t\tVehicle Full!" << endl; setColor(15);
        return;
    }

    TransportPass* pass = new TransportPass(passCount + 1, s, routes[routeIndex]);
    addPass(pass);

    setColor(10); cout << "\n\t\tTransport Registration Successful for " << s->getName() << "!" << endl; setColor(15);
}

void TransportManager::cancelRegistration(int studentID)
{
    clearScreen();
    printHeading();
    printSubHeading("CANCEL REGISTRATION");

    int index = -1;
    for (int i = 0; i < passCount; i++)
    {
        if (passes[i]->getStudent()->getUserID() == studentID)
        {
            passes[i]->displayPass();
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        setColor(14); cout << "\t\tNo Registration Found!" << endl; setColor(15);
        return;
    }

    string choice;
    setColor(14); cout << "\n\t\tCancel Registration? (Y/N or 'R' to return): "; setColor(15);
    cin >> choice;

    if (choice == "r" || choice == "R") return;
    if (choice != "Y" && choice != "y") return;

    if (passes[index]->getStatus() == "APPROVED")
    {
        Vehicle* v = passes[index]->getRoute()->getAssignedVehicle();
        if (v != nullptr) v->releaseSeat();
    }

    delete passes[index];
    for (int i = index; i < passCount - 1; i++) passes[i] = passes[i + 1];

    passes[passCount - 1] = nullptr;
    passCount--;

    setColor(10); cout << "\n\t\tRegistration Cancelled Successfully!" << endl; setColor(15);
}

void TransportManager::assignVehicleToRoute()
{
    clearScreen();
    printHeading();
    printSubHeading("ASSIGN VEHICLE TO ROUTE");

    if (vehicleCount == 0 || routeCount == 0)
    {
        setColor(14); cout << "\t\tAdd Vehicles and Routes First!" << endl; setColor(15);
        return;
    }

    setColor(8); cout << "\n\t\tAvailable Vehicles:\n"; setColor(15);
    for (int i = 0; i < vehicleCount; i++)
    {
        setColor(8); cout << "\n\t\tIndex: "; setColor(15); cout << i + 1 << endl;
        vehicles[i]->displayVehicle();
    }

    int vehicleIndex = getValidInt("\n\t\tSelect Vehicle Index: ");
    if (vehicleIndex == -1) return;
    vehicleIndex--;

    for (int i = 0; i < routeCount; i++)
    {
        if (routes[i]->getAssignedVehicle() == vehicles[vehicleIndex])
        {
            setColor(12);
            cout << "\n\t\tThis Vehicle Is Already Assigned To Another Route!" << endl;
            setColor(15);
            return;
        }
    }

    if (vehicleIndex < 0 || vehicleIndex >= vehicleCount)
    {
        setColor(12); cout << "\t\tInvalid Vehicle Index!\n"; setColor(15);
        return;
    }

    setColor(8); cout << "\n\t\tAvailable Routes:\n"; setColor(15);
    for (int i = 0; i < routeCount; i++)
    {
        setColor(8); cout << "\n\t\tRoute Index: "; setColor(15); cout << i + 1 << endl;
        routes[i]->displayRoute();
    }

    int routeIndex = getValidInt("\n\t\tSelect Route Index: ");
    if (routeIndex == -1) return;
    routeIndex--;

    if (routeIndex < 0 || routeIndex >= routeCount)
    {
        setColor(12); cout << "\t\tInvalid Route Index!\n"; setColor(15);
        return;
    }

    routes[routeIndex]->assignVehicle(vehicles[vehicleIndex]);
    routes[routeIndex]->setAssignedVehicleID(vehicles[vehicleIndex]->getVehicleID());

    setColor(10); cout << "\n\t\tVehicle Assigned Successfully!" << endl; setColor(15);
}

void TransportManager::saveStudents()
{
    ofstream file("students.txt");
    file << left << setw(15) << "UserID"
        << setw(25) << "Name"
        << setw(35) << "Email"
        << setw(20) << "Password"
        << setw(20) << "RegistrationID" << "\n";

    for (int i = 0; i < studentCount; i++)
    {
        file << left << setw(15) << students[i]->getUserID()
            << setw(25) << students[i]->getName()
            << setw(35) << students[i]->getEmail()
            << setw(20) << students[i]->getPassword()
            << setw(20) << students[i]->getRegistrationID() << endl;
    }
    file.close();
}

void TransportManager::loadStudents()
{
    ifstream file("students.txt");
    if (!file) return;

    string dummy;
    getline(file, dummy);

    int id; string name, email, password; int registerationID;
    while (file >> id >> name >> email >> password >> registerationID)
    {
        Student* s = new Student(id, name, email, password, registerationID);
        addStudent(s);
    }
    file.close();
}

void TransportManager::saveVehicles()
{
    ofstream file("vehicles.txt");
    file << left << setw(10) << "Type"
        << setw(15) << "VehicleID"
        << setw(25) << "Number"
        << setw(15) << "Capacity"
        << setw(15) << "OccupiedSeats" << "\n";

    for (int i = 0; i < vehicleCount; i++)
    {
        string vType = dynamic_cast<Bus*>(vehicles[i]) ? "B" : "V";
        file << left << setw(10) << vType
            << setw(15) << vehicles[i]->getVehicleID()
            << setw(25) << vehicles[i]->getVehicleNumber()
            << setw(15) << vehicles[i]->getCapacity()
            << setw(15) << vehicles[i]->getOccupiedSeats() << endl;
    }
    file.close();
}

void TransportManager::loadVehicles()
{
    ifstream file("vehicles.txt");
    if (!file) return;

    string dummy;
    getline(file, dummy);

    char type; int id; string number; int cap; int occSeats;
    while (file >> type >> id >> number >> cap >> occSeats)
    {
        Vehicle* v = nullptr;
        if (type == 'B') v = new Bus(id, number, cap);
        else if (type == 'V') v = new Van(id, number, cap);

        if (v != nullptr)
        {
            v->setOccupiedSeats(occSeats);
            addVehicle(v);
        }
    }
    file.close();
}

void TransportManager::saveRoutes()
{
    ofstream file("routes.txt");
    file << left
        << setw(15) << "RouteID"
        << setw(25) << "StartPoint"
        << setw(25) << "EndPoint"
        << setw(15) << "Distance"
        << setw(20) << "AssignedVehicleID"
        << setw(20) << "AssignedDriverID"
        << "\n";

    for (int i = 0; i < routeCount; i++)
    {
        int vID;
        int dID;

        if (routes[i]->getAssignedVehicle() != nullptr)
        {
            vID = routes[i]->getAssignedVehicle()->getVehicleID();
        }
        else
        {
            vID = -1;
        }

        if (routes[i]->getAssignedDriver() != nullptr)
        {
            dID = routes[i]->getAssignedDriver()->getUserID();
        }
        else
        {
            dID = -1;
        }

        file << left
            << setw(15) << routes[i]->getRouteID()
            << setw(25) << routes[i]->getStartPoint()
            << setw(25) << routes[i]->getEndPoint()
            << setw(15) << routes[i]->getDistance()
            << setw(20) << vID
            << setw(20) << dID
            << endl;
    } file.close();
}

void TransportManager::loadRoutes()
{
    ifstream file("routes.txt");
    if (!file) return;

    string dummy;
    getline(file, dummy);

    int id, vehicleID, driverID;
    string start, end;
    float dist;

    while (file >> id >> start >> end >> dist >> vehicleID >> driverID)
    {
        Route* r = new Route(id, start, end, dist);

        for (int i = 0; i < vehicleCount; i++)
        {
            if (vehicles[i]->getVehicleID() == vehicleID)
            {
                r->assignVehicle(vehicles[i]);
                break;
            }
        }

        for (int i = 0; i < driverCount; i++)
        {
            if (drivers[i]->getUserID() == driverID)
            {
                r->assignDriver(drivers[i]);
                break;
            }
        }

        addRoute(r);
    }

    file.close();
}

void TransportManager::savePasses()
{
    ofstream file("passes.txt");
    file << left << setw(15) << "StudentID"
        << setw(15) << "RouteID"
        << setw(20) << "Status"
        << setw(15) << "FineAmount" << "\n";

    for (int i = 0; i < passCount; i++)
    {
        file << left << setw(15) << passes[i]->getStudent()->getUserID()
            << setw(15) << passes[i]->getRoute()->getRouteID()
            << setw(20) << passes[i]->getStatus()
            << setw(15) << passes[i]->getFineAmount() << endl;
    }
    file.close();
}

void TransportManager::loadPasses()
{
    ifstream file("passes.txt");
    if (!file) return;

    string dummy;
    getline(file, dummy);

    int studentID, routeID; string status; float fine;
    while (file >> studentID >> routeID >> status >> fine)
    {
        Student* s = nullptr;
        Route* r = nullptr;

        for (int i = 0; i < studentCount; i++)
        {
            if (students[i]->getUserID() == studentID)
            {
                s = students[i];
                break;
            }
        }

        for (int i = 0; i < routeCount; i++)
        {
            if (routes[i]->getRouteID() == routeID)
            {
                r = routes[i];
                break;
            }
        }

        if (s != nullptr && r != nullptr)
        {
            TransportPass* p = new TransportPass(passCount + 1, s, r);
            p->setStatus(status);
            p->setFine(fine);
            addPass(p);
        }
    }
    file.close();
}

void TransportManager::saveDrivers()
{
    ofstream file("drivers.txt");
    file << left << setw(15) << "DriverID"
        << setw(25) << "Name"
        << setw(35) << "Email"
        << setw(20) << "Password"
        << setw(25) << "LicenseNo" << "\n";

    for (int i = 0; i < driverCount; i++)
    {
        file << left << setw(15) << drivers[i]->getUserID()
            << setw(25) << drivers[i]->getName()
            << setw(35) << drivers[i]->getEmail()
            << setw(20) << drivers[i]->getPassword()
            << setw(25) << drivers[i]->getLicenseNo() << endl;
    }
    file.close();
}

void TransportManager::loadDrivers()
{
    ifstream file("drivers.txt");
    if (!file) return;

    string dummy;
    getline(file, dummy);

    int id; string name, email, password, license;
    while (file >> id >> name >> email >> password >> license)
    {
        Driver* d = new Driver(id, name, email, password, license);
        addDriver(d);
    }
    file.close();
}

float TransportManager::getTotalRevenue()
{
    float total = 0;
    for (int i = 0; i < passCount; i++)
    {
        if (passes[i]->getStatus() == "APPROVED") total += passes[i]->getTotalBill();
    }
    return total;
}

void TransportManager::routeUsageReport()
{
    if (routeCount == 0)
    {
        setColor(14);
        cout << "\t\tNo routes available yet to generate report.\n\n";
        setColor(15);
        return;
    }

    for (int i = 0; i < routeCount; i++)
    {
        int count = 0;
        for (int j = 0; j < passCount; j++)
        {
            if (passes[j]->getRoute()->getRouteID() == routes[i]->getRouteID() &&
                passes[j]->getStatus() == "APPROVED")
            {
                count++;
            }
        }
        setColor(10); cout << "\t\tRoute ID: "; setColor(15); cout << routes[i]->getRouteID();
        setColor(8); cout << "  ->  ";
        setColor(14); cout << count; setColor(15); cout << " students" << endl;
    }
    cout << endl;
}

void TransportManager::viewMyRegistration(int studentID)
{
    clearScreen();
    printHeading();
    printSubHeading("MY REGISTRATION");

    bool found = false;
    for (int i = 0; i < passCount; i++)
    {
        if (passes[i]->getStudent()->getUserID() == studentID)
        {
            passes[i]->displayPass();
            found = true;
        }
    }

    if (!found)
    {
        setColor(14); cout << "\t\tNo registration found for this student!" << endl; setColor(15);
    }
}

void TransportManager::editVehicle()
{
    clearScreen();
    printHeading();
    printSubHeading("EDIT VEHICLE");

    if (vehicleCount == 0)
    {
        setColor(14); cout << "\t\tNo Vehicles Available to edit!\n\n" << endl; setColor(15);
        return;
    }

    for (int i = 0; i < vehicleCount; i++)
    {
        setColor(8); cout << "\n\t\tIndex: "; setColor(15); cout << i + 1 << endl;
        vehicles[i]->displayVehicle();
    }

    int index = getValidInt("\n\t\tEnter Vehicle Index To Edit: ");
    if (index == -1) return;
    index--;

    if (index < 0 || index >= vehicleCount)
    {
        setColor(12); cout << "\t\tInvalid Index!" << endl; setColor(15);
        return;
    }

    setColor(8); cout << "\n\t\t1. "; setColor(15); cout << "Bus\n";
    setColor(8); cout << "\t\t2. "; setColor(15); cout << "Van\n";
    int type = getValidInt("\n\t\tSelect Vehicle Type: ");
    if (type == -1) return;

    string newNumber;
    setColor(14); cout << "\n\t\tEnter New Vehicle Number (or 'R'): "; setColor(15);
    cin >> newNumber;
    if (newNumber == "r" || newNumber == "R") return;

    int newCapacity = getValidInt("\t\tEnter New Capacity: ");
    if (newCapacity == -1) return;

    int oldID = vehicles[index]->getVehicleID();
    delete vehicles[index];

    if (type == 1) vehicles[index] = new Bus(oldID, newNumber, newCapacity);
    else if (type == 2) vehicles[index] = new Van(oldID, newNumber, newCapacity);
    else
    {
        setColor(12); cout << "\t\tInvalid Vehicle Type!" << endl; setColor(15);
        return;
    }

    setColor(10); cout << "\n\t\tVehicle Updated Successfully!" << endl; setColor(15);
}

void TransportManager::removeVehicle()
{
    clearScreen();
    printHeading();
    printSubHeading("REMOVE VEHICLE");

    if (vehicleCount == 0)
    {
        setColor(14); cout << "\t\tNo Vehicles Available to remove!\n\n"; setColor(15);
        return;
    }

    for (int i = 0; i < vehicleCount; i++)
    {
        setColor(8); cout << "\n\t\tIndex: "; setColor(15); cout << i + 1 << endl;
        vehicles[i]->displayVehicle();
    }

    int index = getValidInt("\n\t\tEnter Vehicle Index To Remove: ");
    if (index == -1) return;
    index--;

    if (index < 0 || index >= vehicleCount)
    {
        setColor(12); cout << "\t\tInvalid Index!" << endl; setColor(15);
        return;
    }

    for (int i = 0; i < routeCount; i++)
    {
        if (routes[i]->getAssignedVehicle() == vehicles[index])
        {
            setColor(12);
            cout << "\n\t\tThis Vehicle Is Assigned To A Route!" << endl;
            cout << "\t\tRemove Vehicle From Route First." << endl;
            setColor(15);
            return;
        }
    }

    delete vehicles[index];
    for (int i = index; i < vehicleCount - 1; i++) vehicles[i] = vehicles[i + 1];

    vehicles[vehicleCount - 1] = nullptr;
    vehicleCount--;

    setColor(10); cout << "\n\t\tVehicle Removed Successfully!" << endl; setColor(15);
}

void TransportManager::viewVehicleSeatStatus()
{
    clearScreen();
    printHeading();
    printSubHeading("VEHICLE SEAT STATUS");

    if (vehicleCount == 0)
    {
        setColor(14); cout << "\t\tNo vehicles available yet.\n\n"; setColor(15);
        return;
    }

    for (int i = 0; i < vehicleCount; i++)
    {
        Vehicle* v = vehicles[i];
        setColor(8); cout << "\n\t\tVehicle Index: "; setColor(15); cout << i + 1 << endl;
        v->displayVehicle();

        setColor(10); cout << "\t\tReserved Seats: "; setColor(15); cout << v->getOccupiedSeats() << endl;
        setColor(10); cout << "\t\tAvailable Seats: "; setColor(15); cout << v->getAvailableSeats() << endl;

        bool foundRoute = false;
        for (int j = 0; j < routeCount; j++)
        {
            if (routes[j]->getAssignedVehicle() == v)
            {
                setColor(10); cout << "\t\tAssigned Route ID: "; setColor(15); cout << routes[j]->getRouteID() << endl;
                setColor(10); cout << "\t\tRoute: "; setColor(15); cout << routes[j]->getStartPoint() << " -> " << routes[j]->getEndPoint() << endl;
                foundRoute = true;
                break;
            }
        }

        if (!foundRoute) { setColor(10); cout << "\t\tAssigned Route: "; setColor(15); cout << "None" << endl; }
        setColor(15);
    }
}

void TransportManager::generateStudentInvoice(int studentID)
{
    clearScreen();
    printHeading();
    printSubHeading("INVOICE GENERATION");

    for (int i = 0; i < passCount; i++)
    {
        if (passes[i]->getStudent()->getUserID() == studentID)
        {
            if (passes[i]->getStatus() == "APPROVED") passes[i]->generateInvoice();
            else if (passes[i]->getStatus() == "PENDING")
            {
                setColor(14); cout << "\t\tYour transport request is still pending!" << endl; setColor(15);
            }
            else if (passes[i]->getStatus() == "REJECTED")
            {
                setColor(12); cout << "\t\tYour transport request has been rejected!" << endl; setColor(15);
            }
            return;
        }
    }

    setColor(14); cout << "\t\tNo Registration Found!" << endl; setColor(15);
}

void TransportManager::assignDriverToRoute()
{
    clearScreen();
    printHeading();
    printSubHeading("ASSIGN DRIVER TO ROUTE");

    if (driverCount == 0 || routeCount == 0)
    {
        setColor(14); cout << "\t\tAdd Drivers and Routes First!\n"; setColor(15);
        return;
    }

    setColor(10); cout << "\n\t\tAvailable Drivers:\n"; setColor(15);

    for (int i = 0; i < driverCount; i++)
    {
        setColor(8); cout << "\n\t\tIndex: "; setColor(15); cout << i + 1 << endl;
        drivers[i]->display();
    }

    int dIndex = getValidInt("\n\t\tSelect Driver Index: ");
    if (dIndex == -1) return;
    dIndex--;

    if (dIndex < 0 || dIndex >= driverCount)
    {
        setColor(12); cout << "\t\tInvalid Driver Index!\n"; setColor(15);
        return;
    }

    for (int i = 0; i < routeCount; i++)
    {
        if (routes[i]->getAssignedDriver() == drivers[dIndex])
        {
            setColor(12);
            cout << "\n\t\tThis Driver Is Already Assigned To Another Route!" << endl;
            setColor(15);
            return;
        }
    }

    setColor(10); cout << "\n\t\tAvailable Routes:\n"; setColor(15);

    for (int i = 0; i < routeCount; i++)
    {
        setColor(8); cout << "\n\t\tRoute Index: "; setColor(15); cout << i + 1 << endl;
        routes[i]->displayRoute();
    }

    int rIndex = getValidInt("\n\t\tSelect Route Index: ");
    if (rIndex == -1) return;
    rIndex--;

    if (rIndex < 0 || rIndex >= routeCount)
    {
        setColor(12); cout << "\t\tInvalid Route Index!\n"; setColor(15);
        return;
    }

    routes[rIndex]->assignDriver(drivers[dIndex]);

    setColor(10); cout << "\n\t\tDriver Assigned Successfully!\n"; setColor(15);
}

void TransportManager::approvePass()
{
    clearScreen();
    printHeading();
    printSubHeading("APPROVE / REJECT REQUESTS");

    if (passCount == 0)
    {
        setColor(14); cout << "\t\tNo transport requests found!\n\n"; setColor(15);
        return;
    }

    for (int i = 0; i < passCount; i++)
    {
        setColor(8); cout << "\n\t\tIndex: "; setColor(15); cout << i + 1 << endl;
        passes[i]->displayPass();
    }

    int index = getValidInt("\n\t\tSelect request index: ");
    if (index == -1) return;
    index--;

    if (index < 0 || index >= passCount)
    {
        setColor(12); cout << "\t\tInvalid index!" << endl; setColor(15);
        return;
    }

    setColor(8); cout << "\n\t\t1. "; setColor(15); cout << "Approve\n";
    setColor(8); cout << "\t\t2. "; setColor(12); cout << "Reject\n";
    int choice = getValidInt("\n\t\tEnter choice: ");
    if (choice == -1) return;

    if (choice == 1)
    {
        Vehicle* v = passes[index]->getRoute()->getAssignedVehicle();
        if (v != nullptr)
        {
            if (v->hasAvailableSeat())
            {
                v->reserveSeat();
                passes[index]->setStatus("APPROVED");
                setColor(10); cout << "\n\t\tRequest Approved Successfully!" << endl; setColor(15);
            }
            else
            {
                setColor(12); cout << "\n\t\tVehicle Full!" << endl; setColor(15);
            }
        }
        else
        {
            setColor(12); cout << "\n\t\tNo Vehicle Assigned To This Route!" << endl; setColor(15);
        }
    }
    else if (choice == 2)
    {
        Vehicle* v = passes[index]->getRoute()->getAssignedVehicle();
        if (passes[index]->getStatus() == "APPROVED")
        {
            if (v != nullptr) v->releaseSeat();
        }
        passes[index]->setStatus("REJECTED");
        setColor(12); cout << "\n\t\tRequest Rejected!" << endl; setColor(15);
    }
}

void TransportManager::removeRoute()
{
    clearScreen();
    printHeading();
    printSubHeading("REMOVE ROUTE");

    if (routeCount == 0)
    {
        cout << "\t\tNo Routes Available!\n";
        return;
    }

    for (int i = 0; i < routeCount; i++)
    {
        cout << "\nRoute Index: " << i + 1 << endl;
        routes[i]->displayRoute();
    }

    int index = getValidInt("\n\t\tEnter Route Index: ");
    if (index == -1) return;

    index--;

    if (index < 0 || index >= routeCount)
    {
        cout << "\t\tInvalid Index!\n";
        return;
    }

    // Check if any student registered on this route
    for (int i = 0; i < passCount; i++)
    {
        if (passes[i]->getRoute() == routes[index])
        {
            cout << "\n\t\tStudents are registered on this route!" << endl;
            cout << "\t\tRemove registrations first." << endl;
            return;
        }
    }

    delete routes[index];

    for (int i = index; i < routeCount - 1; i++)
    {
        routes[i] = routes[i + 1];
    }

    routes[routeCount - 1] = nullptr;
    routeCount--;

    cout << "\n\t\tRoute Removed Successfully!" << endl;
}
void TransportManager::createDriver()
{
    clearScreen();
    printHeading();
    printSubHeading("ADD DRIVER");

    int id = getValidInt("\t\tDriver ID: ");
    if (id == -1) return;
    if (driverIDExists(id))
    {
        setColor(12);
        cout << "\n\t\tDriver ID already exists!" << endl;
        setColor(15);
        return;
    }
    string name;
    setColor(14); cout << "\t\tName (or 'R' to return): "; setColor(15);
    getline(cin, name);
    if (name == "R" || name == "r") return;

    string email;
    setColor(14); cout << "\t\tEmail (or 'R' to return): "; setColor(15);
    getline(cin, email);
    if (email == "R" || email == "r") return;

    string password;
    setColor(14); cout << "\t\tPassword (or 'R' to return): "; setColor(15);
    getline(cin, password);
    if (password == "R" || password == "r") return;

    string license;
    setColor(14); cout << "\t\tLicense No (or 'R' to return): "; setColor(15);
    getline(cin, license);
    if (license == "R" || license == "r") return;

    addDriver(new Driver(id, name, email, password, license));

    setColor(10);
    cout << "\n\t\tDriver Added Successfully!\n";
    setColor(15);
}

void TransportManager::viewDrivers()
{
    clearScreen();
    printHeading();
    printSubHeading("ALL DRIVERS");

    if (driverCount == 0)
    {
        setColor(14);
        cout << "\t\tNo Drivers Available.\n";
        setColor(15);
        return;
    }

    for (int i = 0; i < driverCount; i++)
    {
        drivers[i]->display();
        cout << endl;
    }
}

void TransportManager::applyLateFineToStudent()
{
    clearScreen();
    printHeading();
    printSubHeading("APPLY LATE FINE");

    if (passCount == 0)
    {
        setColor(14); cout << "\t\tNo transport passes found to apply fine!\n\n"; setColor(15);
        return;
    }

    int studentID = getValidInt("\t\tEnter Student ID: ");
    if (studentID == -1) return;

    int daysLate = getValidInt("\t\tEnter Late Days: ");
    if (daysLate == -1) return;

    for (int i = 0; i < passCount; i++)
    {
        if (passes[i]->getStudent()->getUserID() == studentID)
        {
            passes[i]->applyLateFee(daysLate);
            setColor(10); cout << "\n\t\tLate Fine Applied Successfully!" << endl; setColor(15);
            return;
        }
    }

    setColor(12); cout << "\n\t\tStudent Not Found!" << endl; setColor(15);
}

bool adminLogin()
{
    clearScreen();
    printHeading();
    printSubHeading("ADMIN LOGIN");

    string email, password;

    setColor(14); cout << "\t\tEnter Admin Email (or 'R'): "; setColor(15);
    cin >> email;
    if (email == "r" || email == "R") return false;

    setColor(14); cout << "\t\tEnter Admin Password (or 'R'): "; setColor(15);
    cin >> password;
    if (password == "r" || password == "R") return false;

    if (email == "1" && password == "1") return true;

    setColor(12); cout << "\n\t\tInvalid Admin Credentials!" << endl; setColor(15);
    return false;
}

void studentMenu(TransportManager& manager, Student* s)
{
    int choice;
    do
    {
        clearScreen();
        printHeading();
        printSubHeading("STUDENT PORTAL");

        setColor(8); cout << "\t\t1. "; setColor(15); cout << "View Routes\n";
        setColor(8); cout << "\t\t2. "; setColor(15); cout << "Apply For Transport\n";
        setColor(8); cout << "\t\t3. "; setColor(15); cout << "View My Registration\n";
        setColor(8); cout << "\t\t4. "; setColor(15); cout << "Cancel Registration\n";
        setColor(8); cout << "\t\t5. "; setColor(15); cout << "Generate Invoice\n";

        setColor(8); cout << "\t\t6. "; setColor(12); cout << "Logout\n";
        setColor(15);

        choice = getValidInt("\n\t\tEnter Choice: ");
        if (choice == -1) continue;

        switch (choice)
        {
        case 1: manager.viewRoutes(); system("pause"); break;
        case 2: manager.applyForTransport(s); system("pause"); break;
        case 3: manager.viewMyRegistration(s->getUserID()); system("pause"); break;
        case 4: manager.cancelRegistration(s->getUserID()); system("pause"); break;
        case 5: manager.generateStudentInvoice(s->getUserID()); system("pause"); break;
        case 6: setColor(10); cout << "\n\t\tLogging out...\n"; system("pause"); setColor(15); break;
        default: setColor(12); cout << "\n\t\tInvalid Choice!\n"; system("pause"); setColor(15);
        }
    } while (choice != 6);
}

void adminMenu(TransportManager& manager)
{
    int choice;
    do
    {
        clearScreen();
        printHeading();
        printSubHeading("ADMINISTRATOR DASHBOARD");

        setColor(8); cout << "\t\t1. "; setColor(15); cout << "Add Vehicle\n";
        setColor(8); cout << "\t\t2. "; setColor(15); cout << "Add Route\n";
        setColor(8); cout << "\t\t3. "; setColor(15); cout << "Assign Vehicle To Route\n";
        setColor(8); cout << "\t\t4. "; setColor(15); cout << "Edit Vehicle\n";
        setColor(8); cout << "\t\t5. "; setColor(15); cout << "Remove Vehicle\n";
        setColor(8); cout << "\t\t6. "; setColor(15); cout << "View Vehicles\n";
        setColor(8); cout << "\t\t7. "; setColor(15); cout << "View Routes\n";
        setColor(8); cout << "\t\t8. "; setColor(15); cout << "Approve / Reject Request\n";
        setColor(8); cout << "\t\t9. "; setColor(15); cout << "Add Driver\n";
        setColor(8); cout << "\t\t10. "; setColor(15); cout << "View Drivers\n";
        setColor(8); cout << "\t\t11. "; setColor(15); cout << "Remove Driver\n";
        setColor(8); cout << "\t\t12. "; setColor(15); cout<<"Remove Route\n";
        setColor(8); cout << "\t\t13. "; setColor(15); cout << "Generate Reports\n";

        setColor(8); cout << "\t\t14. "; setColor(15); cout << "Generate Reports\n";
        setColor(8); cout << "\t\t15. "; setColor(15); cout << "View Vehicle Seat Status\n";

        setColor(8); cout << "\t\t16. "; setColor(15); cout << "Apply Late Fine\n";
        setColor(8); cout << "\t\t17. "; setColor(15); cout << "View Registered Students\n";
        setColor(8); cout << "\t\t18. "; setColor(12); cout << "Logout\n";
        setColor(15);

        choice = getValidInt("\n\t\tEnter Choice: ");
        if (choice == -1) continue;

        switch (choice)
        {
        case 1: manager.createVehicle(); system("pause"); break;
        case 2: manager.createRoute(); system("pause"); break;
        case 3: manager.assignVehicleToRoute(); system("pause"); break;
        case 4: manager.editVehicle(); system("pause"); break;
        case 5: manager.removeVehicle(); system("pause"); break;
        case 6: manager.viewVehicles(); system("pause"); break;
        case 7: manager.viewRoutes(); system("pause"); break;
        case 8: manager.approvePass(); system("pause"); break;
        case 9: manager.createDriver(); system("pause"); break;
        case 10: manager.viewDrivers(); system("pause"); break;
        case 11: manager.assignDriverToRoute(); system("pause"); break;
        case 12:
            manager.removeRoute();
            system("pause");
            break;

        case 13:
            manager.removeDriver();
            system("pause");
            break;

        case 14:
            clearScreen();
            printHeading();
            printSubHeading("REVENUE & REPORTS");
            setColor(10);
            cout << "\t\tTotal Revenue: ";
            setColor(15);
            cout << manager.getTotalRevenue() << endl << endl;
            manager.routeUsageReport();
            system("pause");
            break;
        case 15: manager.viewVehicleSeatStatus(); system("pause"); break;
        case 16: manager.applyLateFineToStudent(); system("pause"); break;
        case 17:
            manager.viewStudents();
            system("pause");
            break;
        case 18: setColor(10); cout << "\n\t\tLogging out...\n"; system("pause"); setColor(15); break;
        default: setColor(12); cout << "\n\t\tInvalid Choice!\n"; system("pause"); setColor(15);
        }
    } while (choice != 18);
}

int main()
{
    TransportManager manager;
    manager.loadStudents();
    manager.loadVehicles();
    manager.loadDrivers();
    manager.loadRoutes();
    manager.loadPasses();

    string restartApp;

    do
    {
        int choice;
        do
        {
            clearScreen();
            printHeading();
            printSubHeading("MAIN MENU");

            setColor(8); cout << "\t\t1. "; setColor(15); cout << "Register User \n";
            setColor(8); cout << "\t\t2. "; setColor(15); cout << "Login\n";
            setColor(8); cout << "\t\t3. "; setColor(12); cout << "Exit\n";
            setColor(15);

            choice = getValidInt("\n\t\tEnter Choice: ");
            if (choice == -1) continue;

            switch (choice)
            {
            case 1:
                manager.registerStudent();
                system("pause");
                break;
            case 2:
            {
                clearScreen();
                printHeading();
                printSubHeading("LOGIN PORTAL");

                setColor(8); cout << "\t\t1. "; setColor(15); cout << "Admin Login\n";
                setColor(8); cout << "\t\t2. "; setColor(15); cout << "Student Login\n";
                int role = getValidInt("\n\t\tEnter Choice: ");

                if (role == -1) break;

                if (role == 1)
                {
                    if (adminLogin()) adminMenu(manager);
                    else system("pause");
                }
                else if (role == 2)
                {
                    Student* s = manager.loginStudent();
                    if (s != nullptr) studentMenu(manager, s);
                    else
                    {
                        setColor(12); cout << "\n\t\tInvalid Student Login!\n"; system("pause"); setColor(15);
                    }
                }
                break;
            }
            case 3:
                manager.saveStudents();
                manager.saveVehicles();
                manager.saveRoutes();
                manager.savePasses();
                manager.saveDrivers();
                break;
            default:
                setColor(12); cout << "\n\t\tInvalid Choice!\n"; system("pause"); setColor(15);
            }
        } while (choice != 3);

        clearScreen();
        printHeading();

        setColor(14);
        cout << "\t\tApplication closed. Press R or r to start: ";
        setColor(15);
        cin >> restartApp;

    } while (restartApp == "r" || restartApp == "R");

    return 0;
}