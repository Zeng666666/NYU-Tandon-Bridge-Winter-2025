#include <iostream>
using namespace std;

/* Version 1: 
   returns the base address of the array (containing the positive numbers), 
   and updates the output parameter outPosArrSize with the array’s logical size.
*/
int* getPosNums1 (int* arr, int arrSize, int& outPosArrSize) {
    // Count positive size
    outPosArrSize = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            outPosArrSize++;
        }
    }

    // New array
    int *posArr = new int[outPosArrSize];

    // Fill positive value
    int index = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            posArr[index] = arr[i];
            index++;
        }
    }

    return posArr;
}

/* Verison 2:
   returns the base address of the array (containing the positive numbers), 
   and uses the pointer outPosArrSizePtr to update the array’s logical size.
*/
int* getPosNums2 (int* arr, int arrSize, int* outPosArrSizePtr) {
    // Count positive size
    *outPosArrSizePtr = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            (*outPosArrSizePtr)++;
        }
    }

    // New array
    int *posArr = new int[*outPosArrSizePtr];

    // Fill positive value
    int index = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            posArr[index] = arr[i];
            index++;
        }
    }

    return posArr;
}

/* Version 3:
   updates the output parameter outPosArr with the base address of the array (containing the positive numbers), 
   and the output parameter outPosArrSize with the array’s logical size.
*/
void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize) {
    // Count positive size
    outPosArrSize = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            outPosArrSize++;
        }
    }

    // New array
    outPosArr = new int[outPosArrSize];

    // Fill positive value
    int index = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            outPosArr[index] = arr[i];
            index++;
        }
    }
}

/* Version 4:
   uses the pointer outPosArrPtr to update the base address of the array (containing the positive numbers), 
   and the pointer outPosArrSizePtr to update the array’s logical size.
*/
void getPosNums4 (int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr) {
    // Count positive size
    *outPosArrSizePtr = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            (*outPosArrSizePtr)++;
        }
    }

    // New array
    *outPosArrPtr = new int[*outPosArrSizePtr];

    // Fill positive value
    int index = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            (*outPosArrPtr)[index] = arr[i];
            index++;
        }
    }
}

void printArray (int arr[], int arrSize);

int main () {
    int testArr[6] = {3, -1, -3, 0, 6, 4};
    int arrSize = 6;

    cout << "Original: 3 -1 -3 0 6 4" << endl;
    cout << "Expected: 3 6 4" << endl;
    cout << endl;

    cout << "Version 1: ";
    int posArrSize1;
    int* posArr1 = getPosNums1(testArr, arrSize, posArrSize1);
    printArray(posArr1, posArrSize1);
    delete [] posArr1;

    cout << "Version 2: ";
    int posArrSize2;
    int* posArr2 = getPosNums2(testArr, arrSize, &posArrSize2);
    printArray(posArr2, posArrSize2);
    delete [] posArr2;

    cout << "Version 3: ";
    int posArrSize3;
    int* posArr3;
    getPosNums3(testArr, arrSize, posArr3, posArrSize3);
    printArray(posArr3, posArrSize3);
    delete [] posArr3;

    cout << "Version 4: ";
    int posArrSize4;
    int* posArr4;
    getPosNums4(testArr, arrSize, &posArr4, &posArrSize4);
    printArray(posArr4, posArrSize4);
    delete [] posArr4;

    return 0;
}

void printArray (int arr[], int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}