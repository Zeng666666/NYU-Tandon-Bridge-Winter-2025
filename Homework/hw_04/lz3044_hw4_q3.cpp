#include <iostream>
using namespace std;

int main () {
    int inputNum;
    cout << "Enter decimal number:" << endl;
    cin >> inputNum;

    int currNum = inputNum;
    int binaryNum = 0;
    int powerOf10 = 1;

    while (currNum > 0) {
        int remainder = currNum % 2;
        binaryNum += remainder * powerOf10;
        powerOf10 *= 10;
        currNum /= 2;
    }

    cout << "The binary representation of " << inputNum << " is " << binaryNum << endl;

    return 0;
}