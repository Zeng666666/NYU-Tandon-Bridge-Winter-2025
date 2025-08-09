#include <iostream>
#include <string>
using namespace std;

int main () {
    int n;
    int line, s, a;

    cout << "Please enter a positive integer: ";
    cin >> n;

    // Upper half
    for (line = 0; line < n; line++) {
        for (s = 0; s < line; s++) {
            cout << " ";
        }
        for (a = 0; a < (2 * n - 1) - 2 * s; a++) {
            cout << "*";
        }
        cout << endl;
    }

    // Lower half
    for (line = n - 1; line >= 0; line-- ) {
        for (s = 0; s < line; s++) {
            cout << " ";
        }
        for (a = 0; a < (2 * n - 1) - 2 * s; a++) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}