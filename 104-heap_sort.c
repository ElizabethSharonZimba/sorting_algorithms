#include "sort.h"
/**
 * swap - two integers
 * @a: o the first integer
 * @b: to the second integer
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * heapify - an array into a max heap
 * @array: to be sorted
 * @size: of the array
 * @i: to start the heapify process
 * @total_size: of the array (used for printing)
 */
void heapify(int *array, size_t size, size_t i, size_t total_size)
{
    size_t largest = i;
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;

    if (left < size && array[left] > array[largest])
        largest = left;

    if (right < size && array[right] > array[largest])
        largest = right;

    if (largest != i)
    {
        swap(&array[i], &array[largest]);
        print_array(array, total_size);
        heapify(array, size, largest, total_size);
    }
}

/**
 * heap_sort - of int in ascending order using
 * @array: to be sorted
 * @size: of the array
 */
void heap_sort(int *array, size_t size)
{
    size_t i;

    if (array == NULL || size < 2)
        return;

    for (i = size / 2; i > 0; i--)
        heapify(array, size, i - 1, size);

    for (i = size - 1; i > 0; i--)
    {
        swap(&array[0], &array[i]);
        print_array(array, size);
        heapify(array, i, 0, size);
    }
}
