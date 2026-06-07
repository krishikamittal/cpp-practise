// Program: Demonstration of Tempertaure conversion using friend class/function
// Topic: Friend function/class in C++
#include<iostream>
using namespace std;

class Fahrenheit;

class Celsius
{
    float tempC;

public:

    void setData(float c)
    {
        tempC=c;
    }

    friend void convert(Celsius c, Fahrenheit f);
};

class Fahrenheit
{
    float tempF;

public:

    void setData(float f)
    {
        tempF=f;
    }

    friend void convert(Celsius c, Fahrenheit f);
};

void convert(Celsius c, Fahrenheit f)
{
    float converted = (c.tempC * 9/5) + 32;

    cout<<"Celsius in Fahrenheit = "<<converted<<endl;

    if(converted > f.tempF)
    {
        cout<<"Converted temperature is higher";
    }
    else
    {
        cout<<"Fahrenheit temperature is higher";
    }
}

int main()
{
    Celsius c1;
    Fahrenheit f1;

    c1.setData(30);

    f1.setData(80);

    convert(c1,f1);

    return 0;
}
