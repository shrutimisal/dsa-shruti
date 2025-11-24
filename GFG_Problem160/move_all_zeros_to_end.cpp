#include <stdio.h>
#include <iostream>
using namespace std;

void move_zeros(int arr[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {

        if (arr[i] != 0)
        {
            swap(arr[i], arr[count]);
            count++;
        }
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
    return;
}

int main()
{
    int arr[] = {1, 2, 0, 4, 3, 0, 5, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    move_zeros(arr, n);
    printArray(arr, n);
    return 0;
}