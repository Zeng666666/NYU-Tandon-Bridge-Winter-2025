#include <iostream>
#include <string>
using namespace std;

bool isPalindrome (string str) {
    int len = str.length();

    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 -i]) {
            return false;
        }
    }
    
    return true;
}

int main () {
    string input;

    cout << "Please enter a word: ";
    cin >> input;

    if (isPalindrome (input)) 
        cout << input << " is a palindrome" << endl;
    else
        cout << input << " is not a palindrome" << endl;
    
    return 0;
}