#include "sort.h"
/**
 * insertion_sort_list - Sorts doubly linked list integers
 * @list: doubly linked list to sort
 * Return: 0
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp_node = *list, *prev_node = NULL, *temp = *list;
	int cont;

	if (temp  == NULL || (*temp) == NULL || ((*temp)->next) == NULL)
		return;
	while (temp)
	{
		cont++;
		temp = temp->next;
	}
	if (cont < 2)
		return;
	while (tmp_node)
	{
		while (tmp_node->prev && tmp_node->n < tmp_node->prev->n)
		{
			prev_node = tmp_node->prev;
			prev_node->next = tmp_node->next;
			tmp_node->prev = prev_node->prev;
			prev_node->prev = tmp_node;
			tmp_node->next = prev_node;
			if (prev_node->next)
				prev_node->next->prev = prev_node;
			if (tmp_node->prev)
				tmp_node->prev->next = tmp_node;
			if (!tmp_node->prev)
				*list = tmp_node;
			print_list(*list);
		}
		tmp_node = tmp_node->next;
	}
}
