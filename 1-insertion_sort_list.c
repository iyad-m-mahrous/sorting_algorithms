#include "sort.h"

/**
 * insertion_sort_list - a function that sorts a doubly
 * linked list of integers in ascending order using the
 * Insertion sort algorithm
 * @list: Doubly linked list
 *
 * Return: Void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *forward, *swap, *backward;

	if (!list || !*list)
		return;
	forward = *list;
	while (forward)
	{
		backward = forward;
		forward = forward->next;
		while (backward->prev && (backward->prev->n > backward->n))
		{
			swap = backward->prev;
			backward->prev = swap->prev;
			swap->next = backward->next;
			backward->next = swap;
			swap->prev = backward;

			if (backward->prev)
				backward->prev->next = backward;
			else
				*list = backward;
			if (swap->next)
				swap->next->prev = swap;
			print_list(*list);
		}
	}
}
