#include "sort.h"

/**
 * selection_sort - a function that sorts an array of integers in
 *  ascending order using the Selection sort algorithm
 * @array: the array to be sorted
 * @size: size of the array
 *
 * Return: Nothing
 *
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j = 0, min = 0;
	int temp = 0;

	if (!array || !size)
		return;

	for (i = 0; i < (size - 1); i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] <  array[min])
			{
				min = j;
			}
		}
		if (min != i)
		{
			temp = array[i];
			array[i] = array[min];
			array[min] = temp;			
			print_array(array, size);
		}
	}
}
