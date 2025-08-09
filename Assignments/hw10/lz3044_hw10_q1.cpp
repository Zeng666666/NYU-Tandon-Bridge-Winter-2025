#include <iostream>
#include <string>
using namespace std; 

string* createWordsArray (string sentence, int& outWordsArrSize) {
    // Count numbers of words
    outWordsArrSize = 0;
    bool inWord = false;

    for (int i = 0; i < sentence.length(); i++) {
        if (sentence[i] == ' ') {
            inWord = false;
        }
        else if (!inWord) {
            outWordsArrSize++;
            inWord = true;
        }
    }

    // Create new array
    string* outWordsArr = new string[outWordsArrSize];

    // Fill array with words
    int start = 0;
    int end;
    int wordIndex = 0;

    while (start < sentence.length() && sentence[start] == ' ') {
        start++;
    }

    while (start < sentence.length()) {
        if (sentence.find(' ', start) != string::npos) {
            end = sentence.find(" ", start);
        }
        else {
            end = sentence.length();
        }
        outWordsArr[wordIndex] = sentence.substr(start, (end - start)); 
        wordIndex++;
        start = end + 1;
    }

    return outWordsArr;
}

int main () {
    string input;
    cout << "Enter a sentence" << endl;
    getline(cin, input);

    int arrSize;
    string* wordArr = createWordsArray(input, arrSize);

    cout << "[";
    for (int i = 0; i < arrSize; i++) {
        if (i == arrSize - 1) {
            cout << "\"" << wordArr[i] << "\"";
        }
        else {
            cout << "\"" << wordArr[i] << "\", ";
        }
    }
    cout << "]" << endl;

    cout << "outWordsArrSize is update to: " << arrSize << endl;

    delete[] wordArr;

    return 0;
}