#include <iostream>
using namespace std;

int main(){
    const int QUARTER_VALUE = 25;
    const int DIME_VALUE = 10;
    const int NICKEL_VALUE = 5;
    const int PENNY_VALUE = 1;
    const int DOLLAR_VALUE = 100;

    int quarters, dims, nickels, pennies;

    cout << "Please enter number of coins: \n";

    cout << "# of quarters: ";
    cin >> quarters;

    cout << "# of dimes: ";
    cin >> dims;

    cout << "# of nickels: ";
    cin >> nickels;

    cout << "# of pennies: ";
    cin >> pennies;
    
    // Calculate the total cents
    int totalCents = (quarters * QUARTER_VALUE) + (dims * DIME_VALUE) + (nickels * NICKEL_VALUE) + (pennies * PENNY_VALUE);

    // Convert total cents to dooloars and remaining cents
    int dollars = totalCents / DOLLAR_VALUE;
    int remainingCents = totalCents % DOLLAR_VALUE;

    cout << "The total is " << dollars << " dollars and " << remainingCents << " cents" <<endl;

    return 0;
}