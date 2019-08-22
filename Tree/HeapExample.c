#include<stdio.h>
#include<stdlib.h>

typedef struct heap{

    int heap[100];
    int heap_size;

}heap;

heap* initHeap(){

    heap *h         = (heap*)malloc(sizeof(heap));
    h->heap_size    = 0;

    return h;

}

void insertHeap(heap *h, int data){

    int i;
    i   = ++h->heap_size;

    while(i != 1 && data > h->heap[i/2]){

        h->heap[i]  = h->heap[i/2];

        i   /= 2;

    }

    h->heap[i]  = data;

}

int deleteHeap(heap *h){

    int parent, child, item, temp;

    item    = h->heap[1];
    temp    = h->heap[h->heap_size--];
    parent  = 1;
    child   = 2;

    while(child <= h->heap_size){

        if(child < h->heap_size && h->heap[child] < h->heap[child+1])
            child++;

        if(temp >= h->heap[child])
            break;

        h->heap[parent] = h->heap[child];
        parent          = child;
        child *= 2;

    }

    h->heap[parent] = temp;

    return item;


}

void printHeap(heap *h){

    for(int i = 1; i <= h->heap_size; i++){

        printf("%d", h->heap[i]);

    }

    printf("\n");

}

int main(){

    heap *h = (heap*)malloc(sizeof(heap));
    h       = initHeap();

    insertHeap(h, 10);
    insertHeap(h, 20);
    insertHeap(h, 30);

    printHeap(h);

    printf("%d\n", deleteHeap(h));

    printHeap(h);

}
