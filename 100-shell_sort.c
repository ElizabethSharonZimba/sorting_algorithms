#include "sort.h"
/**
 * shell_sort - Sorts an array of int in ascending order
 * @array: to be sorted
 * @size: num of elements in array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int temp;
	
	if (array == NULL || size < 2)
		return;
	
	for (gap = 1; gap <= size / 3; gap = gap * 3 + 1);
	
	while (gap > 0)
	{
		for (i = gap; i < size; ++i)
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

        gap = (gap - 1) / 3;
    }
}
