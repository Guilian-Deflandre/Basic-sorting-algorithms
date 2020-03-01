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
 * array        Array to sort                                                *
 * length       Number of elements in the array                              *
 *                                                                           *
 * RETURN                                                                    *
 * seconds      The number of seconds used by Sort                           *
 * ------------------------------------------------------------------------- */
static double cpuTimeUsedToSort(int* array, size_t length){
    clock_t start = clock();
    sort(array, length);
    return ((double) (clock() - start)) / CLOCKS_PER_SEC;
}



/* ------------------------------------------------------------------------- *
 * Main                                                                      *
 * ------------------------------------------------------------------------- */
int main(void){
    size_t sizeArray = 10;
    int* array = createRandomArray(sizeArray);

    srand(time(NULL));
    printf("Size of the array: %d\n", (int) sizeArray);

    for(size_t i=0;i<sizeArray;i++){
        printf("%d ", array[i]);
    }

    printf("\n");

    const double sec = cpuTimeUsedToSort(array, sizeArray);

    printf("CPU Time for sizeArray = %zu: %f\n", sizeArray, sec);
    printf("\n");

    return 0;
}
