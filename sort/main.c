//selection sort implementation
#include "selectionSort.h"
#include "util.h"
#include "insertionSort.h"
#include "mergeSort.h"
#include "bubbleSort.h"
#include "quickSort.h"
#include "heapSort.h"
#include "radixSort.h"
#include "countingSort.h"

int main()
{
    int start, end;
    int array[MAX_SIZE];
    makeRandom(array, MAX_SIZE-1);
    printf("정렬 전 배열 -> \n");
    printArray(array, MAX_SIZE-1);
    int Sortedarray[MAX_SIZE]={0};
    
    start=clock();
    //selectionSort(array, SIZE-1);
    //insertionSort(array, SIZE-1);
    //mergeSort(array, 1, SIZE-1);
    //bubbleSort(array, SIZE-1);
    //quickSort(array, 1, SIZE-1);
    //heapSort(array, SIZE-1);
    //radixSort(array, SIZE-1, 4);
    countingSort(array, Sortedarray, MAX_SIZE);
    end=clock();
    printf("정렬 후 배열 -> \n");
    printArray(Sortedarray, MAX_SIZE-1);
    printf("MS = %lf\n", (double)(end-start)/CLOCKS_PER_SEC);
    return 0;
}
