#include <iostream>
#include <string>
using namespace std;

int main () {
    const double KILOGRAM = 0.453592;
    const double METTER = 0.0254; 

    // User input
    double weight, height;
    cout << "Please enter weight (in pounds): ";
    cin >> weight;
    cout << "Please enter height (in inches): ";
    cin >> height;

    // Calculate BMI
    double bmi;
    bmi = (weight * KILOGRAM) / ((height * METTER) * (height * METTER));

    // Match weight status
    string status;
    if (bmi < 18.5) {
        status = "Underweight";
    }
    else if ((18.5 <= bmi) && (bmi < 25)) {
        status = "Normal";
    }
    else if ((25 <= bmi) && (bmi < 30)) {
        status = "Overweight";
    }
    else {
        status = "Obese";
    }

    cout << "The weight status is: " << status << endl;

    return 0;
}