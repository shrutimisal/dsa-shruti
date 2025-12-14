#include <stdio.h>
#include <stdlib.h>

// Defining node structure
struct node {
    int data;
    struct node* prev;
    struct node* next;
};

// creating the node
struct node* createNode(int data){
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

struct node* head = NULL; //globally declared

// insert element at beginning
void insertAtBeg(int data){
    struct node* newNode = createNode(data);
    if(head == NULL){
        head = newNode;
        return;
    }
    else{
        newNode->next = head;
        head->prev= newNode;
        head = newNode;
    }
}

// insert element at the end
void insertAtEnd(int data){
    struct node* newNode = createNode(data);
    if(head == NULL){
        head = newNode;
        return;
    }
    else{
        struct node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// insert at specific position
void insertAtPos(int data,int pos){
    struct node* newNode = createNode(data);
    // case1 : inserting at beginning (0) position
    if(pos == 0){
        if(head == NULL){
            head = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }
    struct node* temp = head;
    int i = 0;
    while(temp != NULL && i < pos-1){
        temp = temp->next;
        i++;
    }
    // If position is invalid (greater than list length)
    if (temp == NULL) {
        printf("Invalid position!, Node not inserted.\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if(temp->next != NULL){
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

// deleting from the beginning
void deleteFromBeg(){
    if(head == NULL){
        printf("List is already Empty");
        return;
    }else{
        struct node* temp= head;
        head = head->next;
        if(head != NULL){
            head->prev = NULL;
        }
        free(temp);
    }
}

// deleting from the end
void deleteFromEnd(){
    if(head == NULL){
        printf("List is already empty");
        return;
    }
    else{
        struct node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->prev->next = NULL;
        free(temp);
    }
}

//delete from specific position(index)
void deleteFromPos(int pos){
    if(head == NULL){
        printf("List is already empty");
        return;
    }
    struct node* temp = head;
    if(pos == 0){
        head = head->next;
        if(head!=NULL){
            head->prev = NULL;
        }
        free(temp);
        return;
    }
    int i = 0;
    while(temp!=NULL && i < pos-1){
        temp = temp->next;
        i++;
    }
    if(temp == NULL){
        printf("Position is invalid");
        return;
    }
    struct node* nodeToDelete = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = temp;
    }
    free(nodeToDelete);
}

// displaying doubly linked list
// can be from 2 sides :
// Forward and Backward
void displayForward(){
    struct node* temp = head;
    if(temp == NULL){
        printf("List is Empty");
        return;
    }
    printf("Doubly Linked List (Forward) :");
    while(temp != NULL){
        printf("%d ", temp->data);
        temp= temp->next;
    }
    printf("\n");
}

void displayBackward(){
    struct node* temp = head;
    if(temp == NULL){
        printf("List is Empty");
        return;
    }
    while(temp->next != NULL){
        temp = temp->next;
    }
    printf("Doubly Linked List (Backward) :");
    while(temp != NULL){
        printf("%d ", temp->data);
        temp= temp->prev;
    }
    printf("\n");
}

struct node* reverse(){
    struct node* temp = NULL;
    struct node* current = head;

    while(current != NULL){
        temp = current -> prev;
        current -> prev = current -> next;
        current -> next = temp;
        current = current -> prev;
    }

    if(temp!=NULL){
        head = temp->prev;
    }

    return head;

}

void reverseListDisplay(){
    if(head == NULL){
        printf("List is Empty");
        return;
    }
    struct node* temp = head;
    while(temp!=NULL){
        printf("%d ",temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}
int main(){
    insertAtBeg(10);
    insertAtBeg(20);
    // displayForward();
    // displayBackward();
    // printf("inserting 100 at end \n");
    insertAtEnd(100);
    // displayForward();
    // displayBackward();
    // printf("inserting value 200 at 3 position\n");
    insertAtPos(200,3);
    displayForward();
    // printf("Deleting from beginning\n");
    // deleteFromBeg();
    // displayForward();
    // printf("Deleting from end\n");
    // deleteFromEnd();
    // displayForward();
    printf("Deleting from 2nd position\n");
    deleteFromPos(2);
    displayForward();

    printf("\n Reverse Display : ");
    reverse();
    reverseListDisplay();
    return 0;
}