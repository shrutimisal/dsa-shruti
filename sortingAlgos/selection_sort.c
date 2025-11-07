#include <stdio.h>

void selection_sort(int arr[], int n ){
    for(int i=0; i<n-1; i++){
        int smallestIndex = i;
        for(int j = i+1 ; j<n; j++){
            if(arr[j] < arr[smallestIndex]){
                smallestIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[smallestIndex];
        arr[smallestIndex] = temp;
    }
}

void printArr(int arr[] , int n){
    for(int i=0 ; i<n; i++){
        printf("%d " , arr[i]);
    }
    printf("\n");
}

int main(){
    int n = 5;
    int arr[] ={ 5,4,2,3,1};
    selection_sort(arr,n);
    printArr(arr,n);
    return 0;
}