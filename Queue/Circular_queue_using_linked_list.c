// Q. Write a program to implement Circular Queue using Linked List.
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* createNode(int val){
    struct node* newNode = (struct node*) malloc (sizeof(struct node));
    newNode -> data = val;
    newNode -> next = NULL;
    return newNode;
}

struct node* front = NULL;
struct node* rear = NULL;

void enqueue (int val){
    struct node* newNode = createNode(val);
    if(front == NULL){
        front = rear = newNode;
        rear -> next = front;
        printf("Element added %d \n", rear -> data);
        return;
    }
    rear -> next = newNode;
    rear = newNode;
    newNode -> next = front;
    printf("Element added %d \n", rear -> data);
}

void dequeue(){
    if(front == NULL){
        printf("Queue is Empty");
    }
    struct node* temp = front;
    if(front == rear){
        front = rear = NULL;
    }else{
    front = front -> next;
    rear -> next = front;
    }
    free(temp);
}

    void display(){
        if(front == NULL){
            printf("Queue is Empty");
        }
        struct node* temp = front;
        do{
            printf("%d ", temp -> data);
            temp = temp -> next;
        }while(temp != front);

        printf("\n");
    }

int main(){
    enqueue(25);
    enqueue(23);
    enqueue(89);
    dequeue();
    display();
    return 0;
}