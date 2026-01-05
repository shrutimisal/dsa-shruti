#include <stdio.h>

int FibonacciSearch(int A[] , int n , int key){
    // Generate Fibonacci Sequence until F(k) >= n 
    int fib2 = 0; // f(k-2);
    int fib1 = 1; // f(k-1);
    int fib = fib1 + fib2;
    
    while(fib < n){
        fib2 = fib1;
        fib1 = fib;
        fib = fib1 + fib2;
    }
    
    // initialzie variable 
    int offset = -1; // offset for the index 
    int i;
    
    while(fib > 1){
         // Calculate the index to be checked
        i = (offset + fib2 < n-1) ? offset + fib2 : n-1; // finding the min index
        
        // Compare with the target element
        if(A[i] == key){
            return i;
        }else if(key > A[i]){
             // Move left in the Fibonacci sequence  k = k-1
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        }else {
           // Move two steps left in the Fibonacci sequence  k = k-2
           fib = fib2;
           fib1 = fib1 - fib2;
           fib2 = fib - fib1;
        }
    }
    
    // checking the last element manually 
    if(fib1 && offset+1 < n && A[offset +1 ] == key){
        return offset + 1; 
    }
    
    return -1; // unseccussfull search
}


int main(){
    int A[] = {5 , 6 , 7 , 8 , 9};
    int n = sizeof(A) / sizeof(A[0]);
    
    int result = FibonacciSearch(A , n , 9);
    
    if(result == -1){
        printf("%d" , result);
    }else{
        printf("%d" , result);
    }
    return 0;   
}