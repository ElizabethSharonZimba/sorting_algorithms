#include "sort.h"
/**
 * hoare_partition -implements the Hoare partition scheme
 * @array: to be sorted
 * @low: index of the partition
 * @high: index of the partition
 * @size: the array
 * Return: index after partitioning
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1, j = high + 1;

    while (1)
    {
        do
        {
            i++;
        } while (array[i] < pivot);

        do
        {
            j--;
        } while (array[j] > pivot);

        if (i < j)
        {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            print_array(array, size);
        }
        else
        {
            return j;
        }
    }
}

/**
 * quick_sort_recursive -  sorts recursively a partition of the array
 * @array: to be sorted
 * @low: of the partition
 * @high: of the partition
 * @size: of the array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int pivot = hoare_partition(array, low, high, size);

        quick_sort_recursive(array, low, pivot, size);
        quick_sort_recursive(array, pivot + 1, high, size);
    }
}

/**
 * quick_sort_hoare - Sorts an array of int in ascending order
 * @array: to be sorted
 * @size: of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quick_sort_recursive(array, 0, size - 1, size);
}
