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

    header *h   = malloc(sizeof(header));
    h->header   = NULL;
    h->count    = 0;

    return h;

}

void printList(header *h){

    node *temp  = malloc(sizeof(node));
    temp        = h->header;

    switch(h->count){

        case 0:
            printf("List is empty!\n");

            break;

        case 1:
            printf("List = [%d]", temp->data);

            break;

        default:
            printf("List = [");

            while(temp->link != h->header){

                printf("%d, ", temp->data);

                temp    = temp->link;

            }

            printf("%d]\n", temp->data);

    }

}

node* searchLastNode(header *h){

    node *temp  = h->header;

    switch(h->count){

        case 0:
            return NULL;

        case 1:
            return temp;

        default:
            while(temp->link != h->header){

                temp    = temp->link;

            }

            return temp;

    }

}

void createNode(header *h, int data){

    node *newNode, *temp;

    newNode         = malloc(sizeof(node));
    newNode->data   = data;
    temp            = h->header;

    switch(h->count){

        case 0:
            h->header       = newNode;
            newNode->link   = newNode;
            h->count++;

            break;

        case 1:
            temp->link      = newNode;
            newNode->link   = temp;
            h->count++;

            break;

        default:
            temp            = searchLastNode(h);
            newNode->link   = h->header;
            temp->link      = newNode;
            h->count++;

    }

}

void deleteNode(header *h, int data){

    node *temp, *old, *lastNode = searchLastNode(h);
    temp        = h->header;

    switch(h->count){

        case 0:
            printf("List is empty!\n");

            break;

        default:

            if(temp->data == data){

                h->header       = temp->link;
                lastNode->link  = temp->link;

                free(temp);

                return;

            }

            while(temp->link->link != h->header){

                if(temp->link->data == data){

                    old         = temp->link;
                    temp->link  = old->link;

                    free(old);

                    return;

                }

                temp    = temp->link;

            }

    }

}

int main(){

    header *h = createList();

    createNode(h, 50);
    createNode(h, 20);
    createNode(h, 30);

    printList(h);

}
