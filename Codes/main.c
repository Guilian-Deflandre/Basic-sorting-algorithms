#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "Array.h"
#include "Sort.h"

/* ========================================================================= *
 *                                 PROTOTYPES                                *
 * ========================================================================= */
 /* ------------------------------------------------------------------------- *
  * Compute the CPU time (in seconds) used by the Sort function.              *
  *                                                                           *
  * PARAMETERS                                                                *
  *  -array        Array to sort                                              *
  *  -length       Number of elements in the array                            *
  *                                                                           *
  * RETURN                                                                    *
  *  -seconds      The number of seconds used by Sort                         *
  * ------------------------------------------------------------------------- */
static double cpuTimeUsedToSort(int* array, size_t length);

/* ------------------------------------------------------------------------- *
 * Print a given array in format: [array[0] array[1] ... array[length-1]]    *
 *                                                                           *
 * PARAMETERS                                                                *
 *  -array        Array to print                                             *
 *  -length       Number of elements in the array                            *
 *                                                                           *
 * RETURN                                                                    *
 *  /                                                                        *
 * ------------------------------------------------------------------------- */
void printArray(int* array, size_t length);


/* ========================================================================= *
 *                                 FUNCTIONS                                 *
 * ========================================================================= */
static double cpuTimeUsedToSort(int* array, size_t length){
    clock_t start = clock();
    sort(array, length);
    return ((double) (clock() - start)) / CLOCKS_PER_SEC;
}

void printArray(int* array, size_t length){
    printf("Size of the array: %d\n", (int) length);
    printf("[ ");
    for(size_t i=0; i<length; i++){
        printf("%d ", array[i]);
    }
    printf("]");
    printf("\n");
}



/* ------------------------------------------------------------------------- *
 * Main                                                                      *
 * ------------------------------------------------------------------------- */
int main(void){
    size_t sizeArray = 10;
    int* array = createRandomArray(sizeArray);

    srand(time(NULL));

    printf("Initial array:");
    printArray(array, sizeArray);

    const double sec = cpuTimeUsedToSort(array, sizeArray);
    
    printf("Sorted array:");
    printArray(array, sizeArray);

    printf("CPU Time for sizeArray = %zu: %f\n", sizeArray, sec);
    printf("\n");

    free(array);

    return 0;
}
