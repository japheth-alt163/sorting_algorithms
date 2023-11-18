#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * bitonic_sort - Sorts an array of integers in ascending order
 * using the Bitonic sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array (must be a power of 2)
 */
void bitonic_sort(int *array, size_t size)
{
    if (array == NULL || size < 2 || !is_power_of_two(size))
        return;

    bitonic_recursive_sort(array, size, ASCENDING);
}

/**
 * bitonic_recursive_sort - Recursively performs Bitonic sort
 * @array: Array to be sorted
 * @size: Size of the array
 * @dir: Sorting direction (ASCENDING or DESCENDING)
 */
void bitonic_recursive_sort(int *array, size_t size, int dir)
{
    if (size > 1)
    {
        size_t half = size / 2;

        printf("Merging [%lu/%lu] (%s):\n", size, size, (dir == ASCENDING) ? "UP" : "DOWN");
        print_array(array, size);

        bitonic_recursive_sort(array, half, ASCENDING);
        bitonic_recursive_sort(array + half, half, DESCENDING);

        bitonic_merge(array, size, dir);

        printf("Result [%lu/%lu] (%s):\n", size, size, (dir == ASCENDING) ? "UP" : "DOWN");
        print_array(array, size);
    }
}

/**
 * bitonic_merge - Merges two Bitonic sequences
 * @array: Array to be merged
 * @size: Size of the array
 * @dir: Merging direction (ASCENDING or DESCENDING)
 */
void bitonic_merge(int *array, size_t size, int dir)
{
    if (size > 1)
    {
        size_t half = size / 2;

        bitonic_compare(array, half, dir);
        bitonic_merge(array, half, dir);

        bitonic_compare(array + half, half, dir);
        bitonic_merge(array + half, half, dir);
    }
}

/**
 * bitonic_compare - Compares and swaps elements to create a Bitonic sequence
 * @array: Array to be compared
 * @size: Size of the array
 * @dir: Sorting direction (ASCENDING or DESCENDING)
 */
void bitonic_compare(int *array, size_t size, int dir)
{
    if (size > 1)
    {
        size_t i, j;
        size_t step = size / 2;

        for (i = 0; i < size - step; i++)
        {
            j = i + step;
            if ((array[i] > array[j] && dir == ASCENDING) || (array[i] < array[j] && dir == DESCENDING))
                swap(&array[i], &array[j]);
        }
    }
}

/**
 * swap - Swaps two elements in an array
 * @a: Pointer to the first element
 * @b: Pointer to the second element
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * is_power_of_two - Checks if a number is a power of two
 * @n: Number to be checked
 * Return: 1 if true, 0 otherwise
 */
int is_power_of_two(size_t n)
{
    return (n && !(n & (n - 1)));
}
