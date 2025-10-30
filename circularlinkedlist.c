#include <stdio.h>
#include <stdlib.h>

// defining node structure
struct node {
    int data;
    struct node* next;
};

// creating the node
struct node* createNode(int data){
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct node* head = NULL; // Globally declared

// inserting the element at beg in circular linked list
void insertAtBeg(int data){
    struct node* newNode = createNode(data);
    if(head == NULL){
        head = newNode;
        newNode->next = head;
    }else {
        struct node* temp = head;
        while(temp->next!=head){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
}

// inserting the element at end
void insertAtEnd(int data){
    struct node* newNode = createNode(data);
    if(head == NULL){
        head = newNode;
        newNode->next = head;
    }else{
        struct node* temp = head;
        while(temp->next!=head){
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next= newNode;
    }
}

// inserting the element at specific position
void insertAtPos(int data , int pos){
    struct node* newNode = createNode(data);
    // case1 : nothing in the list
    if(head == NULL){
        head = newNode;
        newNode->next = head;
        return;
    }
    // case2 : if position is 0
    if(pos == 0){
        struct node* temp = head;
        while(temp->next!=head){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
        return;
    }
    // Case 3: Insert at given position
    struct node* temp = head;
    for(int i = 0; i < pos-1 && temp->next!=head ; i++){
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next= newNode;
}

//deleting an element from beginning
void deleteFromBeg(){
    if(head == NULL){
        printf("List is empty \n");
        return;
    }
    // case : if only one element
    else if(head->next == head){
        free(head);
        head = NULL;
    }
    else{
        struct node* temp = head;
        while(temp->next!=head){
            temp = temp->next;
        }
        temp->next = head->next;
        struct node* nodeToDelete = head;
        head = head->next;
        free(nodeToDelete);
    }
}

//deleting an element from end
void deleteFromEnd(){
    if(head == NULL){
        printf("List is Empty");
        return;
    }
    else if(head->next == head){
        free(head);
        head = NULL;
    }
    else{
        struct node* temp = head;
        while(temp->next->next != head){
            temp = temp->next;
        }
        struct node* nodeTodelete = temp->next;
        temp->next = head;
        free(nodeTodelete);
    }
}

// deleting from specific position
void deleteFromPos(int pos){
    if(head == NULL){
        printf("List is Empty");
        return;
    }
    else if(pos == 0){
        //delete from beginning logic
        struct node* temp = head;
        while(temp->next!=head){
            temp = temp->next;
        }
        temp->next = head->next;
        struct node* nodeToDelete = head;
        head = head->next;
        free(nodeToDelete);
    }
    else{
        struct node* temp = head;
        int i = 0;
        while(i < pos-1){
            temp = temp->next;
            i++;
        }
        struct node* nodeTodelete = temp->next;
        temp->next = temp->next->next;
        free(nodeTodelete);
    }
}


// display circular linked list
void display(){
    if(head == NULL){
        printf("Empty List");
        return;
    }
    struct node* temp = head;
    do{
        printf("%d ", temp->data);
        temp= temp->next;
    }while(temp!=head);

    printf("\n");
}

// main function
int main(){
    // insertAtBeg(10);
    // insertAtBeg(20);
    // insertAtBeg(30);
    // insertAtEnd(10);
    // insertAtEnd(20);
    // insertAtEnd(30);
    insertAtPos(10,0);
    insertAtPos(20,1);
    insertAtPos(100,1);
    printf("Circular Linked List: ");
    display();
    // deleteFromBeg();
    // printf("After deleting first element: ");
    // display();
    // deleteFromEnd();
    // printf("After deleting last element: ");
    // display();
    deleteFromPos(1);
    printf("After deleting 1st pos (index) element: ");
    display();
}

