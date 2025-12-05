// Q.Write a function in C for following operations on SLL :
// 1. Insert a node at the end
// 2. Insert a node after a node having value X of SLL
// 3. Count and Display node info of SLL
// 4. Deletion in the beginning
// 5. Minimum element
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* createNode(int val)
{
    struct node* newNode = (struct node*) malloc (sizeof(struct node));
    newNode -> data = val;
    newNode -> next = NULL;
    return newNode;
};

struct node* head = NULL;

void insertAtEnd (int val){
    struct node* newNode = createNode(val);
    if(head == NULL){
        head = newNode;
    }else{
        struct node* temp = head;
        while(temp -> next != NULL){
            temp = temp->next;
        }
        temp -> next = newNode;
    }
}

void insertAfterX (int x , int val){
    if(head == NULL){
        printf("List is empty");
        return;
    }
    struct node* temp = head;
    while(temp!=NULL && temp -> data != x){
            temp = temp->next;
        }
    if(temp == NULL){
        printf("Value doesnt exist \n");
        return;
    }
    struct node* newNode = createNode(val);
    newNode -> next = temp ->next;
    temp -> next = newNode;
}

void deleteAtBeg(){
    if(head == NULL){
        printf("List is empty");
        return;
    }
    struct node* temp = head;
    head = temp->next;
    free(temp);
}

int miniEle(){
    if(head == NULL){
        printf("List is empty");
        return -1;
    }
    struct node* temp = head;
    int min = temp ->data;
    while (temp != NULL){
        if(temp -> data < min){
            min = temp -> data;
        }
        temp = temp -> next;
    }
    return min;
}

void display(){
    struct node* temp = head;
    int count = 0;
    if(head == NULL){
        printf("Linked List is Empty \n");
        return;
    }
    while(temp != NULL){
        printf("%d ", temp ->data);
        temp = temp->next;
        count ++;
    }
    printf("\n");
    printf("Count : %d \n", count);
}

int main(){
    insertAtEnd(25);
    insertAtEnd(56);
    insertAfterX(25,23);
    deleteAtBeg();
    display();
    printf("Minimum element is : %d ", miniEle());
    return 0;
}

