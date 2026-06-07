// Program: Demonstration of movie hall system using Exception Handling
// Topic: Exception Handling in C++
#include <iostream>
using namespace std;

class Movie {
    int seats, booked;

public:
    Movie(int s = 50) {
        seats = s;
        booked = 0;
    }

    void book(int t) {
        try {
            if (t <= 0)
                throw "Invalid tickets!";
            if (t > seats)
                throw "Not enough seats!";

            seats -= t;
            booked += t;
            cout << "Booked successfully\n";
        }
        catch (const char* msg) {
            cout << msg << endl;
        }
    }

    void cancel(int t) {
        try {
            if (t <= 0)
                throw "Invalid tickets!";
            if (t > booked)
                throw "Cannot cancel more than booked!";

            seats += t;
            booked -= t;
            cout << "Cancelled successfully\n";
        }
        catch (const char* msg) {
            cout << msg << endl;
        }
    }
};

int main() {
    Movie m;
    m.book(10);
    m.cancel(20);
}
