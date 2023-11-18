#include "sort.h"

/**
 * heap_sort - Sorts an array of integers in ascending order
 * using the Heap sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
    int i;  /* Declare i at the beginning of the block */

    if (array == NULL || size < 2)
        return;

    /* Build the heap (rearrange array) */
    build_heap(array, size);

    /* One by one extract an element from heap */
    for (i = size - 1; i > 0; i--)
    {
        /* Move current root to the end */
        swap(&array[0], &array[i]);
        print_array(array, size);

        /* Call max heapify on the reduced heap */
        heapify(array, i, 0);
    }
}

/**
 * build_heap - Builds a max heap from the array
 * @array: Array to be transformed into a max heap
 * @size: Size of the array
 */
void build_heap(int *array, size_t size)
{
    int i;  /* Declare i at the beginning of the block */

    for (i = size / 2 - 1; i >= 0; i--)
        heapify(array, size, i);
}

/**
 * heapify - Maintains heap property
 * @array: Array to be heapified
 * @size: Size of the heap
 * @index: Index of the current root
 */
void heapify(int *array, size_t size, int index)
{
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    /* Compare with left child */
    if (left < (int)size && array[left] > array[largest])
        largest = left;

    /* Compare with right child */
    if (right < (int)size && array[right] > array[largest])
        largest = right;

    /* If largest is not root */
    if (largest != index)
    {
        swap(&array[index], &array[largest]);
        print_array(array, size);

        /* Recursively heapify the affected sub-tree */
        heapify(array, size, largest);
    }
}

/**
 * swap - Swaps two integers in an array
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
