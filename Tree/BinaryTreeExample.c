#include<stdio.h>
#include<stdlib.h>

typedef struct node{

    int data;
    struct node *left;
    struct node *right;

}node;

node* insertNode(node *rootNode, int data){

    node *newNode;

    if(rootNode == NULL){

        newNode         = (node*)malloc(sizeof(node));
        newNode->data   = data;
        newNode->left   = NULL;
        newNode->right  = NULL;

        return newNode;

    }
    else if(rootNode->data > data){

        rootNode->left  = insertNode(rootNode->left, data);

    }
    else if(rootNode->data < data){

        rootNode->right = insertNode(rootNode->right, data);

    }
    else{

        printf("삽입하려는 노드가 이미 있습니다.\n");

    }

    return rootNode;

}

void deleteNode(node *rootNode, int data){

    //p : 차수가 1일 때 자식 노드를 임시저장하기 위한 변수
    node *parent, *child, *old;

    old   = rootNode;

    while(1){

        if(old == NULL){

            printf("일치하는 Node가 없습니다.\n");

            return;

        }
        else if(old->data == data){

            break;

        }

        parent  = old;

        if(old->data > data){

            old   = old->left;

        }
        else if(old->data < data){

            old   = old->right;

        }

    }

    if(old->left == NULL && old->right == NULL){

        if(old != rootNode){

            if(parent->left == old){

                parent->left    = NULL;

            }
            else{

                parent->right   = NULL;

            }

        }
        else{

            rootNode    = NULL;

        }

    }
    else if(old->left == NULL || old->right == NULL){

        //자식 노드를 임시저장하기 위한 조건문
        if(old->left == NULL){

            child   = old->right;

        }
        else{

            child   = old->left;

        }

        if(old != rootNode){

            if(parent->left == old){

                parent->left    = child;

            }
            else{

                parent->right   = child;

            }

        }
        else{

            rootNode    = child;

        }

    }
    else{

        return;

    }

    free(old);

}

//inorder방식으로 출력
void printTree(node *rootNode){

    if(rootNode){

        printf("%d ", rootNode->data);
        printTree(rootNode->left);
        printTree(rootNode->right);

    }

}

int main(){

    node *rootNode  = (node*)malloc(sizeof(node));
    rootNode        = NULL;

    rootNode        = insertNode(rootNode, 5);
    rootNode        = insertNode(rootNode, 7);
    rootNode        = insertNode(rootNode, 10);
    rootNode        = insertNode(rootNode, 9);
    rootNode        = insertNode(rootNode, 100);
    rootNode        = insertNode(rootNode, 1);
    rootNode        = insertNode(rootNode, 2);
    rootNode        = insertNode(rootNode, 33);
    deleteNode(rootNode, 33);

    printTree(rootNode);

}
