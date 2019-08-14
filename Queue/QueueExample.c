#include<stdio.h>
#include<malloc.h>

typedef struct node{

    int data;
    struct node *link;

}node;

typedef struct queue{

    node *front, *rear;

}queue;

queue* createQueue(){

    queue *Q     = malloc(sizeof(queue));
    Q->front    = NULL;
    Q->rear     = NULL;

    return Q;

}

void printQueue(queue *Q){

    node *temp  = Q->front;

    printf("Queue = [");

    while(temp->link != NULL){

        printf("%d, ", temp->data);
        temp    = temp->link;

    }

    printf("%d]\n", temp->data);

}

void createNode(queue *Q, int data){

    node *newNode   = malloc(sizeof(node));
    newNode->data   = data;
    newNode->link   = NULL;

    if(Q->front == NULL){
        Q->front  = newNode;
        Q->rear   = newNode;

    }
    else{

        Q->rear->link   = newNode;
        Q->rear         = newNode;

    }

}

void deleteNode(queue *Q){

    node *old   = Q->front;

    if(Q->front == NULL){

        printf("삭제 할 노드가 없습니다!");

        return;

    }

    Q->front    = Q->front->link;

    if(Q->front == NULL){

        Q->rear = NULL;

    }

    free(old);

}

int main(){

    queue *Q    = createQueue();

    createNode(Q, 10);
    createNode(Q, 20);
    printQueue(Q);

}
