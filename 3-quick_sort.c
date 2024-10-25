#include "sort.h"

/**
 * swap - swaps two integers in an array.
 * @a: the first integer.
 * @b: the second integer.
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - partitions the array using the Lomuto scheme.
 * @array: the array to partition.
 * @low: the starting index of the partition.
 * @high: the ending index of the partition (pivot).
 * @size: the size of the array.
 *
 * Return: the final index of the pivot.
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1, j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}

	if (array[high] < array[i + 1])
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quick_sort_recursive - sorts the array using recursive Quick Sort.
 * @array: the array to sort.
 * @low: the starting index of the array partition.
 * @high: the ending index of the array partition.
 * @size: the size of the array.
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = lomuto_partition(array, low, high, size);
		quick_sort_recursive(array, low, pivot_index - 1, size);
		quick_sort_recursive(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - sorting algorithm based on the Divide and Conquer that picks
 * an element as a pivot and partitions the given array around the picked
 * pivot by placing the pivot in its correct position in the sorted array
 * @array: the array to sort.
 * @size: the size of the array.
 *
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
