#include "sort.h"

/**
 * selection_sort - sorts an array by repeatedly selecting the smallest
 * (or largest) element from the unsorted portion and swapping it with the
 * first unsorted element
 * @array: pointer to the array to be sorted
 * @size: size of the array to be sorted
 *
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
	int i, j, min_idx, tmp;

	for (i = 0; i < (int)size - 1; i++)
	{
		min_idx = i;

		for (j = i + 1; j < (int)size; j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
		}

		if (!(array[i] == array[min_idx]))
		{
			tmp = array[i];
			array[i] = array[min_idx];
			array[min_idx] = tmp;
			print_array(array, size);
		}
	}
}
