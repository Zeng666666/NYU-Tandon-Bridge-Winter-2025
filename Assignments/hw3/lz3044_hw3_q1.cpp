#include <iostream>
using namespace std;

int main() {
    const double DISCOUNT_HALF = 0.5; // Half Off
    const double DISCOUNT_CLUBCARD = 0.9; // Club card 10% off
    double firstPrice, secondPrice, tax;
    char haveClubCard;

    // Get user input
    cout << "Enter price of first item: ";
    cin >> firstPrice;

    cout << "Enter price of second item: ";
    cin >> secondPrice;

    cout << "Does customer have a club card? (Y/N): ";
    cin >> haveClubCard;

    cout << "Enter tax rate, e.g. 5.5 for 5.5% tax: ";
    cin >> tax;

    // Calculate base price
    double basePrice = firstPrice + secondPrice;

    // Calculate two items price, buy one get one half off
    double itemsPrice;
    if (firstPrice <= secondPrice) {
        itemsPrice = (firstPrice * DISCOUNT_HALF) + secondPrice;
    } 
    else {
        itemsPrice = (secondPrice * DISCOUNT_HALF) + firstPrice;
    }
    
    // Club card discount
    if ((haveClubCard == 'y') || (haveClubCard == 'Y')) {
        itemsPrice *= DISCOUNT_CLUBCARD;
    }
    
    // Final price with tax
    double totalPrice = itemsPrice * (1 + (tax / 100));

    // Dispaly result
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);
    cout << "Base price: " << basePrice << "\n"
         << "Price after discounts: " << itemsPrice << endl;
    
    cout.precision(5);
    cout << "Total price: " << totalPrice << endl;

    return 0;
}