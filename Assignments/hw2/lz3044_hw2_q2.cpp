#include <iostream>
using namespace std;

int main(){
    const int QUARTER_VALUE = 25;
    const int DIME_VALUE = 10;
    const int NICKEL_VALUE = 5;
    const int PENNY_VALUE = 1;
    const int DOLLAR_VALUE = 100;
    
    int dollars, cents;

    cout << "Please enter your amount in the format of dollars and cents separated by a space:" << endl;
    cin >> dollars >> cents;

    // Calculate the total cents
    int totalCents = (dollars * DOLLAR_VALUE) + cents;

    // Convert total cents to quarters, dimes, nickels and pennies
    int quarters = totalCents / QUARTER_VALUE;
    int dimes = totalCents % QUARTER_VALUE / DIME_VALUE;
    int nickels = totalCents % QUARTER_VALUE % DIME_VALUE / NICKEL_VALUE;
    int pennies = totalCents % QUARTER_VALUE % DIME_VALUE % NICKEL_VALUE;

    cout << dollars << " dollars and " << cents << " cents are:\n"
         << quarters << " quarters, " << dimes << " dimes, " 
         << nickels << " nickels and " << pennies << " pennies" << endl;

    return 0;
}