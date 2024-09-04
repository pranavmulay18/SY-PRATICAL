#include<iostream>
using namespace std;

class Bank {
public:
    float total_amount, deposit_amount, withdrawal_amount;
    int account_number;
    string name;

    void accept() {
        cout << "Enter the name: ";
        cin >> name;
        cout << "Enter the account number: ";
        cin >> account_number;
        cout << "Enter the total amount: ";
        cin >> total_amount;
    }

    void deposit() {
        cout << "Enter the deposit amount: ";
        cin >> deposit_amount;
        total_amount += deposit_amount;
        cout << deposit_amount << " deposited successfully." << endl;
        cout << "Total amount: " << total_amount << endl;
    }

    void withdraw() {
        cout << "Enter the withdrawal amount: ";
        cin >> withdrawal_amount;
        if (withdrawal_amount <= total_amount) {
            total_amount -= withdrawal_amount;
            cout << withdrawal_amount << " withdrawn successfully." << endl;
            cout << "Total amount: " << total_amount << endl;
        } else {
            cout << "Not enough amount." << endl;
        }
    }

    void display() {
        cout << "Name: " << name << "\tAccount: " << account_number << "\tTotal Amount: " << total_amount << endl;
    }
};

int main() {
    Bank b;
    b.accept();
    b.deposit();
    b.withdraw();
    b.display();
    return 0;
}

