#include <iostream>
#include <string>
using namespace std;

// Function to check if a character is a letter
bool isLetter (char c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

// Function to check if a character is a digit
bool isDigit (char c) {
    return (c >= '0' && c <= '9');
}

// Function to replace numbers with x
string replaceNumWithX (string str) {
    string result = str;
    int i = 0;

    while (i < result.length()) {
        // when find a digit, check it's a standlone number or a part of word
        if (isDigit(result[i])) {
            int digitStart = i;
            while (i < result.length() && isDigit(result[i])) {
                i++;
            }
            int digitEnd = i - 1;

            // check if it is a part of word
            bool isPartOfWord = (digitStart > 0 && isLetter(result[digitStart - 1])) || (digitEnd < result.length() - 1 && isLetter(result[digitEnd + 1]));
            if (!isPartOfWord) {
                for (int j = digitStart; j <= digitEnd; j++) {
                    result[j] = 'x';
                }
            }
        }
        else {
            i++;
        }
    }

    return result;
}

int main () {
    string input;
    cout << "Please enter a line of text:" << endl;
    getline(cin, input);

    string output = replaceNumWithX (input);
    cout << output << endl;

    return 0;
}