// Program: Online food delivery details using Dynamic Memory Allocation
// Topic: Dynamic Memory Allocation (DMA)
#include <iostream>
using namespace std;

class DeliveryDetails;   

class OrderDetails
{
public:
    int* prices;
    int n;
    float tax;
    float discount;

    static int count;

    OrderDetails()
    {
        prices = NULL;
    }

    void input()
    {
        cout << "Number of items: ";
        cin >> n;

        prices = new int[n];

        cout << "Enter item prices:\n";
        for (int i = 0; i < n; i++)
        {
            cin >> prices[i];
        }

        cout << "Enter Tax: ";
        cin >> tax;

        cout << "Enter Discount: ";
        cin >> discount;

        count++;
    }

    int getTotalCost()
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += prices[i];
        }
        return sum;
    }

    friend class DeliveryDetails;

    ~OrderDetails()
    {
        delete[] prices;
    }
};

int OrderDetails::count = 0;

class DeliveryDetails
{
public:
    float chargePerKm;
    float distance;

    void input()
    {
        cout << "Delivery charge per km: ";
        cin >> chargePerKm;

        cout << "Delivery distance (km): ";
        cin >> distance;
    }

    void generateBill(OrderDetails &o)
    {
        int itemCost = o.getTotalCost();
        float deliveryCharge = chargePerKm * distance;
        float netPayable = itemCost + o.tax + deliveryCharge - o.discount;

        cout << "\n----- Final Bill -----\n";
        cout << "Total Item Cost : " << itemCost << endl;
        cout << "Tax             : " << o.tax << endl;
        cout << "Delivery Charge : " << deliveryCharge << endl;
        cout << "Discount        : " << o.discount << endl;
        cout << "Net Payable     : " << netPayable << endl;
    }
};

int main()
{
    int orders;
    cout << "Enter number of orders: ";
    cin >> orders;

    OrderDetails* o = new OrderDetails[orders];
    DeliveryDetails d;

    for (int i = 0; i < orders; i++)
    {
        cout << "\nEnter details for Order " << i + 1 << endl;

        o[i].input();
        d.input();

        cout << "\nBill for Order " << i + 1 << endl;
        d.generateBill(o[i]);
    }

    cout << "\nTotal Orders Processed: "
         << OrderDetails::count << endl;

    delete[] o;
    return 0;
}
