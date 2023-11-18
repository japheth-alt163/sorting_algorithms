#include "sort.h"

void merge_sort_recursive(int *array, int *temp, size_t start, size_t end);

/**
 * merge_sort - Sorts an array of integers in ascending order
 * using the Merge sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
    /* Allocate temporary array for merging */
    int *temp = malloc(size * sizeof(int));

    if (array == NULL || size < 2)
        return;
    if (temp == NULL)
        return;

    /* Call the recursive merge sort function */
    merge_sort_recursive(array, temp, 0, size - 1);

    free(temp);
}

/**
 * merge_sort_recursive - Recursively sorts an array of integers
 * using the Merge sort algorithm
 * @array: Array to be sorted
 * @temp: Temporary array for merging
 * @start: Start index of the sub-array
 * @end: End index of the sub-array
 */
void merge_sort_recursive(int *array, int *temp, size_t start, size_t end)
{
    if (start < end)
    {
        /* Divide the array into two halves */
        size_t mid = start + (end - start) / 2;

        /* Recursively sort the left and right halves */
        merge_sort_recursive(array, temp, start, mid);
        merge_sort_recursive(array, temp, mid + 1, end);

        /* Merge the sorted halves */
        merge_arrays(array, temp, start, mid, end);
    }
}

/**
 * merge_arrays - Merges two sorted arrays into one
 * @array: Original array
 * @temp: Temporary array for merging
 * @start: Start index of the first sub-array
 * @mid: End index of the first sub-array
 * @end: End index of the second sub-array
 */
void merge_arrays(int *array, int *temp, size_t start, size_t mid, size_t end)
{
    size_t i = start;
    size_t j = mid + 1;
    size_t k = start;

    printf("Merging...\n[left]: ");
    print_array(array + start, mid - start + 1);
    printf("[right]: ");
    print_array(array + mid + 1, end - mid);

    while (i <= mid && j <= end)
    {
        if (array[i] <= array[j])
            temp[k++] = array[i++];
        else
            temp[k++] = array[j++];
    }

    while (i <= mid)
        temp[k++] = array[i++];

    while (j <= end)
        temp[k++] = array[j++];

    for (i = start; i <= end; i++)
        array[i] = temp[i];

    printf("[Done]: ");
    print_array(array + start, end - start + 1);
}
