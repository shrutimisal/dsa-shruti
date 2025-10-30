#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

// Push operation
void push(int num) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = num;
}

// Pop operation
int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

int main() {
    int arr[MAX] = {10, 20, 30, 40, 50};
    int reversed[MAX];

    printf("Original Array: ");
    for (int i = 0; i < MAX; i++) {
        printf("%d ", arr[i]);
        push(arr[i]);  // push all elements into stack
    }

    printf("\nReversed Array: ");
    for (int i = 0; i < MAX; i++) {
        reversed[i] = pop();  // pop elements in reverse order
        printf("%d ", reversed[i]);
    }

    printf("\n");
    return 0;
}
