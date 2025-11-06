#include <iostream>
using namespace std;

void bubble_sort(int arr[],int n){ // Time complexity : O (n^2)
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

void printArr(int arr[],int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int n = 5;
    int arr[] = {5,3,4,2,1};
    bubble_sort(arr,n);
    printArr(arr,n);
    return 0;
}
