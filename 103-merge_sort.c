#include "sort.h"
/**
 * merge - two sub-arrays of the array
 * @array: to be sorted
 * @size: of the array
 * @left: sub-array
 * @right: sub-array
 */
void merge(int *array, size_t size, int *left, size_t size_left, int *right, size_t size_right)
{
    size_t i = 0, j = 0, k = 0;
    int *merged;

    printf("Merging...\n[left]: ");
    print_array(left, size_left);
    printf("[right]: ");
    print_array(right, size_right);

    merged = malloc(sizeof(int) * size);
    if (merged == NULL)
        return;

    while (i < size_left && j < size_right)
    {
        if (left[i] <= right[j])
        {
            merged[k] = left[i];
            i++;
        }
        else
        {
            merged[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < size_left)
    {
        merged[k] = left[i];
        i++;
        k++;
    }

    while (j < size_right)
    {
        merged[k] = right[j];
        j++;
        k++;
    }

    for (i = 0; i < size; i++)
        array[i] = merged[i];

    printf("[Done]: ");
    print_array(array, size);

    free(merged);
}

/**
 * merge_sort - of int in ascending order using
 * @array: to be sorted
 * @size: of the array
 */
void merge_sort(int *array, size_t size)
{
    size_t mid, i;
    int *left, *right;

    if (array == NULL || size < 2)
        return;

    mid = size / 2;
    left = array;
    right = array + mid;

    merge_sort(left, mid);
    merge_sort(right, size - mid);
    merge(array, size, left, mid, right, size - mid);
}
