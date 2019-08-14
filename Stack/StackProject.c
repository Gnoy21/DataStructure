//Stack�� �̿��Ͽ� ��ȣ�� �ùٸ��� �˻��ϴ� ������Ʈ�Դϴ�.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct stackNode{

    char text;
    struct stackNode *link;

}stackNode;

stackNode *top  = NULL;

void push(char data){

    stackNode *temp = malloc(sizeof(stackNode));
    temp->text      = data;
    temp->link      = top;
    top             = temp;

}

char pop(){

    char data;
    stackNode *temp = malloc(sizeof(stackNode));

    if(top == NULL){

        return 'a';

    }

    temp            = top;
    data            = temp->text;
    top             = temp->link;

    free(temp);

    return data;

}

void printStack(){

    stackNode *temp = malloc(sizeof(stackNode));
    temp            = top;

    printf("Stack = [");

    if(top == NULL){

        printf("]");

    }

    while(temp->link != NULL){

        printf("%c, ", temp->text);

        temp    = temp->link;

    }

    printf("%c]\n", temp->text);

}

void resetStack(){

    while(top != NULL){

        pop();

    }

}

//������ �´ٸ� 1, �ƴ϶�� 0 ��ȯ
int checkBracket(char *s){

    char temp;

    for(int i = 0; i < strlen(s); i++){

        if(s[i] == '(' || s[i] == '{' || s[i] == '['){

            push(s[i]);

        }

        if(s[i] == ')' || s[i] == '}' || s[i] == ']'){

            temp    = pop();

            if(temp == '(' && s[i] != ')'){

                return 0;

            }

            if(temp == '{' && s[i] != '}'){

                return 0;

            }

            if(temp == '[' && s[i] != ']'){

                return 0;

            }

            if(top == NULL){

                return 0;

            }

        }

    }

    if(top == NULL){

        return 1;

    }
    else{

        return 0;

    }

}

int main(){

    char mathematicalExpression[100];

    scanf("%s", mathematicalExpression);

    if(checkBracket(mathematicalExpression)){

        printf("�ùٸ� �����Դϴ�.\n");

    }
    else{

        printf("�ùٸ� ������ �ƴմϴ�.\n");

    }

}
