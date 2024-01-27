#include "sort.h"
/**
 * insertion_sort_list - Sorts lists in ascending order
 * @list: Pointer to the head
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (list == NULL || *list == NULL)
		return;
	current = (*list)->next;
	while (current != NULL)
	{
		temp = current->next;
		while (current->prev != NULL && current->n < current->prev->n)
		{
			current->prev->next = current->next;
			if (current->next != NULL)
				current->next->prev = current->prev;
			current->next = current->prev;
			current->prev = current->prev->prev;
			if (current->prev != NULL)
			current->prev->next = current;
			current->next->prev = current;
			if (current->prev == NULL)
				*list = current;
			print_list(*list);
		}
		current = temp;
	}
}
