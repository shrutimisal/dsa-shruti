#include <stdio.h>
#include <stdlib.h>

// Function to compare two items based on value-to-weight ratio
int compare(const void *a, const void *b) {
    float a1 = (*(float *)a) / (*(float *)a + 1);
    float b1 = (*(float *)b) / (*(float *)b + 1);
    return (b1 - a1);
}

float fractionalKnapsack(float val[], float wt[], int capacity, int n) {
    // Create an array to store value and weight
    float items[n][2];
    for (int i = 0; i < n; i++) {
        items[i][0] = val[i];
        items[i][1] = wt[i];
    }
    
    // Sort items based on value-to-weight ratio in descending order
    qsort(items, n, sizeof(float[2]), compare);
    
    float res = 0.0;
    float currentCapacity = capacity;
    
    // Process items in sorted order
    for (int i = 0; i < n; i++) {
        // If we can take the entire item
        if (items[i][1] <= currentCapacity) {
            res += items[i][0];
            currentCapacity -= items[i][1];
        }
        // Otherwise take a fraction of the item
        else {
            res += (items[i][0] / items[i][1]) * currentCapacity;
            // Knapsack is full
            break;
        }
    }
    return res;
}

int main() {
    float val[] = {60, 100, 120};
    float wt[] = {10, 20, 30};
    int capacity = 50;
    int n = sizeof(val) / sizeof(val[0]);
    printf("%.2f", fractionalKnapsack(val, wt, capacity, n));
    return 0;
}