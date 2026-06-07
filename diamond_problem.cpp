// Program: vehicle choice using Inheritance
// Topic: Object-Oriented Programming - Inheritance
#include <iostream>
using namespace std;

class Vehicle {
protected:
    string brand;
    double price;
public:
    void setVehicle() {
        cin >> brand >> price;
    }
};

class Car : virtual public Vehicle {
protected:
    double mileage;
    int seats;
public:
    void setCar() {
        cin >> mileage >> seats;
    }
};

class Bike : virtual public Vehicle {
protected:
    int engine;
    string type;
public:
    void setBike() {
        cin >> engine >> type;
    }
};

class HybridVehicle : public Car, public Bike {
    double efficiency;
public:
    void compute() {
        efficiency = (mileage / price) + (engine / 1000.0);
    }

    void display() {
        if (efficiency > 1) {
            cout << "Efficient Vehicle\n";
            cout << efficiency << endl;
        } else {
            cout << "Not Efficient\n";
        }
    }
};

int main() {
    HybridVehicle h;
    h.setVehicle();
    h.setCar();
    h.setBike();
    h.compute();
    h.display();
}
