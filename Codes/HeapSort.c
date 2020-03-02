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
 *                                                                           *
 * PARAMETERS                                                                *
 *  -array        The array used to create an heap                           *
 *  -node         The index of the node                                      *
 *  -heapSize     The size of the heap to transform                          *
 *                                                                           *
 * RETURN                                                                    *
 *  /                                                                        *
 * ------------------------------------------------------------------------- */
void maxHeapify(int* array, size_t node, size_t heapSize);

/* ------------------------------------------------------------------------- *
 * Exchange 2 values of an array                                             *
 *                                                                           *
 * PARAMETERS                                                                *
 *  -array        The array which contain the 2 elements                     *
 *  -i            The first element's index                                  *
 *  -j            The second element's index                                 *
 *                                                                           *
 * RETURN                                                                    *
 *  /                                                                        *
 * ------------------------------------------------------------------------- */
void exchange(int* array, size_t i, size_t j);

/* ------------------------------------------------------------------------- *
 * Build an heap based on a given array                                      *
 *                                                                           *
 * PARAMETERS                                                                *
 *  -array        The array used to build an heap                            *
 *  -length       The size of this array                                     *
 *                                                                           *
 * RETURN                                                                    *
 *  /                                                                        *
 * ------------------------------------------------------------------------- */
void buildMaxHeap(int* array, size_t length);

/* ------------------------------------------------------------------------- *
 * Sort an array using the Heap Sort algorithm                               *
 *                                                                           *
 * PARAMETERS                                                                *
 *  -array        The array used to build an heap                            *
 *  -length       The size of this array                                     *
 *                                                                           *
 * RETURN                                                                    *
 *  /                                                                        *
 * ------------------------------------------------------------------------- */
void heapSort(int* array, size_t length);

/* ========================================================================= *
 *                                FUNCTIONS                                  *
 * ========================================================================= */

void exchange(int* array, size_t i, size_t j){
    int temporary = array[i];
    array[i] = array[j];
    array[j] = temporary;
}

void buildMaxHeap(int* array, size_t length){
    for(size_t i=(length/2); i>=0; i--){
        maxHeapify(array, i, length);
    }
}

void maxHeapify(int* array, size_t node, size_t heapSize){
    size_t left = (2*node), right = (2*node)+1, largest = node;

    if(left<heapSize && array[left]>array[node]){
        largest = left;
    }if(right<heapSize && array[right]>array[largest]){
        largest = right;
    }if(largest != node){
        exchange(array, node, largest);
        maxHeapify(array, largest, heapSize);
    }
}

void heapSort(int* array, size_t length){
    size_t heapSize = length;
    printf("Sorted using : HeapSort\n");

    if(!array || length<=1){
        return;
    }

    buildMaxHeap(array, length);
    for(size_t i=heapSize-1; i > 0; i--){
        exchange(array, i, 0);
        heapSize--;
        maxHeapify(array, 0, heapSize);
    }
}

void sort(int* array, size_t length){
    heapSort(array, length);
}
