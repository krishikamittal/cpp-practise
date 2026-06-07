// Program: Demonstration of Electricity Bill using friend function
// Topic: Friend Function
#include<iostream>
using namespace std;

class Electricity
{
    char name[20];
    int units;
    float bill;

public:

    void setData(char n[],int u)
    {
        strcpy(name,n);
        units=u;
    }

    void calculateBill()
    {
        bill = units * 5;
    }

    void calculateBill(int extraCharge)
    {
        bill = (units * 5) + extraCharge;
    }

    friend void display(Electricity e);
};

void display(Electricity e)
{
    cout<<"Name = "<<e.name<<endl;
    cout<<"Bill = "<<e.bill;
}

int main()
{
    Electricity e1;

    e1.setData("Krishika",100);

    e1.calculateBill(50);

    display(e1);

    return 0;
}
