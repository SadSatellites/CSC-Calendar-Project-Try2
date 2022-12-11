#include <iostream>
#include <string>
#include <cassert>
#include <iomanip>
#include "calendarType.h"
using namespace std;

void calendarType::setMonth(int X) {
    firstDate.setMonth(X);
}

void calendarType::setYear(int X) {
    firstDate.setYear(X);
}

int calendarType::returnMonth() {
    return firstDate.getMonth();
}

int calendarType::returnYear() {
    return firstDate.getYear();
}

void calendarType::printCalendar() {
    cout << setw(12) << " ";
    firstDate.printLongMonthYear();
    calendarType::printTopRow();
    calendarType::printDaysInMonth();
}

void calendarType::printTopRow() {
    cout << setw(5) << "Sun " << setw(5) << " Mon " << setw(5)
         << setw(5) << " Tue " << setw(5)
         << setw(5) << " Wed " << setw(5)
         << setw(5) << " Thu " << setw(5)
         << setw(5) << " Fri " << setw(5)
         << setw(5) << " Sat " << setw(5) << endl;
}

void calendarType::printDaysInMonth() {
    int varDaysInMonth = firstDate.daysInCurrentMonth();
    int varTemp = 1;
//    string varFirstDay = "";
    dayType dTObj("Sunday");
    exDateType eDTObj;

    int varSet = 7;
    int varTemp2 = 0;
    for (int i = 0; i < 7; ++i) {       // Gets amount of empty space before first day starts
//        cout << "i val: " << i << endl;
        if (firstDay.getDay() == DaysofWeek[i]) {
            if (i == 0) {
                cout << setw(0) << " ";
            }
            else if (i == 1) {
                cout << setw(2) << " ";
            }
            else {
                if (i == 2) {
                    varTemp2 = 0;
                }
                if (i == 3) {
                    varTemp2 = 1;
                }
                if (i == 4) {
                    varTemp2 = 2;
                }
                if (i == 5) {
                    varTemp2 = 3;
                }
                if (i == 6) {
                    varTemp2 = 6;
                }
                cout << setw(7 + (4 * (i - 2)) + varTemp2) << " ";
            }
            break;
        }
        else {
            dTObj = firstDay;
            }
    }

    int varFlag = 0;
    for (int i = 1; i < (varDaysInMonth + 1) ; ++i) {       // Prints every day in the month
        if (dTObj.getNextDay() == "Monday" && i == 1) {
            cout << setw(3) << varTemp;
            varSet = 5;
            dTObj.setDay(dTObj.getNextDay());
            varFlag = 1;
        }
        if (dTObj.getNextDay() != "Sunday" && varFlag != 1) {
            cout << setw(varSet) << varTemp;
            dTObj.setDay(dTObj.getNextDay());
            varSet = 5;
        }
        else if (dTObj.getNextDay() == "Sunday") {
            cout << setw(5) << varTemp;
            cout << endl;
            varSet = 4;
            dTObj.setDay(dTObj.getNextDay());
        }
        varTemp++;
        varFlag = 0;
    }
    cout << "\n\n" << endl;
}

dayType calendarType::firstDayOfMonth() {
    int varCurrentYear = firstDate.getYear();
    exDateType eDTObj;
    dayType dTObj("Monday");

    for (int i = 1900; i < varCurrentYear; ++i) {       // Full years
        eDTObj.setYear(i);
        if (eDTObj.isLeapYear(i) == 1) {        // If leap-year
            dTObj.addDays(366);
        }
        else {      // If not leap year
            dTObj.addDays(365);
        }
    }
    dTObj.addDays(firstDate.daysPassed() - 1);      // Leftover from beginning of year
    return dTObj;
}

// Constructor without parameters
calendarType::calendarType() {
    firstDate.setDate(1, 1, 1900);
}

// Constructor with parameters
calendarType::calendarType(int X, int Y) {
    assert(X >= 1 && X <= 12 && Y >= 1900);
    firstDate.setDate(1, X, Y);
    firstDay = firstDayOfMonth();
}
