// Program: Demonstration of flight system using Exception Handling
// Topic: Exception Handling in C++
#include <iostream>
using namespace std;

class Flight {
    int seats;

public:
    Flight(int s = 100) { seats = s; }

    void book(string name, int age, int tickets) {
        try {
            if (age < 2)
                throw "Infants cannot travel alone!";
            if (tickets <= 0)
                throw "Invalid ticket count!";
            if (tickets > seats)
                throw "Seats not available!";

            seats -= tickets;
            cout << "Booking successful. Seats left: " << seats << endl;
        }
        catch (const char* msg) {
            cout << msg << endl;
        }
    }
};

int main() {
    Flight f;
    f.book("Aman", 1, 2);
}
