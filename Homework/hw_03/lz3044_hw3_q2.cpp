#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    int graduationYear, currentYear;

    // Get user input
    cout << "Please enter your name: ";
    cin >> name;

    cout << "Please enter your graduation year: ";
    cin >> graduationYear;

    cout << "Please enter current year: ";
    cin >> currentYear;

    // Calculate status
    string status;
    if (graduationYear - currentYear <= 0) {
        status = "Graduated";
    } 
    else if (graduationYear - currentYear == 1) {
        status = "Senior";
    } 
    else if (graduationYear - currentYear == 2) {
        status = "Junior";
    } 
    else if (graduationYear - currentYear == 3) {
        status = "Sophomore";
    } 
    else if (graduationYear - currentYear == 4) {
        status = "Freshman";
    } 
    else {
        status = "student Not in collage yet";
    }

    // Display result
    cout << name << ", you are a " << status << endl;
    
    return 0;
}