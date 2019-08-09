#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct listNode{

    int data;
    struct listNode *link;

}node;

typedef struct listName{

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

    if(h->header == NULL){

        printf("]\n");

    }
    else{

        while(temp->link != NULL){

            printf("%d, ", temp->data);
            temp    = temp->link;

        }

        printf("%d]\n", temp->data);

    }

}

void createNode(header *h, int data){

    node *newNode   = malloc(sizeof(node));
    newNode->data   = data;
    newNode->link   = NULL;

    node *temp      = malloc(sizeof(node));
    temp            = h->header;

    if(h->header == NULL){

        h->header = newNode;

    }
    else{

        while(temp->link != NULL){

            temp = temp->link;

        }

        temp->link = newNode;

    }

    h->count++;

}

int includeNode(header *h, int data){

    node *temp  = malloc(sizeof(node));
    temp        = h->header;

    if(h->count == 0){

        printf("List is empty!\n");

        return;

    }

    while(1){

        if(temp->data == data){

            return 1;

        }

        if(temp->link == NULL){

            return 2;

        }

        temp = temp->link;

    }

}

void deleteNode(header *h, int data){

    node *temp  = malloc(sizeof(node));
    temp        = h->header;
    node *old   = malloc(sizeof(node));

    if(h->count == 0){

        printf("List is empty!\n");

        return;

    }

    if(includeNode(h, data) == 2){

        printf("Matching node is not exist!\n");

        return;

    }

    if(h->header->data == data){

        old         = h->header;
        h->header   = old->link;

        free(old);

        h->count--;

        return;

    }

    while(temp->link != NULL){

        if(temp->link->data == data){

            old         = temp->link;
            temp->link  = old->link;

            free(old);

            h->count--;

            return;

        }

        temp = temp->link;

    }

}

header* bubbleSortList(header *h){

    clock_t start, end;
    node *num1  = malloc(sizeof(node));
    node *num2  = malloc(sizeof(node));
    node *temp  = malloc(sizeof(node));
    int max     = h->count;

    start   = clock();

    for(int i = 0; i < h->count-1; i++){

        num1    = h->header;
        num2    = num1->link;

        if(num1->data > num2->data){

            h->header   = num2;
            num1->link  = num2->link;
            num2->link  = num1;

            temp    = num1;
            num1    = num2;
            num2    = temp;

        }

        for(int j = 0; j < max-2; j++){

            if(num1->link->data > num2->link->data){

                num1->link          = num2->link;
                num2->link          = num1->link->link;
                num1->link->link    = num2;

                num1    = num1->link;

            }
            else{

                num1    = num2;
                num2    = num1->link;

            }

        }

        max--;

    }

    end = clock();

    printf("bubbleSort run-time : %f\n", (double)(end - start) / CLOCKS_PER_SEC);

    return h;

}

int main(){

    header *h   = malloc(sizeof(header));
    h           = createList();

    createNode(h, 100);
    createNode(h, 50);
    createNode(h, 11);
    createNode(h, 13);
    deleteNode(h, 14);

    bubbleSortList(h);

    printList(h);

}
