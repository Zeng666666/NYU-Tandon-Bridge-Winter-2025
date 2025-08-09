#include <iostream>
#include <cmath>
using namespace std;

int main () {

    // Section a
    cout << "Section a)" << endl;
    
    int length, inputNum, count;
    int currNum = 1;

    cout << "Please enter the length of the sequence: ";
    cin >> length;

    cout << "Please enter a sequence of positive integers: " << endl;

    for (count = 0; count < length; count++) {
        cin >> inputNum;
        currNum *= inputNum;
    }

    double mean = pow(currNum, 1.0 / length);

    cout << "The geometric mean is: " << mean << endl;
    cout << endl;

    // Section b
    cout << "Section b)" << endl;

    bool seenEnd;

    cout << "Please enter a non-empty sequence of positive integers, each one in a separate line. End your sequence by typing -1:" << endl;

    currNum = 1;
    count = 0;
    seenEnd = false;
    
    while (seenEnd == false) {
        cin >> inputNum;
        if (inputNum == -1) {
            seenEnd = true;
        }
        else {
            currNum *= inputNum;
            count++;
        }
    }
    
    mean = pow(currNum, 1.0 / count);

    cout << "The geometric mean is: " << mean << endl;
    cout << endl;

    return 0;
}