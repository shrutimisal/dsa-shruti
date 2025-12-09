#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int val){
    struct node* newNode = (struct node*) malloc (sizeof(struct node));
    newNode -> data = val;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

struct node* insert(struct node* root , int val){
    if (root == NULL){
        return createNode(val);
    }
    if(val < root -> data){
        root->left = insert(root->left , val);
    }else{
        root->right = insert(root->right , val);
    }

    return root;
}

void inorder(struct node* root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main(){
    struct node* root = NULL;

    root = insert(root ,50);
    insert(root,23);
    insert(root,20);
    insert(root,85);
    insert(root,56);
    insert(root,14);

    printf("Inorder Traversal : ");
    inorder(root);
    return 0;
}