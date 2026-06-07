// Program: Demonstration of time in hrs and min using Operator Overloading
// Topic: Operator Overloading in C++
#include <iostream>
using namespace std;

class Time {
    int hrs, min;

public:
    friend istream& operator>>(istream& in, Time& t);
    friend ostream& operator<<(ostream& out, Time t);

    Time operator+(Time t) {
        Time temp;
        temp.min = min + t.min;
        temp.hrs = hrs + t.hrs + (temp.min / 60);
        temp.min %= 60;
        return temp;
    }
};

istream& operator>>(istream& in, Time& t) {
    in >> t.hrs >> t.min;
    return in;
}

ostream& operator<<(ostream& out, Time t) {
    out << t.hrs << " hrs " << t.min << " min";
    return out;
}

int main() {
    Time t1, t2, t3;
    cin >> t1 >> t2;
    t3 = t1 + t2;
    cout << t3;
    return 0;
}
