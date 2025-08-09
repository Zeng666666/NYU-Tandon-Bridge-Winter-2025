#include <iostream>
using namespace std;

int fib (int n) {
    int i;
    int a = 1, b = 1, element = 1;
    
    if (n == 1 || n == 2) {
        return element;
    }
    else {
        for (i = 3; i <= n; i++) {
            a = b;
            b = element;
            element = a + b;
        }
        return element;
    }
}

int main () {
    int num;

    cout << "Please enter a positive integer: ";
    cin >> num;
    cout << fib (num) << endl;

    return 0;
}

