/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahrach <mlahrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 01:30:02 by mlahrach          #+#    #+#             */
/*   Updated: 2024/03/23 21:26:19 by mlahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **a)
{
	t_list	*first;

	first = *a;
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
