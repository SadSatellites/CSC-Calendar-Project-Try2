#ifndef EXDATETYPE_PROJECT_EXDATETYPE_H
#define EXDATETYPE_PROJECT_EXDATETYPE_H

#include <iostream>
#include <string>
#include "dateType.h"

using namespace std;

class exDateType: public dateType {
public:
    void printLongDate();
    void printLongMonthYear();
    void setDate(int X, int Y, int Z);
    void setMonth(int X);
    void setYear(int X);

    // Constructor with no parameters
    exDateType();

    // Constructor with parameters
    exDateType(int X, int Y, int Z);

private:
    string varStringMonth;
};

static string varArrayMonths[13] = { "", "January", "February", "March", "April", "May",
                             "June", "July", "August", "September", "October",
                             "November", "December"};

#endif
