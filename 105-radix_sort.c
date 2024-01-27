#include "sort.h"
/**
 * getMax - Returns the maximum value in an array
 * @array: array
 * @size: of the array
 * Return: value
 */
int getMax(int *array, size_t size)
{
    int max = array[0];
    size_t i;

    for (i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    return (max);
}

/**
 * countingSort - an array using counting sort
 * @array: to be sorted
 * @size: of the array
 * @exp: significant place value
 */
void countingSort(int *array, size_t size, int exp)
{
    int *output = NULL;
    int count[10] = {0};
    size_t i;

    output = malloc(sizeof(int) * size);
    if (output == NULL)
        return;

    for (i = 0; i < size; i++)
        count[(array[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = size - 1; i + 1 > 0; i--)
    {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    for (i = 0; i < size; i++)
        array[i] = output[i];

    print_array(array, size);

    free(output);
}

/**
 * radix_sort - of int in ascending order using
 * @array: to be sorted
 * @size: of the array
 */
void radix_sort(int *array, size_t size)
{
    int max, exp;

    if (array == NULL || size < 2)
        return;

    max = getMax(array, size);

    for (exp = 1; max / exp > 0; exp *= 10)
    {
        countingSort(array, size, exp);
    }
}
