/* ========================================================================= *
 * MergeSort.c                                                               *
 * Implementation of the Merge Sort algorithm.                               *
 * ========================================================================= */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>

#include "Sort.h"

/* ========================================================================= *
 *                                 PROTOTYPES                                *
 * ========================================================================= */

/* ------------------------------------------------------------------------- *
 * Merge 2 given subarrays A[p;q] & A[q+1;r] into a single array A[p;r]      *
 *                                                                           *
 * PARAMETERS                                                                *
 *  -array        The array to treat                                         *
 *  -p            Beginning of the array                                     *
 *  -q            End of the first sub array                                 *
 *  -r            End of the second sub array and the array                  *
 *                                                                           *
 * RETURN                                                                    *
 * /                                                                         *
 * ------------------------------------------------------------------------- */
void merge(int* array, int p, int q, int r);

/* ------------------------------------------------------------------------- *
 * Implementation of the Merge Sort algorithm                                *
 *                                                                           *
 * PARAMETERS                                                                *
 *  -array        The array which contain the 2 elements                     *
 *  -i            The indice of the first element of the array               *
 *  -j            The indice of the last element of the array                *
 *                                                                           *
 * RETURN                                                                    *
 * /                                                                         *
 * ------------------------------------------------------------------------- */
void mergeSort(int* array, int p, int r);

/* ------------------------------------------------------------------------- *
 * Sort an array of size lenght using the Merge Sort algorithm               *
 *                                                                           *
 * PARAMETERS                                                                *
 *  -array        The array to sort                                          *
 *  -length       The size of the array                                      *
 *                                                                           *
 * RETURN                                                                    *
 * /                                                                         *
 * ------------------------------------------------------------------------- */
void sort(double* array, size_t length);

/* ========================================================================= *
 *                                 FUNCTIONS                                 *
 * ========================================================================= */

void merge(int* array, int p, int q, int r){

    int sizeBegin = q-p+1, sizeEnd = r-q, i, j, k;
    int* begin = malloc((sizeBegin+1)*sizeof(int));
    assert(begin!=NULL);
    int* end = malloc((sizeEnd+1)*sizeof(int));
    assert(begin!=NULL);

    for(i=0;i<sizeBegin;i++){
        begin[i] = array[p+i];
    }
    for(j=0;j<sizeEnd;j++){
        end[j] = array[q+j+1];
    }

    begin[sizeBegin] = INT_MAX;
    end[sizeEnd] = INT_MAX;
    i = 0;
    j = 0;

    for(k=p; k<=r;k++){
        if(begin[i]<=end[j]){
            array[k] = begin[i];
            i++;
        }else{
            array[k] = end[j];
            j++;
        }
    }
    free(end);
    free(begin);
}

void mergeSort(int* array, int p, int r){
    if(p<r){
        int q = (p+r)/2;
        mergeSort(array,p,q);
        mergeSort(array,q+1, r);
        merge(array,p,q,r);
    }
}

void sort(int* array, size_t length){
    printf("Sorted using : MergeSort\n");

    if(!array || length<=1){
        return;
    }

    mergeSort(array, 0, length-1);
}
