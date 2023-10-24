#include "sort.h"

/**
 * quick_sort_hoare - a function that sorts an array of integers
 * in ascending order using the Quick sort algorithm
 * @array: input array
 * @size: size of the array
 *
 * Return: Void
 */
void quick_sort_hoare(int *array, size_t size)
{
	int pivot = 0;

	if (!array || size < 2)
		return;
	pivot = hoare_part(array, size);
	quick_sort_hoare(array, (size_t) pivot);
	quick_sort_hoare(array + pivot, size - (size_t) pivot);
}

/**
 * hoare_part - partitioning the array into two arrays
 * @array: input array
 * @size: size of the array
 *
 * Return: position of the separator
 */
int hoare_part(int *array, size_t size)
{
	int pivot = array[size - 1], i = -1, j = (int) size, temp = 0;
	static size_t initial_size;
	static int *initial_array, counter;


	if (counter == 0)
	{
		initial_size = size;
		initial_array = array;
		counter++;
	}
	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (i);
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		print_array(initial_array, initial_size);
	}
}
