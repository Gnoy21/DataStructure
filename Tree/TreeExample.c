#include<stdio.h>
#include<stdlib.h>

typedef struct node{

    int data;
    struct node *right;
    struct node *left;

}node;

node* createRootNode(int data, node *leftNode, node *rightNode){

    node *newNode   = (node*)malloc(sizeof(node));
    newNode->data   = data;
    newNode->left   = leftNode;
    newNode->right  = rightNode;

    return newNode;

}

void printPreorder(node *root){

    if(root){

        printf("%d", root->data);
        printPreorder(root->left);
        printPreorder(root->right);

    }

}

void printInorder(node *root){

    if(root){

        printPreorder(root->left);
        printf("%d", root->data);
        printPreorder(root->right);

    }

}

void printPostorder(node *root){

    if(root){

        printPreorder(root->left);
        printPreorder(root->right);
        printf("%d", root->data);

    }

}

void main(){

    node *n7    = createRootNode(7, NULL, NULL);
    node *n6    = createRootNode(6, NULL, NULL);
    node *n5    = createRootNode(5, NULL, NULL);
    node *n4    = createRootNode(4, NULL, NULL);
    node *n3    = createRootNode(3, n6, n7);
    node *n2    = createRootNode(2, n4, n5);
    node *n1    = createRootNode(1, n2, n3);

    printInorder(n1);

}
