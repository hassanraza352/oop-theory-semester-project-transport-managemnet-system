#pragma once
#include "Student.h"
#include "Vehicle.h"
#include "Route.h"
#include "Driver.h"
#include "Bus.h"
#include "Van.h"
#include "TransportPass.h"

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

