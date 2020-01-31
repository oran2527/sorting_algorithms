#include "sort.h"
/**
 * selection_sort - sort an array with selection sort
 * @array: array
 * @size: amount of array's elements
 */
void selection_sort(int *array, size_t size)
{
	int current, low, flag;
	size_t j, i, index;

	if (size <= 1)
		print_array(array, size);
	if (size > 1)
	{
		for (i = 0; i < size - 1; i++)
		{
			low = array[i];
			flag = 0;
			for (j = i + 1; j < size; j++)
			{
				if (low > array[j])
				{
					low = array[j];
					index = j;
					flag = 1;
				}
			}
			if (flag == 1)
			{
				current = array[i];
				array[i] = low;
				array[index] = current;
				print_array(array, size);
			}
		}
	}
}
