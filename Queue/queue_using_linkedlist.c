#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* createNode(int data){
    struct node* newNode = (struct node*) malloc (sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct node* front = NULL;
struct node* rear = NULL;

void enqueue(int data){
    struct node* newNode = createNode(data);
    if(rear == NULL){
        front = rear = newNode;
    }
    else{
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue(){
    if(front == NULL){
        printf("Queue is Empty");
        return;
    }
    struct node* temp = front;
    front = front->next;
    
    if(front == NULL){
        rear = NULL;
    }
    free(temp);
}

void display(){
    if(front == NULL){
        printf("Queue is Empty");
        return;
    }
    struct node* temp = front;
    printf("Queue Elements :");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    dequeue();
    display();
    return 0;
}