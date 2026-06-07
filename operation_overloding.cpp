// Program: Demonstration of student details using Operator Overloading
// Topic: Operator Overloading in C++
#include <iostream>
using namespace std;

class Student {
    int id;
    int hours;

public:
    Student(int i, int h) {
        id = i;
        hours = h;
    }

    Student operator+(int h) {
        hours += h;
        return *this;
    }

    Student operator-(int h) {
        hours -= h;
        return *this;
    }

    friend void compare(Student s1, Student s2);
};

void compare(Student s1, Student s2) {
    cout << "Student 1 ID: " << s1.id << " Hours: " << s1.hours << endl;
    cout << "Student 2 ID: " << s2.id << " Hours: " << s2.hours << endl;

    if (s1.hours > s2.hours)
        cout << "Student 1 studied more" << endl;
    else
        cout << "Student 2 studied more" << endl;
}

int main() {
    Student s1(101, 20);
    Student s2(102, 25);

    s1 = s1 + 10;
    s2 = s2 - 5;

    compare(s1, s2);

    return 0;
}
