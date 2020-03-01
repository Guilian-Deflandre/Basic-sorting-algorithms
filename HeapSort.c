/* ========================================================================= *
 * HeapSort.c                                                                *
 * Implementation of the Heap Sort algorithm.                                *
 * ========================================================================= */

#include <stdio.h>
#include "Sort.h"

/* ========================================================================= *
 *                                 PROTOTYPES                                *
 * ========================================================================= */

/* ------------------------------------------------------------------------- *
 * Transform a given heap into a max heap (bigger elements on the top)       *
 * PARAMETERS                                                                *
 *  -array        The array used to create an heap                           *
 *  -node         The index of the node                                      *
 *  -heapSize     The size of the heap to transform                          *
 * ------------------------------------------------------------------------- */
void maxHeapify(int* array,int node, int heapSize);

/* ------------------------------------------------------------------------- *
 * Exchange 2 values of an array                                             *
 * PARAMETERS                                                                *
 *  -array        The array which contain the 2 elements                     *
 *  -i            The first element's index                                  *
 *  -j            The second element's index                                 *
 * ------------------------------------------------------------------------- */
void exchange(int* array,int i, int j);

/* ------------------------------------------------------------------------- *
 * Build an heap based on a given array                                      *
 * PARAMETERS                                                                *
 *  -array        The array used to build an heap                            *
 *  -length       The size of this array                                     *
 * ------------------------------------------------------------------------- */
void buildMaxHeap(int* array, int length);

/* ========================================================================= *
 *                                FUNCTIONS                                  *
 * ========================================================================= */

void exchange(int* array,int i, int j){
    int temporary = array[i];
    array[i] = array[j];
    array[j] = temporary;
}

void buildMaxHeap(int* array, int length){
    for(int i=(length)/2;i>=0;i--){
        maxHeapify(array, i, length);
    }
}

void maxHeapify(int* array, int node, int heapSize){
    int left = (2*node), right = (2*node)+1, largest;

    if(left<=array[heapSize] && array[left]>array[node]){
        largest = left;
    }else{
        largest = node;
    }
    if(right<=array[heapSize] && array[right]>array[node]){
        largest = right;
    }
    if(largest!=node){
        exchange(array, node, largest);
        maxHeapify(array, largest, heapSize);
    }
}

void sort(int* array, size_t length){
    int  heapSize = length;
    printf("Sorted using : HeapSort\n");

    if(!array || length<=1){
        return;
    }

    buildMaxHeap(array, length);
    for(int i=length;i>=0;i--){
        exchange(array, i, 1);
        heapSize--;
        maxHeapify(array, 0, heapSize);
    }
}
