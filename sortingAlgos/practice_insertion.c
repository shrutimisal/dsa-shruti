#include <stdio.h>

// void insertion_sort(int arr[], int n){
//     for(int i=1 ; i<n ; i++){
//         int curr = arr[i];
//         int prev = i-1;
//         while(prev >= 0 && arr[prev] > curr){
//             arr[prev+1] = arr[prev];
//             prev--;
//         }
//         arr[prev+1] = curr;
//     }
// }

void selection_sort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        int smallInd = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[smallInd]){
                smallInd = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[smallInd];
        arr[smallInd] = temp;
    }
}

void printArray(int arr[] , int n){
    for(int i=0 ; i<n ; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int n = 6;
    int arr[] ={23,1,10,5,200,6};
    // insertion_sort(arr, n);
    selection_sort(arr, n);
    printArray(arr , n);
}

