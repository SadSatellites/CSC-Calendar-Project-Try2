#include "exDateType.h"
#include <string>
using namespace std;

void exDateType::printLongDate() {
    for (int i = 0; i < 12; ++i) {
        if (varArrayMonths[varMonth] == varArrayMonths[i]) {
            varStringMonth = varArrayMonths[i];
        }
    }
    cout << varStringMonth << " " << varDay << ", " << varYear << endl;
}

void exDateType::printLongMonthYear() {
    for (int i = 0; i < 12; ++i) {
        if (varArrayMonths[varMonth] == varArrayMonths[i]) {
            varStringMonth = varArrayMonths[i];
        }
    }
    cout << varStringMonth << " " << varYear << endl;
}

// Override base class's setDate function
void exDateType::setDate(int X, int Y, int Z) {
    dateType::setDate(X, Y, Z);
    varStringMonth = dateType::getMonth();
}

// Override base class's setMonth function
void exDateType::setMonth(int X) {
    dateType::setMonth(X);
    varStringMonth = dateType::getMonth();
}

// Override base class's setYear function
void exDateType::setYear(int X) {
    dateType::setYear(X);
    dateType::getMonth();
}

// Constructor with no parameters
exDateType::exDateType() {
    dateType::~dateType();
}

// Constructor with parameter
exDateType::exDateType(int X, int Y, int Z) {
    dateType::~dateType();
    dateType::setDate(X, Y, Z);
}