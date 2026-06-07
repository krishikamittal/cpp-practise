// Program: patient information using Dynamic Memory Allocation
// Topic: Dynamic Memory Allocation (DMA)
#include <iostream>
using namespace std;

class BillingDepartment;   

class Patient
{
private:
    char* patientName;
    int patientID;
    int daysAdmitted;
    float treatmentCost;

public:
    static int totalPatients;

    // Constructor
    Patient()
    {
        patientName = new char[30];
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

        totalPatients++;
    }

    void display()
    {
        cout << "Patient Name : " << patientName << endl;
        cout << "Patient ID   : " << patientID << endl;
        cout << "Days Admitted: " << daysAdmitted << endl;
        cout << "Treatment Cost: " << treatmentCost << endl;
        cout << "-----------------------" << endl;
    }

    
    friend class BillingDepartment;

    // Destructor
    ~Patient()
    {
        delete[] patientName;
    }
};

int Patient::totalPatients = 0;

class BillingDepartment
{
public:
    void applyInsurance(Patient &p)
    {
        p.treatmentCost = p.treatmentCost * 0.8;   
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

    for (int i = 0; i < n; i++)
    {
        bill.applyInsurance(p[i]);
    }

    cout << "\nUpdated Patient Bills:\n";
    for (int i = 0; i < n; i++)
    {
        p[i].display();
    }

    cout << "Total number of patients: "
         << Patient::totalPatients << endl;

    delete[] p;
    return 0;
}
