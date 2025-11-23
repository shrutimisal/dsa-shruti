#include <stdio.h>

// Merge two sorted parts of the array
void merge(int arr[], int st, int mid, int end) {
    int temp[100];  // temporary array (big enough for most small cases)
    int i = st;     // starting index of left half
    int j = mid + 1; // starting index of right half
    int k = 0;      // index for temp array

    // Compare and merge
    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    // Copy remaining elements from left half
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    // Copy remaining elements from right half
    while (j <= end) {
        temp[k++] = arr[j++];
    }

    // Copy sorted temp array back to original array
    for (int x = 0; x < k; x++) {
        arr[st + x] = temp[x];
    }
}

void merge_sort(int arr[], int st, int end) {
    if (st < end) {
        int mid = (st + end) / 2;
        merge_sort(arr, st, mid);      // left
        merge_sort(arr, mid + 1, end); // right
        merge(arr, st, mid, end);      // merge
    }
}

void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {12, 31, 35, 8, 32, 37};
    int n = sizeof(arr) / sizeof(arr[0]);

    merge_sort(arr, 0, n - 1);

    printf("Sorted array: ");
    printArr(arr, n);

    return 0;
}
