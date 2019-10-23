#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

void insertNode(node *h, int data){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    if(h->next == NULL){
        h->next = newNode;
        return;
    }

    node *temp = h->next;

    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newNode;
}

void deleteNode(node *h){
    if(h->next == NULL){
        printf("List is Empty!\n");
        return;
    }

    node *pre, *temp = h->next;


    while(temp->next != NULL){
        pre  = temp;
        temp = temp->next;
    }

    pre->next = NULL;
    free(temp);
}

void printList(node *h){
    if(h->next == NULL){
        printf("List is Empty!\n");
        return;
    }

    node *temp = h->next;

    printf("List = [ ");

    while(temp != NULL){
        printf("%d ", temp->data);

        temp = temp->next;
    }

    printf("]\n");
}

int main(){
    node *h = (node*)malloc(sizeof(node));
    h->next = NULL;

    insertNode(h, 10);
    insertNode(h, 20);
    insertNode(h, 30);
    insertNode(h, 40);
    deleteNode(h);
    printList(h);
}
