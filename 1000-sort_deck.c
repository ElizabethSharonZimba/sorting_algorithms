#include "deck.h"
#include <stdlib.h>
/**
 * sort_deck - Sorts cards in ascending order
 * @deck: head of the deck
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL)
		return;
	
	size_t count[13][4] = {0};
	deck_node_t *current = *deck;
	
	while (current)
	{
		count[current->card->value[0] - '0' - 1][current->card->kind]++;
		current = current->next;
	}
	current = *deck;
	while (current)
	{
		size_t value_index = current->card->value[0] - '0' - 1;
		size_t kind_index = current->card->kind;
		deck_node_t *temp = current->next;
		
		current->prev = NULL;
		current->next = NULL;
		
		if (count[value_index][kind_index] > 0)
		{
			current->next = *deck;
			
			if (*deck)
				(*deck)->prev = current;
			*deck = current;
			count[value_index][kind_index]--;
		}
		current = temp;
	}
}
