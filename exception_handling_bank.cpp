// Program: Demonstration of banking system and ATM using Exception Handling
// Topic: Exception Handling in C++
#include <iostream>
using namespace std;

class BankSystem {
    double balance;
    int pin;

public:
    BankSystem(double b = 1000, int p = 1234) {
        balance = b;
        pin = p;
    }

    void deposit(double amount) {
        try {
            if (amount <= 0)
                throw "Invalid deposit amount!";

            balance += amount;
            cout << "Deposit successful. Balance: " << balance << endl;
        }
        catch (const char* msg) {
            cout << msg << endl;
        }
    }

    void withdraw(int enteredPin, double amount) {
        try {
            if (enteredPin != pin)
                throw "Incorrect PIN!";
            if (amount <= 0)
                throw "Invalid amount!";
            if (amount > balance)
                throw "Insufficient balance!";

            balance -= amount;
            cout << "Withdrawal successful. Balance: " << balance << endl;
        }
        catch (const char* msg) {
            cout << msg << endl;
        }
    }
};

int main() {
    BankSystem b;

    b.deposit(500);
    b.withdraw(1234, 2000); 

    return 0;
}
