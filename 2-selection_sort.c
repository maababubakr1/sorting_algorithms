#include "sort.h"

/**
 * swap - function to swap two ints
 * @xp: first int to swap
 * @yp: second int to swap
*/

void swap(int *xp, int *yp)
{
int temp = *xp;
*xp = *yp;
*yp = temp;
}

/**
 * selection_sort - an array of integers in ascending order
 * @array: pointer to the array to be sorted
 * @size: the size of the array
*/
void selection_sort(int *array, size_t size)
{
size_t i, j;
int *index;

if (array == NULL || size < 2)
return;
for (i = 0; i < size - 1; i++)
{
index = array + i;
for (j = i + 1; j < size; j++)
{
if (array[j] < *index)
index = array + j;
}
if (array + i != index)
{
swap(array + i, index);
print_array(array, size);
}
}
}
