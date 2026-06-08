#include "Report.h"
#include <iostream>
#include "Utility.h"
using namespace std;
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