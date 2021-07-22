#ifndef _UTIL
#define _UTIL
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define SIZE 101
#define SWAP(x, y, temp) ((temp)=(x), (x)=(y), (y)=(temp)) // SWAP 매크로 함수

void swap(int* a, int* b) {
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void makeRandom(int array[], int n) {
    srand(time(NULL));
    for(int i=1;i<=n;i++){
        array[i]=(rand()%100)+1; // 1~100 
    }
}
void printArray(int array[], int n) {
    for(int i=1;i<=n;i++) printf("%d ",array[i]);
    printf("\n\n");
}

#endif