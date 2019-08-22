#include<stdio.h>
#include<stdlib.h>

typedef struct listNode{

    int data;
    struct listNode *link;

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

        printf("Node�� �����ϴ�!\n");

        return;

    }

    node *temp    = h->header;

    printf("List = [ ");

    while(temp){

        printf("%d ", temp->data);
        temp    = temp->link;

    }

    printf("]\n");

}

node* searchNode(header *h, int data){

    if(h->count == 0){

        printf("Node�� �����ϴ�!\n");

        return NULL;

    }

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

    if(h->count == 0){

        printf("Node�� �����ϴ�!\n");

        return NULL;

    }

    node *temp  = h->header;

    while(temp->link != NULL){

        temp    = temp->link;

    }

    return temp;

}

void insertFirstNode(header *h, int data){

    node *newNode   = (node*)malloc(sizeof(node));
    newNode->data   = data;
    newNode->link   = h->header;
    h->header       = newNode;
    h->count++;

}

void insertMiddleNode(header *h, int preData, int data){

    node *newNode   = (node*)malloc(sizeof(node));
    newNode->data   = data;

    if(h->count == 0){

        newNode->link   = NULL;
        h->header       = newNode;

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

    node *newNode   = (node*)malloc(sizeof(node));
    newNode->data   = data;
    newNode->link   = NULL;

    if(h->count == 0)
        h->header   = newNode;
    else{

        node *temp  = searchLastNode(h);
        temp->link  = newNode;

    }

    h->count++;
}

void deleteFirstNode(header *h){

    if(h->count == 0){

        printf("Node�� �����ϴ�!\n");

        return;

    }

    node *temp  = h->header;

    h->header   = h->header->link;

    free(temp);

}

void deleteMiddleNode(header *h, int preData){

    if(h->count == 0){

        printf("Node�� �����ϴ�!\n");

        return;

    }

    node *pre   = searchNode(h, preData);

    if(pre == searchLastNode(h)){

        printf("������ node�� ������ deleteLastNode�� ������ּ���\n");

        return;

    }
    else if(pre == NULL){

        printf("���� Node�� ã�� ���߽��ϴ�.\n");

        return;

    }

    node *old   = pre->link;
    pre->link   = old->link;

    free(old);

}

void deleteLastNode(header *h){

    if(h->count == 0){

        printf("Node�� �����ϴ�!\n");

        return;

    }
    else if(h->count == 1){

        node *old   = h->header;
        h->header   = NULL;

        free(old);

    }
    else{

        node *temp  = h->header;

        while(temp->link->link != NULL){

            temp    = temp->link;

        }

        node *old   = temp->link;
        temp->link  = old->link;

        free(old);

    }

}

header* bubbleSortList(header *h){

    if(h->count == 0){

        printf("Node�� �����ϴ�!\n");

        return h;

    }
    else if(h->count == 1)
        return h;

    node *num1, *num2, *temp;
    int max     = h->count;

    for(int i = 1; i < h->count; i++){

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

    int number, number1;
    header *h   = createList();

    while(1){

        printf("\n1. ����Ʈ ���\n");
        printf("2. ����Ʈ ����\n");
        printf("3. ��� �߰�\n");
        printf("4. ��� ����\n");
        printf("5. ���α׷� ����\n\n");

        printf("�޴��� �����ϼ��� : ");
        scanf("%d", &number);
        printf("\n");

        switch(number){

            case 1:
                printf("��� : ");
                printList(h);

                break;

            case 2:
                bubbleSortList(h);

                break;

            case 3:
                printf("������ �Է����ּ��� : ");
                scanf("%d", &number1);

                insertLastNode(h, number1);

                break;

            case 4:
                deleteLastNode(h);

                break;

            case 5:
                return 0;

            default:
                printf("�޴��� ��ȣ�� �Է����ּ���\n");

                break;

        }

    }

}
