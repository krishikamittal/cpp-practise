// Program: Demonstration of rethrow using Exception Handling
// Topic: Exception Handling in C++
#include <iostream>
using namespace std;

class Student {
public:
    void checkMarks(int marks) {
        try {
            if (marks < 0 || marks > 100)
                throw "Invalid marks!";

            cout << "Marks accepted";
        }

        catch (const char* msg) {
            cout << "Function catch: " << msg << endl;

            throw;
        }
    }
};

int main() {
    Student s;

    try {
        s.checkMarks(120);
    }

    catch (const char* msg) {
        cout << "Main catch: " << msg;
    }

    return 0;
}
