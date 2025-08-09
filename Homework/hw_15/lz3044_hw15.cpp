#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class PersonList;

// Node class
class Person {
private:
    string name;
    double amountPaid;
    double amountOwed;
    Person* next;

    // Make PersonList a friend
    friend class PersonList; 

public:
    Person(string n, double p) : name(n), amountPaid(p), amountOwed(0.0), next(nullptr) {} 
};

// Linked list class
class PersonList {
private:
    Person* head;

public:
    // Constructor
    PersonList() : head(nullptr) {}

    // Destructor
    ~PersonList() {
        Person* current = head;
        while (current != nullptr) {
            Person* temp = current;
            current = current->next;
            delete temp;
        }
    }

    // Add person to list
    void addPerson(string name, double paid) {
        Person* newPerson = new Person(name, paid);
        if (head == nullptr) {
            head = newPerson;
        }
        else {
            Person* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newPerson;
        }
    }

    // Calculate the average amount
    double calculateAverageAmount() {
        double total = 0;
        int count = 0;
        Person* temp = head;

        while (temp != nullptr) {
            total += temp->amountPaid;
            count++;
            temp = temp->next;
        }

        return (total / count);
    }

    // Calculate owed 
    void calculateAmountOwed() {
        double needToPay = calculateAverageAmount();

        Person* temp = head;
        while (temp != nullptr) {
            temp->amountOwed = temp->amountPaid - needToPay;
            temp = temp->next;
        }
    }

    // Print payment
    void printPayment() {
        // Calcuate balances
        calculateAmountOwed();

        // Separate people into debtors and creditors
        vector<Person*> debtors;
        vector<Person*> creditors;
        Person* current = head;
        while (current != nullptr) {
            if (current->amountOwed < 0) {
                debtors.push_back(current);
            }
            else if (current->amountOwed > 0) {
                creditors.push_back(current);
            }
            else {
                cout << current->name << ", you don't need to do anything" << endl;
            }
            current = current->next;
        }

        // Distribute payment
        int i = 0, j = 0;
        while (i < debtors.size() && j < creditors.size()) {
            double payment = min(-debtors[i]->amountOwed, creditors[j]->amountOwed);

            cout << debtors[i]->name << ", you give " << creditors[j]->name << " $" << payment << endl;
            
            debtors[i]->amountOwed += payment;
            creditors[j]->amountOwed -= payment;
            
            if (debtors[i]->amountOwed == 0) i++;
            if (creditors[j]->amountOwed == 0) j++;
        }

        cout << "In the end, you should all have spent around $" << calculateAverageAmount() << endl;
    }
};

int main() {
    ifstream inFile;
    string filename;
    PersonList list;
    double amount;
    string name;

    cout << "Enter the filename: ";
    cin >> filename;
    inFile.open(filename);

    while (!inFile) {
        cout << "File failed to open!" << endl;
        cout << "Enter the filename: ";
        cin >> filename;
        inFile.clear();
        inFile.open(filename);
    }

    while (inFile >> amount) {
        inFile.ignore(9999, ' ');
        getline(inFile, name);
        list.addPerson(name, amount);
    }

    inFile.close();

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    list.printPayment();

    return 0;
}