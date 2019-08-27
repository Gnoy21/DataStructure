#include<stdio.h>
#include<stdlib.h>

typedef struct stackNode{

    int data;
    struct stackNode *link;

}stackNode;

stackNode *top  = NULL;

void push(int data){

    stackNode *temp = (stackNode*)malloc(sizeof(stackNode));
    temp->data      = data;
    temp->link      = top;
    top             = temp;

}

int pop(){

    int number;
    stackNode *temp = top;
    number          = temp->data;
    top             = temp->link;

    free(temp);

    return number;

}

void printStack(){

    stackNode *temp = top;

    printf("Stack = [");

    while(temp->link != NULL){

        printf("%d, ", temp->data);

        temp    = temp->link;

    }

    printf("%d]\n", temp->data);

}

int main(){

    push(10);
    push(20);
    push(30);
    printStack();

}
