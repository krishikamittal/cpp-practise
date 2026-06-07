// Program: Demonstration of railway system using Operator Overloading
// Topic: Operator Overloading in C++
#include <iostream>
using namespace std;

class Passenger {
private:
    string name;
    int trainNumber;
    int seatNumber;
    string travelClass;

public:
    // Overload >> operator for input
    friend istream& operator>>(istream& in, Passenger& p);

    // Overload << operator for output
    friend ostream& operator<<(ostream& out, Passenger p);
};


istream& operator>>(istream& in, Passenger& p) {
    cout << "Name: ";
    getline(in, p.name);

    cout << "Train Number: ";
    in >> p.trainNumber;

    cout << "Seat Number: ";
    in >> p.seatNumber;
    in.ignore();   

    cout << "Travel Class: ";
    getline(in, p.travelClass);

    return in;
}


ostream& operator<<(ostream& out, Passenger p) {
    out << "Passenger Reservation Details:\n";
    out << "--------------------------------\n";
    out << "Name : " << p.name << endl;
    out << "Train Number : " << p.trainNumber << endl;
    out << "Seat Number : " << p.seatNumber << endl;
    out << "Travel Class : " << p.travelClass << endl;
    out << "--------------------------------\n";
    out << "Reservation Confirmed!\n";
    return out;
}

int main() {
    Passenger p;

    cout << "Enter Passenger Details:\n";
    cin >> p;

    cout << endl;
    cout << p;

    return 0;
}
