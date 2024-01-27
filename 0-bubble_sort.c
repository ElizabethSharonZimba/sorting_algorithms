#include "sort.h"
/**
 * bubble_sort - sorts int in ascending order
 * @array: to be sorted
 * @size: num of elements in array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, k;
	int temp;
	int swapped;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size - 1; ++i)
	{
		swapped = 0;
		for (k = 0; k < size - i - 1; ++k)
		{
			if (array[k] > array[k + 1])
			{
				temp = array[k];
				array[k] = array[k + 1];
				array[k + 1] = temp;
				swapped = 1;
				print_array(array, size);
			}
		}
		if (!swapped)
			break;
	}
}
