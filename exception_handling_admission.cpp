// Program: Demonstration of admission system using Exception Handling
// Topic: Exception Handling in C++
#include <iostream>
using namespace std;

class Admission {
public:
    void checkEligibility(float percentage) {
        try {
            if (percentage < 0 || percentage > 100)
                throw "Invalid percentage!";

            if (percentage < 60)
                throw "Not eligible for admission!";

            cout << "Admission approved";
        }

        catch (const char* msg) {
            cout << "Function catch: " << msg << endl;
            throw;
        }
    }
};

int main() {
    Admission a;

    try {
        a.checkEligibility(45);
    }

    catch (const char* msg) {
        cout << "Main catch: " << msg;
    }
}
