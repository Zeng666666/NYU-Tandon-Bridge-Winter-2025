#include <iostream>
using namespace std;

int* findMissing (int arr[], int n, int& resArrSize) {
    // Mark numbers if present in arr[]
    int* temp = new int[n + 1](); // init temp element all to 0

    for (int i = 0; i < n; i++) { // calculate numbers if present
        temp[arr[i]]++;
    }

    // Count the numbers of missing numbers
    resArrSize = 0;
    for (int i = 0; i < n + 1; i++) {
        if (temp[i] == 0) {
            resArrSize++;
        }
    }

    // Create missing array
    int* missingArr = new int[resArrSize];

    // Fill missing number
    int index = 0;
    for (int i = 0; i < n + 1; i++) {
        if (temp[i] == 0) {
            missingArr[index] = i;
            index++;
        }
    }

    delete [] temp;

    return missingArr;
}

int main () {
    int arr[] = {3, 1, 3, 0, 6, 4};
    int n = 6;
    int resArrSize;

    int* findMissingArr = findMissing(arr, n, resArrSize);

    cout << "[";
    for (int i = 0; i < resArrSize; i++) {
        if (i != resArrSize - 1)
            cout << findMissingArr[i] << ", ";
        else
            cout << findMissingArr[i];
    }
    cout << "]" << endl;

    delete [] findMissingArr;

    return 0;
}