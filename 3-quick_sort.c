#include "sort.h"

/**
 * quick_sort - a function that sorts an array of integers
 * in ascending order using the Quick sort algorithm
 * @array: input array
 * @size: size of the array
 *
 * Return: Void
 */
void quick_sort(int *array, size_t size)
{
	int pivot = 0;

	if (!array || size < 2)
		return;
	pivot = lomuto_part(array, size);
	quick_sort(array, (size_t) pivot);
	quick_sort(array + pivot + 1, size - (size_t) (pivot + 1));
}

/**
 * select_pivot - a function that returns the pivot index
 * @array: input array
 * @size: size of the array
 *
 * Return: Pivot index
 */
int select_pivot(int *array, size_t size)
{
	(void) array;
	return ((int) (size - 1));
}

/**
 * lomuto_part - partitioning the array into two arrays
 * @array: input array
 * @size: size of the array
 *
 * Return: position of the separator
 */
int lomuto_part(int *array, size_t size)
{
	int idx_pivot = 0, i = -1, j = -1, temp = 0;
	static size_t initial_size;
	static int *initial_array, counter;

	if (counter == 0)
	{
		initial_size = size;
		initial_array = array;
		counter++;
	}
	idx_pivot = select_pivot(array, size);
	for (j = 0; j < (idx_pivot + 1); j++)
	{
		if (array[j] < array[idx_pivot] || j == idx_pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			if (i != j)
				print_array(initial_array, initial_size);
		}
	}
	return (i);
}
