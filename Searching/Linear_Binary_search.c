// Q. Write program for Linear and binary search, state the time complexity of the searches.
#include <stdio.h>
#include <stdlib.h>

void linear_search(int arr[], int size , int element){
    for (int i=0; i<size ; i++){
        if(arr[i]==element){
            printf("Element founded %d at location %d.\n",arr[i],i+1);
            return;
        }
    }
    printf("Element Not found");
}

void binary_search(int arr[], int size , int element){
    int low,mid,high;
    low = 0;
    high = size-1;
    
    while(low <= high){
        mid = (low + high) / 2;
        if(arr[mid]==element){
            printf("Element found %d", arr[mid]);
            return;
        }
        if(arr[mid] < element){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
}
int main(){
    // int arr[6] ={23,52,41,12,36,89};
    // int size = sizeof(arr)/sizeof(int);
    // linear_search(arr,size,52);
    int arr2[6] = {1,2,3,4,5,6};
    int size2 = sizeof(arr2)/sizeof(int);
    binary_search(arr2,size2,2);
    return 0;
}

