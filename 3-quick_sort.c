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
 * lomuto_partition - order a subset of an array of integers according to
 *              the lomuto partition scheme
 * @array: The array of integers
 * @size: The size of the array
 * @left: The starting index of the subset to order
 * @right: The ending index of the subset to order
 * Return: The final partition index
*/
int lomuto_partition(int *array, size_t size, int left, int right)
{
int *pivot, above, below;

pivot = array + right;
for (above = below = left; below < right; below++)
{
if (array[below] < *pivot)
{
if (above < below)
{
swap(array + below, array + above);
print_array(array, size);
}
above++;
}
}

if (array[above] > *pivot)
{
swap(array + above, pivot);
print_array(array, size);
}

return (above);
}

/**
 * lomuto_partition - implement the quicksort algorithm through recursion
 * @array: The array of integers
 * @size: The size of the array
 * @left: The starting index of the subset to order
 * @right: The ending index of the subset to order
*/
void lomuto_sort(int *array, size_t size, int left, int right)
{
int part;

if (right - left > 0)
{
part = lomuto_partition(array, size, left, right);
lomuto_sort(array, size, left, part - 1);
lomuto_sort(array, size, part + 1, right);
}
}

/**
 * quick_sort - sort an array of integers in ascending
 *              order using the quicksort algorithm
 * @array: An array of integers
 * @size: The size of the array
*/
void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

lomuto_sort(array, size, 0, size - 1);
}
