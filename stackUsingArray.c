#include <stdio.h>
#include <stdlib.h>

//defining the structure
struct Stack{
    int size;
    int top;
    int * arr;
};

//creating the stack
struct Stack* createStack(){
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->size = 10;
    stack->top = -1;
    stack->arr = (int *) malloc (stack->size * sizeof(int));
    return stack;
}

//If stack is empty = 1 else 0
int isEmpty(struct Stack* stack){
    if(stack->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

//if stack is full = 1 else 0
int isFull(struct Stack* stack){
    if(stack->top == stack->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

//pushing the element on to the stack
void push(struct Stack* stack , int value){
    if(isFull(stack)){
        printf("Stack Overflow");
    }else{
        stack->top++;
        stack->arr[stack->top] = value;
    }
}

// popping the element from the stack
void pop(struct Stack* stack){
    if(isEmpty(stack)){
        printf("Stack Underflow");
    }else{
        stack->arr[stack->top--];
    }
}

//displaying stack elements
void display(struct Stack* stack){
    if(isEmpty(stack)){
        printf("Stack is Empty\n");
    }
    else{
        for(int i = stack->top ; i >= 0 ; i--){
            printf("%d", stack->arr[i]);
        }
    }
}

int main(){
    struct Stack* s = createStack();
    push(s,10);
    display(s);
    pop(s);
    pop(s);
    return 0;
}