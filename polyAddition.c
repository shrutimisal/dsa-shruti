#include <stdio.h>
#include <stdlib.h>

struct node {
    int coeff;
    int pow;
    struct node* next;
};

struct node* createNode(int coeff , int pow){
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = NULL;
    return newNode;
}

void insertPolyExp(struct node** head , int coeff , int pow){
    struct node* newNode = createNode(coeff , pow);
    if(*head == NULL){
        *head = newNode;
        return;
    }
    else{
        struct node* temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

struct node* polyAddition(struct node* p1 , struct node* p2){
    struct node* result = NULL;
    struct node* temp = NULL;

    while(p1 != NULL && p2 != NULL){
        if(p1->pow > p2->pow){
            insertPolyExp(&result, p1->coeff, p1->pow);
            p1 = p1 ->next;
        }
        else if(p1->pow < p2->pow){
            insertPolyExp(&result, p2->coeff, p2->pow);
            p2 = p2 ->next;
        }
        else {
            insertPolyExp(&result, p1->coeff + p2->coeff, p1->pow);
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    while (p1 != NULL) {
        insertPolyExp(&result, p1->coeff, p1->pow);
        p1 = p1->next;
    }

    while (p2 != NULL) {
        insertPolyExp(&result, p2->coeff, p2->pow);
        p2 = p2->next;
    }

    return result;
}

void display(struct node* head){
    if(head == NULL){
        printf("it is empty");
        return;
    }
    struct node* temp = head;
    while(temp != NULL){
        printf("%dx^%d ", temp->coeff,temp->pow);
        temp= temp->next;
        if(temp!=NULL){
            printf("+");
        }
    }
}

int main(){
    struct node* poly1 = NULL;
    struct node* poly2 = NULL;
    struct node* sum = NULL;
    insertPolyExp(&poly1, 5, 3);
    insertPolyExp(&poly1, 4, 2);
    insertPolyExp(&poly1, 2, 1);

    insertPolyExp(&poly2, 3, 3);
    insertPolyExp(&poly2, 2, 1);
    insertPolyExp(&poly2, 7, 0);

    printf("Polynomial 1: ");
    display(poly1);

    printf("\n");

    printf("Polynomial 2: ");
    display(poly2);

    printf("\n");

    sum = polyAddition(poly1, poly2);
    printf("Sum: ");

    display(sum);

    return 0;
}