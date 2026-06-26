#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <cstdlib>
#include <iomanip>
#include "TransportManager.h"
#include "UIUtils.h"
#include "Student.h"
#include "Vehicle.h"
#include "Route.h"
#include "TransportPass.h"
#include "Driver.h"

using namespace std;

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
        setColor(8); cout << "\t\t11. "; setColor(15); cout << "Assign Driver To Route\n";
        setColor(8); cout << "\t\t12. "; setColor(15); cout << "Remove Route\n";
        setColor(8); cout << "\t\t13. "; setColor(15); cout << "Remove Driver\n";

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
