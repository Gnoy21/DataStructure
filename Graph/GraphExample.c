#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTEX 30

typedef struct node{

    int vertex;
    struct node *link;

}node;

typedef struct graph{

    int n;
    node* adjList_H[MAX_VERTEX];

}graph;

void createGraph(graph *g){

    g->n    = 0;
    for(int v = 0; v < MAX_VERTEX; v++)
        g->adjList_H[v] = NULL;

}

void insertVertex(graph *g){

    if(g->n+1 > MAX_VERTEX){

        printf("\n 그래프의 정점의 개수를 초과하였습니다!");

        return;

    }

    g->n++;

}


void insertEdge(graph *g, int u, int v){

    node *N;

    if(u >= g->n || v >= g->n){

        printf("\n 그래프에 없는 정점입니다!");

        return;

    }

    N               = (node*)malloc(sizeof(node));
    N->vertex       = v;
    N->link         = g->adjList_H[u];
    g->adjList_H[u] = N;

}

void print_adjList(graph *g){

    node *p;

    for(int i = 0; i < g->n; i++){

        printf("\n\t\t정점 %c의 인접 리스트", i + 65);

        p   = g->adjList_H[i];

        while(p){

            printf(" -> %c", p->vertex + 65);
            p   = p->link;

        }

    }

}

void main(){

    graph *G1   = (graph*)malloc(sizeof(graph));

    createGraph(G1);

    for(int i = 0; i < 4; i++)
        insertVertex(G1);

    insertEdge(G1, 0, 3);
    insertEdge(G1, 0, 1);
    insertEdge(G1, 1, 3);
    insertEdge(G1, 1, 2);
    insertEdge(G1, 1, 0);
    insertEdge(G1, 2, 3);
    insertEdge(G1, 2, 1);
    insertEdge(G1, 3, 2);
    insertEdge(G1, 3, 1);
    insertEdge(G1, 3, 0);

    print_adjList(G1);

}
