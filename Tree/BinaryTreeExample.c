#include<stdio.h>
#include<stdlib.h>

typedef struct node{

    int data;
    struct node *left;
    struct node *right;

}node;

node* insertNode(node *rootNode, int data){

    if(rootNode == NULL){

        rootNode        = (node*)malloc(sizeof(node));
        rootNode->data  = data;
        rootNode->left  = NULL;
        rootNode->right = NULL;

        return rootNode;

    }
    else if(rootNode->data > data) rootNode->left  = insertNode(rootNode->left, data);
    else if(rootNode->data < data) rootNode->right = insertNode(rootNode->right, data);
    else printf("�����Ϸ��� ��尡 �̹� �ֽ��ϴ�.\n");

    return rootNode;

}

node* findMinNode(node *rootNode){

    node *temp  = rootNode;

    if(rootNode == NULL) return NULL;

    while(temp->left != NULL){

        temp    = temp->left;

    }

    return temp;

}

node* deleteNode(node *rootNode, int data){

    node *tNode;

    if(rootNode == NULL) return NULL;
    else if(rootNode->data > data) rootNode->left   = deleteNode(rootNode->left, data);
    else if(rootNode->data < data) rootNode->right  = deleteNode(rootNode->right, data);
    else{

        //������ 2�� ��
        if(rootNode->left != NULL && rootNode->right != NULL){

            tNode           = findMinNode(rootNode->right);
            rootNode->data  = tNode->data;
            rootNode->right = deleteNode(rootNode->right, tNode->data);

        }
        //���� 1 �Ǵ� 0�϶�
        else{

            tNode   = (rootNode->left == NULL) ? rootNode->right : rootNode->left;

            free(rootNode);

            return tNode;

        }

    }

    return rootNode;

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

    rootNode    = insertNode(rootNode, 5);
    rootNode    = insertNode(rootNode, 7);
    rootNode    = insertNode(rootNode, 10);
    rootNode    = insertNode(rootNode, 9);
    rootNode    = insertNode(rootNode, 100);
    rootNode    = insertNode(rootNode, 1);
    rootNode    = insertNode(rootNode, 2);
    rootNode    = insertNode(rootNode, 33);
    rootNode    = deleteNode(rootNode, 5);

    printTree(rootNode);

}
