#include "sort.h"

/**
 * quick_sort - Function that sorts an array of integers in ascending
 * order using the Quick sort algorithm and Lomuto partition scheme
 *
 * @array: array to sort
 * @size: the size of the array
 *
 * Return: 0
 */
void quick_sort(int *array, size_t size)
{
	if (array != NULL)
	{
		sorting(array, 0, size - 1, size);
	}
}

/**
 * sorting - Function that implements quicksort
 *
 * @array: array to sort
 * @low: Starting index
 * @high: Ending index
 * @size: the size of the array
 *
 * Return: 0
 */
void sorting(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);

		sorting(array, low, pivot - 1, size);
		sorting(array, pivot + 1, high, size);
	}
}

/**
 * partition - Function that takes last element as pivot, places
 * the pivot element at its correct position in sorted array, and places
 * all smaller to left of pivot and all greater elements to right of pivot
 *
 * @array: array to sort
 * @low: Starting index
 * @high: Ending index
 * @size: the size of the array
 *
 * Return: Int
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high], i = low - 1, j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
				swap(array, &array[i], &array[j], size);
		}
	}

	if (array[high] < array[i + 1])
		swap(array, &array[i + 1], &array[high], size);

	return (i + 1);
}

/**
 * swap - Function that swap two elements
 *
 * @array: Array to print
 * @a: Element a
 * @b: Element b
 * @size: Size to array
 *
 * Return: Int
 */
void swap(int *array, int *a, int *b, size_t size)
{
	int t = *a;
	*a = *b;
	*b = t;
	print_array(array, size);
}
