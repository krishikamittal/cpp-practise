#include <iostream>
using namespace std;

class Student
{
public:
    int rollNo;
    char* name;
    float marks;
    static int count;

    Student()
    {
        name = new char[20];
    }

    void input()
    {
        cout << "Enter Roll Number: ";
        cin >> rollNo;

        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter Marks: ";
        cin >> marks;

        count++;
    }

    void display()
    {
        cout << "Roll No: " << rollNo << endl;
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks << endl;
        cout << "-----------------" << endl;
    }

    friend void highestMarks(Student*, int);
};

int Student::count = 0;

void highestMarks(Student* s, int n)
{
    int max = 0;

    for (int i = 1; i < n; i++)
    {
        if (s[i].marks > s[max].marks)
        {
            max = i;
        }
    }

    cout << "Student with Highest Marks:\n";
    cout << "Roll No: " << s[max].rollNo << endl;
    cout << "Name: " << s[max].name << endl;
    cout << "Marks: " << s[max].marks << endl;
}

int main()
{
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    Student* s = new Student[n];

    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter details for Student " << i + 1 << endl;
        s[i].input();
    }

    cout << "\nAll Student Details:\n";
    for (int i = 0; i < n; i++)
    {
        s[i].display();
    }

    highestMarks(s, n);

    int above75 = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i].marks > 75)
            above75++;
    }

    cout << "\nNumber of students scoring more than 75 marks: "
         << above75 << endl;

    cout << "Total number of students: "
         << Student::count << endl;

    delete[] s;
    return 0;
}
