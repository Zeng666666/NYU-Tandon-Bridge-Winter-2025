#include <iostream>
#include <string>
using namespace std;

int main () {
    string firstName, middleName, lastName;

    cout << "Please enter your name:" << endl;
    cin >> firstName >> middleName >> lastName;

    char middleInitial = middleName[0];

    cout << lastName << ", " << firstName << " " << middleInitial << "." << endl;
    
    return 0;
}