#include <iostream>
#include <string>
using namespace std;

// Check if a character is a letter
bool isLetter (char c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

// Convert to lowercase
void toLowercase (string& str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] - 'A' + 'a';
        }
    }
}

// Count the numbers of letters in alphabetical order
void countLetters (string str, int numbersOfLetters[26]) {
    for (int i = 0; i < 26; i++) {
        numbersOfLetters[i] = 0;
    }

    toLowercase(str);

    for (int i = 0; i < str.length(); i++) {
        if (isLetter(str[i])) {
            numbersOfLetters[str[i] - 'a']++;
        }
    }
}

// Compare two strings, determine if two strings are anagrams
bool isAnagrams (string str1, string str2) {
    int numberOfLetters1[26];
    int numberOfLetters2[26];

    countLetters(str1, numberOfLetters1);
    countLetters(str2, numberOfLetters2);

    for (int i = 0; i < 26; i++) {
        if (numberOfLetters1[i] != numberOfLetters2[i]) {
            return false;
        }
    }
    return true;
}

int main () {
    string str1;
    string str2;

    cout << "Please enter the first string: " << endl;
    getline(cin, str1);
    cout << "Please enter the second string: " << endl;
    getline(cin, str2);

    if (isAnagrams(str1, str2))
        cout << "They are anagrams." << endl;
    else
        cout << "They are NOT anagrams." << endl;

    return 0;
}