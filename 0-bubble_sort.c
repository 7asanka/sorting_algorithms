#include "sort.h"

/**
 * bubble_sort - sorting algorithm that works by repeatedly swapping
 * the adjacent elements if they are in the wrong order
 * @array: pointer to the array to be sorted
 * @size: size of the array
 *
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
	int swapped;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;

		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				int tmp = array[j];

				array[j] = array[j + 1];
				array[j + 1] = tmp;

				print_array(array, size);
				swapped = 1;
			}
		}

		if (!swapped)
			break;
	}
}
