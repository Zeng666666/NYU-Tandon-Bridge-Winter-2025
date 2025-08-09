#include <iostream>
#include <cmath>
using namespace std;

void printDivisors (int num) {
    int divisor;
    int sqrtNum = sqrt(num);

    // print smaller divisor
    for (int i = 1; i <= sqrtNum; i++) {
        if (num % i == 0){
            cout << i << " ";
        }
    }

    // print larger divisor by ascending order
    for (int i = sqrtNum; i >= 1; i--) {
        if (num % i == 0 && i != num / i) {
            cout << num / i << " ";
        }
    }

    cout << endl;
}

int main () {
    int num;

    cout << "Please enter a positive integer >= 2: ";
    cin >> num;

    printDivisors (num);

    return 0;
}