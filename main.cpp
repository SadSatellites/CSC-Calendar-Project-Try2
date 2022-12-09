#include <iostream>
#include <string>
#include "dayType.h"

using namespace std;

int main() {
//    string DaysofWeek[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday",
//                            "Friday","Saturday"};

    dayType dayTypeObj("Sunday");
    dayTypeObj.printDay();
    cout << "getPreviousDay test: " << dayTypeObj.getPreviousDay() << endl;
    cout << "getNextDay test: " << dayTypeObj.getNextDay() << endl;

    cout << "\nCreating object with Monday..." << endl;
    dayType MondaydayTypeObj("Monday");
    MondaydayTypeObj.printDay();
    cout << endl;
    cout << "Adding three days to Monday object: " << endl;
    MondaydayTypeObj.addDays(3);
    MondaydayTypeObj.printDay();
    cout << endl;
    cout << "Adding thirty days to Monday object: " << endl;
    MondaydayTypeObj.addDays(30);
    MondaydayTypeObj.printDay();
    cout << endl;
    cout << "Adding 365 days to Monday object: " << endl;
    MondaydayTypeObj.addDays(365);
    MondaydayTypeObj.printDay();
    cout << endl;


    return 0;
}
