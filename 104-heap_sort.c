#include "sort.h"

/**
 * heap_sort - a function that sorts an array of integers
 * in ascending order using the Heap sort algorithm
 * @array: array to be sorted
 * @size: array size
 *
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
	size_t i;
	int temp;

	if (!array || size <= 1)
		return;
	build_max_heap(array, size);

	for (i = size - 1; i > 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		print_array(array, size);
		max_heapify(array, i, 0, size);
	}
}

/**
 *  build_max_heap - build Max Heap
 *  @array: array to be sorted
 *  @size: array size
 *
 *  Return: void
 */
void build_max_heap(int *array, size_t size)
{
	int i = 0;

	for (i = (int) size / 2 - 1; i >= 0; i--)
		max_heapify(array, size, i, size);
}

/**
 * max_heapify - max heapify subtree
 * @array: array to be sorted
 * @size: array size
 * @index: the index of the root of the subtree
 * @original_size: the original array size
 *
 * Return: void
 */
void max_heapify(int *array, size_t size, size_t index, size_t original_size)
{
	size_t largest = index, left = 0, right = 0;
	int temp;

	left = index * 2 + 1;
	right = index * 2 + 2;

	if (left < size && array[left] > array[largest])
		largest = left;
	if (right < size && array[right] > array[largest])
		largest = right;

	if (largest != index)
	{
		temp = array[index];
		array[index] = array[largest];
		array[largest] = temp;
		print_array(array, original_size);
		max_heapify(array, size, largest, original_size);
	}

}
