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

        printf("Node가 없습니다!\n");

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

        printf("Node가 없습니다!\n");

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

        printf("Node가 없습니다!\n");

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

            printf("이전 Node를 찾지 못했습니다.\n");

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

        printf("Node가 없습니다!\n");

        return;

    }

    node *temp  = h->header;

    h->header   = h->header->link;

    free(temp);

}

void deleteMiddleNode(header *h, int preData){

    if(h->count == 0){

        printf("Node가 없습니다!\n");

        return;

    }

    node *pre   = searchNode(h, preData);

    if(pre == searchLastNode(h)){

        printf("마지막 node는 삭제는 deleteLastNode를 사용해주세요\n");

        return;

    }
    else if(pre == NULL){

        printf("이전 Node를 찾지 못했습니다.\n");

        return;

    }

    node *old   = pre->link;
    pre->link   = old->link;

    free(old);

}

void deleteLastNode(header *h){

    if(h->count == 0){

        printf("Node가 없습니다!\n");

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

        printf("Node가 없습니다!\n");

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

        printf("\n1. 리스트 출력\n");
        printf("2. 리스트 정렬\n");
        printf("3. 노드 추가\n");
        printf("4. 노드 삭제\n");
        printf("5. 프로그램 종료\n\n");

        printf("메뉴를 선택하세요 : ");
        scanf("%d", &number);
        printf("\n");

        switch(number){

            case 1:
                printf("결과 : ");
                printList(h);

                break;

            case 2:
                bubbleSortList(h);

                break;

            case 3:
                printf("정수를 입력해주세요 : ");
                scanf("%d", &number1);

                insertLastNode(h, number1);

                break;

            case 4:
                deleteLastNode(h);

                break;

            case 5:
                return 0;

            default:
                printf("메뉴의 번호를 입력해주세요\n");

                break;

        }

    }

}
