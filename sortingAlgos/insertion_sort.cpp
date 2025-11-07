#include <iostream>
using namespace std;

void insertion_sort(int arr[],int n){ // Time complexity : O (n^2)F
   for(int i=1; i<n; i++){
    int curr = arr[i];
    int prev = i-1;

    while(prev>=0 && arr[prev] > curr){
        arr[prev+1] = arr[prev];
        prev--;
    }
    arr[prev+1] = curr; // placing the curr element in its correct position.
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
    insertion_sort(arr,n);
    printArr(arr,n);
    return 0;
}
