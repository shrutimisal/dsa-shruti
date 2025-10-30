#include <stdio.h>
#include <stdlib.h>

// defining strcuture
struct Stack
{
    int size;
    int top;
    int *arr;
};

// creating the stack
struct Stack *createStack()
{
    struct Stack *st = (struct Stack *)malloc(sizeof(struct Stack));
    st->size = 10;
    st->top = -1;
    st->arr = (int *)malloc(st->size * sizeof(int));
    return st;
}

int isEmpty(struct Stack* st){
    return st->top == -1;
}

int isFull(struct Stack* st){
    return st->top == st->size-1;
}

int peek(struct Stack* st)
{
    if (isEmpty(st)) {
        printf("Stack is empty\n");
        return 1;
    }
    return st->arr[st->top];
}

void push(struct Stack* st , int data){
    if(isFull(st)){
        printf("Stack Overflow , Stack is Full\n");
    }else{
        st->top++;
        st->arr[st->top] = data;
    }
}

int pop(struct Stack* st){
    if(isEmpty(st)){
        printf("Stack Underflow , Stack is Empty\n");
    }else{
        int value = st->arr[st->top];
        st->top--;
        return value;
    }
}

void display(struct Stack* st){
    if(isEmpty(st)){
        printf("Stack is Empty Nothing to display\n");
    }else{
        printf("Printing Stack Values : \n");
        for(int i = st->top ; i>=0 ; i--){
            printf("%d  ", st->arr[i]);
        }
    }
    printf("\n");
}

int main(){
    struct Stack* st = createStack();
    peek(st);
    push(st,5);
    push(st,50);
    push(st,500);
    push(st,5000);
    display(st);
    pop(st);
    display(st);
    printf("Peek value : %d",peek(st));
    return 0;
}