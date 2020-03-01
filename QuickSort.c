/* ========================================================================= *
 * QuickSort.c                                                               *
 * Implementation of the Quick Sort algorithm.                               *
 * ========================================================================= */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "Sort.h"
#include "MedianQueue.h"



struct median_queue_t {
    double* circular;
    double* sorted;
    size_t size;
    size_t start;
};
/* ========================================================================= *
 *                               PROTOTYPES                                  *
 * ========================================================================= */

/* ------------------------------------------------------------------------- *
 * Exchange 2 values of an array                                             *
 * PARAMETERS                                                                *
 *  -array        The array which contain the 2 elements                     *
 *  -i            The indice of the first element                            *
 *  -j            The indice of the second element                           *
 * ------------------------------------------------------------------------- */
void exchange(double* array,size_t i, size_t j);

/* ------------------------------------------------------------------------- *
 * Partition a given array in 2 sub array around a pivot                     *
 * PARAMETERS                                                                *
 *  -array            The array to split                                     *
 *  -pivot            The element around which we divide the table           *
 *  -end              The size of the array                                  git *
 * ------------------------------------------------------------------------- */
size_t partitioning(double* array, size_t pivot, size_t end);

/* ------------------------------------------------------------------------- *
 * Implementation of the Quick Sort algorithm recursively
 * PARAMETERS
 * array        The array to sort
 * begin        The first element of the array
 * end          The size of the array
 * ------------------------------------------------------------------------- */
void quickSort(double* array, size_t begin, size_t end);

/* ------------------------------------------------------------------------- *
 * Implementation of the Quick Sort algorithm recursively
 * PARAMETERS
 * array        The array to sort
 * length       The size of the array
 * ------------------------------------------------------------------------- */
void sort(double* array, size_t length);


/* ========================================================================= *
 *                                 FUNCTIONS
 * ========================================================================= */

void exchange(double* array,size_t i, size_t j){
    int temporary = array[i];
    array[i] = array[j];
    array[j] = temporary;
}
/* ------------------------------------------------------------------------ */
size_t partitioning(double* array, size_t pivot, size_t end){
    size_t j=0, new_pivot = pivot-1;
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
void quickSort(double* array, size_t begin, size_t end){
    if(begin<end){
        size_t q = partitioning(array, begin, end);
        quickSort(array,begin, q-1);
        quickSort(array, q+1, end);
    }
}
/* ------------------------------------------------------------------------ */
void sort(double* array, size_t length){
    //printf("Sorted using : QuickSort\n");

    if(!array || length<=1){
        return;
    }

    quickSort(array, 0, length-1);
}

/* ------------------------------------------------------------------------- *
 * Double comparison function.
 * ------------------------------------------------------------------------- */
static int compareDouble(const void* d1, const void* d2);
static int compareDouble(const void* d1, const void* d2) {
    double diff = (*(double*) d2 - *(double*) d1);
    return diff > 0 ? -1 : (diff < 0 ? 1 : 0);
}

MedianQueue* mqCreate(const double* values, size_t size) {
    // create the median queue
    MedianQueue* mq = malloc(sizeof(MedianQueue));
    if (!mq)
        return NULL;

    mq->size = size;
    mq->start = 0;

    // allocate circular array
    mq->circular = malloc(sizeof(double) * mq->size);
    if (!mq->circular) {
        free(mq);
        return NULL;
    }

    // allocated sorted array
    mq->sorted = malloc(sizeof(double) * mq->size);
    if (!mq->circular) {
        free(mq->circular);
        free(mq);
        return NULL;
    }

    for (size_t i = 0; i < mq->size; ++i) {
        mq->circular[i] = values[i];
        mq->sorted[i] = values[i];
    }

    sort(mq->sorted, mq->size);

    return mq;
}

void mqFree(MedianQueue* mq) {
    free(mq->sorted);
    free(mq->circular);
    free(mq);
}

void mqUpdate(MedianQueue* mq, double value) {
    if (!mq) {
        return;
    }
    mq->circular[mq->start] = value;
    mq->start = (mq->start + 1) % mq->size;
    for (size_t i = 0; i < mq->size; ++i) {
        mq->sorted[i] = mq->circular[(mq->start + i) % mq->size];
    }
    sort(mq->sorted, mq->size);
}

double mqMedian(const MedianQueue* mq) {
    if (!mq) { return INFINITY; }
    return mq->sorted[mq->size / 2];
}
