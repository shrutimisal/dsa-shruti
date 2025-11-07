#include <stdio.h>
int partition (int arr[] , int st , int end){
    int idx = st - 1;
    int pivot = arr[end];
    for (int j=st ; j < end; j++){
        if(arr[j] <= pivot){
            idx++;
            int temp = arr[j];
            arr[j] = arr[idx];
            arr[idx] = temp;
        }
    }
    idx++;
    int temp = arr[end];
    arr[end] = arr[idx];
    arr[idx] = temp;
    return idx;
}

void quick_sort(int arr[] , int st , int end){
    if(st < end){
        int pivotIdx = partition(arr , st , end);
        quick_sort(arr , st , pivotIdx - 1); //--> left
        quick_sort(arr , pivotIdx + 1 , end) ;//--> right
    }
}

void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[] = {12,31,34,14,26,10};
    int n = sizeof(arr) / sizeof(arr[0]);
    quick_sort(arr, 0, n-1);
    printf("Sorted array: ");
    printArr(arr, n);
    return 0;
}

/*
Quick Sort Algorithm
--------------------
 Time Complexity:
   - Best Case: O(n log n) → occurs when pivot divides the array into almost equal halves
   - Average Case: O(n log n)
   - Worst Case: O(n^2) → occurs when the array is already sorted or reverse sorted
 Space Complexity:
   - O(log n) due to recursive function calls (stack space)
*/