//1. Given an ordered array of distinct integer numbers, return an element whose value is equal to its index, or -1 if none is found with those conditions. 

#include <iostream>
using namespace std;

 
int distinctInteger(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == i)
            return i;
    }
 
    
    return -1;
}
 

int main()
{
    int arr[] = { -3, 0, 2, 34 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Element value is " << distinctInteger(arr, n);
    return 0;
}