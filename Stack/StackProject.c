//Stack을 이용하여 괄호가 올바른지 검사하는 프로젝트입니다.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct stackNode{

    char text;
    struct stackNode *link;

}stackNode;

stackNode *top  = NULL;

void push(char data){

    stackNode *temp = (stackNode*)malloc(sizeof(stackNode));
    temp->text      = data;
    temp->link      = top;
    top             = temp;

}

char pop(){

    stackNode *temp;
    char text;

    if(top == NULL){

        return 'a';

    }

    temp    = top;
    text    = temp->text;
    top     = temp->link;

    free(temp);

    return text;

}

int checkBracket(char *s){

    char text;

    for(int i = 0; i < strlen(s); i++){

        if(s[i] == '(' || s[i] == '{' || s[i] == '['){

            push(s[i]);

        }

        if(s[i] == ')' || s[i] == '}' || s[i] == ']'){

            text    = pop();

            if(text == '(' && s[i] != ')')
                return 0;
            else if(text == '{' && s[i] != '}')
                return 0;
            else if(text == '[' && s[i] != ']')
                return 0;

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

    if(checkBracket(mathematicalExpression) == 1){

        printf("괄호 쌍이 맞습니다.\n");

    }
    else{

        printf("괄호 쌍이 맞지 않습니다.\n");

    }

}
