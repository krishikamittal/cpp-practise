// Program: Demonstration of sum of number using Class,Function Templates
// Topic: Templates in C++
#include <iostream>
using namespace std;
template <class T>
T largestPairSum(T a, T b, T c)
{
    T sum1 = a + b;
    T sum2 = b + c;
    T sum3 = a + c;

    if(sum1 >= sum2 && sum1 >= sum3)
        return sum1;
    else if(sum2 >= sum1 && sum2 >= sum3)
        return sum2;
    else
        return sum3;
}


template <class T>
void largestPairSum(T arr[], int n, T &max, T &min)
{
    max = arr[0];
    min = arr[0];

    for(int i = 1; i < n; i++)
    {
        if(arr[i] > max)
            max = arr[i];

        if(arr[i] < min)
            min = arr[i];
    }
}

int main()
{
    
    cout << "Largest pair sum: ";
    cout << largestPairSum(3, 1, 2) << endl;

   
    int arr[] = {10, 5, 20, 3, 15};
    int n = sizeof(arr)/sizeof(arr[0]);

    int max, min;

    largestPairSum(arr, n, max, min);

    cout << "Maximum value: " << max << endl;
    cout << "Minimum value: " << min << endl;

    return 0;
}
