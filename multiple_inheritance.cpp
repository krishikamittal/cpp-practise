// Program: student role using Inheritance
// Topic: Object-Oriented Programming - Inheritance
#include <iostream>
#include <string>
using namespace std;


class Student {
protected:
    string name;
    int rollNo;

public:
    void setStudent() {
        cout << "Enter Name and Roll No: ";
        cin >> name >> rollNo;
    }

    void displayStudent() {
        cout << "Name: " << name << endl;
        cout << "Roll No: " << rollNo << endl;
    }
};

// Cricketer Class
class Cricketer : virtual public Student {
protected:
    int runs, wickets;

public:
    void setCricketer() {
        cout << "Enter Runs and Wickets: ";
        cin >> runs >> wickets;
    }

    void displayCricketer() {
        cout << "Runs: " << runs << endl;
        cout << "Wickets: " << wickets << endl;
    }
};

// Footballer Class
class Footballer : virtual public Student {
protected:
    int goals, assists;

public:
    void setFootballer() {
        cout << "Enter Goals and Assists: ";
        cin >> goals >> assists;
    }

    void displayFootballer() {
        cout << "Goals: " << goals << endl;
        cout << "Assists: " << assists << endl;
    }
};

// Derived Class
class StarPerformer : public Cricketer, public Footballer {
    double starPerformerIndex;

public:
    void computeIndex() {
        // Avoid division by zero
        if (runs == 0 || goals == 0) {
            starPerformerIndex = 0;
            return;
        }

        starPerformerIndex =
            ((runs - 1000) / (double)runs) +
            ((goals - 10) / (double)goals);
    }

    double getIndex() {
        return starPerformerIndex;
    }

    void displayIndex() {
        cout << "Star Performer Index: " << starPerformerIndex << endl;
    }

    void displayAll() {
        displayStudent();
        displayCricketer();
        displayFootballer();
        displayIndex();
    }
};


int main() {
    StarPerformer s;
    int choice;

    s.setStudent();

    cout << "Enter:\n1. Cricketer\n2. Footballer\n3. Both\nChoice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            s.setCricketer();
            break;

        case 2:
            s.setFootballer();
            break;

        case 3:
            s.setCricketer();
            s.setFootballer();
            s.computeIndex();
            break;

        default:
            cout << "Invalid choice\n";
            return 0;
    }

    if (choice == 3 && s.getIndex() > 0) {
        cout << "\n--- STAR PERFORMER ---\n";
        s.displayAll();
    } else {
        cout << "\nNot a Star Performer\n";
    }

    return 0;
}
