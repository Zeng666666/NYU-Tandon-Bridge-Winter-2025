#include <iostream>
using namespace std;

int main () {
    int inputNum;
    
    // Version 1, using a while loop.
    cout << "Section a: while loop" << endl;

    cout << "Please enter a positive integer: ";
    cin >> inputNum;

    int count = 1, even = 2;

    while (count <= inputNum) {
        cout << even << endl;
        even += 2;
        count++;
    }

    // Version 2, using a for loop.
    cout << "Section b: for loop" << endl;
    
    cout << "Please enter a positive integer: ";
    cin >> inputNum;

    for (int i = 1; i <= inputNum; i++) {
        cout << i * 2 << endl;
    }

    return 0;
}