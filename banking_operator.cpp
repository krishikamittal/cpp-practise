// Program: Demonstration of banking system Operator Overloading
// Topic: Operator Overloading in C++
#include <iostream>
using namespace std;

class BankAccount {
private:
    int accNo;
    string name;
    float balance;

public:
    
    BankAccount() {
        accNo = 0;
        name = "Merged";
        balance = 0;
    }

   
    BankAccount(int a, string n, float b) {
        accNo = a;
        name = n;
        if (b >= 0)
            balance = b;
        else
            balance = 0;
    }

    
    void deposit(float amt) {
        if (amt > 0)
            balance += amt;
    }

    void deposit(float cash, float cheque) {
        if (cash >= 0 && cheque >= 0)
            balance += cash + cheque;
    }

    // + operator using BASIC temp object method
    BankAccount operator+(BankAccount b) {
        BankAccount temp;
        temp.balance = balance + b.balance;
        return temp;
    }

    // > operator for comparison
    bool operator>(BankAccount b) {
        return balance > b.balance;
    }

    void display() {
        cout << "Account No: " << accNo << endl;
        cout << "Name: " << name << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    BankAccount acc1(101, "Amit", 5000);
    BankAccount acc2(102, "Neha", 3000);

    acc1.deposit(1000);          
    acc2.deposit(500, 500);     

    BankAccount acc3 = acc1 + acc2;

    cout << "Merged Account Details:" << endl;
    acc3.display();

    if (acc1 > acc2)
        cout << "Account 1 has higher balance";
    else
        cout << "Account 2 has higher balance";

    return 0;
}
}
