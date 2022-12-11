#include <iostream>
#include <string>
#include "exDateType.h"
#include "dayType.h"
#include "calendarType.h"

using namespace std;

int main() {
    int varInputMonth, varInputYear;

    cout << "What month do you wish to use? (Input 1 - 12)" << endl;
    cin >> varInputMonth;
    cout << "What year do you wish to use? (Input >= 1900)" << endl;
    cin >> varInputYear;

    calendarType myCalType(varInputMonth, varInputYear);
//    myCalType.setMonth(4);
//    myCalType.setYear(1903);
    cout << "Return month: " << myCalType.returnMonth() << endl;
    cout << "Return year: " << myCalType.returnYear() << endl;

    cout << endl;
    myCalType.printCalendar();

    return 0;
}