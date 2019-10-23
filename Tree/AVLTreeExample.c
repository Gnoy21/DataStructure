#include<stdio.h>
#include<stdlib.h>

typedef struct node{

    int data;
    struct node *left, *right;

}node;

node* LL_rotate(node *p){

    node *child     = p->left;
    p->left         = NULL;
    child->right    = p;

    return child;

}

node* RR_rotate(node *p){

    node *child     = p->right;
    p->right        = NULL;
    child->left     = p;

    return child;

}

node* LR_rotate(node *p){

    p->left     = RR_rotate(p->left);

    return LL_rotate(p);

}

node* RL_rotate(node *p){

    p->right     = LL_rotate(p->right);

    return RR_rotate(p);

}

int getHeight(node *p){

    if(p == NULL) return 0;
    else{

        int leftHeight  = getHeight(p->left);
        int rightHeight = getHeight(p->right);

        return 1 + (leftHeight > rightHeight? leftHeight : rightHeight);

    }

}

int getBF(node *p){

    if(p == NULL) return 0;
    else return getHeight(p->left) - getHeight(p->right);

}

node* rebalanceTree(node *p){

    int BF  = getBF(p);

    if(BF > 1){

        if(getBF(p->left) == 1) p   = LL_rotate(p);
        else p   = LR_rotate(p);

    }
    else if(BF < -1){

        if(getBF(p->right) == -1) p = RR_rotate(p);
        else p   = RL_rotate(p);

    }

    return p;

}

node* insertNode(node *p, int data){

    if(p == NULL){

        p           = (node*)malloc(sizeof(node));
        p->data     = data;
        p->left     = NULL;
        p->right    = NULL;

    }
    else if(p->data > data){

        p->left = insertNode(p->left, data);
        p       = rebalanceTree(p);

    }
    else if(p->data < data){

        p->right    = insertNode(p->right, data);
        p           = rebalanceTree(p);

    }
    else    printf("이미 같은 키가 존재합니다!\n");

    return p;

}

void printTree(node *p){

    if(p){

        printTree(p->left);
        printf("%d ", p->data);
        printTree(p->right);

    }

}

int main(){

    node *root  = NULL;

    root    = insertNode(root, 10);
    root    = insertNode(root, 20);
    root    = insertNode(root, 8);
    root    = insertNode(root, 9);
    root    = insertNode(root, 7);
    root    = insertNode(root, 30);
    root    = insertNode(root, 5);

    printTree(root);

}
