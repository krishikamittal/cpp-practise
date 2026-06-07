// Program: Demonstration of Shopping details using friend class
// Topic: Friend class in C++
#include<iostream>
using namespace std;

class Cart
{
    char itemName[20];
    int quantity;
    int price;

public:

    void setData(char n[],int q,int p)
    {
        strcpy(itemName,n);
        quantity=q;
        price=p;
    }

    void addItem(int q)
    {
        quantity += q;
    }

    friend void generateBill(Cart c);
};

void generateBill(Cart c)
{
    cout<<"Item = "<<c.itemName<<endl;

    cout<<"Total Bill = "<<c.quantity * c.price;
}

int main()
{
    Cart c1;

    c1.setData("Book",2,500);

    c1.addItem(3);

    generateBill(c1);

    return 0;
}
