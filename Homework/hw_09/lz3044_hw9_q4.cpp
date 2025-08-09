#include <iostream>
using namespace std;

void oddsKeepEvensFlip(int arr[], int arrSize) {
    int* temp = new int[arrSize]; 

    // Find odd number and keep the orignal order
    int index = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] % 2 != 0) {
            temp[index] = arr[i];
            index++;
        }
    }

    // Find even number and flip order
    for (int i = arrSize - 1; i >= 0; i--) {
        if (arr[i] % 2 == 0) {
            temp[index] = arr[i];
            index++;
        }
    }

    // Copy temp to arr
    for (int i = 0; i < arrSize; i++) {
        arr[i] = temp[i];
    }
    delete [] temp;
}

void printArr (int arr[], int arrSize);

int main () {
    int testArr[6] = {5, 2, 11, 7, 6, 4};
    int arrSize = 6;

    oddsKeepEvensFlip(testArr, arrSize);
    cout << "Original: 5 2 11 7 6 4" << endl;
    cout << "Expected: 5 11 7 4 6 2" << endl;
    cout << "Call oddsKeepEvensFlip: ";
    printArr(testArr, arrSize);

    return 0;
}

void printArr (int arr[], int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}