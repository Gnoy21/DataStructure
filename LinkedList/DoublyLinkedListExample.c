#include<stdio.h>
#include<stdlib.h>

typedef struct node{

    int data;
    struct node *left;
    struct node *right;

}node;

typedef struct header{

    node *header;
    int count;

}header;

header* createList(){

    header *h   = (header*)malloc(sizeof(header));
    h->header   = NULL;
    h->count    = 0;

    return h;

}

void printList(header *h){

    if(h->count == 0){

        printf("Node가 없습니다!\n");

        return;

    }

    node *temp  = h->header;

    printf("List = [ ");

    while(temp){

        printf("%d ", temp->data);

        temp    = temp->right;

    }

    printf("]\n");

}

void reversePrintList(header *h){

    if(h->count == 0){

        printf("Node가 없습니다!\n");

        return;

    }

    node *temp  = h->header;

    printf("List = [ ");

    while(temp->right != NULL){

        temp    = temp->right;

    }

    while(temp){

        printf("%d ", temp->data);

        temp    = temp->left;

    }

    printf("]\n");

}

void createNode(header *h, int data){

    node *newNode   = (node*)malloc(sizeof(node));
    newNode->data   = data;

    if(h->header == NULL){

        newNode->left   = NULL;
        newNode->right  = NULL;
        h->header       = newNode;

    }
    else{

        node *temp  = h->header;

        while(temp->right != NULL){

            temp    = temp->right;

        }

        temp->right     = newNode;
        newNode->right  = NULL;
        newNode->left   = temp;

    }

    h->count++;

}

void deleteNode(header *h, int data){

    if(h->count == 0){

        printf("Node가 없습니다!\n");

        return;

    }

    node *temp  = h->header;

    if(temp->data == data){

        h->header           = temp->right;
        temp->right->left   = NULL;

        free(temp);

        return;

    }

    temp    = temp->right;

    while(temp->right == NULL){

        if(temp->data == data){

            temp->left->right   = temp->right;
            temp->right->left   = temp->left;

            free(temp);

            return;

        }

        temp    = temp->right;

    }

    printf("일치하는 node가 없습니다!\n");

}

int main(){

    header *h   = createList();

    createNode(h, 10);
    createNode(h, 15);
    createNode(h, 11);
    createNode(h, 16);
    createNode(h, 1);
    createNode(h, 3);
    deleteNode(h, 1111);

    printList(h);
    reversePrintList(h);

}
