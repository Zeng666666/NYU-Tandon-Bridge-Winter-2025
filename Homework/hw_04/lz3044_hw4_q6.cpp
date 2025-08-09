#include <iostream>
using namespace std;

int main () {
    int n;
    cout << "Enter a positive integer number: ";
    cin >> n;

    for (int num = 1; num <= n; num++) {

        int currNum = num;
        int currDigit;
        int evenCount = 0;
        int oddCount = 0;

        while (currNum > 0){
            currDigit = currNum % 10;
            if (currDigit % 2 == 0) {
                evenCount++;
            }
            else {
                oddCount++;
            }
            currNum /= 10;
        }
        if (evenCount > oddCount) {
            cout << num << endl;
        }
    }   

    return 0;
}