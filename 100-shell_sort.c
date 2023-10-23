#include "sort.h"

/**
 * shell_sort -  a function that sorts an array of integers in ascending
 * order using the Shell sort algorithm, using the Knuth sequence
 * @array: the integers array
 * @size: the size of the array
 *
 * Return: Void
 */
void shell_sort(int *array, size_t size)
{
	int i = 0, j = 0, temp = 0, k = 0, l = 1, start = 0;

	while (l < (int) size / 3)
		l = 3 * l + 1;
	while (l >= 1)
	{
		while (start < l)
		{
			for (i = start; i < (int) size; i += l)
			{
				k = i;
				for (j = i; j >= 0; j -= l)
				{
					if (array[j] > array[k])
					{
						temp = array[k];
						array[k] = array[j];
						array[j] = temp;
						k = j;
					}
				}
			}
			start++;
		}
		start = 0;
		l = (l - 1) / 3;
		print_array(array, size);
	}
}
