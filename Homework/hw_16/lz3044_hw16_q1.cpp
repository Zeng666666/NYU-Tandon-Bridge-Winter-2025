#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

// Class stack
template <typename T>
class Stack {
    list<T> data;
public:
    void push(T newItem) { data.push_front(newItem); }
    void pop() { data.pop_front(); }
    T top() const {return *data.begin(); }
    bool isEmpty() const { return data.size() == 0; }
    int size() const {return data.size(); }
    void clear() { data.clear(); }
};

// Helper function: check if a word is standalone "begin" or "end"
bool isStandaloneWord(const string& word, const string& target) {
    if (word.find(target) == string::npos) {
        return false;
    }

    if (word == target) {
        return true;
    }

    size_t pos = word.find(target);
    if (target == "begin" && pos == 0 && !isalpha(word[5])) {
        return true;
    }
    if (target == "end" && pos == word.length() - 3 && (pos == 0 || !isalpha(word[pos - 1]))) {
        return true;
    }
        
    return false;
}

// Symbol balance checker function
bool symbolBalanceChecker(ifstream& inFile) {
    char symbo;
    Stack<char> symboStack;

    // Check begin with beigin
    string word;
    inFile >> word;
    if (!isStandaloneWord(word, "begin")) {
        return false;
    }

    // Clear
    inFile.clear();
    inFile.seekg(0, ios::beg);

    // Check end with end
    string lastWord;
    while (inFile >> word) {
        lastWord = word;
    }
    if (!isStandaloneWord(lastWord, "end")) {
        return false;
    }

    // Clear
    inFile.clear();
    inFile.seekg(0, ios::beg);

    // Check symbo pairs
    bool inSingleQuote = false;
    bool inDoubleQuote = false;

    while (inFile.get(symbo)) {
        // Skip characters inside quotes
        if (symbo == '\'' && !inDoubleQuote) {
            inSingleQuote = !inSingleQuote;
            continue;
        }
    
        if (symbo == '"' && !inSingleQuote) {
            inDoubleQuote = !inDoubleQuote;
            continue;
        }
    
        if (inSingleQuote || inDoubleQuote) {
            continue;
        }

        // Check for symbols
        if (symbo == '(' || symbo == '[' || symbo == '{') {
            symboStack.push(symbo);
        }
        if (symbo == ')') {
            if (symboStack.isEmpty() || symboStack.top() != '(') {
                return false;
            }
            symboStack.pop();
        }
        if (symbo == ']') {
            if (symboStack.isEmpty() || symboStack.top() != '[') {
                return false;
            }
            symboStack.pop();
        }
        if (symbo == '}') {
            if (symboStack.isEmpty() || symboStack.top() != '{') {
                return false;
            }
            symboStack.pop();
        }
    }

    return symboStack.isEmpty();
}

int main() {
    // Create test files to simulate input
    ofstream out1("test1.txt");
    out1 << "begin [{}][] end";
    out1.close();

    ofstream out2("test2.txt");
    out2 << "begin [{}(]) end";
    out2.close();

    ofstream out3("test3.txt");
    out3 << "begin [{}] end []";
    out3.close();

    ofstream out4("test4.txt");
    out4 << "                      begin end";
    out4.close();

    ofstream out5("test5.txt");
    out5 << "begin () () {} {} {{{}}} end                 ";
    out5.close();

    ofstream out6("test6.txt");
    out6 << "#comment begin () end";
    out6.close();

    ofstream out7("test7.txt");
    out7 << "begin () end.";
    out7.close();

    ifstream file1("test1.txt");
    ifstream file2("test2.txt");
    ifstream file3("test3.txt");
    ifstream file4("test4.txt");
    ifstream file5("test5.txt");
    ifstream file6("test6.txt");
    ifstream file7("test7.txt");

    cout << "Test 1 (should be True): " << (symbolBalanceChecker(file1) ? "True" : "False") << endl;
    cout << "Test 2 (should be False): " << (symbolBalanceChecker(file2) ? "True" : "False") << endl;
    cout << "Test 3 (should be False): " << (symbolBalanceChecker(file3) ? "True" : "False") << endl;
    cout << "Test 4 (should be True): " << (symbolBalanceChecker(file4) ? "True" : "False") << endl;
    cout << "Test 5 (should be True): " << (symbolBalanceChecker(file5) ? "True" : "False") << endl;
    cout << "Test 6 (should be False): " << (symbolBalanceChecker(file6) ? "True" : "False") << endl;
    cout << "Test 7 (should be False): " << (symbolBalanceChecker(file7) ? "True" : "False") << endl;

    file1.close();
    file2.close();
    file3.close();
    file4.close();
    file5.close();
    file6.close();
    file7.close();

    return 0;
}