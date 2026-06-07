// Program: Demonstration of wallet count using  Exception Handling
// Topic: Exception Handling in C++
#include <iostream>
using namespace std;

class Wallet {
    double balance;

public:
    Wallet(double b = 1000) { balance = b; }

    void add(double amt) {
        try {
            if (amt <= 0)
                throw "Invalid amount!";

            balance += amt;
            cout << "Balance: " << balance << endl;
        }
        catch (const char* msg) {
            cout << msg << endl;
        }
    }

    void spend(double amt) {
        try {
            if (amt <= 0)
                throw "Invalid amount!";
            if (amt > balance)
                throw "Insufficient balance!";

            balance -= amt;
            cout << "Balance: " << balance << endl;
        }
        catch (const char* msg) {
            cout << msg << endl;
        }
    }
};

int main() {
    Wallet w;
    w.spend(2000);
}
