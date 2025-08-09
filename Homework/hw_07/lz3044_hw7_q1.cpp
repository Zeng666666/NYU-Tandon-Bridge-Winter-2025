#include <iostream>
#include <string>
using namespace std;

/* This function:
    1. Print a formatted monthly calendar of that month
    2. Return a number 1-7 that represents the day in the week of the last day in that month. 
*/
int printMonthCalender (int numOfDays, int startingDay) {
    // print header
    cout << "Mon\t" << "Tue\t" << "Wed\t" << "Thu\t" << "Fri\t" << "Sat\t" << "Sun" << endl;

    // print spaces before first day 
    for (int i = 1; i < startingDay; i++) {
        cout << "\t";
    }

    // print days
    for (int day = 1; day <= numOfDays; day++) {
        cout << day << "\t";
        
        if ((startingDay + day - 1) % 7 == 0) {
            cout << endl;
        }
    }

    int lastDay = (startingDay + numOfDays - 1) % 7;
    if (lastDay == 0)
        lastDay = 7;
    
    if (lastDay != 7)
        cout << endl;

    return lastDay;
}

/* This function: determining if a year is a leap year. */
bool isLeapYear (int year) {
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

/* This function: convert month from number to string. */
string printMonth (int num) {
    string month;

    switch (num)
    {
    case 1:
        month = "January";
        break;
    case 2:
        month = "February";
        break;
    case 3:
        month = "March";
        break;
    case 4:
        month = "April";
        break;
    case 5:
        month = "May";
        break;
    case 6:
        month = "June";
        break;
    case 7:
        month = "July";
        break;
    case 8:
        month = "August";
        break;
    case 9:
        month = "September";
        break;
    case 10:
        month = "October";
        break;
    case 11:
        month = "November";
        break;
    case 12:
        month = "December";
        break;
    }

    return month;
}

/* The function use the functions printMonthCalender (int numOfDays, int startingDay) 
   to print a formatted yearly calendar of that year.
*/
void printYearCalender (int year, int startingDay) {
    int numOfDays;
    int lastDay;

    for (int i = 1; i <= 12; i++) {
        // the number of days in the month
        if (i == 2) {
            if (isLeapYear(year))
                numOfDays = 29;
            else
                numOfDays = 28;
        }   
        else if ( i == 4 || i == 6 || i == 9 || i == 11) {
            numOfDays = 30;
        }
        else {
            numOfDays = 31;
        }

        // print header
        cout << printMonth(i) << " " << year << endl;

        // print month calender
        lastDay = printMonthCalender(numOfDays, startingDay);
        cout << endl;

        if (lastDay == 7)
            startingDay = 1;
        else
            startingDay = lastDay + 1;
    }
}

int main () {
    int year;
    int startingDay;

    cout << "Enter an integer that represents a year (e.g. 2016): " << endl;
    cin >> year;

    cout << "Enter a number 1-7 that represents the day in the week of 1/1 in that year\n" 
         << "(1 for Monday, 2 for Tuesday, 3 for Wednesday, etc.): " << endl;
    cin >> startingDay;

    printYearCalender(year, startingDay);

    return 0;
}