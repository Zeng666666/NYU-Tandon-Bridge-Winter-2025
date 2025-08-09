#include <iostream>
#include <string>
using namespace std;

int main () {
    string dayOfWeek;
    int hour, minute, length;
    char temp;

    cout << "Please enter the day of the week of the call (Mo Tu We Th Fr Sa Su): ";
    cin >> dayOfWeek;
    cout << "Please enter the time the call started (in 24-hour notation, e.g. 13:30): ";
    cin >> hour >> temp >> minute;
    cout << "Please enter the length of the call in minutes: ";
    cin >> length;

    // Match rate
    double rate;
    if (dayOfWeek == "Sa" || dayOfWeek == "Su") {
        rate = 0.15;
    }
    else {
        if ((8 <= hour) && (hour <= 17)) {
            rate = 0.40;
        }
        else {
            rate = 0.25;
        }
    }
    
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    // Calculate cost
    double cost = rate * length;
    cout << "The cost of the call: $" << cost << endl;

    return 0;
}