#include<stdio.h>
#include<stdlib.h>
#include<time.h>

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

    header *h   = malloc(sizeof(header));
    h->header   = NULL;
    h->count    = 0;

    return h;

}

void printList(header *h){

    node *temp  = malloc(sizeof(node));
    temp        = h->header;

    if(h->count == 0){

        printf("List is empty!\n");

        return;

    }

    printf("List = [");

    while(temp->right != NULL){

        printf("%d, ", temp->data);

        temp    = temp->right;

    }

    printf("%d]\n", temp->data);

}

void reversePrintList(header *h){

    node *temp  = malloc(sizeof(node));
    temp        = h->header;

    if(h->count == 0){

        printf("List is empty!\n");

        return;

    }

    printf("List = [");

    while(temp->right != NULL){

        temp    = temp->right;

    }

    while(temp->left != NULL){

        printf("%d, ", temp->data);

        temp    = temp->left;

    }

    printf("%d]\n", temp->data);

}

void createNode(header *h, int data){

    node *newNode   = malloc(sizeof(node));
    newNode->data   = data;

    if(h->header == NULL){

        newNode->left   = NULL;
        newNode->right  = NULL;
        h->header       = newNode;

    }
    else{

        node *temp  = malloc(sizeof(node));
        temp        = h->header;

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

    node *temp  = malloc(sizeof(node));
    temp        = h->header;

    if(h->count == 0){

        printf("List is empty!\n");

        return;

    }

    if(temp->data == data){

        h->header           = temp->right;
        temp->right->left   = NULL;

        free(temp);

        return;

    }

    temp    = temp->right;

    while(1){

        if(temp->data == data){

            temp->left->right   = temp->right;
            temp->right->left   = temp->left;

            free(temp);
            return;

        }

        if(temp->right == NULL){

            break;

        }

        temp    = temp->right;

    }

    printf("Matching node is not exitst!\n");

}

int main(){

    header *h   = malloc(sizeof(header));
    h           = createList();

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
