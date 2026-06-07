// Program: Demonstration of circle using Class Templates
// Topic: Templates in C++
#include <iostream>
using namespace std;

template <class T>
class Circle
{
private:
    T rad;

public:
   
    Circle(T r = 0)
    {
        rad = r;
    }

    // Operator +
    Circle operator+(T x)
    {
        return Circle(rad + x);
    }

    // Operator +=
    Circle& operator+=(T x)
    {
        rad += x;
        return *this;
    }

    Circle operator+(Circle c)
    {
        return Circle(rad + c.rad);
    }

    friend ostream& operator<<(ostream &out, Circle c)
    {
        out << c.rad;
        return out;
    }
};

int main()
{
    Circle<int> c1(5), c2;

    c2 += 3; 

    Circle<int> c3 = c1 + c2; 

    Circle<double> c4(1.5);

    c4 += 1.2; 

    cout << c3 << '\n' << c4;

    return 0;
}
