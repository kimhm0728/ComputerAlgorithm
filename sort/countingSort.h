#ifndef _COUNTINGSORT
#define _COUNTINGSORT

#define MAX_NUM 100 // 값의 범위
#define MAX_SIZE 101 // 배열 사이즈

void countingSort(int A[], int B[], int n) {
    int C[MAX_SIZE]={0};
    for(int j=1;j<=n;j++) C[A[j]]++;
    for(int i=2;i<=MAX_NUM;i++) C[i]=C[i]+C[i-1];
    for(int j=n;j>=1;j--) {
        B[C[A[j]]]=A[j];
        C[A[j]]--;
    }
}

#endif