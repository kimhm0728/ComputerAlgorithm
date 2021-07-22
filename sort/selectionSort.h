#ifndef _SELECTIONSORT
#define _SELECTIONSORT
#include "util.h"

int theLargest(int A[], int last) {
    int largest=1;
    for(int i=2;i<=last;i++){
        if(A[largest]<A[i]) largest=i;
    }
    return largest;
}

void selectionSort(int A[], int n) {
    int k; // 가장 큰 수의 인덱스 저장
    for(int last=n;last>1;last--) {
        k=theLargest(A, last);
        swap(&A[k], &A[last]);
    }
}

#endif