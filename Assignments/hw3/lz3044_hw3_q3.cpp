#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, c;

    cout << "Please enter value of a: ";
    cin >> a;
    cout << "Please enter value of b: ";
    cin >> b;
    cout << "Please enter value of c: ";
    cin >> c;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);

    // Calculate by formula
    double discriminant = b * b - 4 * a * c;

    if (a == 0) {
        if (b == 0 && c == 0) {
            cout << "This equation has infinite number of solutions" << endl;
        }
        else if (b == 0) {
            cout << "This equation has no solution" << endl;
        }
        else {
            double x = (- c) / b;
            cout << "This equation has a single real solution x = " << x << endl;
        }
    }
    else {
        if (discriminant < 0) {
            cout << "This equation has no real solution" << endl;
        }
        else if (discriminant == 0) {
            double x = (- b) / (2 * a);
            cout << "This equation has a single real solution x = " << x << endl;
        }
        else {
            double x1 = (- b + sqrt(discriminant)) / (2 * a);
            double x2 = (- b - sqrt(discriminant)) / (2 * a);
            cout << "This equation has two real solutions x1 = " << x1 << ", x2 = " << x2 << endl;
        }
    }
    
    return 0;
}