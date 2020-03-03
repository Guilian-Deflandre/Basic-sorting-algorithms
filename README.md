# Basic sorting algorithms

## Basics
In this repository are implemented several basic sorting algorithms, namely

* The Insertion Sort algorithm in `InsertionSort.c`;
* The Quick Sort algorithm in `QuickSort.c`;
* The Merge Sort algorithm in `MergeSort.c`;
* The Heap Sort algorithm in `HeapSort.c`;

It also implement an uncommon algorithm named Other Sort in `OtherSort.c`. This algorithm works as follow

1. If the array has a size smaller or equal to one, it does nothing;
2. If the leftmost element of the table is wider than the rightmost element, swap them;
3. If there are at least three elements in the array,
    * (i)   The first two thirds of the table are sorted recursively;
    * (ii)  The last two thirds of the table are sorted;
    * (iii) The first two-thirds are re-sorted again;

## Main
The `main.c` file is a simple tester for the whole implementation. It provide the CPU compilation time for a given sorting algorithm (at the compilation) and a given array size (that can be alter in the main function changing the `sizeArray` variable).

This file also use the `Array.h` interface implemented in the `Array.c` file. These only initialize a random array of length `sizeArray`. This array will be then use by the chosen sorting algorithm.

## Usage

One can compile the code using

``bash
gcc main.c Array.c BasicSortingAlgorithm.c -o ExecutableName
``

where `BasicSortingAlgorithm.c` can be either `InsertionSort.c`, `QuickSort.c`, `MergeSort.c`, `HeapSort.c`
or `OtherSort.c` and `ExecutableName` will be the chosen name of you `.exe` file.
