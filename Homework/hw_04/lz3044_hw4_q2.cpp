#include <iostream>
#include <string>
using namespace std;

int main () {
    const int I_VALUE = 1;
    const int V_VALUE = 5;
    const int X_VALUE = 10;
    const int L_VALUE = 50;
    const int C_VALUE = 100;
    const int D_VALUE = 500;
    const int M_VALUE = 1000;

    int inputNum;
    string romanDigit = "";

    cout << "Enter decimal number:" << endl;
    cin >> inputNum;

    int currNum = inputNum;

    while (currNum >= M_VALUE) {
        romanDigit += "M";
        currNum -= M_VALUE;
    }

    if (currNum >= D_VALUE) {
        currNum -= D_VALUE;
        romanDigit += "D";
    }
    
    int count = 1;
    while (currNum >= C_VALUE && count <= 4) {
        romanDigit += "C";
        currNum -= C_VALUE;
        count++;
    }

    if (currNum >= L_VALUE) {
        currNum -= L_VALUE;
        romanDigit += "L";
    }

    count = 1;
    while (currNum >= X_VALUE && count <= 4) {
        romanDigit += "X";
        currNum -= X_VALUE;
        count++;
    }

    if (currNum >= V_VALUE) {
        currNum -= V_VALUE;
        romanDigit += "V";
    }

    count = 1;
    while (currNum >= I_VALUE && count <= 4) {
        romanDigit += "I";
        currNum -= I_VALUE;
        count++;
    }

    cout << inputNum << " is " << romanDigit << endl;
    
    return 0;
}