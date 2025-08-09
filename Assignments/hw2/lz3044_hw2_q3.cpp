#include <iostream>
using namespace std;

int main(){
    // Time value based on minutes
    const int HOURS_VALUE = 60;
    const int DAYS_VALUE = 1440; // 1 day = 1440 minutes
    
    int daysOfJohn, hoursOfJohn, minsOfJohn, daysOfBill, hoursOfBill, minsOfBill;

    // Input for John
    cout << "Please enter the number of days John has worked: ";
    cin >> daysOfJohn;

    cout << "Please enter the number of hours John has worked: ";
    cin >> hoursOfJohn;

    cout << "Please enter the number of minutes John has worked: ";
    cin >> minsOfJohn;

    // Input for Bill
    cout << "\nPlease enter the number of days Bill has worked: ";
    cin >> daysOfBill;

    cout << "Please enter the number of hours Bill has worked: ";
    cin >> hoursOfBill;

    cout << "Please enter the number of minutes Bill has worked: ";
    cin >> minsOfBill;

    // Calculate the total time
    int totalTime = (daysOfJohn + daysOfBill) * DAYS_VALUE 
                  + (hoursOfJohn + hoursOfBill) * HOURS_VALUE 
                  + (minsOfJohn + minsOfBill); 

    // Convert total time to days, hours and minutes
    int days = totalTime / DAYS_VALUE;
    int hours = totalTime % DAYS_VALUE / HOURS_VALUE;
    int minutes = totalTime % DAYS_VALUE % HOURS_VALUE;

    cout << "\nThe total time both of them worked together is: "  
         << days << " days, " << hours << " hours and " << minutes << " minutes." << endl;

    return 0;
}