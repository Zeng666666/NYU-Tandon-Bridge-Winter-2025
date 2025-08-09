#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

vector<int> divideAndConquer(const vector<int>& data, int start, int end) {
    vector<int> result(2); // result[0] = min value, result[1] = max value.

    // base case 1 item
    if (start == end) {
        result[0] = data[start];
        result[1] = data[end];
        return result;
    }

    // base case 2 items
    if (start + 1 == end) {
        if (data[start] < data[end]) {
            result[0] = data[start];
            result[1] = data[end];
        } else {
            result[0] = data[end];
            result[1] = data[start];
        }
        return result;
    }

    // split array into two halves
    int mid = (start + end) / 2;
    vector<int> left = divideAndConquer(data, start, mid);
    vector<int> right = divideAndConquer(data, mid + 1, end);

    left[0] < right[0] ? result[0] = left[0] : result[0] = right[0];
    left[1] > right[1] ? result[1] = left[1] : result[1] = right[1];

    return result;
}

int main() {
    vector<int> v;
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        v.push_back(rand() % 200 - 100);
    }

    cout << "Test array: ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    vector<int> result = divideAndConquer(v, 0, v.size() - 1);
    cout << "Max: " << result[1] << "; Min: " << result[0] << endl;

    return 0;
}