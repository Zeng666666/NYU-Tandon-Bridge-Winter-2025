#include <iostream>
using namespace std;

int main() {
    const int FLOOR_ROUND = 1;
    const int CEILING_ROUND = 2;
    const int ROUND = 3;

    double realNum;
    int method;

    cout << "Please enter a Real number:" << endl;
    cin >> realNum;

    cout << "Choose your rounding method:\n"
         << "1. Floor round\n"
         << "2. Ceiling round\n"
         << "3. Round to the nearest whole number" << endl;
    cin >> method;

    // Floor logic
    int floor;
    if (realNum >= 0) {
        floor = int(realNum);
    } else {
        if (realNum == int(realNum)) {
            floor = int(realNum);
        } else {
            floor = int(realNum) - 1;
        }
    }

    // Ceiling logic
    int ceiling;
    if (realNum == int(realNum)) {
        ceiling = int(realNum);
    } else if (realNum > 0) {
        ceiling = int(realNum) + 1;
    } else {
        ceiling = int(realNum);
    }

    // Calculate result
    int result;
    switch (method) {
        case FLOOR_ROUND:
            result = floor;
            break;
        case CEILING_ROUND:
            result = ceiling;
            break;
        case ROUND:
            if (realNum >= 0) {
                result = int(realNum + 0.5);
            } else {
                result = int(realNum - 0.5);
            }
            break;
        default:
            cout << "No matched method." << endl;
            return 1;
    }

    cout << result << endl;

    return 0;
}