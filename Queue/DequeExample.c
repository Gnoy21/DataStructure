#include<stdio.h>
#include<stdlib.h>

typedef struct dequeNode{

    int data;
    struct dequeNode *link;

}dequeNode;

typedef struct deque{

    dequeNode *front, *rear;

}deque;

deque* initDeque(){

    deque *newDeque = (deque*)malloc(sizeof(deque));
    newDeque->front = NULL;
    newDeque->rear  = NULL;

    return newDeque;

}

void printDeque(deque *D){

    dequeNode *temp;

    if(D->front == NULL){

        printf("Node가 없습니다!\n");

        return;

    }

    temp    = D->front;

    printf("Deque = [ ");

    while(temp){

        printf("%d ", temp->data);

        temp    = temp->link;

    }

    printf("]\n");

}

void frontInsertNode(deque *D, int data){

    dequeNode *newNode  = (dequeNode*)malloc(sizeof(dequeNode));
    newNode->data       = data;

    if(D->front == NULL){

        newNode->link   = NULL;
        D->front        = newNode;
        D->rear         = newNode;

    }
    else{

        newNode->link   = D->front;
        D->front        = newNode;

    }

}

void rearInsertNode(deque *D, int data){

    dequeNode *newNode  = (dequeNode*)malloc(sizeof(dequeNode));
    newNode->data       = data;
    newNode->link       = NULL;

    if(D->front == NULL){

        D->front    = newNode;
        D->rear     = newNode;

    }
    else{

        D->rear->link   = newNode;
        D->rear         = newNode;

    }

}

void frontDeleteNode(deque *D){

    dequeNode *old  = D->front;

    if(D->front == NULL)
        printf("Node가 없습니다!\n");
    else if(D->front == D->rear){

        D->front    = NULL;
        D->rear     = NULL;

        free(old);

    }
    else{

        D->front    = old->link;

        free(old);

    }

}

void rearDeleteNode(deque *D){

    dequeNode *pre, *old;

    if(D->front == NULL)
        printf("Node가 없습니다!\n");
    else if(D->front == D->rear){

        old         = D->front;
        D->front    = NULL;
        D->rear     = NULL;

        free(old);

    }
    else{

        pre = D->front;

        while(pre->link != D->rear){

            pre = pre->link;

        }

        old         = pre->link;
        pre->link   = NULL;
        D->rear     = pre;

        free(old);

    }

}

int main(){

    deque *D    = initDeque();

    frontInsertNode(D, 10);
    frontInsertNode(D, 120);
    frontInsertNode(D, 20);
    rearDeleteNode(D);

    printDeque(D);

}
