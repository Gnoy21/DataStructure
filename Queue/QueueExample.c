#include<stdio.h>
#include<stdlib.h>

typedef struct queueNode{

    int data;
    struct queueNode *link;

}queueNode;

typedef struct queue{

    queueNode *front, *rear;

}queue;

queue* initQueue(){

    queue *newQueue = (queue*)malloc(sizeof(queue));
    newQueue->front = NULL;
    newQueue->rear  = NULL;

    return newQueue;

}

void printQueue(queue *Q){

    queueNode *temp;

    if(Q->front == NULL){

        printf("Node가 없습니다!\n");

        return;

    }

    temp    = Q->front;

    printf("Queue = [ ");

    while(temp){

        printf("%d ", temp->data);

        temp    = temp->link;

    }

    printf("]\n");

}

void insertNode(queue *Q, int data){

    queueNode *newNode   = (queueNode*)malloc(sizeof(queueNode));
    newNode->data   = data;
    newNode->link   = NULL;

    if(Q->front == NULL){

        Q->front    = newNode;
        Q->rear     = newNode;

    }
    else{

        Q->rear->link   = newNode;
        Q->rear         = newNode;

    }

}

void deleteNode(queue *Q){

    queueNode *old = Q->front;

    if(Q->front == NULL)
        printf("Node가 없습니다!\n");
    else if(Q->front == Q->rear){

        Q->front    = NULL;
        Q->rear     = NULL;

        free(old);

    }
    else{

        Q->front        = old->link;

        free(old);

    }

}

int main(){

    queue *Q    = initQueue();

    insertNode(Q, 10);
    insertNode(Q, 20);
    insertNode(Q, 19);
    insertNode(Q, 11);

    printQueue(Q);

}
