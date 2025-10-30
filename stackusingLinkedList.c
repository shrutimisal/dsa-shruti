#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int isEmpty(struct Node* top){
    return top == NULL;
}

// Function to check if stack is full (linked list version)
int isFull(struct Node* top) {
    // Unlike an array-based stack, a linked list stack is dynamic.
    // Theoretically, it can grow until the system memory is exhausted.
    // But in reality, system memory may run out.

    // Try to allocate memory for a new node
    // If memory allocation fails, malloc returns NULL
    struct Node* p = (struct Node*) malloc(sizeof(struct Node));

    // If p is NULL, it means no memory is available → stack is "full"
    // This is the equivalent of "stack overflow" in array-based stack
    int full = (p == NULL);

    // Free the memory if allocation was successful
    // (We only wanted to check if memory is available)
    if (p != NULL) free(p);

    // Return 1 if stack is full, 0 otherwise
    return full;
}


struct Node* push(struct Node* top, int data){
    if(isFull(top)){
        printf("Stack Overflow");
    }else{
        struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = top;
        top = newNode;
        return newNode;
    }
}

int pop(struct Node** top){
    if(isEmpty(*top)){
        printf("Stack Underflow");
    }else{
        struct Node* temp = *top;
        *top = (*top)->next;
        int val = temp->data;
        free(temp);
        return val;
    }
}

void display(struct Node* top){
    if(isEmpty(top)){
        printf("Stack Empty");
    }else{
        while(top!=NULL){
            printf("%d  ", top->data);
            top= top->next;
        }
    }
    printf("\n");
}

int main(){
    struct Node* top = NULL;
    top = push(top,28);
    top = push(top,27);
    top = push(top,26);
    display(top);
    int element = pop(&top);
    printf("Element deleted : %d \n",element);
    display(top);
    return 0;
}

