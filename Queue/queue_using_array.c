#include <stdio.h>
#include <stdlib.h>

//defining structure
struct Queue {
    int size;
    int front;
    int rear;
    int * arr;
};

//creation of queue
struct Queue* createQueue(int size){
    struct Queue* q = (struct Queue*) malloc(sizeof(struct Queue));
    q->size = size;
    q->front= -1;
    q->rear = -1;
    q->arr = (int*)malloc(q->size * sizeof(int));
    return q;
}

//is queue full
int isFull(struct Queue* q){
    return q->rear == q->size-1;
}

//is queue empty
int isEmpty(struct Queue* q){
    return q->front == q->rear;
}

//adding data in the queue
void enqueue(struct Queue* q , int data){
    if(isFull(q)){
        printf("Queue is Full");
    }else{
        q->rear++;
        q->arr[q->rear]=data;
    }
}

//deleting data from the queue
int dequeue(struct Queue* q){
    int val = -1;
    if(isEmpty(q)){
        printf("Queue is Empty");
    }else{
        q->front++;
        val = q->arr[q->front];
    }
    return val;
}

//displaying the queue
void display(struct Queue* q){
    if(isEmpty(q)){
        printf("Queue is Empty");
        return;
    }else{
        printf("Current Linear Queue : ");
        for(int i=q->front+1 ; i <= q->rear ; i++){
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
}

int main(){
    struct Queue* q = createQueue(5);
    enqueue(q,10);
    enqueue(q,20);
    display(q);
    dequeue(q);
    printf("After dequeue \n");
    display(q);
    return 0;
}
