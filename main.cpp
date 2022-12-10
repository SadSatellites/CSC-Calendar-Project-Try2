#include <iostream>
#include <string>
#include "exDateType.h"

using namespace std;

int main() {
    dateType myDefaultObj = dateType() ;

    cout << "Default constructor printDate: " << endl;
    myDefaultObj.printDate();       // Print date with object from default constructor (no parameters)

    exDateType myObj(2,2,2002);       // Constructor with parameter - February 2, 2001
    cout << "\nConstructor with parameters: February 2, 2002: " << endl;
    cout << "Days passed: " << myObj.daysPassed() << endl;
    cout << "Days remaining: " << myObj.daysRemaining() << endl;

    cout << "\nAdding 115 days to current date... " << endl;
    myObj.addDays(115);
    myObj.printDate();

    cout << "Days in month: " << myObj.daysInCurrentMonth() << endl;

    cout << "\n Invariant test: " << endl;
    exDateType myAssertObj(0, 1, 1900);       // Test creating object with bad day
    myAssertObj.setDate(29, 2, 2001);       // Test setting bad February date in non-leap year
    myAssertObj.setDate(1, 13, 2000);        // Test bad month input
    myAssertObj.setDate(3, 3, 1805);        // Test bad year input
    cout << endl;
    myAssertObj.printDate();

    // exDateType test
    exDateType myexObj;
    cout <<"\nexDateType Test: " << endl;
    myexObj.printLongDate();
    cout << endl;
    myexObj.printLongMonthYear();

    cout << "\nOverride function test: " << endl;
    myexObj.setDate(2, 2, 2000);
    myexObj.printLongDate();
    myexObj.setMonth(3);
    myexObj.printLongDate();
    myexObj.setYear(1998);
    myexObj.printLongDate();

    return 0;
}