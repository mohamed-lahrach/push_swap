#include "libft.h"

void rotate(t_list **a)
{
    t_list *first = *a;

    (*a) = first->next;
    first->next = NULL;
    ft_lstadd_back(a, first);
}
void	ra(t_list **head)
{
	rotate(head);
	write(1, "ra\n", 3);
}

void	rb(t_list **head)
{
	rotate(head);
	write(1, "rb\n", 3);
}

void	rr(t_list **head1, t_list **head2)
{
	rotate(head1);
	rotate(head2);
	write(1, "rr\n", 3);
}