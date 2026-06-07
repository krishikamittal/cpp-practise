// Program: Employee Management using Inheritance
// Topic: Object-Oriented Programming - Inheritance
#include<iostream>
#include<cstring>
using namespace std;

class Employee
{
protected:
    char name[30];
    double salary;

public:
    void setEmployeeDetails()
    {
        cout<<"Enter name: ";
        cin>>name;
    }

    virtual void computeSalary() = 0;

    double getSalary()
    {
        return salary;
    }
};

class FullTime : public Employee
{
    double basic, bonus;

public:
    void setFullTimeDetails()
    {
        cout<<"Enter basic and bonus: ";
        cin>>basic>>bonus;
    }

    void computeSalary()
    {
        salary = basic + bonus;
    }
};

class PartTime : public Employee
{
    int hours;
    double rate;

public:
    void setPartTimeDetails()
    {
        cout<<"Enter hours and rate: ";
        cin>>hours>>rate;
    }

    void computeSalary()
    {
        salary = hours * rate;
    }
};

int main()
{
    Employee *E;
    FullTime F;
    PartTime P;

    int ch;
    cout<<"1.FullTime 2.PartTime: ";
    cin>>ch;

    switch(ch)
    {
        case 1:
            E = &F;
            E->setEmployeeDetails();
            F.setFullTimeDetails();
            E->computeSalary();
            break;

        case 2:
            E = &P;
            E->setEmployeeDetails();
            P.setPartTimeDetails();
            E->computeSalary();
            break;
    }

    cout<<"Salary = "<<E->getSalary();
    return 0;
}
