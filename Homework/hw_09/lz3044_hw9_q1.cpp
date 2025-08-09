#include <iostream>
#include <string>
using namespace std;

// Check if a character is a letter
bool isLetter (char c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

// Count words in line of string
int countWords (string str) {
    int index = 0;
    int count = 0;

    while (index < str.length()) {
        if (isLetter(str[index])) {
            while (index < str.length() && isLetter(str[index])) {
                index++;
            }
            count++;
        }
        else {
            index++;
        }
    }

    return count;
}

// Covert to lowercase
void toLowercase (string& str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] - 'A' + 'a';
        }
    }
}

// Calculate numbers of letters
void countLetters (string str) {
    toLowercase(str);

    int numbersOfLetter[26] = {0};

    // Count numbers of letters 
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        if (isLetter(c)) {
            numbersOfLetter[c - 'a']++;
        }
    }

    // Print letters in alphabetical order
    for (int i = 0; i < 26; i++) {
        if (numbersOfLetter[i] > 0) {
            char letter = 'a' + i;
            cout << numbersOfLetter[i] << "\t" << letter << endl;
        }
    }
}

int main () {
    string input;
    cout << "Please enter a line of text:" << endl;
    getline(cin, input);

    cout << countWords(input) << "\twords" << endl;
    countLetters(input);

    return 0;
}