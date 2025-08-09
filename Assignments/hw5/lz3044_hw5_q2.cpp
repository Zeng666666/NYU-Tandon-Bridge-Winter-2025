#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int input;
    int rangeLow = 1;
    int rangeHigh = 100;
    int guessTime = 0;
    int leftTime = 5;

    srand(time(0));
    int num = (rand()%100)+1;

    cout << "I thought of a number between 1 and 100! Try to guess it." << endl;

    while ( leftTime > 0) {
        cout << "Range: [" << rangeLow << ", " << rangeHigh << "], Number of guesses left: " << leftTime << endl;
        cout << "Your guess: ";
        cin >> input;
        
        guessTime++;
        leftTime--;

        if (input == num) {
            cout << "Congrats! You guessed my number in " << guessTime << " guesses." << endl;
            break;
        }
        else {
            if (leftTime == 0) {
            cout << "Out of guesses! My number is " << num << endl;
            }
            else {
                if (input < rangeLow) {
                    cout << "Wrong! My number is bigger." << endl;
                }
                else if (input > rangeHigh) {
                    cout << "Wrong! My number is smaller." << endl;
                }
                else if (input > num) {
                    cout << "Wrong! My number is smaller." << endl;
                    rangeHigh = input - 1;
                }
                else { 
                    cout << "Wrong! My number is bigger." << endl;
                    rangeLow = input + 1;
                }
            }
        }
    }
    
    return 0;
}