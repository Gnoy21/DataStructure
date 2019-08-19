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

        printf("�����Ϸ��� ��尡 �̹� �ֽ��ϴ�.\n");

    }

    return rootNode;

}

void deleteNode(node *rootNode, int data){

    //p : ������ 1�� �� �ڽ� ��带 �ӽ������ϱ� ���� ����
    node *parent, *child, *old;

    old   = rootNode;

    while(1){

        if(old == NULL){

            printf("��ġ�ϴ� Node�� �����ϴ�.\n");

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

        //�ڽ� ��带 �ӽ������ϱ� ���� ���ǹ�
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

//inorder������� ���
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
