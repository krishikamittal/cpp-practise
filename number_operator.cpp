// Program: Demonstration of greater than or equal to using Operator Overloading
// Topic: Operator Overloading in C++
#include <iostream>
using namespace std;

class Number {
    int x;

public:
    Number(int a=0) {
        x = a;
    }

    bool operator==(Number n) {
        return x == n.x;
    }

    bool operator!=(Number n) {
        return !(x == n.x);
    }
};

int main() {
    Number n1(10), n2(20);

    if (n1 != n2)
        cout << "Not equal";
    else
        cout << "Equal";

    return 0;
}
