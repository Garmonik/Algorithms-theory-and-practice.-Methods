#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

struct otrez{
    int leftPoint;
    int rightPoint;
};

int compare(const void* a, const void* b);

int main(){
    int n, a, b, i, counter=0, j;
    int point[100];
    struct otrez* ptr;

    scanf("%d", &n);

    ptr = (struct otrez*)malloc(sizeof(struct otrez)*n);

    for (i = 0; i < n && scanf("%d %d", &a, &b); i++) {
        ptr[i].leftPoint = a;
        ptr[i].rightPoint = b;
    }

    qsort((void *)ptr, n,sizeof(struct otrez), compare);

    counter++;
    point[0] = ptr[0].rightPoint;
    
    for(i = 1, j=0; i < n; i++) {
        if(ptr[i].leftPoint > point[j]) {
            counter++;
            point[++j] = ptr[i].rightPoint;
        }
    }
    printf("%d\n", counter);

    for(i=0; i<counter; i++)
        printf("%d%s",point[i], i+1==counter?"\n":" ");

}

int compare(const void* a, const void* b) {
    struct otrez* a_ptr, *b_ptr;
    a_ptr = (struct otrez*)a;
    b_ptr = (struct otrez*)b;

    if (a_ptr->rightPoint < b_ptr->rightPoint)
        return -1;
    else if (a_ptr->rightPoint > b_ptr->rightPoint)
        return 1;
    else
        return 0;
}

/*for(i = 0; i < n; i++)
    printf("%d-%d ", ptr[i].leftPoint, ptr[i].rightPoint);
printf("\nposle sort: \n");*/
