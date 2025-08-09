#include <iostream>
#include <vector>
#include <string>
using namespace std;

/* Function for Version 1: Get a sequence of user input
   This function gets the logic size of input sequence and return the input sequence
*/
int* readInputNums (int& inputArrSize) {
    inputArrSize = 0;
    int capacity = 1;
    int* temp = new int[capacity];

    cout << "Please enter a sequence of positive integers, each in a separate line." << endl;
    cout << "End you input by typing -1." << endl;

    int input;
    bool seenEnd = false;
    while (seenEnd == false) {
        if (inputArrSize != capacity) {
            cin >> input;
            if (input == -1) {
                seenEnd = true;
            }
            else {
                temp[inputArrSize] = input;
                inputArrSize++;
            }
        }
        else {
            int* doublingTemp = new int[capacity * 2];
            for (int i = 0; i < capacity; i++) {
                doublingTemp[i] = temp[i];
            }
            delete [] temp;
            temp = doublingTemp;
            capacity *= 2;
        }
    }

    return temp;
}

/* Function for Version 1: Search the target number and display it
   This function gets the target number from user, and the target array and its logic size to compare
*/
void searchTargetNum (int targetNum, int* targetArr, int targetArrSize) {
    cout << "Please enter a number you want to search." << endl;
    cin >> targetNum;

    bool found = false;
    string result;
    for (int i = 0; i < targetArrSize; i++) {
        if (targetArr[i] == targetNum) {
            if (found) {
                result += ", ";
            }
            result += to_string(i + 1) ;
            found = true;
        }
    }

    if (found == true) {
        cout << targetNum << " shows in lines " << result << "." << endl;
    }
    else {
        cout << targetNum << " does not show at all in the sequence." << endl;
    }
}

/* Version 1: without vector
*/
void main1 () {
    int inputArrSize;
    int* targetArr = readInputNums(inputArrSize);

    int targetNum;
    searchTargetNum(targetNum, targetArr, inputArrSize);

    delete [] targetArr;
}

/* Version 2: with vector
*/
void main2 () {
    cout << "Please enter a sequence of positive integers, each in a separate line." << endl;
    cout << "End you input by typing -1." << endl;

    // Get a senquence of user input
    int input;
    bool seenEnd = false;
    vector<int> inputArr;

    while (seenEnd == false) {
        cin >> input;
        if (input == -1) {
            seenEnd = true;
        }
        inputArr.push_back(input);
    }

    // Search the target number and put result in string line
    int targetNum;
    cout << "Please enter a number you want to search." << endl;
    cin >> targetNum;

    bool found = false;
    string result;
    for (int i = 0; i < inputArr.size(); i++) {
        if (inputArr[i] == targetNum) {
            if (found == true) {
                result += ", ";
            }
            result += to_string(i + 1);
            found = true;
        }
    }

    // Display result
    if (found == true) {
        cout << targetNum << " shows in lines " << result << "." << endl;
    }
    else {
        cout << targetNum << " does not show at all in the sequence." << endl;
    }
}

int main () {
    cout << "The verison 1: main1() without vector:" << endl;
    main1();

    cout << endl;
    cout << "The verison 2: main2() with vector:" << endl;
    main2();

    return 0;
}