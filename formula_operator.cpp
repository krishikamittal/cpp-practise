// Program: Demonstration of formula using Operator Overloading
// Topic: Operator Overloading in C++
#include <iostream>
using namespace std;

class Vector {
    float x, y;

public:
    void input() {
        cin >> x >> y;
    }

    Vector operator*(float t) {
        Vector temp;
        temp.x = x * t;
        temp.y = y * t;
        return temp;
    }

    Vector operator+(Vector v) {
        Vector temp;
        temp.x = x + v.x;
        temp.y = y + v.y;
        return temp;
    }

    void show() {
        cout << x << "x + " << y << "y" << endl;
    }
};

int main() {
    Vector P, V, F;
    float t;

    P.input();
    V.input();
    cin >> t;

    F = P + (V * t);

    F.show();
    return 0;
}
