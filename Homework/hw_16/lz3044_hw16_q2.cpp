#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Queue {
    vector<T> data;
    int start;
    int count;
public:
    Queue() : start(0), count(0) {}

    void push(T item) {
        data.push_back(item);
        count++;
    }

    T pop() { 
        if (isEmpty()) {
            cout << "Empty queue!" << endl;
            return T();
        }
        else {
            T value = data[start];
            start++;
            count--;
            
            if (isEmpty()) {
                data.clear();
                start = 0;
            }
    
            return value;
        }
    }

    T top() const {
        if (isEmpty()) {
            cout << "Empty queue!" << endl;
            return T();
        }
        else {
            return data[start]; 
        }
    }

    bool isEmpty() const { return count == 0; }

    int size() const { return count; }

    void clear() {
        data.clear();
        start = 0;
        count = 0;
    }
};
