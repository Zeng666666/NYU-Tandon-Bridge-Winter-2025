#include <iostream>
using namespace std;

void printTriangle (int n) {
    if (n == 1) {
        cout << "*" << endl;
    }
    else {
        printTriangle(n - 1);
        for (int i = 1; i <= n; i++) {
            cout << "*";
        }
        cout << endl;
    }
}

void printOppositeTriangles (int n) {
    if (n == 1) {
        cout << "*" << endl;
        cout << "*" << endl;
    }
    else {    
        // Upper triangle
        for (int i = 1; i <= n; i++) {
            cout << "*";
        }
        cout << endl;
    
        // Recursive call
        printOppositeTriangles (n - 1);
    
        // Lower triangle
        for (int i = 1; i <= n; i++) {
            cout << "*";
        }
        cout << endl;
    }
}

void printRuler (int n) {
    if (n == 1) {
        cout << "-" << endl;
    }
    else {
        printRuler (n - 1);

        // Print middle line 
        for (int i = 0; i < n; i++) {
            cout << "-";
        }
        cout << endl;
    
        printRuler (n - 1);
    }
}

int main () {

    cout << "printTriangle(4):" << endl;
    printTriangle (4);
    cout << endl;

    cout << "printOppositeTriangles(4):" << endl;
    printOppositeTriangles (4);
    cout << endl;

    cout << "printRuler(4):" << endl;
    printRuler (4);

    return 0;
}