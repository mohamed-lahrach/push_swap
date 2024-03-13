#include "libft.h"

void swap(t_list **a)
{
    if (*a != NULL && (*a)->next != NULL)
    {
        t_list *first = *a;
        t_list *second = (*a)->next;

        first->next = second->next;
        second->next = first;
        *a = second;
    }
}

void	sa(t_list **head)
{
	swap(head);
	write(1, "sa\n", 3);
}

void	sb(t_list **head)
{
	swap(head);
	write(1, "sb\n", 3);
}