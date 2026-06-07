// Program: Demonstration of marks using Operator Overloading
// Topic: Operator Overloading in C++
#include <iostream>
using namespace std;

class Marks {
    int score;

public:
    Marks(int s=0) {
        score = s;
    }

    friend bool operator>(Marks m1, Marks m2);
    friend bool operator<(Marks m1, Marks m2);
};

bool operator>(Marks m1, Marks m2) {
    return m1.score > m2.score;
}

bool operator<(Marks m1, Marks m2) {
    return m1.score < m2.score;
}

int main() {
    Marks s1(85), s2(75);

    if (s1 > s2)
        cout << "Student 1 scored more";
    else
        cout << "Student 2 scored more";

    return 0;
}
