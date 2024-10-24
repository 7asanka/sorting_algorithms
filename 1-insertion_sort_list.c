#include "sort.h"

/**
 * swap_nodes - swaps two adjacent nodes in a doubly linked list
 * @list: A pointer to the pointer to the head of the doubly linked list
 * @node: A pointer to the node to be moved backwards.
 *
 * Return: nothing
 */
void swap_nodes(listint_t **list, listint_t *node)
{
	listint_t *prev_node = node->prev;
	listint_t *next_node = node->next;

	if (prev_node->prev != NULL)
		prev_node->prev->next = node;
	else
		*list = node;

	if (next_node != NULL)
		next_node->prev = prev_node;

	node->prev = prev_node->prev;
	node->next = prev_node;
	prev_node->prev = node;
	prev_node->next = next_node;
}

/**
 * insertion_sort_list - sorting algorithm that works by iteratively
 * inserting each element of an unsorted list into its correct position
 * @list: pointer to the pointer to the head of the list
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insert;

	if (*list == NULL || list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		insert = current->prev;

		while (insert != NULL && current->n < insert->n)
		{
			swap_nodes(list, current);
			print_list(*list);
			insert = current->prev;
		}

		current = current->next;
	}
}
