#include <iostream>
using namespace std;

int jumpIt(int board[], int n) {
    if (n == 1) {
        return board[0];
    }
    
    if (n == 2) {
        return board[0] + board[1];
    }

    // Move to adjacent column
    int moveOneCost = board[0] + jumpIt(board + 1, n - 1);
    
    // Jump over adjacent column
    int jumpTwoCost = board[0] + jumpIt(board + 2, n - 2);
    
    if (moveOneCost < jumpTwoCost) {
        return moveOneCost;
    } else {
        return jumpTwoCost;
    }
}

int main() {
    int arr[] = {0, 3, 80, 6, 57, 10};
    int arrSize = 6;
    
    cout << "Lowest cost for board: " << jumpIt(arr, 6) << endl;
    
    return 0;
}