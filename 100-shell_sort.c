#include "sort.h"
/**
 * shell_sort - function with shell sort algorithm
 * @array: array
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t interval = 1, i, j;
	int temp;

	while (interval <= size / 3)
	{
		interval = (interval * 3) + 1;
	}
	while (interval > 0)
	{
		for (i = interval; i < size; i++)
		{
			temp = array[i];

			for (j = i; j > interval - 1 && array[j - interval] >= temp;
					j = j - interval){
				array[j] = array[j - interval];
			}
			array[j] = temp;
		}
		interval = (interval - 1) / 3;
		print_array(array, size);
	}
}
