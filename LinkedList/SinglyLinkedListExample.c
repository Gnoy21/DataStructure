#include<stdio.h>
#include<malloc.h>

typedef struct listNode{

    int data;
    struct listNode *link;

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

//Node�� ���ٸ� 1, �ִٸ� 0 ��ȯ
int checkEmpty(header *h){

    if(h->count == 0){

        return 1;

    }
    else{

        return 0;

    }

}

void printList(header *h){

    node *temp  = h->header;

    if(checkEmpty(h)){

        printf("Node�� �����ϴ�!\n");

        return;

    }

    printf("List = [ ");

    while(temp){

        printf("%d ", temp->data);
        temp    = temp->link;

    }

    printf("]\n");

}

//�Ű����� data�� ��ġ�ϴ� node ��ȯ ���ٸ� NULL ��ȯ
node* searchNode(header *h, int data){

    node *temp  = h->header;

    while(temp){

        if(temp->data == data){

            return temp;

        }

        temp    = temp->link;

    }

    return NULL;

}

node* searchLastNode(header *h){

    node *temp  = h->header;

    while(temp->link != NULL){

        temp    = temp->link;

    }

    return temp;

}

void insertFirstNode(header *h, int data){

    node *newNode   = malloc(sizeof(node));
    newNode->data   = data;
    newNode->link   = h->header;
    h->header       = newNode;
    h->count++;

}

void insertMiddleNode(header *h, int preData, int data){

    node *newNode   = malloc(sizeof(node));
    newNode->data   = data;

    if(checkEmpty(h)){

        h->header       = newNode;
        newNode->link   = NULL;
        h->count++;

        return;

    }
    else{

        node *temp      = searchNode(h, preData);

        if(temp == NULL){

            printf("���� Node�� ã�� ���߽��ϴ�.\n");

            return;

        }

        newNode->link   = temp->link;
        temp->link      = newNode;

    }

    h->count++;

}

void insertLastNode(header *h, int data){

    node *newNode   = malloc(sizeof(node));
    newNode->data   = data;
    newNode->link   = NULL;

    if(checkEmpty(h)){

        h->header   = newNode;
        h->count++;

        return;

    }
    else{

        node *temp  = searchLastNode(h);
        temp->link  = newNode;

    }

    h->count++;
}

void deleteFirstNode(header *h){

    node *temp  = h->header;

    if(checkEmpty(h)){

        printf("���� �� Node�� �����ϴ�\n");

        return;

    }

    h->header   = h->header->link;

    free(temp);

}

void deleteMiddleNode(header *h, int preData){

    if(checkEmpty(h)){

        printf("���� �� Node�� �����ϴ�\n");

        return;

    }

    node *pre   = searchNode(h, preData);

    if(pre == searchLastNode(h)){

        printf("������ node�� ���� �� �� �����ϴ�. deleteLastNode�� ������ּ���\n");

        return;

    }

    if(pre == NULL){

        printf("���� Node�� ã�� ���߽��ϴ�.\n");

        return;

    }

    node *old   = pre->link;
    pre->link   = pre->link->link;

    free(old);

}

void deleteLastNode(header *h){

    if(checkEmpty(h)){

        printf("���� �� Node�� �����ϴ�.\n");

        return;

    }
    else{

        node *temp  = h->header;

        while(temp->link->link != NULL){

            temp    = temp->link;

        }

        node *old   = temp->link;
        temp->link  = temp->link->link;

        free(old);

    }

}

header* bubbleSortList(header *h){

    node *num1  = malloc(sizeof(node));
    node *num2  = malloc(sizeof(node));
    node *temp  = malloc(sizeof(node));
    int max     = h->count;

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

    return h;

}

int main(){

    header *h   = createList();

    insertFirstNode(h, 10);
    insertFirstNode(h, 15);
    insertFirstNode(h, 20);
    insertFirstNode(h, 25);

    printList(h);

    deleteMiddleNode(h, 10);

    printList(h);

}
