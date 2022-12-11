#ifndef DATETYPE_PROJECT_DATETYPE_H
#define DATETYPE_PROJECT_DATETYPE_H

#include <iostream>
#include <string>
#include <cassert>
using namespace std;

class dateType {
public:
    void setDate(int X, int Y, int Z);
    void setDay(int X);
    void setMonth(int X);
    void setYear(int X);
    int getDay();
    int getMonth();
    int getYear();
    bool isLeapYear(int X);
    int daysInMonth(int X, int Y);
    int daysInCurrentMonth();
    void printDate();
    int daysPassed();
    int daysRemaining();
    void addDays(int X);

    //Constructor with no parameters
    dateType();

    //Constructor with parameters
    dateType(int X, int Y, int Z);

protected:
    int varDay, varMonth, varYear;
    void classInvariant(int X, int Y, int Z);      // Class invariant
};


#endif
