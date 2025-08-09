#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

const int PIN_LENGTH = 5;
const string ACTUAL_PIN = "12345";

// Function to generate random NUM for digits range of 1,2,3
void generateRandomNum (int num[10]) {
    for (int i = 0; i < 10; i++) {
        num[i] = rand() % 3 + 1;
    }
}

// Function to display the PIN and NUM
void displayPINAndNum(int num[10]) {
    cout << "Please enter your PIN according to the following mapping:" << endl;
    cout << "PIN: 0123456789" << endl;
    cout << "NUM: ";
    for (int i = 0; i < 10; i++) {
        cout << num[i];
    }
    cout << endl;
}

// Function to verify if the user input matches the actual PIN
bool isCorrect(string userInput, string actualPIN, int num[]) {
    if (userInput.length() != actualPIN.length()) {
        return false;
    }
    for (int i = 0; i < actualPIN.length(); ++i) {
        int pinDigit = actualPIN[i] - '0';
        int expected = num[pinDigit];
        if (userInput[i] - '0' != expected) {
            return false;
        }
    }
    return true;
}

int main () {
    srand(time(0));

    int num[10];
    string input;

    generateRandomNum(num);
    displayPINAndNum(num);
    cin >> input;

    if (isCorrect(input, ACTUAL_PIN, num)) {
        cout << "Your PIN is correct" << endl;
    } 
    else {
        cout << "Your PIN is not correct" << endl;
    }

    return 0;
}