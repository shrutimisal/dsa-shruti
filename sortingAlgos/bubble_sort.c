#include <stdio.h>
#include <stdbool.h>

void bubble_sort(int arr[] , int n){
    for(int i=0 ; i<n-1; i++){
        bool isSwap = false;
        for(int j=0 ; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                isSwap = true;
            }
        }
        // Optimization: If no swap happened, the array is already sorted
        if(!isSwap) {
            return;
        }
    }
}

void printArr(int arr[] , int n){
    for(int i=0 ; i<n; i++){
        printf("%d " , arr[i]);
    }
    printf("\n");
}

int main(){
    int n = 12;
    int arr[] ={ 5,4,2,3,1,10,0,6,12,85,52,93};
    bubble_sort(arr,n);
    printArr(arr,n);
    return 0;
}