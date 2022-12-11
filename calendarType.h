#ifndef CALENDAR_PROJECT_CALENDARTYPE_H
#define CALENDAR_PROJECT_CALENDARTYPE_H

#include <iostream>
#include <string>
#include "dayType.h"
#include "exDateType.h"
using namespace std;

class calendarType {
public:
    void setMonth(int X);
    void setYear(int X);
    int returnMonth();
    int returnYear();
    void printCalendar();
    void printTopRow();
    void printDaysInMonth();

    // Constructor without parameters
    calendarType();


    // Constructor with parameters
    calendarType(int X, int Y);

private:
    dayType firstDayOfMonth();
    exDateType firstDate;
    dayType firstDay;

    void printTitleAndColumns();
    void printMonthsDays();

};


#endif
