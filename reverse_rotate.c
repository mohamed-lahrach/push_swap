/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahrach <mlahrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 01:29:58 by mlahrach          #+#    #+#             */
/*   Updated: 2024/03/23 21:26:19 by mlahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_list **a)
{
	t_list	*second_last;
	t_list	*last;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	second_last = *a;
	last = ft_lstlast(*a);
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
