#include "sort.h"
/**
 * bitonic_merge - two halves of the array in either
 * @array: to be sorted
 * @size: of the array
 * @order: 1 for ascending, 0 for descending
 */
void bitonic_merge(int *array, size_t size, int order)
{
    size_t i, half_size;
    int temp;

    if (size > 1)
    {
        half_size = size / 2;

        for (i = 0; i < half_size; i++)
        {
            if ((array[i] > array[i + half_size]) == order)
            {
                temp = array[i];
                array[i] = array[i + half_size];
                array[i + half_size] = temp;
            }
        }

        bitonic_merge(array, half_size, order);
        bitonic_merge(array + half_size, half_size, order);
    }
}

/**
 * bitonic_sort_recursive - sorts recursively a bitonic sequence
 * @array: to be sorted
 * @size: of the array
 * @order: sorts in order 1 for ascending, 0 for descending
 */
void bitonic_sort_recursive(int *array, size_t size, int order)
{
    size_t half_size;

    if (size > 1)
    {
        half_size = size / 2;

        bitonic_sort_recursive(array, half_size, 1);
        bitonic_sort_recursive(array + half_size, half_size, 0);

        bitonic_merge(array, size, order);
    }
}

/**
 * bitonic_sort - an array of int in ascending
 * @array: to be sorted
 * @size: of the array
 */
void bitonic_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    bitonic_sort_recursive(array, size, 1);
}
