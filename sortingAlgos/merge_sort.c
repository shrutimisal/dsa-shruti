#include <stdio.h>

void merge(int arr[], int st, int mid, int end) {
    int n1 = mid - st + 1;
    int n2 = end - mid;

    // Temporary arrays
    int left[n1], right[n2];

    // Copy data into temporary arrays
    for (int i = 0; i < n1; i++)
        left[i] = arr[st + i];
    for (int j = 0; j < n2; j++)
        right[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = st;

    // Merge the two halves
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of left[], if any
    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    // Copy remaining elements of right[], if any
    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int st, int end) {
    if (st < end) {
        int mid = (st + end) / 2;

        merge_sort(arr, st, mid);
        merge_sort(arr, mid + 1, end);

        merge(arr, st, mid, end);
    }
}

void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
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
