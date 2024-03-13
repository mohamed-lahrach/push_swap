#include "libft.h"

void reverse_rotate(t_list **a)
{
    if (*a == NULL || (*a)->next == NULL)
        return;

    t_list *second_last = *a;
    t_list *last = ft_lstlast(*a);
    while (second_last->next->next != NULL)
        second_last = second_last->next;
    second_last->next = NULL;
    ft_lstadd_front(a, last);
}

void	rra(t_list **head)
{
	reverse_rotate(head);
	write(1, "rra\n", 4);
}

void	rrb(t_list **head)
{
	reverse_rotate(head);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **head, t_list **head1)
{
	reverse_rotate(head);
	reverse_rotate(head1);
	write(1, "rrr\n", 4);
}