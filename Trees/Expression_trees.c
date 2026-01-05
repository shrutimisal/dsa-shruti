#include <stdio.h>
#include <stdlib.h>

/* Expression tree node */
struct node {
    char data;
    struct node* left;
    struct node* right;
    struct node* next;
};

struct node *head = NULL;

/* Create new node */
struct node* createNode(char data)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->next = NULL;
    return newNode;
}

/* Inorder traversal */
void printInorder(struct node* root)
{
    if (root == NULL)
        return;

    printInorder(root->left);
    printf("%c ", root->data);
    printInorder(root->right);
}

/* NORMAL STACK PUSH (LIFO) */
void push(struct node* x)
{
    x->next = head;
    head = x;
}

/* STACK POP */
struct node* pop()
{
    if (head == NULL)
        return NULL;

    struct node* temp = head;
    head = head->next;
    return temp;
}

int main()
{
    char s[] = {'A','B','C','*','+','D','/'};
    int l = sizeof(s) / sizeof(s[0]);

    struct node *x, *y, *z;

    for (int i = 0; i < l; i++)
    {
        // If operator
        if (s[i] == '+' || s[i] == '-' || s[i] == '*'
            || s[i] == '/' || s[i] == '^')
        {
            z = createNode(s[i]);

            x = pop();   // right child
            y = pop();   // left child

            z->left = y;
            z->right = x;

            push(z);
        }
        // If operand
        else
        {
            z = createNode(s[i]);
            push(z);
        }
    }

    // z is the ROOT of expression tree
    printf("The Inorder Traversal of Expression Tree: ");
    printInorder(z);

    return 0;
}
