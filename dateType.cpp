#include "dateType.h"
#include <string>
#include <cassert>
using namespace std;

void dateType::setDate(int X, int Y, int Z) {
    varDay = X;
    varMonth = Y;
    varYear = Z;
    classInvariant(varDay, varMonth, varYear);      // Class invariant to make sure data is clean
}


void dateType::setDay(int X) {
    varDay = X;
    classInvariant(varDay, varMonth, varYear);      // Class invariant to make sure data is clean
}

void dateType::setMonth(int X) {
    varMonth = X;
    classInvariant(varDay, varMonth, varYear);      // Class invariant to make sure data is clean
}

void dateType::setYear(int X) {
    varYear = X;
    classInvariant(varDay, varMonth, varYear);      // Class invariant to make sure data is clean
}

int dateType::getDay() {
    classInvariant(varDay, varMonth, varYear);      // Class invariant to make sure data is clean
    return varDay;
}

int dateType::getMonth() {
    classInvariant(varDay, varMonth, varYear);      // Class invariant to make sure data is clean
    return varMonth;
}

int dateType::getYear() {
    classInvariant(varDay, varMonth, varYear);      // Class invariant to make sure data is clean
    return varYear;
}

bool dateType::isLeapYear(int X) {
    classInvariant(varDay, varMonth, varYear);      // Class invariant to make sure data is clean
    if (varYear % 4 == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

int dateType::daysInMonth(int X, int Y) {
    int varTempMonth = X;
    int varTempYear = Y;

    classInvariant(varDay, varMonth, varYear);      // Class invariant to make sure data is clean
    if (varTempMonth == 2) {        // Handles february in a leap year
        if (varTempYear % 4 == 0) {
            return 29;
        }
        else {
            return 28;
        }
    }

    // If not february && not leap year:
    else if (varTempMonth == 1 || varTempMonth == 3 || varTempMonth == 5 || varTempMonth == 7 ||
            varTempMonth == 8 || varTempMonth == 10 || varTempMonth == 12) {
        return 31;
    }
    else {
        return 30;
    }
}

int dateType::daysInCurrentMonth() {
    classInvariant(varDay, varMonth, varYear);      // Class invariant to make sure data is clean
    return (daysInMonth(varMonth, varYear));
}

void dateType::printDate() {
    classInvariant(varDay, varMonth, varYear);      // Class invariant to make sure data is clean
    cout << "The current date is: " << varMonth << "--" << varDay << "--" << varYear << "." << endl;
}

int dateType::daysPassed() {
    int varNumOfWholeMonths = (varMonth - 1);       // Number of months that have completely passed
    int varDaysFromWholeMonths = 0;     // Number of days from completely passed months
    int varReturn = 0;

//    dateType::printDate();
    for (int i = 0; i < varNumOfWholeMonths; ++i) {
        if (isLeapYear(varYear) == 1 && (i + 1) == 2) {       // Handle February in leap years
            varDaysFromWholeMonths += 29;
        }
        else {      // If not february in a leap year
            varDaysFromWholeMonths += (daysInMonth((i + 1), varYear));
        }
    }

    varReturn = (varDaysFromWholeMonths + (varDay - 1));        // Add passed days from current month
    classInvariant(varDay, varMonth, varYear);      // Class invariant to make sure data is clean

    return varReturn;
}

int dateType::daysRemaining() {
    int varNumOfRemainingMonths = (12 - varMonth);      // Number of whole months left in the year
    int varDaysFromRemainingMonths = 0;
    int varReturn = 0;

//    dateType::printDate();
    for (int i = (varMonth + 1); i <= 12; ++i) {        // i = month of the year being processed
        if ((i + 1) == 2 && isLeapYear(varYear) == 1) {     // Handles February in leap years
            varDaysFromRemainingMonths += 29;
        }
        else {      // If not February in leap year
            varDaysFromRemainingMonths += (daysInMonth((i +1), varYear));
        }
    }

    varReturn = (varDaysFromRemainingMonths + (daysInMonth(varMonth, varYear) - varDay));
    varReturn += 1;     // Include last day of the year in calculation
    classInvariant(varDay, varMonth, varYear);      // Class invariant to make sure data is clean

    return  varReturn;
    //// Note:
    //      This does not include the currently set day.
    //      It includes every day after up to and including the last day of the year.
}

void dateType::addDays(int X) {
    int varInput = X;
    int varAfterRollover = 0;
    int varNumOfYears = 0;
    int varTemp = 0;
    int varDaysIntoResultMonth = 100;
    int varCompletedMonths = 0;


    if (varInput >= daysRemaining()) {      // If input requires a new year
//        cout << "Year roll-over detected. " << endl;
        varNumOfYears = ((varInput / 365) + 1);     // Gets how many years need to be added
        varAfterRollover = (varInput - daysRemaining());        // Gets how many days are left new year
        while (varAfterRollover > 363) {        // Chop off increments of 365 days
            varAfterRollover = varAfterRollover - 365;
        }
        for (int i = 1; i < ((varAfterRollover / 28) + 1); ++i) {       // For every whole month in new year...
            varTemp += daysInMonth(i, varYear + varNumOfYears);     // Add the days of each whole month
        }

//        cout << "varNum of years: " << varNumOfYears << endl;
//        cout << "After year roll-over there are " << varTemp << " days left to add." << endl;
//        cout << "varAfterRollover: " << varAfterRollover << endl;

        varDaysIntoResultMonth = varAfterRollover - varTemp;        // Get number of days into resulting month

//        cout << "varDaysIntoResultMonth: " << varDaysIntoResultMonth << endl;
//        cout << "varTemp: " << varTemp << endl;

        for (int i = 1; i < ((varTemp / 28) + 1) ; ++i) {       // Get how many whole months have passed into new year
            if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12) {
                varCompletedMonths += (varTemp / 31);
            }
            else if (i == 2) {
                varCompletedMonths += 1;
            }
            else {
                varCompletedMonths += (varTemp / 30);
            }
        }

//        cout << "varCompletedMonths: " << varCompletedMonths << endl;

        setDate(varDaysIntoResultMonth, (varCompletedMonths + 1), (varYear + varNumOfYears));
    }

    else if (varInput <= daysRemaining()) {     // If no year roll-over is needed
//        cout << "NO year roll-ver. " << endl;
        int varInputCopy = varInput;
        int varMo = varMonth;

//        cout << "varInputCopy before: " << varInputCopy << endl;
        // This while loop gets the number of whole months offset from the beginning date
        while (varInputCopy > 31) {
            if (varMo == 1 || varMo == 3 || varMo == 5 || varMo == 7 || varMo == 8 || varMo == 10 || varMo == 12) {
                varInputCopy = (varInputCopy - 31);
            }
            else if (varMo == 2) {
                varInputCopy = (varInputCopy - 28);
            }
            else {
                varInputCopy = (varInputCopy - 30);
            }
            varMo++;
//            cout << "varInputCopy in loop: " << varInputCopy << " Month: " << varMo << endl;

        }
//        cout << "varInputCopy after: " << varInputCopy << endl;
        int varResultDay = (varInputCopy + varDay);

        setDate(varResultDay, varMo, varYear);
    }
    classInvariant(varDay, varMonth, varYear);      // Class invariant to make sure data is clean
}

// Class invariant
void dateType::classInvariant(int X, int Y, int Z) {
    //// Comment block below is non-assert way of handling invariant
//    if (Y%4 != 0 && Y == 2 && X > 28) {
//        cout << "\nBad input!" << endl;
//        cout << "Year is not a leap year, can not set day in February above 28!" << endl;
//        cout << "Resetting date..." << endl;
//        setDate(1, 1, 1900);
//    }
//    if (varDay > 31 or varDay < 1) {
//        cout << "\nBad day value!" << endl;
//        cout << "Resetting date..." << endl;
//        setDate(1, 1, 1900);
//    }
//    if (varMonth > 12 or varMonth < 1) {
//        cout << "\nBad month value!" << endl;
//        cout << "Resetting date..." << endl;
//        setDate(1, 1, 1900);
//    }
//    if (varYear < 1900) {
//        cout << "\nBad year value!" << endl;
//        cout << "Resetting date..." << endl;
//        setDate(1, 1, 1900);
//    }

    //// Below is the assert way of handling the class invariant
//    assert(Y%4 != 0 && Y == 2 && X > 28);
//    assert(varDay > 31 or varDay < 1);
    assert(varMonth <= 12);
    assert(varMonth >= 1);
    assert(varYear >= 1900);
}

// Constructor without parameters
dateType::dateType() {
    varDay = 1;
    varMonth = 1;
    varYear = 1900;
}

// Constructor with parameters
dateType::dateType(int X, int Y, int Z) {
    varDay = X;
    varMonth = Y;
    varYear = Z;
    classInvariant(varDay, varMonth, varYear);
}