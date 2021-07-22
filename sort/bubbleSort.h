#ifndef _BUBBLESORT
#define _BUBBLESORT
#include "util.h"

void bubbleSort(int A[], int n) {
    for(int last=n;last>1;last--){
        int sorted=1;
        for(int i=1;i<last;i++){
            if(A[i]>A[i+1]) {
                swap(&A[i], &A[i+1]);
                sorted=0;
            }
        }
        if(sorted==1) return;
    }
}

#endif