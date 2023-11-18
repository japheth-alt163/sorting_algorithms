#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * radix_sort - Sorts an array of integers in ascending order
 * using the Radix sort algorithm (LSD)
 * @array: Array to be sorted
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    /* Find the maximum number to determine the number of digits */
    int max = array[0];
    size_t i;

    for (i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    /* Perform counting sort for every digit place (exp) */
    int exp;
    for (exp = 1; max / exp > 0; exp *= 10)
    {
        counting_sort(array, size, exp);
        print_array(array, size);
    }
}

/**
 * counting_sort - Performs counting sort on the specified digit place
 * @array: Array to be sorted
 * @size: Size of the array
 * @exp: Current digit place (10^exp)
 */
void counting_sort(int *array, size_t size, int exp)
{
    /* Allocate memory for the output array */
    int *output = malloc(size * sizeof(int));
    int count[10] = {0}; // Initialize count array
    size_t i;

    if (output == NULL)
        return;

    /* Count occurrences of each digit in the input array */
    for (i = 0; i < size; i++)
        count[(array[i] / exp) % 10]++;

    /* Modify count array to store the position of each digit in the output array */
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    /* Build the output array */
    for (int i = size - 1; i >= 0; i--)
    {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    /* Copy the output array to the original array */
    for (i = 0; i < size; i++)
        array[i] = output[i];

    /* Free the allocated memory */
    free(output);
}
