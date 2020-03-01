/* ========================================================================= *
 * QuickSort
 * Implementation of the Quick Sort algorithm.
 * ========================================================================= */

#include <stdio.h>
#include "Sort.h"

/* ========================================================================= *
 *                               PROTOTYPES
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
 * Partition a given array in 2 sub array around a pivot
 * PARAMETERS
 * array            The array to split
 * pivot            The element around which we divide the table
 * end              The size of the array
 * ------------------------------------------------------------------------- */
int partitioning(int* array, int pivot, int end);

/* ------------------------------------------------------------------------- *
 * Implementation of the Quick Sort algorithm recursively
 * PARAMETERS
 * array        The array to sort
 * begin        The first element of the array
 * end          The size of the array
 * ------------------------------------------------------------------------- */
void quickSort(int* array, int begin, int end);


/* ========================================================================= *
 *                                 FUNCTIONS
 * ========================================================================= */

void exchange(int* array,int i, int j){
    int temporary = array[i];
    array[i] = array[j];
    array[j] = temporary;
}
/* ------------------------------------------------------------------------ */
int partitioning(int* array, int pivot, int end){
    int j=0, new_pivot = pivot-1;
    for(j=pivot;j<end;j++){
        if(array[j] <= array[end]){
            new_pivot++;
            exchange(array, new_pivot, j);
        }
    }
    exchange(array, new_pivot+1, end);
    return new_pivot+1;
}
/* ------------------------------------------------------------------------ */
void quickSort(int* array, int begin, int end){
    if(begin<end){
        int q = partitioning(array, begin, end);
        quickSort(array,begin, q-1);
        quickSort(array, q+1, end);
    }
}
/* ------------------------------------------------------------------------ */
void sort(int* array, size_t length){
    printf("Sorted using : QuickSort\n");
    
    if(!array || length<=1){
        return;
    }
    
    quickSort(array, 0, length-1);
}
