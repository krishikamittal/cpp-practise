// Program: shapes using Inheritance
// Topic: Object-Oriented Programming - Inheritance
#include<iostream>
using namespace std;

class Shape
{
protected:
    double area;

public:
    virtual void calculateArea() = 0;

    double getArea()
    {
        return area;
    }
};

class Circle : public Shape
{
    double r;

public:
    void setCircle()
    {
        cout<<"Enter radius: ";
        cin>>r;
    }

    void calculateArea()
    {
        area = 3.14 * r * r;
    }
};

class Rectangle : public Shape
{
    double l, b;

public:
    void setRectangle()
    {
        cout<<"Enter length and breadth: ";
        cin>>l>>b;
    }

    void calculateArea()
    {
        area = l * b;
    }
};

int main()
{
    Shape *S;
    Circle C;
    Rectangle R;

    int ch;
    cin>>ch;

    switch(ch)
    {
        case 1:
            S = &C;
            C.setCircle();
            S->calculateArea();
            break;

        case 2:
            S = &R;
            R.setRectangle();
            S->calculateArea();
            break;
    }

    cout<<"Area = "<<S->getArea();
    return 0;
}
