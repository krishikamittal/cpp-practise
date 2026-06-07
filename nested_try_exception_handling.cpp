// Program: Demonstration of nested try block using Exception Handling
// Topic: Exception Handling in C++
#include <iostream>
using namespace std;

class ATM {
    int balance;
    int pin;

public:
    ATM(int b = 5000, int p = 1234) {
        balance = b;
        pin = p;
    }

    void withdraw(int enteredPin, int amount) {

        try {
            // OUTER TRY

            if (enteredPin != pin)
                throw "Incorrect PIN!";

            try {
                // INNER TRY

                if (amount <= 0)
                    throw amount;

                if (amount > balance)
                    throw "Insufficient balance!";

                balance -= amount;

                cout << "Withdrawal successful\n";
                cout << "Remaining balance: " << balance << endl;
            }

            // MULTIPLE CATCH BLOCKS
            catch (int x) {
                cout << "Inner Catch: Invalid amount entered: "
                     << x << endl;

                // RETHROW
                throw;
            }

            catch (const char* msg) {
                cout << "Inner Catch: " << msg << endl;

                // RETHROW
                throw;
            }
        }

        catch (const char* msg) {
            cout << "Outer Catch: " << msg << endl;
        }

        catch (int x) {
            cout << "Outer Catch: Invalid amount again: "
                 << x << endl;
        }
    }
};

int main() {

    ATM a;

    a.withdraw(1234, -500);

    return 0;
}
