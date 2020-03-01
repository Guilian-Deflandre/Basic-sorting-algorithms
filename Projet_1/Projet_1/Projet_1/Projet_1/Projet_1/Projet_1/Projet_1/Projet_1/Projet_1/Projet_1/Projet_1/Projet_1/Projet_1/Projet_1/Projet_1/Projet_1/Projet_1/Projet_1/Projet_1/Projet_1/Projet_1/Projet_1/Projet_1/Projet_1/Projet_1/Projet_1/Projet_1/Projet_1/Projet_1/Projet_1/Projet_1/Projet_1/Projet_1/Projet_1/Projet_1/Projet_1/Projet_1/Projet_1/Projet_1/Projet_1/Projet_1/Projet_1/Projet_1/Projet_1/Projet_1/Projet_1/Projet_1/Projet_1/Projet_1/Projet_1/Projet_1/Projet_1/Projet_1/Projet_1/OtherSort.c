/* ========================================================================= *
 * MergeSort
 * Implementation of the Merge Sort algorithm.
 * ========================================================================= */

#include <stdio.h>
#include "Sort.h"

/* ========================================================================= *
 *                                 PROTOTYPES
 * ========================================================================= */

/* ------------------------------------------------------------------------- *
 * Exchange 2 values of an array
 * PARAMETERS
 * array        The array which contain the 2 elements
 * i            The indice of the first element
 * j            The indice of the second element
 * ------------------------------------------------------------------------- */
void exchange(int* array,int i, int j);

/* ------------------------------------------------------------------------- *
 *Sort an array recursively
 * PARAMETERS
 * array        The array to treat
 * begin        The beginnig of the array
 * end          The end of the array
 * ------------------------------------------------------------------------- */
void otherSort(int* array, int begin, int end);

/* ========================================================================= *
 *                                FUNCTIONS
 * ========================================================================= */

void exchange(int* array,int i, int j){
    int temporary = array[i];
    array[i] = array[j];
    array[j] = temporary;
}
/* ------------------------------------------------------------------------ */
void otherSort(int* array, int begin, int end){
    int thirdArray;
    
    if (array[begin] > array[end]){
        exchange(array, begin, end);
    }
    if ((begin + 1) >= end){
        return;
    }
    thirdArray = ((end - begin + 1) / 3);
    otherSort(array, begin, end - thirdArray);
    otherSort(array, begin + thirdArray, end);
    otherSort(array, begin, end - thirdArray);
}
/* ------------------------------------------------------------------------ */
void sort(int* array, size_t lenght){
    printf("Tier par OtherSort  \n");
    
    if(!array || lenght<=1){
        return;
    }
    
    otherSort(array, 0, lenght-1);
}
