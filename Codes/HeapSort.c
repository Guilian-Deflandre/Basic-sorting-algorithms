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

 void sort(int* array, size_t length){
 	heapSort(array, length);
 }

 void heapSort(int* array, size_t length){
 	buildMaxHeap(array, length);
 	for (size_t i = length-1; i > 0; --i){
 		exchange(array, i, 0);
 		--length;
 		maxHeapify(array, 0, length);
 	}
 }

 void buildMaxHeap(int* array, size_t length){
 	for (int i = length/2 ; i >= 0 ; --i){
 		maxHeapify(array, i, length);
 	}
 }

 void maxHeapify(int* array, size_t index, size_t heapSize){
 	size_t indexLeft = 2*index, indexRight = 2*index + 1, indexLargest = index;

 	if(indexLeft < heapSize && array[indexLeft] > array[index])
 		indexLargest = indexLeft;
 	if(indexRight < heapSize && array[indexRight] > array[indexLargest])
 		indexLargest = indexRight;
 	if(indexLargest != index){
 		exchange(array, index, indexLargest);
 		maxHeapify(array, indexLargest, heapSize);
 	}
 }

 void exchange(int* array, size_t i, size_t j){
 	int tmp = array[i];
 	array[i] = array[j];
 	array[j] = tmp;
 }
