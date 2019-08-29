#include<stdio.h>
#include<stdlib.h>

typedef struct treeNode{

    int data;
    struct treeNode *left, *right;

}treeNode;

treeNode* insertNode(treeNode *p, int data){

    treeNode *newNode;

    if(p == NULL){

        newNode         = (treeNode*)malloc(sizeof(treeNode));
        newNode->data   = data;
        newNode->left   = NULL;
        newNode->right  = NULL;

        return newNode;

    }
    else if(p->data > data) p->left     = insertNode(p->left, data);
    else if(p->data < data) p->right    = insertNode(p->right, data);
    else printf("이미 노드가 존재합니다!!!\n");

    return p;
}

treeNode* findMinNode(treeNode *p){

    treeNode *temp  = p;

    if(p == NULL){

        return NULL;

    }

    while(p->left){

        p   = p->left;

    }

    return p;

}

treeNode* deleteNode(treeNode *p, int data){

    if(p == NULL) printf("Node가 없습니다!!\n");
    else if(p->data > data) p->left     = deleteNode(p->left, data);
    else if(p->data < data) p->right    = deleteNode(p->right, data);
    else{

        //차수가 2일 때
        if(p->left == NULL && p->right == NULL){

            treeNode *temp  = findMinNode(p->right);

            p->data = temp->data;

            free(temp);

        }
        //차수가 1 또는 0일 때
        else{



        }

    }

}

void printTree(treeNode *p){

    if(p){

        printTree(p->left);
        printf("%d ", p->data);
        printTree(p->right);

    }

}

void main(){

    treeNode *p = (treeNode*)malloc(sizeof(treeNode));
    p           = NULL;

    p   = insertNode(p, 10);
    p   = insertNode(p, 6);
    p   = insertNode(p, 15);
    p   = insertNode(p, 13);

    printTree(p);

}
