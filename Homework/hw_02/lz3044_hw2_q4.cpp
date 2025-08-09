#include <iostream>
using namespace std;

int main(){
    int num1, num2;

    cout << "Please enter two positive integers, separated by a space:" << endl;
    cin >> num1 >> num2;

    int add = num1 + num2;
    int subtract = num1 - num2;
    int multiply = num1 * num2;
    double divide = (double)num1 / (double)num2;
    int div = num1 / num2;
    int mod = num1 % num2;

    cout << num1 << " + " << num2 << " = " << add << "\n"
         << num1 << " - " << num2 << " = " << subtract << "\n"
         << num1 << " * " << num2 << " = " << multiply << "\n"
         << num1 << " / " << num2 << " = " << divide << "\n"
         << num1 << " div " << num2 << " = " << div << "\n"
         << num1 << " mod " << num2 << " = " << mod << endl;

    return 0;
}