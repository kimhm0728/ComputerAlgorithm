#ifndef _MERGESORT
#define _MERGESORT
#include "util.h"

int tmp[SIZE]={0};

void merge(int A[], int p, int q, int r){
    int i=p, j=q+1, t=1;
    while(i<=q && j<=r){
        if(A[i]>=A[j]) tmp[t++]=A[j++];
        else tmp[t++]=A[i++];
    }
    while(i<=q) tmp[t++]=A[i++];
    while(j<=r) tmp[t++]=A[j++];
    i=p, t=1;
    while(i<=r) A[i++]=tmp[t++];
}

void mergeSort(int A[], int p, int r) {
    if(p<r){
        int q=(p+r)/2;
        mergeSort(A, p, q);
        mergeSort(A, q+1, r);
        merge(A, p, q, r);
    }
}

#endif
