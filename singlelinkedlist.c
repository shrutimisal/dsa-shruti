#include <stdio.h>
#include <stdlib.h>

// Node Structure
struct node{
    int data;
    struct node* next;
};

// creating node
struct node* createNode(int data){
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data= data;
    newNode->next= NULL;
    return newNode;
}

struct node* head = NULL; //Globally declared

// inserting an element at beginning
// void insertAtBeg(int data){
//     struct node* newNode = createNode(data);
//     if(head == NULL){
//         head = newNode;
//     }else{
//         newNode->next = head;
//         head = newNode;
//     }
// }

// inserting element at the end
// void insertAtEnd(int data){
//     struct node* newNode = createNode(data);
//     if(head == NULL){
//         head = newNode;
//     }else{
//         struct node* temp = head;
//         while(temp->next!=NULL){
//         temp = temp->next;
//     }
//     temp->next = newNode;
//     }
// }

// Inserting element at given index
void insertAtInd(int data , int index){
    struct node* newNode = createNode(data);
    // Case1 : insert at beginning logic (if index is 0)
    if(index == 1){
        newNode->next = head;
        head = newNode;
        return;
    }
    struct node* temp = head;
    int i = 1;
    // Traverse to the node before the index
    while(temp!=NULL && i < index-1){
        temp = temp->next;
        i++;
    }
    //Case2 : index out of range
    if(temp == NULL){
        printf("Out of range index\n");
        free(newNode);
        return;
    }
    // case3 : normal nsertion
    newNode->next = temp->next;
    temp->next = newNode;

}

//deleting element from beginning
void deleteFromBeg(){
    if(head == NULL){
        printf("List is Empty , Nothing to delete");
    }else {
        struct node* temp = head;
        head = temp->next;
        free(temp);
    }
}

// deleting element from end
void deleteFromEnd(){
    if(head == NULL){
        printf("List is Empty , Nothing to delete");
    }
    // case : if in the list only one node is present
    else if(head->next == NULL){
        free(head);
        head = NULL;
    }
    else{
        struct node* temp = head;
        while(temp->next->next!=NULL){
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

//delete element from specific position
void deleteFromPos(int pos){
    if(head == NULL){
        printf("List is Empty , Nothing to delete");
        return;
    }
    struct node* temp = head;
    // case1 : delete first node
    if(pos == 1){
        head = temp->next;
        free(temp);
        return;
    }
    // Traverse to the node before the one to delete
    for(int i = 1 ; temp != NULL && i < pos-1 ; i++ ){
        temp = temp->next;
    }
    // if position is invalid
    if(temp==NULL || temp->next == NULL){
        printf("Invalid position");
        return;
    }

    struct node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
}

// display the singly linked list
void display(){
    struct node* temp = head;
    if(temp == NULL){
        printf("List is Empty\n");
        return;
    }
    while(temp!=NULL){
        printf(" %d ->",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// main function
int main(){
    // insertAtBeg(20);
    // insertAtEnd(40);
    // insertAtInd(60,2);
    // display();
    // deleteFromBeg();
    // printf("After deleting the first element \n");
    // display();
    // deleteFromEnd();
    // printf("After deleting the end element \n");
    // display();
    // deleteFromEnd();
    // printf("After deleting the end element \n");
    // display();
    // deleteFromPos(2);
    // printf("After deleting the element at 2 position \n");
    // display();
    insertAtInd(10,1);
    insertAtInd(20,2);
    insertAtInd(30,2);
    display();
}