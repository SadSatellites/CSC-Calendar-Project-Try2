#include "dayType.h"
#include <string>
#include <iostream>
using namespace std;

void dayType::printDay() {
    cout << "Current day of the week: " << varDoW << endl;
}

string dayType::getDay() {
    return varDoW;
}

string dayType::getNextDay() {
    if (varIndexofDoW == 6) {       // If current day is Saturday (prevent index out of range error)
        return DaysofWeek[0];
    }
    else {
        return DaysofWeek[varIndexofDoW + 1];       // Return next day
    }
}

string dayType::getPreviousDay() {
    if (varIndexofDoW == 0) {       // If current day is Sunday (prevent index out of range error)
        return DaysofWeek[6];
    }
    else {
        return DaysofWeek[varIndexofDoW - 1];       // Return previous day
    }
}

void dayType::addDays(int X) {
    int varInput = X;       // More readable as varInput
    int varNumofWeeks = 0;      // Holds the number of weeks (every 7 days) that can be taken from input
    int varDaySubtract = 0;     // Holds the leftover days after taking out every 7 days
    int varLeftoverDays = 0;        // Holds the number of days to add to current index position

    varNumofWeeks = (varInput / 7);     // Get how many weeks can be taken out of the input
    varDaySubtract = (varNumofWeeks * 7);       // Get how many days can be removed from the input
    varLeftoverDays = (varInput - varDaySubtract);      // Get how many days we need to add to current day of the week

    while (varIndexofDoW + varLeftoverDays > 6) {       // Prevent reading out of range index
      varLeftoverDays = (varLeftoverDays - 7);
    }

    varIndexofDoW = (varIndexofDoW + varLeftoverDays);      // Update index for the day of the week
    varDoW = DaysofWeek[varIndexofDoW];     // Update string variable of the current day of the week
}

// Constructor
dayType::dayType(string X) {
    varDoW = X;     // Assign the string Day of the Week to varDoW
    for (int i = 0; i < 7; ++i) {       // Get the index from the array holding all the days of the week
        if (varDoW == DaysofWeek[i]) {
            varIndexofDoW = i;
        }
    }
}