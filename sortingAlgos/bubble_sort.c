#include <stdio.h>

void bubble_sort(int arr[] , int n){
    for(int i=0 ; i<n-1; i++){
        for(int j=0 ; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
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