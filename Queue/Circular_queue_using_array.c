// Q. Write a program to implement Circular Queue using Arrays.
#include <stdio.h>
#include <stdlib.h>
int arr[6];
int curr_arr_size = 0;
int capacity_of_arr = 6;
int f = -1;
int r = -1;

void push(int arr[], int val){
    if(curr_arr_size == capacity_of_arr){
        printf("Queue is full \n");
        return;
    }
    r = (r+1) % capacity_of_arr;
    arr[r] = val;
    printf("Element added = %d \n", arr[r]);
    if(curr_arr_size == 0){
        f = r;
    }
    curr_arr_size ++;
}

void pop(){
    if(curr_arr_size == 0){
        printf("Queue is Empty \n");
        return;
    }
    printf("Element deleted = %d \n", arr[f]);
    if(curr_arr_size == 1){
        f = -1 ;
        r = -1 ;
    }else{
        f = (f+1) % capacity_of_arr;
    }
    curr_arr_size -- ;
}

void display(int arr[]){
    if(curr_arr_size == 0){
        printf("Queue is Empty \n");
        return;
    }
    int i = f;
    printf("Elements in the Queue : ");
    for (int count = 0 ; count < curr_arr_size; count ++){
        printf("%d ", arr[i]);
        i = (i + 1) % capacity_of_arr;
    }
}


int main(){
    push(arr , 1);
    push(arr , 2);
    push(arr , 3);
    push(arr , 4);
    push(arr , 5);
    push(arr , 6);
    push(arr , 7);
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();
    display(arr);
    return 0;
}