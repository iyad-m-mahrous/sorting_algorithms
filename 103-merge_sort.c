#include "sort.h"

/**
 * merge_sort - a function that sorts an array of integersi
 * in ascending order using the Merge sort algorithm
 * @array: the array to be sorted
 * @size: size of the array
 *
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	size_t mid, i = 0;
	int *left, *right;

	if (!array || size <= 1)
		return;
	mid = size / 2;
	merge_sort(array, mid);
	merge_sort(array + mid, size - mid);

	left = malloc(sizeof(*left) * mid);
	if (!left)
	{
		fprintf(stderr, "Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	right =  malloc(sizeof(*right) * (size - mid));
	if (!right)
	{
		free(left);
		fprintf(stderr, "Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < size; i++)
	{
		if (i < mid)
			left[i] = array[i];
		else
			right[i - mid] = array[i];
	}

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, mid);
	printf("[right]: ");
	print_array(right, size - mid);
	merge(array, left, mid, right, size - mid);
	printf("[Done]: ");
	print_array(array, size);
	free(left);
	free(right);
}

/**
 * merge - merging the two array
 * @array: the original list
 * @left: the sorted left part
 * @l_size: the size of left array
 * @right: the sorted right part
 * @r_size: the size of right array
 *
 * Return: Void
 */
void merge(int *array, int *left, size_t l_size, int *right, size_t r_size)
{
	size_t i = 0, j = 0, k = 0;

	while (i < l_size && j < r_size)
	{
		if (left[i] <= right[j])
		{
			array[k] = left[i];
			i++;
		}
		else
		{
			array[k] = right[j];
			j++;
		}
		k++;
	}

	while (i < l_size)
	{
		array[k] = left[i];
		k++;
		i++;
	}
	while (j < r_size)
	{
		array[k] = right[j];
		k++;
		j++;
	}

}
