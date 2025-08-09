#include <iostream>
#include <cmath>
using namespace std;

/* The function takes as an input a positive integer num (≥ 2), 
   and updates two output parameters with the number of num's proper divisors and their sum.
*/
void analyzeDividors (int num, int& outCountDivs, int& outSumDivs) {
    outCountDivs = 1;
    outSumDivs = 1;

    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            // i is a divisor
            outCountDivs++;
            outSumDivs += i;

            // If i is not sqrt(num), then num/i is also a divisor
            if (i != num / i) {
                outCountDivs++;
                outSumDivs += num / i;
            }
        }
    }
}

/* This functions is given positive integer num (≥ 2), 
   and determines if it is perfect number or not.
*/
bool isPerfect (int num) {
    int countDivs, sumDivs;
    analyzeDividors (num, countDivs, sumDivs);

    return sumDivs == num;
}

/* This functions is to find all perfect numbers between 2 and num
*/
void findPerfectNums (int num) {
    cout << "Perfect numbers: ";

    bool found = false;

    for (int i = 2; i <= num; i++) {
        int countDivs, sumDivs;
        analyzeDividors (i, countDivs, sumDivs);
        if (isPerfect(i)) {
            cout << i << " "; 
            found = true;
        }
    }

    if (!found)
        cout << "None found.";

    cout << endl;
}

/* This functions is to find all amicable pairs between 2 and num
*/
void findAmicablePairs(int num) {
    cout << "Pairs of amicable numbers: ";

    bool found = false;

    for (int i = 2; i <= num; i++) {
        int countA, sumA;
        analyzeDividors (i, countA, sumA);

        int divisorsSum = sumA;

        if (divisorsSum <= num && divisorsSum > i) {
            int countB, sumB;
            analyzeDividors (divisorsSum, countB, sumB);
            
            if (sumB == i) {
                cout << "(" << i << ", " << divisorsSum << ") ";
                found = true;
            }
        }
    }

    if (!found) {
        cout << "None found.";
    }
    cout << endl;

} 

int main () {
    int num;

    cout << "Please enter an integer number (>=2): ";
    cin >> num;

    findPerfectNums(num);
    findAmicablePairs(num);

    return 0;
}