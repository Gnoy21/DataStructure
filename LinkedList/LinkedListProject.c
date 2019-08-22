//주사위를 LinkedList로 구현하는 프로젝트입니다.

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct eyes{

    int state;
    struct eyes *link;

}eyes;

typedef struct dice{

    int number;
    eyes *header;

}dice;

void createDice(dice *D);
void setDice(dice *D);
void printDice(dice *D);
void throwDice(dice *D);
void setOne(dice *D);
void setTwo(dice *D);
void setThree(dice *D);
void setFour(dice *D);
void setFive(dice *D);
void setSix(dice *D);

int Flag    = 0;

void createDice(dice *D){

    D->number   = 1;
    D->header   = NULL;

    for(int i = 0; i < 9; i++){

        setDice(D);
        Flag++;

    }

}

void setDice(dice *D){

    eyes *temp      = D->header;
    eyes *newEyes   = (eyes*)malloc(sizeof(eyes));
    newEyes->link   = NULL;
    newEyes->state  = 0;

    if(temp == NULL){

        D->header       = newEyes;

        return;

    }

    if(Flag == 4){

        newEyes->state  = 1;

    }

    while(temp->link != NULL){

        temp    = temp->link;

    }

    temp->link  = newEyes;

}

void printDice(dice *D){

    eyes *temp  = (eyes*)malloc(sizeof(eyes));
    temp        = D->header;
    Flag        = 0;

    while(temp->link != NULL){

        if(temp->state == 0){

            printf("○ ");

        }
        else{

            printf("● ");

        }

        if(Flag == 2 || Flag == 5){

            printf("\n");

        }

        temp    = temp->link;
        Flag++;

    }

    if(temp->state == 0){

        printf("○ ");

    }
    else{

        printf("● ");

    }

}

void throwDice(dice *D){

    srand(time(NULL));
    D->number   = (rand() % 6) + 1;

    switch(D->number){

        case 1:
            setOne(D);
            break;

        case 2:
            setTwo(D);
            break;

        case 3:
            setThree(D);
            break;

        case 4:
            setFour(D);
            break;

        case 5:
            setFive(D);
            break;

        default:
            setSix(D);
            break;

    }

}

void setOne(dice *D){

    eyes *temp  = D->header;

    for(int i = 0; i < 9; i++){

        if(i == 4){

            temp->state = 1;

        }
        else{

            temp->state = 0;

        }

        temp    = temp->link;

    }

}

void setTwo(dice *D){

    eyes *temp  = D->header;

    for(int i = 0; i < 9; i++){

        if(i == 3 || i == 5){

            temp->state = 1;

        }
        else{

            temp->state = 0;

        }

        temp    = temp->link;

    }

}

void setThree(dice *D){

    eyes *temp  = D->header;

    for(int i = 0; i < 9; i++){

        if(i == 2 || i == 4 || i == 6){

            temp->state = 1;

        }
        else{

            temp->state = 0;

        }

        temp    = temp->link;

    }

}

void setFour(dice *D){

    eyes *temp  = D->header;

    for(int i = 0; i < 9; i++){

        if(i == 0 || i == 2 || i == 6 || i == 8){

            temp->state = 1;

        }
        else{

            temp->state = 0;

        }

        temp    = temp->link;

    }

}

void setFive(dice *D){

    eyes *temp  = D->header;

    for(int i = 0; i < 9; i++){

        if(i == 0 || i == 2 || i == 4 || i == 6 || i == 8){

            temp->state = 1;

        }
        else{

            temp->state = 0;

        }

        temp    = temp->link;

    }

}

void setSix(dice *D){

    eyes *temp  = D->header;

    for(int i = 0; i < 9; i++){

        if(i == 0 || i == 2 || i == 3 || i == 5 || i == 6 || i == 8){

            temp->state = 1;

        }
        else{

            temp->state = 0;

        }

        temp    = temp->link;

    }

}

int main(){

    dice *D = (dice*)malloc(sizeof(dice));

    createDice(D);
    throwDice(D);
    printDice(D);

}
