/* ========================================================================= *
 * QuickSort.c                                                               *
 * Implementation of the Quick Sort algorithm.                               *
 * ========================================================================= */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "Sort.h"

/* ========================================================================= *
 *                               PROTOTYPES                                  *
 * ========================================================================= */

/* ------------------------------------------------------------------------- *
 * Exchange 2 values of an array                                             *
 * PARAMETERS                                                                *
 *  -array        The array which contain the 2 elements                     *
 *  -i            The indice of the first element                            *
 *  -j            The indice of the second element                           *
 *                                                                           *
 * RETURN                                                                    *
 *  /                                                                        *
 * ------------------------------------------------------------------------- */
void exchange(int* array,size_t i, size_t j);

/* ------------------------------------------------------------------------- *
 * Partition a given array in 2 sub array around a pivot                     *
 * PARAMETERS                                                                *
 *  -array            The array to split                                     *
 *  -pivot            The element around which we divide the table           *
 *  -end              The end index of the array                             *
 *                                                                           *
 * RETURN                                                                    *
 *  -new_pivot+1      The array index after the one array's elements are big-*
 *                    ger than the pivot                                     *
 * ------------------------------------------------------------------------- */
size_t partitioning(int* array, size_t pivot, size_t end);

/* ------------------------------------------------------------------------- *
 * Implementation of the Quick Sort algorithm                                *
 * PARAMETERS                                                                *
 *  -array        The array to sort                                          *
 *  -begin        The first element of the array                             *
 *  -end          The size of the array                                      *
 *                                                                           *
 * RETURN                                                                    *
 *  /                                                                        *
 * ------------------------------------------------------------------------- */
void quickSort(int* array, size_t begin, size_t end);

/* ========================================================================= *
 *                                 FUNCTIONS                                 *
 * ========================================================================= */

void exchange(int* array,size_t i, size_t j){
    int temporary = array[i];
    array[i] = array[j];
    array[j] = temporary;
}

size_t partitioning(int* array, size_t begin, size_t end){
    int indexRandom;

    if(begin == (end-1)){
        indexRandom=begin;
    }else{
        indexRandom = rand()%((end-1)-begin)+begin;
    }
    exchange(array, indexRandom, end-1);

    int pivot = array[end-1];
    size_t i = begin;
    for(size_t j = begin; j < end-1; j++){
        if(array[j] <= pivot){
            if(i != j){
                exchange(array, i, j);
            }
            i++;
        }
    }
    exchange(array, i, end-1);
    return i;
}

void quickSort(int* array, size_t begin, size_t end){
    if(begin<end){
        size_t q = partitioning(array, begin, end);
        quickSort(array, begin, q);
        quickSort(array, q+1, end);
    }
}

void sort(int* array, size_t length){
    printf("Sorted using : QuickSort\n");

    if(!array || length<=1){
        return;
    }

    quickSort(array, 0, length);
}
