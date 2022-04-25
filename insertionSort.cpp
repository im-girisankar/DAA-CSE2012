#include <bits/stdc++.h>
using namespace std;
 
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = n-2; i > -1; i--)
    {
        key = arr[i];
        j = i + 1;
 
        while (j <= n-1 && arr[j] < key)
        {
            arr[j-1] = arr[j];
            j = j + 1;
        }
        arr[j-1]=key;
    }
}
 
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
 
int main()
{
    int arr[] = { 1,10,7,4,3 };
    int n = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, n);
    printArray(arr, n);
    return 0;
}
 