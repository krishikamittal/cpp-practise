// Program: Demonstration of STL Containers and Operations
// Topic: Standard Template Library (STL) in C++
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    vector<int> A;

    int Q;
    cin >> Q;

    for(int i=0; i<Q; i++)
    {
        char ch;
        cin >> ch;

        if(ch == 'a')
        {
            int x;
            cin >> x;

            A.push_back(x);
        }

        if(ch == 'b')
        {
            sort(A.begin(), A.end());
        }

        if(ch == 'c')
        {
            reverse(A.begin(), A.end());
        }

        if(ch == 'd')
        {
            cout << A.size() << endl;
        }

        if(ch == 'e')
        {
            for(int j=0; j<A.size(); j++)
            {
                cout << A[j] << " ";
            }

            cout << endl;
        }

        if(ch == 'f')
        {
            sort(A.begin(), A.end(), greater<int>());
        }
    }
}
