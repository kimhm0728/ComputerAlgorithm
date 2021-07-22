#ifndef _REDIXSORT
#define _REDIXSORT

typedef struct queue{
    int head; // 후단
    int tail; // 전단
    int data[SIZE];
}QUEUE;
int isEmptyQueue(QUEUE* q) {
    if(q->head==q->tail) return -1;
    else return 0;
}
void enQueue(QUEUE* q, int num) {
    q->data[q->head++]=num;
    q->head=q->head%SIZE;
}
int deQueue(QUEUE* q) {
    int num;
    if(!isEmptyQueue(q)) num=q->data[q->tail++];
    else return -1;
    q->tail=q->tail%SIZE;
    return num;
}
void initQueue(QUEUE* q) {
    q->head=q->tail=0;
    for(int i=0;i<SIZE;i++) q->data[i]=0;
}

void initBuckets(QUEUE* q, int k) {
    for(int i=0;i<k;i++) initQueue(&q[i]);
}
void sorting(int A[], int n, int k) {
    QUEUE buckets[10];
    int j=1;
    int position;
    initBuckets(buckets, 10);
    for(int i=1;i<=n;i++){
        position=(A[i]/(int)pow(10, k-1))%10; // k번째 자리수의 값이 몇인지 추출
        enQueue(&buckets[position], A[i]);
    }
    for(int i=0;i<10;i++){
        int num;
        while((num=deQueue(&buckets[i]))!=-1) A[j++]=num;
    }
}
void radixSort(int A[], int n, int k) {
    for(int i=1;i<=k;i++)
        sorting(A, n, i);
}

#endif 