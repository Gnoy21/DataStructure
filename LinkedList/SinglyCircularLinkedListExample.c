#include<stdio.h>
#include<stdlib.h>

typedef struct node{

    int data;
    struct node *link;

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

    while(temp->link != h->header){

        printf("%d ", temp->data);

        temp    = temp->link;

    }

    printf("%d ]\n", temp->data);

}

node* searchLastNode(header *h){

    if(h->count == 0){

        return NULL;

    }

    node *temp  = h->header;

    while(temp->link != h->header){

        temp    = temp->link;

    }

    return temp;

}

void createNode(header *h, int data){

    node *newNode, *temp;

    newNode         = (node*)malloc(sizeof(node));
    newNode->data   = data;
    temp            = searchLastNode(h);

    if(h->count == 0){

        h->header       = newNode;
        newNode->link   = newNode;

    }
    else{

        newNode->link   = h->header;
        temp->link      = newNode;

    }

    h->count++;

}

//마지막 Node 삭제
void deleteNode(header *h){

    if(h->count == 0){

        printf("Node가 없습니다!\n");

        return;

    }

    node *temp, *old, *lastNode;
    temp        = h->header;
    lastNode    = searchLastNode(h);

    if(h->count == 1){

        h->header       = temp->link;
        lastNode->link  = temp->link;

        free(temp);

        return;

    }

    while(temp->link->link != h->header){

        temp    = temp->link;

    }

    old         = temp->link;
    temp->link  = old->link;

    free(old);

}

int main(){

    header *h = createList();

    createNode(h, 50);
    createNode(h, 20);
    createNode(h, 21);
    //createNode(h, 11);
    deleteNode(h);

    printList(h);

}
