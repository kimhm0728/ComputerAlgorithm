#ifndef _HEAPSORT
#define _HEAPSORT
#include "util.h"

void heapify(int A[], int k, int n) {
    int left=2*k;
    int right=2*k+1;
    int smaller;
    if(right<=n){ // 두 자식 모두 가진 경우
        if(A[left]<A[right]) smaller=left; 
        else smaller=right;
    }
    else if(left<=n) smaller=left; // 왼쪽 자식만 가진 경우
    else return; // 자식이 없는 경우 (리프 노드)
    if(A[smaller]<A[k]) {
        swap(&A[smaller], &A[k]);
        heapify(A, smaller, n);
    }
}

void buildHeap(int A[], int n) {
    for(int i=n/2;i>=1;i--){ // i는 리프 노드를 제외한 가장 마지막 노드부터 시작
        heapify(A, i, n);
    }
}

void heapSort(int A[], int n) {
    buildHeap(A, n);
    for(int i=n;i>=2;i--){
        swap(&A[1], &A[i]);
        heapify(A, 1, i-1);
    }
}

#endif