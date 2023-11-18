#include <stdio.h>
#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using
 * the Shell sort algorithm with the Knuth sequence.
 *
 * @array: Array to be sorted.
 * @size: Size of the array.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1;
    size_t i, j;
    int temp;

    if (array == NULL || size < 2)
        return;

    while (gap < size)
        gap = gap * 3 + 1;

    while (gap > 1)
    {
        gap = (gap - 1) / 3;

        for (i = gap; i < size; i++)
        {
            temp = array[i];
            j = i;

            while (j >= gap && array[j - gap] > temp)
            {
                array[j] = array[j - gap];
                j -= gap;
            }

            array[j] = temp;
        }

        print_array(array, size);
    }
}
