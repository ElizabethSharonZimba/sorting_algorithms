#include "sort.h"
/**
 * quick_sort - int in ascending order
 * @array: to be sorted
 * @size: num of elements in array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort_recursive(array, 0, size - 1, size);
}

/**
 * quicksort_recursive - function to perform Quick Sort
 * @array: to be sorted
 * @low: index of the partition
 * @high: index of the partition
 * @size: num of elements in array
 */
void quicksort_recursive(int *array, int low, int high, size_t size)
{
	int partition_index;

	if (low < high)
	{
		partition_index = lomuto_partition(array, low, high, size);
		quicksort_recursive(array, low, partition_index - 1, size);
		quicksort_recursive(array, partition_index + 1, high, size);
	}
}

/**
 * lomuto_partition - scheme for Quick Sort
 * @array: array to be sorted
 * @low: index of the partition
 * @high: index of the partition
 * @size: num of elements in array
 * Return: index
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j, temp;

	pivot = array[high];
	i = low - 1;

	for (j = low; j <= high - 1; ++j)
	{
		if (array[j] < pivot)
		{
			++i;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			print_array(array, size);
		}
	}
	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;
	print_array(array, size);
	return (i + 1);
}
