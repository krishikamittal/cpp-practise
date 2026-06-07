// Program: patient information using Dynamic Memory Allocation
// Topic: Dynamic Memory Allocation (DMA)
#include <iostream>
using namespace std;

class BillingDepartment;   

class Patient
{
public:
    char* patientName;
    int patientID;
    int daysAdmitted;
    float treatmentCost;

    static int count;

    Patient()
    {
        patientName = new char[20];
    }

    void input()
    {
        cout << "Enter Patient Name: ";
        cin >> patientName;

        cout << "Enter Patient ID: ";
        cin >> patientID;

        cout << "Enter Days Admitted: ";
        cin >> daysAdmitted;

        cout << "Enter Treatment Cost: ";
        cin >> treatmentCost;

        count++;
    }

    void display()
    {
        cout << "Patient Name : " << patientName << endl;
        cout << "Patient ID   : " << patientID << endl;
        cout << "Days Admitted: " << daysAdmitted << endl;
        cout << "Treatment Cost: " << treatmentCost << endl;
        cout << "----------------------" << endl;
    }

    friend class BillingDepartment;

    ~Patient()
    {
        delete[] patientName;
    }
};

int Patient::count = 0;

class BillingDepartment
{
public:
    void applyDiscount(Patient* p, int n)
    {
        for (int i = 0; i < n; i++)
        {
            p[i].treatmentCost = p[i].treatmentCost * 0.8; 
        }
    }
};

int main()
{
    int n;
    cout << "Enter number of patients: ";
    cin >> n;

    Patient* p = new Patient[n];
    BillingDepartment bill;

    for (int i = 0; i < n; i++)
    {
        cout << "\n--- Patient " << i + 1 << " ---\n";
        p[i].input();
    }

    cout << "\nPatient Details Before Insurance:\n";
    for (int i = 0; i < n; i++)
    {
        p[i].display();
    }

    cout << "\nApplying Medical Insurance Discount (20%)...\n";
    bill.applyDiscount(p, n);

    cout << "\nUpdated Patient Bills:\n";
    for (int i = 0; i < n; i++)
    {
        p[i].display();
    }

    cout << "Total number of patients: "
         << Patient::count << endl;

    delete[] p;
    return 0;
}
}
