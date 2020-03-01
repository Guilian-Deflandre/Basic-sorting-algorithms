/* ========================================================================= *
 * InsertionSort.c                                                           *
 * Implementation of the InsertionSort algorithm.                            *
 * ========================================================================= */

#include <stddef.h>
#include <stdio.h>

#include "Sort.h"

/* ========================================================================= *
 *                                 PROTOTYPES                                *
 * ========================================================================= */

/* ------------------------------------------------------------------------- *
 * Sort an array of size lenght using the Insertion Sort algorithm           *
 *                                                                           *
 * PARAMETERS                                                                *
 * array        The array to sort                                            *
 * length       The size of the array                                        *
 *                                                                           *
 * RETURN                                                                    *
 * /                                                                         *
 * ------------------------------------------------------------------------- */
void sort(double* array, size_t length);

/* ========================================================================= *
 *                                 FUNCTIONS                                 *
 * ========================================================================= */

void sort(int* array, size_t length){

    printf("Sorted using : InsertionSort\n");
    if(!array)
        return;

    int j;
    int tmp;
    for (size_t i = 0; i < length; i++){
        tmp = array[i];
        j = i;
        while(j > 0 && array[j-1] > tmp){
            array[j] = array[j-1];
            j--;
        }
        array[j]=tmp;
    }
}
