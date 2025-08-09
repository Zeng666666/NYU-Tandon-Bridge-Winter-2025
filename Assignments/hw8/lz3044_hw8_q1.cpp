#include <iostream>
using namespace std;

/*This function is given arr and its size, returns the minimum value in arr.*/
int minInArray (int arr[], int arrSize) {
    int min = arr[0];

    for (int i = 1; i < arrSize; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    return min;
}

/*This function is given arr, its size, and a num, prints the index of this num in arr.*/
void locationInArray (int arr[], int arrSize, int num) {
    bool isSeenNum = false;

    for (int i = 0; i < arrSize; i++) {
        if (arr[i] == num) {
            cout << i << " ";
            isSeenNum = true;
        }
    }

    if (isSeenNum == false) {
        cout << "Number is not in the array.";
    }

    cout << endl;
}

int main () {
    int arr[20];

    cout << "Please enter 20 integers separated by a space:" << endl;
    for (int i = 0; i < 20; i++) {
        cin >> arr[i];
    }

    int minValue = minInArray(arr, 20);

    cout << "The minimum value is " << minValue << ", and it is located in the following indices: ";
    locationInArray(arr, 20, minValue);

    return 0;
}