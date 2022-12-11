#ifndef TRY_TWO_DAYTYPE_H
#define TRY_TWO_DAYTYPE_H

#include <iostream>
#include <string>
using namespace std;

class dayType {
public:
    void setDay(string X);      // Manually sets the day of the week with string
    void printDay();        // Prints the currently set day of the week
    string getDay();        // Returns the current day of the week
    string getNextDay();        // Returns the next day of the week
    string getPreviousDay();        // Returns the previous day of the week
    void addDays(int X);        // Add 'x' number of days to the currently set day of the week. Updates varDoW.

    // Constructor
    dayType(string X);

    dayType();
    // Supply constructor with initial day of the week as string

protected:
    string varDoW;      // Holds the current working day of the week as string
    int varIndexofDoW;      // Holds the index of the current working day of the week from DaysofWeek[7]

};

static string DaysofWeek[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday",
                        "Friday","Saturday"};       // Static array for days of the week

#endif
