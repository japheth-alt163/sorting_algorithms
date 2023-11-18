#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order
 * using the Counting sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */
void counting_sort(int *array, size_t size)
{
	/* Find the maximum value in the array */
        int max = array[0];
        size_t i;

	/* Create the counting array and initialize to 0 */
        int *count = malloc((max + 1) * sizeof(int));

	/* Create the output array and populate it using the counting array */
        int *output = malloc(size * sizeof(int));

	if (array == NULL || size < 2)
		return;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	if (count == NULL)
		return;

	for (i = 0; i <= (size_t)max; i++)
		count[i] = 0;

	/* Populate the counting array */
	for (i = 0; i < size; i++)
		count[array[i]]++;

	/* Update the counting array to store the actual position of each element */
	for (i = 1; i <= (size_t)max; i++)
		count[i] += count[i - 1];

	print_array(count, max + 1);

	if (output == NULL)
	{
		free(count);
		return;
	}

	for (i = size - 1; i < size; i--)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	/* Copy the output array back to the original array */
	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
	free(count);
}
