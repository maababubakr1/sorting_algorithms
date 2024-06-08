#include "sort.h"

/**
 * node_swap - swap two nodes of list
 * @h: pointer to head of the double-linked list
 * @n: pointer to first node to swap
 * @m: the second node to swap
*/
void node_swap(listint_t **h, listint_t **n, listint_t *m)
{
(*n)->next = m->next;
if (m->next != NULL)
m->next->prev = *n;
m->prev = (*n)->prev;
m->next = *n;
if ((*n)->prev != NULL)
(*n)->prev->next = m;
else
*h = m;
(*n)->prev = m;
(*n) = m->prev;
}

/**
 * insertion_sort_list - sorts a doubly linked list in ascending order
 * @list: pointer to  the double-linked list to be sorted
*/
void insertion_sort_list(listint_t **list)
{
listint_t *iterate, *insert, *temp;

if (list == NULL || *list == NULL || (*list)->next == NULL)
return;
for (iterate = (*list)->next; iterate != NULL; iterate = temp)
{
temp = iterate->next;
insert = iterate->prev;
while (insert != NULL && iterate->n < insert->n)
{
node_swap(list, &insert, iterate);
print_list((const listint_t *)*list);
}
}
}
