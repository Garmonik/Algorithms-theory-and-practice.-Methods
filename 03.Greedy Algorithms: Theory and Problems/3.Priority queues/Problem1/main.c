#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NL printf("\n")

void swap(int *a, int *b){
    int t;
    
    t = *a;
    *a = (*b);
    *b = t;
}

struct Heap{
    int *root;
    int size;
};

typedef struct Heap Heap;

void init(Heap *h, int n){
    h->root = malloc(n * sizeof(int));
    h->size = n;
}

int Parent(int i){
    return (i - 1) / 2;
}

int Left(int i){
    return 2 * i + 1;
}

int Right(int i){
    return 2 * i + 2;
}

void siftUp(Heap *h){
    int child, parent;
    
    child = h->size - 1, parent = Parent(child);
    while(child > 0 && h->root[child] > h->root[parent]){
        swap(&(h->root[child]), &(h->root[parent]));
        child = parent;
        parent = Parent(child);
    }
}

void siftDown(Heap *h){
    int child, parent;
    
    parent = 0, child = Left(parent);
    while (child < h->size){
        if(Right(parent) < h->size && h->root[Right(parent)] > h->root[child]){
            child = Right(parent);
        }
        if(h->root[parent] >= h->root[child]){
            break;
        }
        swap(&(h->root[parent]), &(h->root[child]));
        parent = child;
        child = Left(parent);
    }
}


void insert(Heap *h, int elem){
    if(h->size){
        h->size++;
        h->root = realloc(h->root, h->size * sizeof(int));
    }
    else {
        init(h, 1);
    }
    h->root[h->size - 1] = elem;
    siftUp(h);
}


int extractMax(Heap *h){
    if (h->size == 0){
        return -1;
    }
    int max = h->root[0];
    (h->size)--;
    h->root[0] = h->root[h->size];
    h->root = realloc(h->root, h->size * sizeof(int));
    siftDown(h);
    return max;
}

void print(Heap *h){
    if (h->root == NULL){
        return;
    }
    int i, j, *p;
    p = h->root;

    puts("Current state: ");
    for(i = 0; i < h->size; i = i * 2 + 1){
        for(j = i; j <= 2 * i && j < h->size; j++){
            printf("%10d", *p++);
        }
            NL;
    }
    NL;

}

void read(Heap *h){
    int x;
    char cmd[11];
    
    scanf("%s", &cmd);
    if(strcmp(cmd, "Insert") == 0){
        scanf("%d", &x);
        insert(h, x);
    }
    else{
        printf("%d\n", extractMax(h));
    }
    //print(h);
}

int main(){
    int n;
    Heap *h;
    h = malloc(sizeof(Heap));
    scanf("%d", &n);
    
    while(n--){
        read(h);
    }
}
