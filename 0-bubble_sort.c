#include "sort.h"

/**
 * int_swap - swap ints in an array
 * @x: first int to swap
 * @y: second int to swap
 */
void int_swap(int *x, int *y)
{
int temp;

temp = *x;
*x = *y;
*y = temp;
}

/**
 * bubble_sort - function that sorts an array
 *  of integers in ascending order
 * @array: array to be sorted
 * @size: size of the array
*/

void bubble_sort(int *array, size_t size)
{
/** define */
size_t i, len = size;
bool check = false;

/** check if swap is available*/
if (array == NULL || size < 2)
return;
/** loop to iterate through the array*/
while (check == false)
{
check = true;
for (i = 0; i < len - 1; i++)
{
if (array[i] > array[i + 1])
{
int_swap(array + i, array + i + 1);
print_array(array, size);
check = false;
}
}
len--;
}
}
