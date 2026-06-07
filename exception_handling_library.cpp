// Program: Demonstration of library system using Exception Handling
// Topic: Exception Handling in C++
#include <iostream>
using namespace std;

class Library {
    int books;

public:
    Library(int b = 5) {
        books = b;
    }

    void issueBook(int studentID) {
        try {
            if (studentID <= 0)
                throw "Invalid student ID!";
            if (books == 0)
                throw "No books available!";

            books--;
            cout << "Book issued. Remaining: " << books;
        }
        catch (const char* msg) {
            cout << msg;
        }
    }
};

int main() {
    Library l;
    l.issueBook(0);
    return 0;
}
