#include "TransportManager.h"
#include "Utility.h"
#include "UIUtils.h"
#include <fstream>
#include <iomanip>
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
