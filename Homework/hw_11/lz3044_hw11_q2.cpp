#include <iostream>
using namespace std;

int sumOfSquares (int arr[], int arrSize) {
    if (arrSize == 0) {
        return 0;
    }
    else {
        return arr[arrSize - 1] * arr[arrSize - 1] + sumOfSquares(arr, arrSize - 1);
    }
}

bool isSorted (int arr[], int arrSize) {
    if (arrSize == 0 || arrSize == 1) {
        return true;
    }
    else if (arr[arrSize - 2] > arr[arrSize - 1]) {
        return false;
    }
    else {
        return isSorted(arr, arrSize - 1);
    }
}

int main () {
    int arr[] = {2, -1, 3, 10};
    int arrSize = 4;

    cout << "a. Sum of squares: " << sumOfSquares(arr, arrSize) << endl;
    cout << "b. Is sorted: ";
    if (isSorted(arr, arrSize))
        cout << "true" << endl;
    else 
        cout << "false" << endl;
    
    return 0;
}