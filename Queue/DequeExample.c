#include<stdio.h>
#include<malloc.h>

typedef struct node{

    int data;
    struct node *link;

}node;

typedef struct deque{

    node *front, *rear;

}deque;

deque* createDeque(){

    deque *D    = malloc(sizeof(deque));
    D->front    = NULL;
    D->rear     = NULL;

    return D;

}

int checkEmpty(deque *D){

    if(D->front == NULL || D->rear == NULL){

        return 1;

    }
    else{

        return 0;

    }

}

void printDeque(deque *D){

    if(checkEmpty(D)){

        printf("Node가 존재하지 않습니다\n");

    }
    else{

        node *temp  = D->front;

        printf("Deque = [ ");

        while(temp){

            printf("%d ", temp->data);

            temp    = temp->link;

        }

        printf("]\n");

    }

}

void insertFront(deque *D, int data){

    node *newNode   = (node*)malloc(sizeof(node));
    newNode->data   = data;

    if(checkEmpty(D)){

        newNode->link   = NULL;
        D->front        = newNode;
        D->rear         = newNode;

    }
    else{

        newNode->link   = D->front;
        D->front        = newNode;

    }

}

void deleteFront(deque *D){

    if(checkEmpty(D)){

        printf("Node가 존재하지 않습니다]n");

    }
    else if(D->front == D->rear){

        node *old   = D->front;
        D->front    = NULL;
        D->rear     = NULL;

        free(old);

    }
    else{

        node *old   = D->front;
        D->front    = D->front->link;

        free(old);

    }

}

void insertRear(deque *D, int data){

    node *newNode  = (node*)malloc(sizeof(node));
    newNode->data  = data;
    newNode->link   = NULL;

    if(checkEmpty(D)){

        D->front        = newNode;
        D->rear         = newNode;

    }
    else{

        D->rear->link   = newNode;
        D->rear         = newNode;

    }

}

void deleteRear(deque *D){

    if(checkEmpty(D)){

        printf("Node가 존재하지 않습니다\n");

    }
    else if(D->front == D->rear){

        node *old   = D->front;
        D->front    = NULL;
        D->rear     = NULL;

        free(old);

    }
    else{

        node *pre   = D->front;

        while(pre->link != D->rear){

            pre = pre->link;

        }

        node *old   = pre->link;
        pre->link   = NULL;
        D->rear     = pre;

        free(old);

    }

}

int main(){

    deque *D    = createDeque();

    insertFront(D, 10);
    insertFront(D, 20);
    insertRear(D, 30);

    deleteFront(D);

    printDeque(D);

}
