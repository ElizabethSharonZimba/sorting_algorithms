#include "sort.h"
/**
 * counting_sort - of int in ascending order using
 * @array: to be sorted
 * @size: of the array
 */
void counting_sort(int *array, size_t size)
{
    int *counting_array, *output_array;
    int max, i;

    if (array == NULL || size < 2)
        return;

    max = array[0];
    for (i = 1; i < (int)size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    counting_array = malloc(sizeof(int) * (max + 1));
    if (counting_array == NULL)
        return;

    for (i = 0; i <= max; i++)
        counting_array[i] = 0;

    for (i = 0; i < (int)size; i++)
        counting_array[array[i]]++;

    print_array(counting_array, max + 1);

    for (i = 1; i <= max; i++)
        counting_array[i] += counting_array[i - 1];

    output_array = malloc(sizeof(int) * size);
    if (output_array == NULL)
    {
        free(counting_array);
        return;
    }

    for (i = size - 1; i >= 0; i--)
    {
        output_array[counting_array[array[i]] - 1] = array[i];
        counting_array[array[i]]--;
    }

    for (i = 0; i < (int)size; i++)
        array[i] = output_array[i];

    free(output_array);
    free(counting_array);
}
