#include <iostream>
using namespace std;

char SPACE = ' ';

void printShiftedTriangle (int n, int m, char symbol) {
    int i, j;

    for (i = 1; i <= n; i++) {
        // Print left margin (m space) per line
        for (j = 1; j <= m; j++) {
            cout << SPACE;
        }

        // Print shifted triangle space before symbol per line
        for (j = 1; j <= n - i; j++) {
            cout << SPACE;
        }

        // Print shifted triangle symbol per line
        for (j = 1; j <= 2 * i - 1; j++) {
            cout << symbol;
        }

        cout << endl;
    }
}

void printPineTree (int n, char symbol) {
    int sequence, height, margin;

    for (sequence = 1; sequence <= n; sequence++) {
        height = sequence + 1;
        margin = n - sequence;
        printShiftedTriangle(height, margin, symbol);
    }
}

int main () {
    int num;
    char symbol;

    cout << "Enter a positive number of triangles in the pine tree: ";
    cin >> num;
    cout << "Enter a character to fill the pine tree: ";
    cin >> symbol;

    printPineTree (num, symbol);

    return 0;
}